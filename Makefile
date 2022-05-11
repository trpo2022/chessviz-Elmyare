CFLAGS = -Wall -Werror -I src -MP -MMD


APP_SOURCES = $(shell find src/chessviz -name '*.c')
APP_OBJECTS = $(APP_SOURCES:src/chessviz/%.c=obj/src/chessviz/%.o)

LIB_SOURCES = $(shell find src/libchessviz -name '*.c')
LIB_OBJECTS = $(LIB_SOURCES:src/libchessviz/%.c=obj/src/libchessviz/%.o)
LIB_PATH = obj/src/libchessviz/libchessviz.a

DEPS = $(APP_OBJECTS:.o=.d) $(LIB_OBJECTS:.o=.d)

-include $(DEPS)


.PHONY: all
all: bin/chessvizRun

bin/chessvizRun: $(APP_OBJECTS) $(LIB_PATH)
	gcc $(CFLAGS) $^ -o $@

$(LIB_PATH): $(LIB_OBJECTS)
	ar rcs $@ $^

obj/src/chessviz/%.o: src/chessviz/%.c
	gcc -c $(CFLAGS) $< -o $@

obj/src/libchessviz/%.o: src/libchessviz/%.c
	gcc -c $(CFLAGS) $< -o $@


.PHONY: clean
clean:
	rm $(APP_OBJECTS) $(LIB_PATH) $(LIB_OBJECTS) bin/chessvizRun $(DEPS)