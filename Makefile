#Single makefile
vpath %.c src

SRC_PROJ=addproducts.c downproducts.c sales.c papeleria.c

ODIR=obj

OBJS=$(patsubst %.c, $(ODIR)/%.o, $(SRC_PROJ))

CC=gcc
CFLAGS=-Wall -Wextra -I lib
#vpath %.o obj

all: papeleria

$(OBJS): | obj

obj:
	@mkdir -p $@

papeleria: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

obj/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ papeleria
