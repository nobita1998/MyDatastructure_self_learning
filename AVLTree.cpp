#include<stdio.h>
#include<stdlib.h>
// ������ 
typedef int ElemenType;
typedef struct AVLNode* Position;
typedef Position AVLTree;
struct AVLNode{
	ElemenType data;
	AVLTree left;       //�ڽ�㶨�������ٶ���������� 
	AVLTree right;      //right&leftʵ����ָ�����ָ�� 
	ElemenType height;
}; 

int Max( int a, int b){
	return a>b ? a : b;
}
int GetHeight(AVLTree A){
	if(!A) return 0;  //����������0 
	if(A->left == NULL && A->right == NULL){
		 return 1;
	}
	return Max(GetHeight(A->left), GetHeight(A->right)) + 1;
}
AVLTree SingleLeftRotation( AVLTree A){        /*���鷳��������������ʱ�������� */ 
	AVLTree B = A->left;  /* ��˨����  */
	A->left = B->right;   /* �ٽ���� */ 
	B->right = A;
	A->height = Max( GetHeight(A->left), GetHeight(A->right)) + 1;
	B->height = Max( GetHeight(B->left), A->height) + 1; 
	return B; 
}
AVLTree SingleRightRotation( AVLTree A){        /*���鷳���ҽ����ҽ�����ʱ�������� */ 
	AVLTree B = A->right;
	A->right = B->left;
	B->left = A;
	A->height = Max(GetHeight(A->left), GetHeight(A->right)) + 1;
	B->height = Max(GetHeight(B->left), GetHeight(B->right)) + 1;
	return B; 
} 
AVLTree DoubleLeftRotation( AVLTree A){    /*���鷳��������ҽ�����ʱ�������� */ 
/* ע�⣺A������һ�����ӽ��B����B������һ�����ӽ��C */
/* ��A��B��C�����ε����������µĸ����C */
     
/* ��B��C���ҵ�������ʱA->left = C */
    A->left = SingleRightRotation(A->left);
/* ��A��C������*/
    return SingleLeftRotation(A);
} 
AVLTree DoubleRightRotation( AVLTree A){        /*���鷳���ҽ����������ʱ�������� */ 
	A->right = SingleLeftRotation(A->right);
	return SingleRightRotation(A); 
} 

AVLTree Insert( AVLTree T, ElemenType x ){
	/*���T�ǿ��� */
	if(!T){
//		T = CreateAVLTree(x);
		T = (AVLTree)malloc(sizeof(struct AVLNode));
		T->data = x;
		T->height = 0;
		T->left =T->right = NULL;
	}
	/* x�ȸ������ֵ�󣬾�Ҫ��x���ڸ�������������� */ 
	else if(x<T->data){
		T->left = Insert(T->left , x); 
		/* �������if���Ѿ������ݹ���ִ�е���� */ 
		if(GetHeight(T->left) - GetHeight(T->right) == 2)
			if(x<T->left->data)  /* xС��T�������ֵ��˵����������������*/ 
				T = SingleLeftRotation(T); /*����  */
			else                 /* x����T�������ֵ��˵�������������ҽ��*/ 
				T = DoubleLeftRotation(T); /*����˫��*/ 
	} 
	else if(x>T->data){
		T->right = Insert(T->right , x);
		if(GetHeight(T->left) - GetHeight(T->right) == 2)
			if(x > T->right->data)
				T = SingleRightRotation(T);  /* �ҵ��� */
			if(x < T->right->data)
				T = DoubleRightRotation(T); /* ��-��˫�� */
	} 
	else  x == T->data;
	T->height = Max( GetHeight(T->left), GetHeight(T->right)) + 1;   //�������� 
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
//�ݹ�ʵ���������
void PreOrderTraversal(AVLTree bt){
	if(bt){
		printf("%d ", bt->data);
		PreOrderTraversal(bt->left);
		PreOrderTraversal(bt->right);
	} 
} 
//������� 
void InOrderTraversal(AVLTree bt){
	if(bt){
		InOrderTraversal(bt->left);
		printf("%d ", bt->data);
		InOrderTraversal(bt->right);
	}
} 
//������� 
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
	printf("����������(����ʱ��0��β)��\n"); 
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
