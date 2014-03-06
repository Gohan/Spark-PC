#pragma once
#include "system/thread.h"
#include <boost/thread/mutex.hpp>
#include <boost/thread/locks.hpp>
#include <map>
class CThreadManager
{
public:
	void AddThread(const sparks::shared_ptr<CThread>& thread);
	const sparks::shared_ptr<CThread>& GetThreadByName(const std::string& thread_name);
	bool RemoveThread(const sparks::shared_ptr<CThread>& thread);
	bool RemoveThreadByName(const std::string& thread_name);

private:
	std::map<std::string, sparks::shared_ptr<CThread>> m_mapThreads;
	static sparks::shared_ptr<CThread> ms_spNullThread;
	boost::mutex m_mutex;
};