CC = gcc
CFLAGS += -g -Wall -Werror -Wextra -pedantic -DDEBUG
LIBS +=
ODIR = obj

TARGET = life
DIST = dist.tar.gz
DOC = doc

DEPS = ansi.h board.h

OBJ = life.o ansi.o board.o

_OBJ = $(patsubst %,$(ODIR)/%,$(OBJ))

all: $(TARGET) dist

$(ODIR)/%.o: %.c $(DEPS)
	@mkdir -p obj
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(_OBJ)
	@mkdir -p obj
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

dist: $(TARGET) $(DOC)
	tar -czf $(DIST) $(TARGET) $(DOC)

doc:
	doxygen

clean:
	rm -rf $(TARGET) $(_OBJ) $(DIST) $(DOC)
