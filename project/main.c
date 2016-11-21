#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

#define printP(x) printf("%p\n",x)

void visit(BiTNode *e);

int main(){
	BiTree T;
	char str[100], *p = str;
	while((*p++=getchar()) != '\n') ;
	*--p=0;
//	printf("%s",str);
	initBiTree(&T);
	createBiTree(&T,str);
/*	debug:	*/
//	T.root=(BiTNode *)malloc(sizeof(BiTNode));
//	T.root->lNode=(BiTNode *)malloc(sizeof(BiTNode));
//	T.root->data='a';
//	T.root->lNode->data='b';
//	T.root->rNode=NULL;
//	T.root->lNode->lNode=NULL;
//	T.root->lNode->rNode=NULL;
/*
	printP(T.root);
	printP(T.root->lNode);
	printP(T.root->rNode);
	printP(T.root->lNode->lNode);
	printP(T.root->lNode->rNode);
	printP(T.root->rNode->lNode);
	printP(T.root->rNode->rNode);
	printP(T.root->lNode->lNode->lNode);
	printP(T.root->lNode->lNode->rNode);
	printP(T.root->lNode->rNode->lNode);
	printP(T.root->lNode->rNode->rNode);
*/

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
