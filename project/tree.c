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

BiTNode *createTNodes(char *str){
	//printf("[EnterFunction]\n%s\n",str);
	BiTNode *tp = NULL, *head = NULL; 
	int firstmalloc = 1;
	while(1){
		if (*str == '('){
			int bracket = 1;
			BiTNode *ttp = createTNodes(str+1);
			//printf("\n\n[ReturnFunction]\n");
			str++;
			while(bracket != 0){
				if(*str=='(') bracket++;
				else if(*str==')') bracket--;
				str++;
			}
			str--;
			tp->lNode = ttp;
		}
		else if (*str >= 'A' && *str <= 'Z'){
			if (firstmalloc){
				tp = (BiTNode *)malloc(sizeof(BiTNode));
				firstmalloc = 0;
				head = tp;
			}else
			{
				tp->rNode = (BiTNode *)malloc(sizeof(BiTNode));
				tp = tp->rNode;
			}
			tp->data = *str;
			tp->lNode = tp->rNode = NULL;
		}
		else if (*str == ','){
			//tp = tp->rNode;
		}
		else if (*str == ')'||*str == 0)
			return head;
		str++;
	} 
	// if str == 字母
		// malloc,存字母
	// if str == 左括号
		// 调用函数(str+1)
		// 往右搜寻第一个右括号，跳过，继续 
		// 把返回的地址连接到前一次的字母
	// if str == 逗号
		// malloc 读取下一个字母,存值
	// if str == 右括号或 0 
		// return  
}
