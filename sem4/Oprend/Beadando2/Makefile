CC = gcc
CFLAGS = -Wall
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c,obj/%.o,$(SRC))

$(shell mkdir -p obj)

nyuszi: $(OBJ)
	$(CC) -o $@ $^

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf obj/ nyuszi
