#include "hash_map.h"
#include "file_loading.h"
#include <stdio.h>
#include <string.h>

void test_add_customer(){
	HashMap map;
	init_hash_map(&map);
	
	add_customer(&map, "sonny@ucsc.edu", "Sonny", 12, "Chicken");
	Customer *customer = lookup_customer(&map, "sonny@ucsc.edu");

	if(customer != NULL && strcmp(customer->name, "Sonny") == 0){
		printf("PASS: test_add_customer\n");
	} else {
		printf("FAIL: test_add_customer\n");
	}
	free_hash_map(&map);
	return 0;
}

void test_lookup_customer(){
	HashMap map;
	init_hash_map(&map);

	add_customer(&map, "julian@ucsc.edu", "Julian", 12, "Taco");
	Customer *existing = lookup_customer(&map, "julian@ucsc.edu");
	Customer *non_existing = lookup_customer(&map, "sally@ucsc.edu");
	if (existing != NULL && strcmp(existing->name, "Julian") == 0 && non_existing == NULL){
		printf("PASS: test_lookup_customer\n");
	} else {
		printf("FAIL: test_lookup_customer\n");
	}
	free_hash_map(&map);
	return 0;
}

void test_delete_customer(){
	HashMap map;
	init_hash_map(&map);

	add_customer(&map, "jake@ucsc.edu", "Jake", 8, "Burger");
	int delete_result = delete_customer(&map, "jake@ucsc.edu");
	Customer *after_delete = lookup_customer(&map, "jake@ucsc.edu");
	int non_existing_result = delete_customer(&map, "jay@ucsc.edu");
	if (delete_result == 1 && after_delete == NULL && non_existing_result == 0){
		printf("PASS: test_delete_customer\n");
	} else {
		printf("FAIL: test_delete_customer\n");
	}
	free_hash_map;
}

int main(void){
	printf("Running tests...\n");
	test_add_customer();
	test_lookup_customer();
	test_delete_customer();
	printf("...Finished");
	return 0;
}
