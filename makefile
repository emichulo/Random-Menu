# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -I.

# Source files
SRCS = example.cpp Menu.cpp SubMenu.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
EXEC = myprogram

# Default target
all: $(EXEC)

# Link object files to create the executable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean target to remove generated files
clean:
	rm -f *.o $(EXEC)
