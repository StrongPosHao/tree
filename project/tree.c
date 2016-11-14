#include "tree.h"
#include <stdio.h>
/* tree.c */

#include <stdlib.h>
Status createBiTree(BiTree *T){
	char ch;
	scanf("%c",&ch);
	if(ch==' ') 
		T=NULL;
	else{
		if(!(T=(BiTNode *)malloc(sizeof(BiTNode))))
			exit(OVERFLOW);
	T->data=ch;
	createBiTree(T->lchild);
	createBiTree(T->rchild);
	}
	return OK;
}
Status traverseBiTree(BiTree *T, void (*traverse)(BiTNode *), int order){
	switch(order){
		case 0:
			printf("%c",T->data);
			// traverseBiTree(T,traverse, 0);
			break;
		case 1:
			
			break;
		case 2:
			
			break;
		default: 
			exit(ERROR);
	}
}
