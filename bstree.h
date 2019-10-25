//
//  bstree.h
//  2211ASN5
//
//  Created by Ben Tilden on 2018-11-25.
//  Copyright © 2018 Ben Tilden. All rights reserved.
//

#ifndef bstree_h
#define bstree_h

#include <stdio.h>
// Type definitions
typedef struct BStree_node {
    Key key;
    Data data;
    struct BStree_node *left, *right;
} BStree_node;
typedef BStree_node** BStree;
// Function prototypes
BStree bstree_ini(void);
// Allocate memory of type BStree node*, set the value to NULL, and return a pointer to the
// allocated memory.
void bstree_insert(BStree bst, Key key, Data data);
// Insert data with key into bst. If key is in bst, then do nothing.
// You may want to use a helper function for insertion to create a pointer to a tree node from
// key and data.
// BStree_node *new_node(Key key, Data data);
Data bstree_search(BStree bst, Key key);
// If key is in bst, return key’s associated data. If key is not in bst, return NULL.
void bstree_traversal(BStree bst);
// In order traversal of bst and print each node’s key and data.
void bstree_free(BStree bst);
// Free all the dynamically allocated memory of bst.
#endif /* bstree_h */
