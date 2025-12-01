# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

# Source files
SRC = main.cpp Soul.cpp Afterlife.cpp

# Output program name
TARGET = hell_management

# Default rule: build the program
all: $(TARGET)

# Link object files into final executable
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Remove compiled files
clean:
	rm -f $(TARGET)
