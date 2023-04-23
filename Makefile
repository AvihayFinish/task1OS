CC = gcc
FLAGS = -Wall -g
SO = -shared -fPIC

all: cmp copy codecA codecB encode decode

cmp: cmpTool.c
	$(CC) $(FLAGS) cmpTool.c -o cmp

copy: copyTool.c
	$(CC) $(FLAGS) copyTool.c -o copy

codecA: codecA.c
	$(CC) $(SO) -o codecA codecA.c

codecB: codecB.c
	$(CC) $(SO) -o codecB codecB.c

encode: encode.c
	$(CC) $(FLAGS) encode.c -o encode

decode: decode.c
	$(CC) $(FLAGS) decode.c -o decode

clean:
	rm -f *.o cmp copy codecA encode codecB decode

.PHONY: clean all