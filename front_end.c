#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_map.h"
#include "file_loading.h"

#define COMMAND_SIZE 16

void prompt_user(HashMap *map, const char *filename);

int main(void){
	HashMap map;
	init_hash_map(&map);
	const char *filename = "customers.tsv";
	load_from_file(&map, filename);
	prompt_user(&map, filename);
	free_hash_map(&map);
	return 0;
}

void prompt_user(HashMap *map, const char *filename){
	char command[COMMAND_SIZE];
	while(1){
		printf("\nEnter a command (add, lookup, delete, list, save, quit): ");
		scanf("%s", command);
		if (strcmp(command, "add") == 0){
			char email[50], name[50], food[50];
			int shoe_size;
			printf("Enter email: ");
			scanf("%s", email);
			printf("Enter name: ");
			scanf("%s", name);
			printf("Enter shoe size: ");
			scanf("%d", &shoe_size);
			printf("Enter favorite food: ");
			scanf("%s", food);
			add_customer(map, email, name, shoe_size, food);
		} else if (strcmp(command, "lookup") == 0){
			char email[50];
			printf("Enter email: ");
			scanf("%s", email);

			Customer *customer = lookup_customer(map, email);
			if (customer){
				printf("Customer found: %s (%d) likes %s\n", customer->name, customer->shoe_size, customer->food);
			} else {
				printf("Customer not found.\n");
			}
		} else if (strcmp(command, "delete") == 0){
			char email[50];
			printf("Enter email: ");
			scanf("%s", email);
			if (delete_customer(map, email)){
				printf("Customer deleted.\n");
			} else {
				printf("Customer not found.\n");
			}
		} else if (strcmp(command, "list") == 0) {
			list_customers(map);
		} else if (strcmp(command, "save") == 0){
			save_to_file(map, filename);
			printf("Database saved to %s.\n", filename);
		} else if (strcmp(command, "quit") == 0) {
			printf("Exiting program.\n");
			break;
		} else {
			printf("Invalid command.\n");
		}
	}
}

