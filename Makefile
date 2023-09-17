CC = gcc
CFLAGS = -Wall -Wextra -g  #compiler flags

SRC_DIR = src
BUILD_DIR = build
EXECUTABLE = my_program

# List of source files
SRCS = $(wildcard $(SRC_DIR)/*.c)

# List of object files (automatically generated from source files)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))

# Main target
all: $(EXECUTABLE)

# Linking the object files to create the executable
$(EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Compiling individual source files into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule to remove compiled files
clean:
	rm $(BUILD_DIR)/*.o
