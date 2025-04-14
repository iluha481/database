CC = gcc
CFLAGS = -Wall -g -I src -I src/lib -I src/models
TARGET = program

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

SOURCES = $(SRC_DIR)/main.c $(SRC_DIR)/lib/Print.c $(SRC_DIR)/lib/Storage.c $(SRC_DIR)/lib/StorageSaver.c

OBJECTS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SOURCES))

TARGET_PATH = $(BIN_DIR)/$(TARGET)

all: $(TARGET_PATH)

$(TARGET_PATH): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJECTS) -o $(TARGET_PATH)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)