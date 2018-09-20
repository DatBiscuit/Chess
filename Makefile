# what compiler we are using
CXX = g++

# the source files
SOURCE = $(wildcard source/*.cpp)

# where the objects are
OBJ := $(patsubst source/%.cpp,objects/%.o,$(wildcard source/*.cpp))

# paths
INCLUDE_PATHS = -Iheaders


#OBJ_NAME specifies the name of our exectuable
TARGET = build/Chess

#This is the target that compiles our executable
all: $(TARGET)

# rule for making the actual target
$(TARGET): $(OBJ)
	@echo "---- Linking target $@"
	@$(CXX) $(INCLUDE_PATHS) -o $@ $^

## Generic compilation rule saves to the build folder
objects/%.o: source/%.cpp
	@echo "---- Compiling $<"
	@$(CXX) -c $< -o $@ $(INCLUDE_PATHS)
