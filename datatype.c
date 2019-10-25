//
//  datatype.c
//  2211ASN5
//
//  Created by Ben Tilden on 2018-11-25.
//  Copyright © 2018 Ben Tilden. All rights reserved.
//

#include "datatype.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// Duplicate string pointed to by str with dynamic memory allocation.
char *string_dup(char *str){
    char *string = (char*) malloc (strlen(str) + 1);
    if(string == NULL) return NULL;
    strcpy(string, str);
    return string;
}
// Generate a key with dynamic memory allocation.
Key key_gen(char *skey1, char *skey2){
    Key key;
    key = (Key) malloc(sizeof(Key));
    key->skey1 = string_dup(skey1);
    key->skey2 = string_dup(skey2);
    return key;
}
// Use strcmp( ) to do comparison. If key1->skey1 and key2->skey1 are different, then
// they determine the comparison result. If key1->skey1 and key2->skey1 are the same,
// then key1->skey2 and key2->skey2 determine the comparison result.
int key_comp(Key key1, Key key2){
    int comparison = strcmp(key1->skey1, key2->skey1);
    if(comparison == 0)
        comparison = strcmp(key1->skey2, key2->skey2);
    return comparison;
}
// Print a key.
void key_print(Key key){
    printf("%-10s   %-10s", key->skey1, key->skey2);
}
// Free memory allocated for key.
void key_free(Key key){
    free(key->skey1);
    free(key->skey2);
    free(key);
}
// Generate a data with dynamic memory allocation.
Data data_gen(int idata){
    Data data;
    data = (Data) malloc(sizeof(Data));
    *data = idata;
    return data;
}
// Assign data with idata.
void data_set(Data data, int idata){
    (*data) = idata;
}
// Print a data.
void data_print(Data data){
    printf("  %d\n", *data);
}
// Free memory allocated for data.
void data_free(Data data){
    free(data);
}
