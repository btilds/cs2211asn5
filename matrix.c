//
//  matrix.c
//  2211ASN5
//
//  Created by Ben Tilden on 2018-11-26.
//  Copyright © 2018 Ben Tilden. All rights reserved.
//

#include "matrix.h"
#include "datatype.h"
#include "bstree.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Matrix construction using bstree ini();
Matrix matrix_construction(void){
    Matrix m = bstree_ini();
    return m;
}
// If location (index1, index2) is defined in Matrix m, then return a pointer to the associated
// value. Otherwise, return NULL.
Value *matrix_get(Matrix m, Index index1, Index index2){
    Key key = key_gen(index1, index2);
    Data data = bstree_search(m, key);
    return data;
}
// If location (index1, index2) is defined in Matrix m, then return 1. Otherwise, return 0.
unsigned char matrix_isin(Matrix m, Index index1, Index index2){
    Key key = key_gen(index1, index2);
    Data data = bstree_search(m, key);
    if(data != NULL)
        return '1';
    return '0';
}
// Assign value to Matrix m at location (index1, index2). If that location already has value,
// then overwrite.
void matrix_set(Matrix m, Index index1, Index index2, Value value){
    Key key = key_gen(index1, index2);
    Data data = data_gen(value);
    Data result = bstree_search(m, key);
    if(result != NULL){
        matrix_inc(m, index1, index2, 1);
    }
    else{
        bstree_insert(m, key, data);
    }
}
// If location (index1, index2) is defined in Matrix m, then increase the associated value by
// value. Otherwise, report error.
void matrix_inc(Matrix m, Index index1, Index index2, Value value){
    Key key = key_gen(index1, index2);
    Data temp = bstree_search(m, key);
    if(temp != NULL){
        (*temp) = (*temp) + value;
    }
    else{
        printf("Error.");
    }
}
// Print indices and values in the Matrix m (with bstree traversal()).
void matrix_list(Matrix m){
    bstree_traversal(m);
}
// Free allocated space (with bstree free()).
void matrix_destruction(Matrix m){
    bstree_free(m);
}
