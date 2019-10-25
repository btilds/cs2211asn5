//
//  bstree.c
//  2211ASN5
//
//  Created by Ben Tilden on 2018-11-25.
//  Copyright © 2018 Ben Tilden. All rights reserved.
//

#include "datatype.h"
#include "bstree.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Allocate memory of type BStree node*, set the value to NULL, and return a pointer to the
// allocated memory.
BStree bstree_ini(void){
    BStree tree;
    tree = (BStree) malloc(sizeof(BStree_node *));
    (*tree) = NULL;
    return tree;
}
// Insert data with key into bst. If key is in bst, then do nothing.
// You may want to use a helper function for insertion to create a pointer to a tree node from
// key and data.
BStree_node *new_node(Key key, Data data){
    BStree_node *node;
    node = (BStree_node *) malloc(sizeof(BStree_node));
    node->key = key;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
void bstree_insert(BStree bst, Key key, Data data){
    if(*bst == NULL)
        *bst = new_node(key, data);
    else{
        int cmp = key_comp(key, (*bst)->key);
        if(cmp < 0)
            bstree_insert(&(*bst)->left, key, data);
        else if(cmp > 0)
            bstree_insert(&(*bst)->right, key, data);
        else
            return;
    }
}
// If key is in bst, return key’s associated data. If key is not in bst, return NULL.
Data bstree_search_helper(BStree_node *node, Key key){
    if(node == NULL)
        return NULL;
    else{
        int cmp = key_comp(key, node->key);
        if(cmp < 0)
            return bstree_search(&node->left, key);
        else if(cmp > 0)
            return bstree_search(&node->right, key);
        else if(cmp == 0)
            return node->data;
        else
            return NULL;
    }
}
Data bstree_search(BStree bst, Key key){
    return bstree_search_helper(*bst, key);
}
// In order traversal of bst and print each node’s key and data.
void bstree_traversal_helper(BStree_node *node){
    if(node == NULL){
        return;
    }
    bstree_traversal_helper(node->left);
    key_print(node->key);
    data_print(node->data);
    bstree_traversal_helper(node->right);
}
void bstree_traversal(BStree bst){
    printf("String 1     String 2    Occurance\n");
    bstree_traversal_helper(*bst);
}
// Free all the dynamically allocated memory of bst.
void bstree_free_helper(BStree_node *node){
    if(node == NULL) return;
    bstree_free_helper(node->left);
    bstree_free_helper(node->right);
    key_free(node->key);
    data_free((*node).data);
}
void bstree_free(BStree bst){
    bstree_free_helper(*bst);
    free(bst);
}
