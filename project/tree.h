/* tree.h */

#ifndef H_TREE
#define H_TREE

#include "basic.h"
#include "stack.h"
#include <stdio.h>
Status initBiTree(BiTree *T);
Status createBiTree(BiTree *T,char *src);
Status inOrderTraverseTest(BiTree *T, void (*trvs)(BiTNode *), int tag);
Status traverse(BiTNode *p, void (*trvs)(BiTNode *),int tag);
BiTNode *createTNodes(char *str);

#endif


