/* tree.c */

#include "tree.h"
#define printP(x) printf("%p\n",x)
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
	initStack(&S);
	char *p=src;
	int flag=1, flr=0;
	T->root = (BiTNode *)malloc(sizeof(BiTNode));
	push(&S,T->root);
	T->root->data = *p++;
	BiTNode *tp = T->root;
	while(*p){
		if(*p==' '){
			if (flr == 0){
				getTop(&S)->lNode = NULL;
				flr = 1;	
			}
			else{
				pop(&S)->rNode = NULL;
			}
		}
		else{
			if (flr == 0){
				tp = (getTop(&S)->lNode = (BiTNode *)malloc(sizeof(BiTNode)));
			}else{
				tp = (pop(&S)->rNode = (BiTNode *)malloc(sizeof(BiTNode)));
				flr = 0 ;
			}
			tp->data=*p;
			push(&S,tp);

		}
		//printStack(&S);
		p++;
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
