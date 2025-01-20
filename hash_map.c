#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_map.h"

#define HASH_SIZE 100

void init_hash_map(HashMap *map){
	for (int i = 0; i < HASH_SIZE; i++){
		map->buckets[i] = NULL;
	}
}
unsigned int hash(const char *email){
	unsigned int hash = 0;
	while (*email){
		hash = (hash * 31) + *email++;
	}
	return hash % HASH_SIZE;
}
void add_customer(HashMap *map, const char *email, const char *name, int shoe_size, const char *food){
	unsigned int index = hash(email);
	Customer *existing = lookup_customer(map, email);
	if (existing) {
		strcpy(existing->name, name);
		existing->shoe_size = shoe_size;
		strcpy(existing->food, food);
		return;
	}
	Customer *new_customer = malloc(sizeof(Customer));
	strcpy(new_customer->email, email);
	strcpy(new_customer->name, name);
	new_customer->shoe_size = shoe_size;
	strcpy(new_customer->food, food);
	new_customer->next = map->buckets[index];
	map->buckets[index] = new_customer;
}

Customer *lookup_customer(HashMap *map, const char *email){
	unsigned int index = hash(email);
	Customer *current = map->buckets[index];
	while(current){
		if (strcmp(current->email, email) == 0){
			return current;
		}
		current = current->next;
	}
	return NULL;
}

int delete_customer(HashMap *map, const char *email){
	unsigned int index = hash(email);
	Customer *current = map->buckets[index];
	Customer *prev = NULL;
	while(current){
		if (strcmp(current->email, email) == 0){
			if (prev){
				prev->next = current->next;
			} else {
				map->buckets[index] = current->next;
			}
			free(current);
			return 1;
		}
		prev = current;
		current = current->next;
	}
	return 0;
}

void list_customers(HashMap *map){
	for (int i = 0; i < HASH_SIZE; i++){
		Customer *current = map->buckets[i];
		while (current){
			printf("Email: %s, Name: %s, Shoe Size: %d, Favorite Food: %s\n", current->email, current->name, current->shoe_size, current->food);
			current = current->next;
		}
	}
}

void free_hash_map(HashMap *map){
	for (int i = 0; i < HASH_SIZE; i++){
		Customer *current = map->buckets[i];
		while (current){
			Customer *to_free = current;
			current = current->next;
			free(to_free);
		}
	}
}


