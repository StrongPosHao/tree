/* tree.c */

#include "tree.h"

Status createBiTree(BiTNode *root){
	char ch;
	ch = getchar();
	if(ch==' ') root=NULL;
	else{
		if(!(root=(BiTNode *)malloc(sizeof(BiTNode))))
			exit(OVERFLOW);
		root->data=ch;
		createBiTree(root->lNode);
		createBiTree(root->rNode);
	}
	return OK;
}

Status visit(char e){
	printf("%c  ",e);
	return OK;
}

Status inOrderTraverse(BiTree *T){
	Stack S;
	BiTNode *p = T->root;
	initStack(&S);
	while(p||!isStackEmpty(&S)){
		if(p){
			push(&S,p);
			p=p->lNode;
		}
		else{
			p=pop(&S);
			if(!visit(p->data))
				return ERROR;
			p=p->rNode;	
		}
	}
	return OK;
} 

