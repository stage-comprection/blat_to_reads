# Compiler options
CC = g++
OPTCFLAGS= -Ofast -march=native 
CFLAGS= -Wall -Werror -std=c++11 -I $(OPTCFLAGS)
LDFLAGS=

# Directory organisation
BASEDIR = .
SRC = $(BASEDIR)/src
BUILD = $(BASEDIR)/build
BIN = $(BASEDIR)/bin

# Program name
TARGET = blat_to_reads

# Objects names
OBJECTS = $(BUILD)/blat_to_reads.o

# Rules

all: init $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(BIN)/$(TARGET) $^ 

$(BUILD)/%.o: $(SRC)/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -rf $(BUILD)/*.o
	rm -rf $(BIN)/$(TARGET)

init: 
	mkdir -p $(BUILD) $(BIN)

rebuild: clean $(TARGET)
