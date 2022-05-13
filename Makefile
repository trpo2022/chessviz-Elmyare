CFLAGS = -Wall -Wextra -Werror
CPPFLAGS =  -I src -MP -MMD
TESTFLAGS = -I thirdparty

APP_SOURCES = $(shell find src/chessviz -name '*.c')
APP_OBJECTS = $(APP_SOURCES:src/chessviz/%.c=obj/src/chessviz/%.o)

LIB_SOURCES = $(shell find src/libchessviz -name '*.c')
LIB_OBJECTS = $(LIB_SOURCES:src/libchessviz/%.c=obj/src/libchessviz/%.o)
LIB_PATH = obj/src/libchessviz/libchessviz.a
TEST_SOURCES = $(shell find test -name '*.c')
TEST_OBJECTS = $(TEST_SOURCES:test/%.c=obj/test/%.o)

DEPS = $(APP_OBJECTS:.o=.d) $(LIB_OBJECTS:.o=.d) $(TEST_OBJECTS:.o=.d)

-include $(DEPS)


.PHONY: all
all: bin/chessvizRun

bin/chessvizRun: $(APP_OBJECTS) $(LIB_PATH)
	gcc $(CFLAGS) $(CPPFLAGS) $^ -o $@

$(LIB_PATH): $(LIB_OBJECTS)
	ar rcs $@ $^

obj/src/chessviz/%.o: src/chessviz/%.c
	gcc -c $(CFLAGS) $(CPPFLAGS) $< -o $@

obj/src/libchessviz/%.o: src/libchessviz/%.c
	gcc -c $(CFLAGS) $(CPPFLAGS) $< -o $@

.PHONY: test
test: bin/test

bin/test: $(TEST_OBJECTS) $(LIB_PATH)
	gcc $(CFLAGS) $(TESTFLAGS) $(CPPFLAGS) $^ -o $@

obj/%.o: %.c
	gcc -c $(CFLAGS) $(TESTFLAGS) $(CPPFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -rf $(APP_OBJECTS) $(LIB_PATH) $(LIB_OBJECTS) bin/chessvizRun bin/test $(DEPS)