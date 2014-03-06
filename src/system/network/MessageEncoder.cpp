#include "MessageEncoder.h"

void CMessageEncoder::EncodeGameMessage( GameMessage::GameMessage& msg )
{
	msg.mutable_msg_head()->set_body_size(msg.msg_body().ByteSize());
	msg.mutable_msg_head()->set_client_type(GameMessage::GameMessage_ClientType_PC);
}