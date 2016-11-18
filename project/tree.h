/* tree.h */

#ifndef H_TREE
#define H_TREE

#include "basic.h"
#include "stack.h"
#include <stdio.h>
Status initBiTree(BiTree T);
Status createBiTree(BiTNode *root);
Status inOrderTraverse(BiTree *T, void (*trvs)(BiTNode *));

#endif


