#include<stdio.h>
#include<stdlib.h>
// 定义结点 
typedef int ElemenType;
typedef struct TreeNode* BinTree;
typedef BinTree Position;
struct TreeNode{
	ElemenType data;
	BinTree left;       //在结点定义里面再定义两个结点 
	BinTree right;      //right&left实质是指向结点的指针 
}; 
//是否为空 
//int isEmpty(BinTree bt){
//	if(bt->data == bt->left == bt->left == NULL) return 1;
//	else{
//		return 0;
//	}
//} 
//遍历，按照某顺序访问每个结点 
//void Traversal(BinTree bt){
//}
//创建一个二叉树 
BinTree CreateBinTree(ElemenType x){
	BinTree bt;
	bt = (BinTree)malloc(sizeof(struct TreeNode));
	bt->data = x;
	bt->left = bt->right = NULL;
	return bt;
}
//递归实现先序遍历
void PreOrderTraversal(BinTree bt){
	if(bt){
		printf("%d ", bt->data);
		PreOrderTraversal(bt->left);
		PreOrderTraversal(bt->right);
	} 
} 
//中序遍历 
void InOrderTraversal(BinTree bt){
	if(bt){
		InOrderTraversal(bt->left);
		printf("%d ", bt->data);
		InOrderTraversal(bt->right);
	}
} 
//后序遍历 
void PostOrderTraversal(BinTree bt){
	if(bt){
		PostOrderTraversal(bt->left);
		PostOrderTraversal(bt->right);
		printf("%d ", bt->data);
	}
} 
//层次遍历 
//void LevelOrderTraversal(BinTree bt){
//} 
BinTree findNode(BinTree bt, ElemenType p){
	if(!bt) return 0;
	if(bt->data == p) return bt;
	BinTree found;
	found = findNode(bt->left, p);
	return found ? found : findNode(bt->right, p);
}
/*在普通二叉树中的插入值，bt指向的结点二叉树根结点，p为要插入的结点的值data
  LorR表示左还是右，0为左，1为右。
  x表示要插入的结点的值data 
*/ 
int insert(BinTree bt, ElemenType p, ElemenType LorR, ElemenType x){
	BinTree found;
	found = findNode(bt, p);
	if(!found) return 0;
	if(LorR == 0){
		found->left = CreateBinTree(x);
	}
	else{
		found->right = CreateBinTree(x);
	}
	return 1;
}
//二叉树情况下进行插入操作,此函数运用的是迭代 
int Binsert_It(BinTree bt, ElemenType x){
	if(!bt){
	    BinTree root = CreateBinTree(x); 
	    return 1;
	}
	else{
		if(x == bt->data) return 0;
		else if(x < bt->data){
			if(bt->left == NULL){
				BinTree NewNode = CreateBinTree(x);
				bt->left = NewNode; 
	    		return 1;	
			}
			else{
			Binsert_It(bt->left, x);
		}
	}
		else{
			if(bt->right == NULL){
				BinTree NewNode = CreateBinTree(x);
				bt->left = NewNode; 
	    		return 1;	
			}
			else{
			Binsert_It(bt->right, x);
			}
		}
		} 
}
//二叉树情况下插入数据，使用递归 
BinTree Binsert_Re(BinTree bt, ElemenType x){
	if(!bt){
        bt = CreateBinTree(x);
//		bt = (BinTree)malloc(sizeof(struct TreeNode));
//		bt->data = x;
//		bt->left = bt->right = 0;
	       }
	else{
//		if(x == bt->data) return 0;
	    if(x < bt->data){
			bt->left = Binsert_Re(bt->left, x);
		                }
		else if(x > bt->data){
			bt->right = Binsert_Re(bt->right, x);
		    }
	    } 
	return bt;
} 
/*  找到此二叉树的最大值 
*/
BinTree FindMax(BinTree bt){
	if(!bt) return NULL;
	else {
		if(!bt->right){
		printf("找到的最大值是%d\n",bt->data); 
		return bt;
	    }
		else 
			bt->right = FindMax(bt->right);
	} 
} 
/*  找到此二叉树的最小值 
*/
BinTree FindMin(BinTree bt){
	if(!bt) return NULL;
	else {
		if(!bt->left){
		printf("找到的最小值是%d\n",bt->data); 
		return bt;
	    }
		else 
			bt->left = FindMin(bt->left);
	} 
} 
/*在二分查找树bt中删除值为x的结点并保持此二叉树为二分查找树(Binary Search Tree) 
*/ 
BinTree BinDelete(BinTree bt, ElemenType x){
	Position Tmp;
	if(!bt) printf("要删除的元素未找到");
	else{
		if(x<bt->data)
			bt->left = BinDelete(bt->left, x);
		else if(x>bt->data)
			bt->right = BinDelete(bt->right, x);
		else{
			if(bt->left && bt->right){
				Tmp = FindMin(bt->right);
			//	printf("找到的最大值是 %d \n", Tmp->data);
				bt->data = Tmp->data;
			
				bt->right = BinDelete(bt->right, bt->data);
			//	printf("%d\n", bt->left->data);
			}
			else{
			//	Tmp = bt;
				if(!bt->left)     //如果只有右孩子或无孩子 
					bt = bt->right;
				else if(bt->left == bt->right == NULL)
				    bt = NULL;	
				else              //如果有左孩子 
					bt = bt->left;
			//	free( Tmp ); 
			}
		}
	}
	return bt;
}
int main(int argc, const char* argv[]){
	BinTree bt = CreateBinTree(18);
/*0为left，1为right，以下为构建树的过程 
*/ 
	insert(bt, 18, 0 ,10);
	insert(bt, 10, 0 ,7);
	insert(bt, 7, 1 ,9);
	insert(bt, 10, 1 ,15);
	insert(bt, 18, 1 ,20);
	insert(bt, 20, 1 ,22);
//	insert(bt, 15, 0 ,12);
	InOrderTraversal(bt);
	printf("\n");
	BinTree BST = Binsert_Re(bt, 12);  //向二叉树中插入12 
	InOrderTraversal(BST);
	printf("\n");
//	BinTree a = FindMin(bt);
	BinDelete(bt, 10);
	InOrderTraversal(bt);
	printf("\n");
//	PreOrderTraversal(bt);
	return 0;
} 
