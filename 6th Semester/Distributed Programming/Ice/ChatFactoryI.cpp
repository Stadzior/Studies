#include <ChatFactoryI.h>

ChatRoomPrx ChatFactoryI::getNewChatRoom(const string& roomName, const Current& current)
{
	Identity roomId;
	roomId.name = roomName;
	roomId.category = "ChatRoom";

	ChatRoomPtr chatRoomPtr = new ChatRoomI();
	ChatRoomPrx chatRoomPrx = ChatRoomPrx::uncheckedCast(current.adapter->add(chatRoomPtr,roomId));
	chatRoomPrx->setName(roomName);
	cout<<"Created room: "<<roomName<<endl;
	return chatRoomPrx;
}
