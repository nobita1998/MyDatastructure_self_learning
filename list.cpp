#include<stdio.h>
#include<stdlib.h 
//int *p = a, ����p������a�ĵ�ַ����*p�����a��ֵ 
struct Node{           //����һ���ڵ�Node,�ڵ��ڰ���data��ָ����һ���ڵ��ָ��next
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
	p = head;   //����*p = **phead��ָ��head
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
	else if(k == 1){        //��ͷ�������� 
        struct Node *t;
		t = createNode(x);
		t->next = *phead; //ָ��ԭ���ĵ�һ���� 
		*phead = t;
		return 1;		
	}
	else{
	struct Node *p; //����һ��ָ��Ҫ����Ľڵ�p��ָ�� 
    p = findKth(*phead, k-1);
	if(p){             //p���գ����Բ��� 
		struct Node *t;
		t = createNode(x); //����һ������Ϊx�Ľ��t  
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
	else if (k == 1){      //���ɾ������ͷ��� 
		if(*phead){        //������ǿձ� 
			*px = (*phead)->data;    //��ɾȥ��㴢����*px�� 
			*phead= (*phead)->next;  //*phead�����Ͼ���head 
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
		struct Node *head; //����һ��ָ��Node�ṹ���ͷָ�� 
		init(&head);       //&headָ�������ָ��ĵ�ַ����ʼ�����ͷָ��ָ��NULL 
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
