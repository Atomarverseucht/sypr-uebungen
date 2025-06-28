#
# Makefile
#
# Autor: Tom
# Erstellt am: 30.8.2021
#

CXX = g++
CXXFLAGS = -g -fPIC -Wall -Wextra -Werror -Weffc++ -Wold-style-cast -std=$(STD) -pedantic
STD = c++11
SRC_Code = ../../Aufgabe5
LIBTYPE ?= a
LIB = libaufgabe6
LIBNAME = $(LIB).$(LIBTYPE)

TARGET = fachnoten_liste
OBJECTS = \
    benotung.o \
    fachnote.o \
	fachnoten_liste.o

.PHONY: all clean

all: $(OBJECTS) $(LIBNAME)

clean:
	rm -f $(OBJECTS) $(LIB).a $(LIB).so

benotung.o: $(SRC_Code)/benotung.cpp 
	$(CXX) $(CXXFLAGS) -c -o $@ $^ -I$(SRC_Code)
fachnote.o: $(SRC_Code)/fachnote.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $^ -I$(SRC_Code)
fachnoten_liste.o: $(SRC_Code)/fachnoten_liste.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $^ -I$(SRC_Code)
$(LIB).a: $(OBJECTS)
	ar rcs $@ $^
$(LIB).so: $(OBJECTS)
	$(CXX) -shared -o $@ $^

