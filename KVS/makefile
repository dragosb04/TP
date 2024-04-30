CFLAGS = -Wall
CC = gcc
target = program
RM = del

all: ${target}

${target}:
	${CC} ${CFLAGS} -c program.c
	${CC} ${CFLAGS} -c kvs.c
	${CC} ${CFLAGS} -o ${target} program.o kvs.o
	${RM} program.o kvs.o
#clean:
#	${RM} program.o hs_utils.o