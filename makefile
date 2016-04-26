#
# TrimLx
#
# Last updated on 2016-04-10 by Kohji OKAMURA, Ph.D.
#
# Note that OS X gcc does not accept option -s.

PROGRAM=trimlx
CC=gcc
CFLAGS=-W -Wall -O
VERSION=-v
# ANSI=-ansi -pedantic -Werror -s
ANSI=-ansi -pedantic -Werror

trimlx: trimlx.o
	which $(CC)
	$(CC) $(VERSION)
	$(CC) $(CFLAGS) -o $(PROGRAM) trimlx.o
	chmod go+rx $(PROGRAM)
	file $(PROGRAM)
	ls -lF $(PROGRAM)

trimlx.o: trimlx.c
	$(CC) $(CFLAGS) $(ANSI) -c trimlx.c

.PHONY: clean
clean:
	rm -f $(PROGRAM) trimlx.o
