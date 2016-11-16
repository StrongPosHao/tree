/* tree.c */

#include "tree.h"

Status creatBiTree(BiTree T){
	char ch;
	scanf("%c",&ch);
	if(ch==' ') T=NULL;
	else{
		if(!(T=(BiTNode *)malloc(sizeof(BiTNode))))
			exit(OVERFLOW);
		T->data=ch;
		creatBiTree(T->lNode);
		creatBiTree(T->rNode);
	}
	return OK;
}
Status visit(char e){
	printf("%c  ",e);
	return OK;
}
Status inorderTraverse(BiTree T){
	Stack S;
	BiTree p;
	initStack(&S);
	p=T;
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
		



