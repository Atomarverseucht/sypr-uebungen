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
LIB = aufgabe6
LIBNAME = $(LIBDIR)/lib$(LIB)
LIBDIR = ../lib
LIBTYPE ?= a
SRC_Code = ../../Aufgabe5

TARGET = notenspiegel

.PHONY: all clean

all: $(TARGET)

clean:
	rm -f $(TARGET) $(TARGET).o

$(TARGET): $(TARGET).o $(LIBNAME).$(LIBTYPE)
	$(CXX) $(LDFLAGS) -o $@ $< -l$(LIB) -L$(LIBDIR)

notenspiegel.o: $(SRC_Code)/notenspiegel.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $^ -I$(SRC_Code)

$(LIBNAME).$(LIBTYPE): $(LIBDIR)/*.o
	$(MAKE) -C $(LIBDIR) LIBTYPE=$(LIBTYPE)