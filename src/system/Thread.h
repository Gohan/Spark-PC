#pragma once
#include "common/config.h"
#include <string>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/function.hpp>
#include <boost/thread/condition_variable.hpp>

class CThread: public boost::enable_shared_from_this<CThread>
{
public:
	CThread() {}
	~CThread() {}

	void StartThread();
	const std::string& GetThreadName() {return m_strThreadName;}
	void SetThreadName(const std::string& name) {m_strThreadName = name;}
	sparks::shared_ptr<boost::thread>& GetThread() {return m_spThread;}
	boost::asio::io_service& GetIOService() {return m_oIoService;}
	virtual void ThreadProc();
	void StopThread();

private:
	void SetStop(bool bStop) {m_bStop = bStop;}

	sparks::uint64 m_uThreadId;
	sparks::shared_ptr<boost::thread> m_spThread;
	bool m_bStop;
	std::string m_strThreadName;
	boost::asio::io_service m_oIoService;
	boost::function<void()> m_oFunction;
	boost::condition_variable m_oExit;
};