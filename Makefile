
CC = gcc
CFLAGS += -g -Wall -Werror -Wextra -pedantic -DDEBUG
LIBS +=
ODIR = obj

TARGET = life
DIST = dist.tar.gz

DEPS =

OBJ = life.o

_OBJ = $(patsubst %,$(ODIR)/%,$(OBJ))

all: $(TARGET) dist

$(ODIR)/%.o: %.c $(DEPS)
	@mkdir -p obj
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(_OBJ)
	@mkdir -p obj
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

dist: $(TARGET)
	tar -czvf $(DIST) $(TARGET)

clean:
	rm -f $(TARGET) $(_OBJ) $(DIST)
