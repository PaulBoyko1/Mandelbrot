CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17


SRC = main.cpp ComplexPlane.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = complexplane


all: $(EXEC)


$(EXEC): $(OBJ)
$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJ)


%.o: %.cpp ComplexPlane.h
$(CXX) $(CXXFLAGS) -c $<


clean:
rm -f $(OBJ) $(EXEC)


.PHONY: all clean
