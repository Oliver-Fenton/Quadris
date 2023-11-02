CXX=g++
CXXFLAGS=-std=c++14 -Wall -Werror=vla -MMD -I/opt/X11/include
LDFLAGS=-L/opt/X11/lib
OBJECTS=main.o blocks/abstractblock.o blocks/iblock.o blocks/jblock.o blocks/lblock.o blocks/oblock.o blocks/sblock.o blocks/zblock.o blocks/tblock.o blocks/singleblock.o levels/abstractlevel.o levels/levelzero.o levels/levelone.o levels/leveltwo.o levels/levelthree.o levels/levelfour.o grid.o cell.o commandinterpreter.o displays/textdisplay.o displays/graphicsdisplay.o observer.o subject.o score.o displays/window.o quadris.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=quadris

all: ${EXEC}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} ${LDFLAGS} -o ${EXEC} -lX11

-include ${DEPENDS}

clean:
	rm -f ${OBJECTS} ${DEPENDS} ${EXEC}
.PHONY: clean
