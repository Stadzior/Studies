#include <Ice/Ice.h>
#include "chat.h"
#include "ChatFactoryI.h"

using namespace std;
using namespace Chat;
using namespace Ice;

class Factory : virtual public Application {
private:
	ChatServerPrx chatServerPrx;
	ChatFactoryPrx chatFactoryPrx;

public:
	virtual int run(int, char*[]);
};

int Factory::run(int, char*[]) {
  CommunicatorPtr ic = communicator();
	ObjectAdapterPtr adapter =
            ic->createObjectAdapterWithEndpoints("FactoryAdapter", "default");

	ObjectPrx base = ic->stringToProxy("Server:default -p 10000");
  chatServerPrx = ChatServerPrx::checkedCast(base);
  if (!chatServerPrx)
      throw "Invalid proxy";
	ChatFactoryPtr chatFactoryPtr = new ChatFactoryI;
	chatFactoryPrx = ChatFactoryPrx::uncheckedCast(adapter->addWithUUID(chatFactoryPtr));
	chatServerPrx->registerChatFactory(chatFactoryPrx);
	adapter->activate();
	ic->waitForShutdown();
  return 0;
}

int main(int argc, char* argv[]) {
    Factory app;
    return app.main(argc, argv);
}
