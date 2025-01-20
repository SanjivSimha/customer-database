#ifndef HASH_MAP_H
#define HASH_MAP_H

typedef struct Customer{
	char email[50];
	char name[50];
	int shoe_size;
	char food[50];
	struct Customer *next;
} Customer;

#define HASH_SIZE 100

typedef struct HashMap {
	Customer *buckets[HASH_SIZE];
} HashMap;

void init_hash_map(HashMap *map);
void add_customer(HashMap *map, const char *email, const char *name, int shoe_size, const char *food);
Customer *lookup_customer(HashMap *map, const char *email);
int delete_customer(HashMap *map, const char *email);
void list_customers(HashMap *map);
void free_hash_map(HashMap *map);

#endif
