#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void visit(BiTNode *e);

int main() {
	BiTree T;
	/*createBiTree(T);
	inOrderTraverse(T);*/
	return 0;
}

void visit(BiTNode *e){
	printf("%c  ",e->data);
	return ;
}
