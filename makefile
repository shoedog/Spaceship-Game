CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = main.o player.o playersShip.o hanger.o bridge.o combatRoom.o crewQuarters.o engineR.o hallway.o holoRoom.o medbay.o messHall.o weaponRoom.o

SRCS = main.cpp player.cpp playersShip.cpp hanger.cpp bridge.cpp combatRoom.cpp crewQuarters.cpp engineR.cpp hallway.cpp holoRoom.cpp medbay.cpp messHall.cpp weaponRoom.cpp

HDRS = room.hpp player.hpp playersShip.hpp hanger.hpp bridge.hpp combatRoom.hpp crewQuarters.hpp engineR.hpp hallway.hpp holoRoom.hpp medbay.hpp messHall.hpp weaponRoom.hpp

PROGS = fp

all: fp

fp:  ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o fp

main.o: main.cpp ${HDRS}
	${CXX} ${CXXFLAGS} -c main.cpp

player.o: player.hpp player.cpp room.hpp
	${CXX} ${CXXFLAGS} -c player.cpp

playersShip.o: playersShip.hpp playersShip.cpp room.hpp
	${CXX} ${CXXFLAGS} -c playersShip.cpp

hanger.o: hanger.hpp hanger.cpp room.hpp
	${CXX} ${CXXFLAGS} -c hanger.cpp

bridge.o: bridge.cpp bridge.hpp room.hpp
	${CXX} ${CXXFLAGS} -c bridge.cpp

combatRoom.o: combatRoom.cpp combatRoom.hpp room.hpp
	${CXX} ${CXXFLAGS} -c combatRoom.cpp

crewQuarters.o: crewQuarters.cpp crewQuarters.hpp room.hpp
	${CXX} ${CXXFLAGS} -c crewQuarters.cpp

engineR.o: engineR.cpp engineR.hpp room.hpp
	${CXX} ${CXXFLAGS} -c engineR.cpp

hallway.o: hallway.cpp hallway.hpp room.hpp
	${CXX} ${CXXFLAGS} -c hallway.cpp

holoRoom.o: holoRoom.cpp holoRoom.hpp room.hpp
	${CXX} ${CXXFLAGS} -c holoRoom.cpp

medbay.o: medbay.cpp medbay.hpp room.hpp
	${CXX} ${CXXFLAGS} -c medbay.cpp

messHall.o: messHall.cpp messHall.hpp room.hpp
	${CXX} ${CXXFLAGS} -c messHall.cpp

weaponRoom.o: weaponRoom.cpp weaponRoom.hpp room.hpp
	${CXX} ${CXXFLAGS} -c weaponRoom.cpp

clean: 
	rm -f fp *.o *~

