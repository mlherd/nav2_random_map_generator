$(info Random Map Generator build starts...)

CC:=g++

CC_OPTS:=-O3

SRCS:=$(wildcard src/*.cpp)

HEADERS:=$(wildcard include/*.h)

OBJECTS:=$(patsubst src/%.cpp,build/%.o,$(SRCS))

build/map_editor: $(OBJECTS)
	$(CC) $^ $(CC_OPTS) -o $@ `pkg-config --cflags --libs opencv`
	$(info Random Map Generator is successfully build!)

build/%.o: src/%.cpp $(HEADERS)
	$(CC) $< $(CC_OPTS) -c -o $@