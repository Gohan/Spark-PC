#pragma once
#include "logic/proto/GameMessage.pb.h"
#include "logic/proto/ScheduleMessage.pb.h"
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <memory>
#include <functional>
namespace sparks
{
	using boost::shared_ptr;
	using boost::bind;
	using ::google::protobuf::int8;
	using ::google::protobuf::int16;
	using ::google::protobuf::int32;
	using ::google::protobuf::int64;
	using ::google::protobuf::uint8;
	using ::google::protobuf::uint16;
	using ::google::protobuf::uint32;
	using ::google::protobuf::uint64;
}