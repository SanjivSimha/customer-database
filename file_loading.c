#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_map.h"

void load_from_file(HashMap *map, const char *filename){
	FILE *file = fopen(filename, "r");
	if(!file){
		printf("Warning: Could not open file %s. Starting with an empty databse.\n", filename);
		return;
	}
	char line[256];
	while (fgets(line, sizeof(line), file)){
		char email[50], name[50], food[50];
		int shoe_size;
		sscanf(line, "%s\t%s\t%d\t%s", email, name, &shoe_size, food);
		add_customer(map, email, name, shoe_size, food);
	}
	fclose(file);
}

void save_to_file(HashMap *map, const char *filename){
	FILE *file = fopen(filename, "w");
	if (!file){
		printf("Error: Could not open file %s for writing.\n", filename);
		return;
	}
	for (int i = 0; i < HASH_SIZE; i++){
		Customer *current = map->buckets[i];
		while(current){
			fprintf(file, "%s\t%s\t%d\t%s\n",
					current->email, current->name, current->shoe_size, current->food);
			current = current->next;
		}
	}
	fclose(file);
}

