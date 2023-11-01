CC 				= g++
# flags as required by C++ compiler
FLAGS 			= -I /workspaces/loki

# binary
BINARY 			= loki.elf

# binary directories
BIN 			= bin
BUILD 			= bin/build

# object files
OBJECT_FILES 	= ${BUILD}/fen.o \
				  ${BUILD}/piece.o \
				  ${BUILD}/board.o

# src
FEN 			= src/chess/fen.cpp
PIECE			= src/chess/piece.cpp
BOARD			= src/chess/board.cpp
CHESS			= src/chess/fen.cpp

# rules
loki: main.cpp fen piece board
	${CC} ${FLAGS} -o ${BIN}/${BINARY} main.cpp ${OBJECT_FILES}

fen: ${FEN}
	${CC} -c ${FLAGS} -o ${BUILD}/fen.o ${FEN}

piece: ${PIECE}
	${CC} -c ${FLAGS} -o ${BUILD}/piece.o ${PIECE}

board: ${BOARD}
	${CC} -c ${FLAGS} -o ${BUILD}/board.o ${BOARD}

clean:
	rm -rf ${BUILD}/*
	rm -rf ${BIN}/${BINARY}
