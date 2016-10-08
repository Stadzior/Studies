ICE=chat.ice
SLICE=slice2cpp
CC=g++ -pthread
CFLAGS=-I. -I$ICE_HOME/include
LFLAGS=-L$ICE_HOME/lib -lIce -lIceUtil

SERVER_OBJS=Server.o chat.o ResponseGenerator.o ChatServerI.o ChatRoomI.o ChatFactoryI.o
USER_OBJS=User.o chat.o ResponseGenerator.o UserI.o
FACTORY_OBJS=Factory.o chat.o ChatRoomI.o ChatFactoryI.o

SERVER_C=Server.cpp chat.cpp ResponseGenerator.cpp ChatServerI.cpp ChatRoomI.cpp ChatFactoryI.cpp
USER_C=User.cpp chat.cpp ResponseGenerator.cpp UserI.cpp
FACTORY_C=Factory.cpp chat.cpp ChatRoomI.cpp ChatFactoryI.cpp

EXECS=Server User Factory
ICE_OUT=chat.cpp chat.h

all: $(EXECS) $(ICE_OUT)

$(ICE_OUT): $(ICE)
	$(SLICE) $^

Server: $(SERVER_OBJS)
	$(CC) -o $@ $^ $(LFLAGS)

User: $(USER_OBJS)
	$(CC) -o $@ $^ $(LFLAGS)

Factory: $(FACTORY_OBJS)
	$(CC) -o $@ $^ $(LFLAGS)

Server.o: $(SERVER_C)
	$(CC) $(CFLAGS) -c $^

User.o: $(USER_C)
	$(CC) $(CFLAGS) -c $^

Factory.o: $(FACTORY_C)
	$(CC) $(CFLAGS) -c $^

clean:
	rm -rf $(EXECS)
	rm -rf *.o
	rm -rf $(ICE_OUT)
