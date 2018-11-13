# Makefile

CC=c++
CFLAGS=-Wall

all: Tower

Tower: Tower.o Character.o Clock.o CommandCenter.o CommandUnlock.o Item.o ItemManager.o KeyLockPair.o Path.o Room.o RoomManager.o TheGame.o
	$(CC) $(CFLAGS) -o $@ $^

Tower.o: Tower.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

CommandUnlock.o: CommandUnlock.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.o Tower
