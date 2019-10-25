//
//  matrix.h
//  2211ASN5
//
//  Created by Ben Tilden on 2018-11-26.
//  Copyright © 2018 Ben Tilden. All rights reserved.
//

#ifndef matrix_h
#define matrix_h
#include "datatype.h"
#include "bstree.h"
#include <stdio.h>
// Type definitions
typedef BStree Matrix;
typedef char* Index;
typedef int Value;
// Function prototypes
Matrix matrix_construction(void);
// Matrix construction using bstree ini();
Value *matrix_get(Matrix m, Index index1, Index index2);
// If location (index1, index2) is defined in Matrix m, then return a pointer to the associated
// value. Otherwise, return NULL.
unsigned char matrix_isin(Matrix m, Index index1, Index index2);
// If location (index1, index2) is defined in Matrix m, then return 1. Otherwise, return 0.
void matrix_set(Matrix m, Index index1, Index index2, Value value);
// Assign value to Matrix m at location (index1, index2). If that location already has value,
// then overwrite.
void matrix_inc(Matrix m, Index index1, Index index2, Value value);
// If location (index1, index2) is defined in Matrix m, then increase the associated value by
// value. Otherwise, report error.
void matrix_list(Matrix m);
// Print indices and values in the Matrix m (with bstree traversal()).
void matrix_destruction(Matrix m);
// Free allocated space (with bstree free()).
#endif /* matrix_h */
