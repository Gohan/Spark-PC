#include "Thread.h"

void CThread::ThreadProc()
{
	m_uThreadId = GetCurrentThreadId();
	m_bStop = false;
	boost::mutex mutex; 
	boost::mutex::scoped_lock lock(mutex);
	while (m_bStop == false)
	{
		m_oIoService.poll();
	}
}

void CThread::StopThread()
{
	m_oIoService.post(boost::bind(&CThread::SetStop, this, true));
}

void CThread::StartThread()
{
	m_spThread.reset(new boost::thread(boost::bind(&CThread::ThreadProc, this)));
}
