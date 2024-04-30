CFLAGS = -Wall
CC = gcc
target = program
RM = del
FILE = stack

all: ${target}

${target}:
	${CC} ${CFLAGS} -c ${target}.c
	${CC} ${CFLAGS} -c ${FILE}.c
	${CC} ${CFLAGS} -o ${target} ${target}.o ${FILE}.o
	${RM} ${target}.o ${FILE}.o
#clean:
#	${RM} program.o hs_utils.o