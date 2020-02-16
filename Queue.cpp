#include<stdio.h>
#include<stdlib.h>
struct Queue{
	int *data;
	int capacity;
	int front;
	int rear;
};
void init(struct Queue *pq, int capacity){
	pq->capacity = capacity;
	pq->data = (int*)malloc(sizeof(pq->capacity+1)); 
	pq->front = pq->rear = 0;
}
int isFull(struct Queue* pq){
	if((pq->rear + 1) % (pq->capacity+1) == pq->front) return 1;
	else{
	  return 0;
    }
}
int isEmpty(struct Queue* pq){
	return pq->front == pq->rear ;
} 
int enQueue(struct Queue* pq, int x){
	if(isFull(pq)){ return 0;
	}
	else{
		pq->data[pq->rear] = x;
		pq->rear = (pq->rear + 1) % (pq->capacity+1);
		return 1;  
	}
}
int deQueue(struct Queue* pq, int *px){
	if(isEmpty(pq)){ return 0;
	}
	else{
		*px = pq->data[pq->front];
		pq->front = (pq->front + 1) % (pq->capacity + 1);
		return 1;	
	}
}
int main(int argc, const char* argv[]){
	struct Queue q;
	init(&q, 5);
	enQueue(&q, 11);
	enQueue(&q, 22);
	enQueue(&q, 33);
	enQueue(&q, 44);
	enQueue(&q, 55);
	enQueue(&q, 66);
	int x;
	deQueue(&q, &x); 
	printf("%d\n", x);
		deQueue(&q, &x); 
	printf("%d\n", x);
		deQueue(&q, &x); 
	printf("%d\n", x);
		deQueue(&q, &x); 
	printf("%d\n", x);
		deQueue(&q, &x); 
	printf("%d\n", x);
		deQueue(&q, &x); 
	printf("%d\n", x);     //再次出现55是因为这个printf又把上一个x打印了一遍 
	
	return 0;
} 
