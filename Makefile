CC := gcc
CFLAGS := -g -Wall -Werror -O -std=c99 -D_DEFAULT_SOURCE
LDFLAGS := -lncurses

# If you add any source files in the src/ directory, you should add
# their names to this variable.
SOURCEFILES := term.c main.c

all: field

field: $(SOURCEFILES)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c Makefile
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f *~ src/*~ src/*.o life submission.tar outputs/*.output.txt
	rm -f core core.* vgcore.*

.PHONY: all clean submission
