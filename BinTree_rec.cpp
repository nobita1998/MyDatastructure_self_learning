#include<stdio.h>
#include<stdlib.h>
// ������ 
typedef int ElemenType;
typedef struct TreeNode* BinTree;
typedef BinTree Position;
struct TreeNode{
	ElemenType data;
	BinTree left;       //�ڽ�㶨�������ٶ���������� 
	BinTree right;      //right&leftʵ����ָ�����ָ�� 
}; 
//�Ƿ�Ϊ�� 
//int isEmpty(BinTree bt){
//	if(bt->data == bt->left == bt->left == NULL) return 1;
//	else{
//		return 0;
//	}
//} 
//����������ĳ˳�����ÿ����� 
//void Traversal(BinTree bt){
//}
//����һ�������� 
BinTree CreateBinTree(ElemenType x){
	BinTree bt;
	bt = (BinTree)malloc(sizeof(struct TreeNode));
	bt->data = x;
	bt->left = bt->right = NULL;
	return bt;
}
//�ݹ�ʵ���������
void PreOrderTraversal(BinTree bt){
	if(bt){
		printf("%d ", bt->data);
		PreOrderTraversal(bt->left);
		PreOrderTraversal(bt->right);
	} 
} 
//������� 
void InOrderTraversal(BinTree bt){
	if(bt){
		InOrderTraversal(bt->left);
		printf("%d ", bt->data);
		InOrderTraversal(bt->right);
	}
} 
//������� 
void PostOrderTraversal(BinTree bt){
	if(bt){
		PostOrderTraversal(bt->left);
		PostOrderTraversal(bt->right);
		printf("%d ", bt->data);
	}
} 
//��α��� 
//void LevelOrderTraversal(BinTree bt){
//} 
BinTree findNode(BinTree bt, ElemenType p){
	if(!bt) return 0;
	if(bt->data == p) return bt;
	BinTree found;
	found = findNode(bt->left, p);
	return found ? found : findNode(bt->right, p);
}
/*����ͨ�������еĲ���ֵ��btָ��Ľ�����������㣬pΪҪ����Ľ���ֵdata
  LorR��ʾ�����ң�0Ϊ��1Ϊ�ҡ�
  x��ʾҪ����Ľ���ֵdata 
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
//����������½��в������,�˺������õ��ǵ��� 
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
//����������²������ݣ�ʹ�õݹ� 
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
/*  �ҵ��˶����������ֵ 
*/
BinTree FindMax(BinTree bt){
	if(!bt) return NULL;
	else {
		if(!bt->right){
		printf("�ҵ������ֵ��%d\n",bt->data); 
		return bt;
	    }
		else 
			bt->right = FindMax(bt->right);
	} 
} 
/*  �ҵ��˶���������Сֵ 
*/
BinTree FindMin(BinTree bt){
	if(!bt) return NULL;
	else {
		if(!bt->left){
		printf("�ҵ�����Сֵ��%d\n",bt->data); 
		return bt;
	    }
		else 
			bt->left = FindMin(bt->left);
	} 
} 
/*�ڶ��ֲ�����bt��ɾ��ֵΪx�Ľ�㲢���ִ˶�����Ϊ���ֲ�����(Binary Search Tree) 
*/ 
BinTree BinDelete(BinTree bt, ElemenType x){
	Position Tmp;
	if(!bt) printf("Ҫɾ����Ԫ��δ�ҵ�");
	else{
		if(x<bt->data)
			bt->left = BinDelete(bt->left, x);
		else if(x>bt->data)
			bt->right = BinDelete(bt->right, x);
		else{
			if(bt->left && bt->right){
				Tmp = FindMin(bt->right);
			//	printf("�ҵ������ֵ�� %d \n", Tmp->data);
				bt->data = Tmp->data;
			
				bt->right = BinDelete(bt->right, bt->data);
			//	printf("%d\n", bt->left->data);
			}
			else{
			//	Tmp = bt;
				if(!bt->left)     //���ֻ���Һ��ӻ��޺��� 
					bt = bt->right;
				else if(bt->left == bt->right == NULL)
				    bt = NULL;	
				else              //��������� 
					bt = bt->left;
			//	free( Tmp ); 
			}
		}
	}
	return bt;
}
int main(int argc, const char* argv[]){
	BinTree bt = CreateBinTree(18);
/*0Ϊleft��1Ϊright������Ϊ�������Ĺ��� 
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
	BinTree BST = Binsert_Re(bt, 12);  //��������в���12 
	InOrderTraversal(BST);
	printf("\n");
//	BinTree a = FindMin(bt);
	BinDelete(bt, 10);
	InOrderTraversal(bt);
	printf("\n");
//	PreOrderTraversal(bt);
	return 0;
} 
