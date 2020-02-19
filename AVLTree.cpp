#include<stdio.h>
#include<stdlib.h>
// 定义结点 
typedef int ElemenType;
typedef struct AVLNode* Position;
typedef Position AVLTree;
struct AVLNode{
	ElemenType data;
	AVLTree left;       //在结点定义里面再定义两个结点 
	AVLTree right;      //right&left实质是指向结点的指针 
	ElemenType height;
}; 

int Max( int a, int b){
	return a>b ? a : b;
}
int GetHeight(AVLTree A){
	if(!A) return 0;  //空树，返回0 
	if(A->left == NULL && A->right == NULL){
		 return 1;
	}
	return Max(GetHeight(A->left), GetHeight(A->right)) + 1;
}
AVLTree SingleLeftRotation( AVLTree A){        /*在麻烦点左结点的左结点插入时出现问题 */ 
	AVLTree B = A->left;  /* 先栓新绳  */
	A->left = B->right;   /* 再解旧绳 */ 
	B->right = A;
	A->height = Max( GetHeight(A->left), GetHeight(A->right)) + 1;
	B->height = Max( GetHeight(B->left), A->height) + 1; 
	return B; 
}
AVLTree SingleRightRotation( AVLTree A){        /*在麻烦点右结点的右结点插入时出现问题 */ 
	AVLTree B = A->right;
	A->right = B->left;
	B->left = A;
	A->height = Max(GetHeight(A->left), GetHeight(A->right)) + 1;
	B->height = Max(GetHeight(B->left), GetHeight(B->right)) + 1;
	return B; 
} 
AVLTree DoubleLeftRotation( AVLTree A){    /*在麻烦点左结点的右结点插入时出现问题 */ 
/* 注意：A必须有一个左子结点B，且B必须有一个右子结点C */
/* 将A、B与C做两次单旋，返回新的根结点C */
     
/* 将B与C做右单旋，此时A->left = C */
    A->left = SingleRightRotation(A->left);
/* 将A与C做左单旋*/
    return SingleLeftRotation(A);
} 
AVLTree DoubleRightRotation( AVLTree A){        /*在麻烦点右结点的左结点插入时出现问题 */ 
	A->right = SingleLeftRotation(A->right);
	return SingleRightRotation(A); 
} 

AVLTree Insert( AVLTree T, ElemenType x ){
	/*如果T是空树 */
	if(!T){
//		T = CreateAVLTree(x);
		T = (AVLTree)malloc(sizeof(struct AVLNode));
		T->data = x;
		T->height = 0;
		T->left =T->right = NULL;
	}
	/* x比根部结点值大，就要把x放在根部结点左子树下 */ 
	else if(x<T->data){
		T->left = Insert(T->left , x); 
		/* 下面这个if是已经跳出递归后才执行的语句 */ 
		if(GetHeight(T->left) - GetHeight(T->right) == 2)
			if(x<T->left->data)  /* x小于T的左结点的值，说明会插在左结点的左结点*/ 
				T = SingleLeftRotation(T); /*左单旋  */
			else                 /* x大于T的左结点的值，说明会插在左结点的右结点*/ 
				T = DoubleLeftRotation(T); /*左右双旋*/ 
	} 
	else if(x>T->data){
		T->right = Insert(T->right , x);
		if(GetHeight(T->left) - GetHeight(T->right) == 2)
			if(x > T->right->data)
				T = SingleRightRotation(T);  /* 右单旋 */
			if(x < T->right->data)
				T = DoubleRightRotation(T); /* 右-左双旋 */
	} 
	else  x == T->data;
	T->height = Max( GetHeight(T->left), GetHeight(T->right)) + 1;   //更新树高 
	return T;    
}

AVLTree MakeEmpty( AVLTree A){
    if(!A){
    	MakeEmpty(A->left);
    	MakeEmpty(A->right);
    	free(A);
	}
	return NULL;
}
//递归实现先序遍历
void PreOrderTraversal(AVLTree bt){
	if(bt){
		printf("%d ", bt->data);
		PreOrderTraversal(bt->left);
		PreOrderTraversal(bt->right);
	} 
} 
//中序遍历 
void InOrderTraversal(AVLTree bt){
	if(bt){
		InOrderTraversal(bt->left);
		printf("%d ", bt->data);
		InOrderTraversal(bt->right);
	}
} 
//后序遍历 
void PostOrderTraversal(AVLTree bt){
	if(bt){
		PostOrderTraversal(bt->left);
		PostOrderTraversal(bt->right);
		printf("%d ", bt->data);
	}
} 

int main(int argc, const char* argv[]){
	AVLTree T = NULL;
//	T = MakeEmpty(T);
	printf("123");
	printf("请输入数字(结束时以0结尾)：\n"); 
	while(1)
    {
        int Element;
        
        scanf("%d",&Element);
        if(Element == 0)  
            break;
        else
            T = Insert( T, Element);
    }
    printf("PreOrderTraversal: ");
    PreOrderTraversal(T);
    printf("\n");
    printf("InOrderTraversal: ");
    InOrderTraversal(T);
    printf("\n");
    printf("PostOrderTraversal: ");
    PostOrderTraversal(T);
    printf("\n");
	return 0;
} 
