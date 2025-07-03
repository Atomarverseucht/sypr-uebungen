#
# Makefile
#
# Autor: Tom
# Erstellt am: 30.8.2021
#

CXX = g++
CXXFLAGS = -fPIC -Wall -Wextra -Werror -Weffc++ -Wold-style-cast -std=$(STD) -pedantic
STD = c++11
SRC_Code = ../../Aufgabe5
LIBTYPE ?= a
LIB = libaufgabe6
LIBNAME = $(LIB).$(LIBTYPE)

TARGET = fachnoten_liste
LISTE = \
    benotung \
    fachnote \
	fachnoten_liste
OBJECTS = $(addsuffix .o, $(LISTE))
SOURCES = $(addprefix $(SRC_Code)/, $(addsuffix .cpp, $(LISTE)))
HEADERS = $(SOURCES:.cpp=.h)

.PHONY: all clean

all: $(LIBNAME)

clean:
	rm -f $(OBJECTS) $(LIB).a $(LIB).so depend

$(OBJECTS): $(SRC_Code)/$(@:.o=.cpp) $(SRC_Code)/$(@:.o=.h)
	$(CXX) -c $(CXXFLAGS) -c -o $@ $(SRC_Code)/$(@:.o=.cpp) -I$(SRC_Code)

$(LIB).a: $(OBJECTS)
	ar rs $@ $^
$(LIB).so: $(OBJECTS)
	$(CXX) -shared $^ -o $@ 

depend: $(SOURCES) $(HEADERS)
	$(CXX) -MM $(CXXFLAGS) $(SOURCES) -I$(SRC_Code) > $@

include depend