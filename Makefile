#Single makefile

SRC_PROJ=papeleria.c

ODIR=obj

OBJS=papeleria.o

CC=gcc
CFLAGS=-Wall -Wextra

vpath %.c src

all: papeleria

papeleria: $(ODIR)/$(OBJS)
	gcc $(CFLAGS) -o $@ $^

$(ODIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ papeleria
