#
# Makefile
#
# Autor: Tom
# Erstellt am: 30.8.2021
#

CXX = g++ -g #-fno-elide-constructors
CXXFLAGS = -Wall -Wextra -Werror -Weffc++ -Wold-style-cast -std=$(STD) -pedantic
CPPCHECK = cppcheck --enable=warning,style --std=$(STD)
STD = c++11
SRC_Code = ../../Aufgabe5
SRC_O = ../lib

TARGET = notenspiegel
OBJECTS = \
    $(SRC_O)/benotung.o \
    $(SRC_O)/fachnote.o \
    $(SRC_O)/fachnoten_liste.o

.PHONY: all clean cppcheck

all: $(TARGET)

clean:
	rm -f $(TARGET) $(TARGET).o $(OBJECTS)

$(TARGET): $(TARGET).o $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $@ $^

cppcheck: $(SRC_Code)/$(TARGET).cpp $(OBJECTS:.o=.cpp)
	$(CPPCHECK) $^ 

notenspiegel.o: $(SRC_Code)/notenspiegel.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $^ -I$(SRC_Code)

g++ -g -Wall -Wextra -Werror -Weffc++ -Wold-style-cast -std=c++11 -pedantic ../../Aufgabe5/