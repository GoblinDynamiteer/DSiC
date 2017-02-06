TARGET = dsic
LIBS =
CC = gcc
CFLAGS = 
SUBDIR = ch01/exercise01_01
SRC = $(wildcard *.c) $(wildcard $(SUBDIR)/*.c)

all: clean compile run

compile:
	$(CC) $(SRC) -o $(TARGET) $(LIBS) $(CFLAGS)

clean:
	-rm -f *.o
	-rm -f $(TARGET).*

run:
	.\$(TARGET)
