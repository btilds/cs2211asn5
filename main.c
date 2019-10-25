//
//  main.c
//  2211ASN5
//
//  Created by Ben Tilden on 2018-11-25.
//  Copyright © 2018 Ben Tilden. All rights reserved.
//
#include "matrix.h"

int main(void) {
    Matrix m;
    m = matrix_construction();
    char key1[256];
    char key2[256];
    printf("Enter in some string doubles. Press ctr + d to stop:\n");
    while((scanf(" %s %s", key1, key2)) == 2){
        matrix_set(m, key1, key2, 1);
    }
    matrix_list(m);
    matrix_destruction(m);
    return 0;
}
