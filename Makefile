CC = clang
CFLAGS = -Wall -Wpedantic -Werror -Wextra

all: businessdb

businessdb: front_end.o hash_map.o file_loading.o
	$(CC) front_end.o hash_map.o file_loading.o -o businessdb

front_end.o: front_end.c
	$(CC) $(CFLAGS) -c front_end.c

hash_map.0: hash_map.c hash_map.h
	$(CC) $(CFLAGS) -c hash_table.c

file_loading.o: file_loading.c file_loading.h
	$(CC) $(CFLAGS) -c file_loading.c

clean:
	rm -f businessdb front_end.o hash_map.o file_loading.o

format:
	clang-format -i -style=file *.[ch]

