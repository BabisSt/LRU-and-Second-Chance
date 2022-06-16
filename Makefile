CC = gcc
CFLAGS = -g3 -Wall
LDFLAGS = -lm

BDIR = bin
ODIR = build
IDIR = headers
SDIR = src

EXECUTABLE = runner

_DEPS = InvertedPageTable.h SC.h LRU.h Simulator.h queue.h list.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o InvertedPageTable.o SC.o LRU.o Simulator.o queue.o list.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)

$(BDIR)/$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

.PHONY: clean run

run:
	./$(BDIR)/$(EXECUTABLE) -a SC -sc 10 -f 10 -q 10 -m 100


valgrind:
	valgrind --leak-check=full ./$(BDIR)/$(EXECUTABLE) -a LRU -lru 10 -f 10 -q 10 -m 100

clean:
	rm -f $(ODIR)/*.o
	rm -f $(BDIR)/$(EXECUTABLE)
