#include "gtest\gtest.h"
#include "logic\proto\GameMessage.pb.h"
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <cstdio>
#include <functional>

void print(const boost::system::error_code& e)
{
	printf("OVER\n");
}

int main(int argc, char **argv)
{
	boost::asio::io_service io_service;
	boost::asio::deadline_timer timer(io_service, boost::posix_time::seconds(1));
	timer.async_wait(print);
	io_service.run();

	GameMessage::PlayerAuctionBroadcast message;
	message.set_player_id(1);
	message.set_auction_card_index(1);
	message.set_auction_card_deal(true);

	GameMessage::GameMessage msg;
	GameMessage::GameMessage::MessageBody body;
	GameMessage::PlayerAuctionBroadcast* pBody = msg.mutable_msg_body()->MutableExtension(GameMessage::player_auction_broadcast);
	pBody->CopyFrom(message);

	namespace logging = boost::log;
	namespace src = boost::log::sources;
	namespace sinks = boost::log::sinks;
	namespace keywords = boost::log::keywords;
	logging::add_file_log
		(
		keywords::file_name = "sample_%N.log",                                        
		keywords::rotation_size = 10 * 1024 * 1024,                                   
		keywords::time_based_rotation = sinks::file::rotation_at_time_point(0, 0, 0)
		);

	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}