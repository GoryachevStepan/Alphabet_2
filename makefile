OBJ_CATALOG=build/src
OBJ_CATALOG_TEST=build/test

CC=gcc
CFLAGS=-c -Wall -Werror
LDFLAGS=-Wall -Werror
SOURCES=main.cpp text.cpp list_element.cpp
SOURCES_TEST=main-test.c text.cpp list_element.cpp
VPATH=src test

.PHONY: all clean

OBJECTS=$(addprefix $(OBJ_CATALOG)/, $(SOURCES:.c=.o))
OBJECTS_TEST=$(addprefix $(OBJ_CATALOG_TEST)/, $(SOURCES_TEST:.c=.o))
EXECUTABLE=converter

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) $(OBJECTS_TEST)
	$(CC) $(LDFLAGS) $(OBJECTS) -o bin/main
	$(CC) $(LDFLAGS) $(OBJECTS_TEST) -o bin/main_test
	./bin/main_test

$(OBJ_CATALOG)/%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

$(OBJ_CATALOG_TEST)/%.o: %.c
	$(CC) -I thirdparty -I src $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJ_CATALOG)/.o $(OBJ_CATALOG_TEST)/.o bin/*.exe