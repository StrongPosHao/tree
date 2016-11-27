#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

#define printP(x) printf("%p\n",x)

typedef enum{
	BINARY_TREE = 0 ,
	NORMAL_TREE = 1 ,
}TreeType;

void visit(BiTNode *e);
void printTitle(); 
void printNotice();
TreeType createTree(char *str,BiTree *T);
TreeType isTree(char *str);

int main(){
	printTitle();
	printNotice();
	int opt;
	BiTree T;
	initBiTree(&T);
	TreeType tt;
	char str[100] = {0};
	printf(" Please create a tree first:\n");
	printf(" T = ");
	gets(str);
	tt = createTree(str,&T);
	printf("_______________________________________________________________________________\n");
	printf(" What the order you want to traverse the tree?\n");
	printf(" 0:DLR.\n");
	printf(" 1:LDR.\n");
	if(tt == BINARY_TREE)
		printf(" 2:LRD.\n");
	while(1){
		printf(" Please enter: ");
		scanf("%d",&opt);
		if(opt<0||opt>2 || (opt == 2 && tt == NORMAL_TREE)){
			printf(" ERROR:Invaid number! Please enter again!\n");
//			printf("_______________________________________________________________________________\n");
			printf("\n");
		}
		else 
			break;
	}
	printf(" ");
	traverse(T.root,visit,opt);
//	char str[100], *p = str;
//	while((*p++=getchar()) != '\n') ;
//	*--p=0;
//	printf("%s",str);
//	initBiTree(&T);
//	createBiTree(&T,str,' ');
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

//	traverse(T.root,visit,0);
//	printf("\n");
//	traverse(T.root,visit,1);
//	printf("\n");
//	traverse(T.root,visit,2);
//	printf("\n");

	return 0;
}
void printTitle(){
	printf("©°©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©´\n");
	printf("©¦                                                                          ©¦\n");
	printf("©¦                    Tree & Huffman Coding Experiment                      ©¦\n");
	printf("©¦                                                                          ©¦\n");
	printf("©¸©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¼\n");
}

void printNotice(){
	printf("---------------------------------- Notice -------------------------------------\n");
	printf(" You can create a binary tree by input string with space character.\n");
	printf(" For example: T = A _ B _ C _ _ (underline here means space character).\n");
	printf(" You will get a tree like below (left figure).\n");
	printf(" Or if you want to create a normal tree by input string with brackets and com-\n mas.\n");
	printf(" For example: T = A(B(E),C,D(F,G,H)).\n");
	printf(" You will get a tree like below (right figure).\n");
	printf("              A                        A                \n");
	printf("             / \\                     / | \\                  \n");
	printf("                B                   B  C  D                 \n");
	printf("               / \\                  |   / | \\               \n");
	printf("                  C                 E  F  G  H             \n");
	printf("                 / \\                                        \n");
	printf("_______________________________________________________________________________\n");
}
TreeType isTree(char *str){
	char *p=str;
	while(*p)
		if(*p++==' ')
			return BINARY_TREE;
	return NORMAL_TREE;
}

TreeType createTree(char *str,BiTree *T){
	TreeType tt = isTree(str);
	if(tt==NORMAL_TREE)
		T->root=createTNodes(str);
	else
		createBiTree(T,str);
	return tt;
}
void visit(BiTNode *e){
	printf("%c  ",e->data);
	return ;
}
