/* tree.c */

#include "tree.h"

Status initBiTree(BiTree *T){
	T->root=NULL;
	return OK;
}

Status createBiTree(BiTree *T,char *src){
	/*char ch,enter;
	ch = getchar();
	enter=getchar();
	if(ch==' ') root=NULL;
	else{
		if(!(root=(BiTNode *)malloc(sizeof(BiTNode))))
			exit(OVERFLOW);
		root->data=ch;
		createBiTree(root->lNode);
		createBiTree(root->rNode);
	}*/
	Stack S;
	char *p=src;
	BiTNode *tp=T->root;
//	while(s)
	T->root=(BiTNode *)malloc(sizeof(BiTNode));
	initStack(&S);
	if(*p=' ')
		tp=NULL;
	else{
		while(*p){
			if(tp){
				push(&S,tp);
				tp=tp->lNode;
				tp=(BiTNode *)malloc(sizeof(BiTNode));
			}
			else{
				tp=pop(&S);
				tp=(BiTNode *)malloc(sizeof(BiTNode));
				tp=tp->rNode;
				tp=(BiTNode *)malloc(sizeof(BiTNode));
				}
			}
		}
	return OK;
}

Status inOrderTraverseTest(BiTree *T, void (*trvs)(BiTNode *), int tag){
	Stack S;
	int count=0;
	BiTNode *p = T->root;
	initStack(&S);
	while(p||!isStackEmpty(&S)){
		switch(tag){
			case 0:
				if(p){
					push(&S,p);
					trvs(p);
					p=p->lNode;
				}
				else{
					p=pop(&S);
					p=p->rNode;	
				}
				break;
			case 1:
				if(p){
					push(&S,p);
					p=p->lNode;
				}
				else{
					p=pop(&S);
					trvs(p);
					p=p->rNode;	
				}
				break;
			case 2:

				break;
			default:break;
		}
	}
	return OK;
} 

Status traverse(BiTNode *p, void (*trvs)(BiTNode *),int tag){
	if(p){
		switch(tag){
			case 0:
				trvs(p);
				traverse(p->lNode, trvs, 0);
				traverse(p->rNode, trvs, 0);
				break;
			case 1:
				traverse(p->lNode, trvs, 1);
				trvs(p);
				traverse(p->rNode, trvs, 1);
				break;
			case 2:
				traverse(p->lNode, trvs, 2);
				traverse(p->rNode, trvs, 2);
				trvs(p);
				break;
			
		}
	}
}
