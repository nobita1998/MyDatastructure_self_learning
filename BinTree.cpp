#include<stdio.h>
#include<stdlib.h>
typedef int Elem;
struct BinNode{
	Elem data;
	struct BinNode* left;
	struct BinNode* right;	
};
typedef struct BinNode* BinTree;

BinTree initBinTree(Elem x){
	BinTree r;
	r = (BinTree)malloc(sizeof(struct BinNode));
	r->data = x;
	r->left = r->right = NULL;
	return r;
}
void preprint(BinTree r){
	if(r == NULL) return;
	else{
		printf("%d ", r->data);
		preprint(r->left);
		preprint(r->right);
	}
}
BinTree findX(BinTree r, Elem x){
	if(!r) return NULL;
	if(r->data == x) return r;
	BinTree found;
	found = findX(r->left,x);
	return found ? found: findX(r->right, x);
}

void printTree(BinTree r, int depth){
	for(int i=0; i<depth;i++) printf("  ");
	if(!r){
		printf("[/]\n");
	}
	else{
		printf("%d\n", r->data);
		printTree(r->left, depth+1);
		printTree(r->right, depth+1);
	}
}

int insert(BinTree bt, Elem p, int LorR, Elem x){
	BinTree found;
	found = findX(bt, p);
	if(!found) return 0;
	if(LorR == 0){
		if(found->left) return 0;
		found->left = initBinTree(x);
	}
	else{
		if(found->right) return 0;
		found->right = initBinTree(x);
	}
	return 1;
}

int main(int argc, const char *argv[]){
	BinTree bt = initBinTree(11);
	insert(bt, 11 , 0, 22);
	insert(bt, 11 , 1, 33);
	insert(bt, 22 , 0, 44);
	insert(bt, 33 , 0, 55);
	
	printTree(bt, 0);
	preprint(bt);
	return 0;
} 
