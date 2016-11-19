#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void visit(BiTNode *e);

int main(){
	BiTree T;
	char p[100];
	gets(p);
	initBiTree(&T);
	createBiTree(&T,p);
/*	debug:	*/
//	T.root=(BiTNode *)malloc(sizeof(BiTNode));
//	T.root->lNode=(BiTNode *)malloc(sizeof(BiTNode));
//	T.root->data='a';
//	T.root->lNode->data='b';
//	T.root->rNode=NULL;
//	T.root->lNode->lNode=NULL;
//	T.root->lNode->rNode=NULL;

	traverse(T.root,visit,0);
	printf("\n");
	traverse(T.root,visit,1);
	printf("\n");
	traverse(T.root,visit,2);
	printf("\n");
	return 0;
}

void visit(BiTNode *e){
	printf("%c  ",e->data);
	return ;
}
