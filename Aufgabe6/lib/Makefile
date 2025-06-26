#
# Makefile
#
# Autor: Tom
# Erstellt am: 30.8.2021
#

CXX = g++ -g #-fno-elide-constructors
CXXFLAGS = -Wall -Wextra -Werror -Weffc++ -Wold-style-cast -std=$(STD) -pedantic
STD = c++11
SRC_Code = ../../Aufgabe5

TARGET = notenspiegel
OBJECTS = \
    benotung.o \
    fachnote.o \
    fachnoten_liste.o \

.PHONY: all clean cppcheck

all: $(TARGET)

clean:
	rm -f $(TARGET) $(TARGET).o $(OBJECTS)

$(TARGET): $(TARGET).o $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $@ $^

benotung.o: $(SRC_Code)/benotung.cpp $(SRC_Code)/benotung.h	
fachnote.o: $(SRC_Code)/fachnote.cpp $(SRC_Code)/fachnote.h $(SRC_Code)/benotung.h	
fachnoten_liste.o: $(SRC_Code)/fachnoten_liste.cpp $(SRC_Code)/fachnoten_liste.h $(SRC_Code)/fachnote.h $(SRC_Code)/benotung.h
notenspiegel.o: $(SRC_Code)/notenspiegel.cpp $(SRC_Code)/fachnoten_liste.h $(SRC_Code)/fachnote.h $(SRC_Code)/benotung.h

