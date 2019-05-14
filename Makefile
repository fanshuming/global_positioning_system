CC = arm-linux-gnueabihf-gcc
CFLAGS = -I./include
LDFLAGS = -L ./lib -lgps -lm

LIB_FLAGS = -fPIC -shared
CP = cp

.PHONY: all

all:so
	${CC} ${CFLAGS}  ${LDFLAGS} src/gps_test.c -o ./bin/gps_test

so:
	${CC} src/gps.c  ${CFLAGS} ${LIB_FLAGS} -o ./lib/libgps.so

install:
	${CP} ./lib/libgps.so ../../lib/
	${CP} ./bin/* ../../bin/
	${CP} ./config/* ../../configure/
	${CP} ./include/gps.h ../../include/
	${CP} ./readme ../../doc/readme_gps

.PHONY:clean
clean:
	rm -f bin/gps* lib/*

