#ifndef FILE_LOADING_H
#define FILE_LOADING_H

#include "hash_map.h"

void load_from_file(HashMap *map, const char *filename);
void save_to_file(HashMap *map, const char *filename);

#endif


