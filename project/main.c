#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main() {
	BiTree T;
	creatBiTree(T);
	inorderTraverse(T);
	return 0;
}
