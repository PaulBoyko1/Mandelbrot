# Compiler
CXX = g++

# Executable name
TARGET = mandelbrot

# Source files
SRC = main.cpp ComplexPlane.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# SFML settings — adjust if needed
SFML_INCLUDE = -I"C:/SFML/include"
SFML_LIB = -L"C:/SFML/lib"
SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# Compiler flags
CXXFLAGS = -std=c++17 $(SFML_INCLUDE)
LDFLAGS = $(SFML_LIB) $(SFML_FLAGS)

# Default rule
all: $(TARGET)

# Build executable
$(TARGET): $(OBJ)
	$(CXX) -o $(TARGET) $(OBJ) $(LDFLAGS)

# Compile .cpp → .o
%.o: %.cpp ComplexPlane.h
	$(CXX) $(CXXFLAGS) -c $<

# Clean object files + executable
clean:
	del /Q $(OBJ) $(TARGET).exe 2>nul || true

.PHONY: all clean
