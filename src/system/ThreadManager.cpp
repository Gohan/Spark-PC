#include "ThreadManager.h"
#include "Thread.h"
#include <boost/log/trivial.hpp>

sparks::shared_ptr<CThread> CThreadManager::ms_spNullThread;
void CThreadManager::AddThread( const sparks::shared_ptr<CThread>& thread )
{
	boost::mutex::scoped_lock lock(m_mutex);
	if (m_mapThreads.count(thread->GetThreadName())) {
		BOOST_LOG_TRIVIAL(error) << "AddThread(): thread name: [" << thread->GetThreadName() << "] already add!";
		return;
	}

	m_mapThreads[thread->GetThreadName()] = thread;
}

const sparks::shared_ptr<CThread>& CThreadManager::GetThreadByName( const std::string& thread_name )
{
	boost::mutex::scoped_lock lock(m_mutex);
	if (m_mapThreads.count(thread_name))
		return m_mapThreads[thread_name];

	BOOST_LOG_TRIVIAL(error) << "GetThreadByName(): thread name: [" << thread_name << "] not exist!";
	return ms_spNullThread;
}

bool CThreadManager::RemoveThread( const sparks::shared_ptr<CThread>& thread )
{
	boost::mutex::scoped_lock lock(m_mutex);
	if (m_mapThreads.count(thread->GetThreadName()) == 0) {
		BOOST_LOG_TRIVIAL(error) << "RemoveThread(): thread name: [" << thread->GetThreadName() << "] not exist!";
		return false;
	}

	m_mapThreads.erase(thread->GetThreadName());
	return true;
}

bool CThreadManager::RemoveThreadByName(const std::string& thread_name)
{
	boost::mutex::scoped_lock lock(m_mutex);
	if (m_mapThreads.count(thread_name) == 0) {
		BOOST_LOG_TRIVIAL(error) << "RemoveThreadByName(): thread name: [" << thread_name << "] not exist!";
		return false;
	}

	m_mapThreads.erase(thread_name);
	return true;
}