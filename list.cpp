#include<stdio.h>
#include<stdlib.h 
//int *p = a, 其中p包含有a的地址，而*p则包含a的值 
struct Node{           //定义一个节点Node,节点内包含data和指向下一个节点的指针next
	int data;
	struct Node* next; 
};                                   
void init(struct Node** phead){
	*phead = NULL;
}
int getLength(struct Node* head){
	int len = 0;
	while(head){
		head = head->next;
		len++;
	}
	return len;
}
void printList(struct Node* head){
	while(head){
		printf("%d\n", head->data);
		head = head->next;
	}
}
struct Node *createNode(int x){
	struct Node* t;
	t = (struct Node*)malloc(sizeof(struct Node));
	t->next = NULL;
	t->data = x;
	return t;
}
struct Node* findKth(struct Node* head, int k){
	int count = 1;
	struct Node* p;
	p = head;   //所以*p = **phead，指向head
	printf("%d\n5\n",*p);
	printf("%d\n5\n",p);
	while(p && count<k){
		p = p->next;
		count++;
	}
	return p;
}
int insert(struct Node** phead, int k, int x){
	if(k<1){
		return 0;
	}
	else if(k == 1){        //在头部插入结点 
        struct Node *t;
		t = createNode(x);
		t->next = *phead; //指向原来的第一个点 
		*phead = t;
		return 1;		
	}
	else{
	struct Node *p; //定义一个指向要插入的节点p的指针 
    p = findKth(*phead, k-1);
	if(p){             //p不空，可以插入 
		struct Node *t;
		t = createNode(x); //创建一个内容为x的结点t  
		t->next = p->next;
		p->next =t; 
		return 1;
	}
	else{
		return 0;
	}
}
}
int removeNode(struct Node** phead, int k, int *px){
	if(k<1) return 0;
	else if (k == 1){      //如果删除的是头结点 
		if(*phead){        //如果不是空表 
			*px = (*phead)->data;    //把删去结点储存在*px中 
			*phead= (*phead)->next;  //*phead本质上就是head 
			return 1;
		}
		else{
			return 0;
		}
	} 
	else{
		struct Node* p;
		p = findKth(*phead, k-1);
		
		
		
		if(p == NULL && p->next == NULL) return 0;
		struct Node *t;
		t = p->next;
		p->next = t->next;
		*px = t->data;
		free(t);
		return 1;
		
	}
}
int main(int argc, const char* argv[]){
		struct Node *head; //定义一个指向Node结构体的头指针 
		init(&head);       //&head指的是这个指针的地址，初始化后该头指针指向NULL 
		insert(&head, 1, 11); 
		insert(&head, 1, 22);
		insert(&head, 2, 33);
		insert(&head, 4, 55);
		insert(&head, 6, 88);
		printList(head); 
		int x;
		removeNode(&head, 1, &x);
		printf("%d\n", x);
		printList(head);
		printf("%d\n",*head);
		printf("%d",head);
		
		//int k = getLength(head);
		//printf("%d\n", k);
		return 0;
} 
