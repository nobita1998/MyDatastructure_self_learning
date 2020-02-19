#include<stdio.h>
#include<stdlib.h>
/*开放定址法实现散列表*/ 
enum GridStatus{ Active , Removed , Empty };
typedef enum GridStatus Status;
struct HashTable{
	int *key;
	Status* status;
	int size;
	int remains;
};
typedef struct HashTable* HT;
HT initHashTable(int size){
	HT h;
	h = (HT)malloc(sizeof(struct HashTable));
	if(!h)  return NULL;
	h->key = (int*)malloc(sizeof(int) * size);
	if(!h->key) { free(h); return NULL;}
	h->status = (Status*)malloc(sizeof(Status) * size);
	if(!h->status){ free(h->key); free(h);  return NULL;};
	h->size = h->remains = size;
	for(int i = 0; i<size; i++){
		h->status[i] = Empty;
	}
	return h;
}
int Hash( int x, int p){
	return x % p;
}
int isFull(const HT h){
	return h->remains == 0;
}
int InsertHash(int x, HT h){
	if(isFull(h))  return 0;
	int pos = Hash(x, h->size);
	while(h->status[pos] == Active){
		pos = (pos + 1) % h->size;
	}
	h->key[pos] = x;
	h->status[pos] = Active;
	h->remains--;
	return 1;
}
int FindHash(int x, HT h){
	int pos, index;
	pos = index = Hash(x, h->size);
	while( h->status[pos] != Empty ){
		if(h->key[pos] == x && h->status[pos] == Active) return pos;
		pos = (pos + 1) % h->size;
		if(index == pos) break;
	}
	return -1;
}
int RemoveHash(int x, HT h){
	int pos;
	pos = FindHash(x, h);
	if(pos == -1) return 0;
	h->status[pos] = Removed;
	h->remains--;
	return 0;
} 
void PrintHash(const HT h){
	for(int i = 0; i< h->size; i++)
		printf("%4d", i);
	printf("\n");
	for(int i = 0; i<h->size; i++){
		if(h->status[i] == Active) printf("%4d",h->key[i]);
		else if(h->status[i] == Removed) printf("   X");
		else printf("   -");
	}
	printf("\n");
}
typedef struct HashTable* HT;
int main(){
    HT h = initHashTable(11);
    PrintHash(h);
    InsertHash(5, h);
    InsertHash(16, h);
    InsertHash(27, h);
    InsertHash(38, h);
    InsertHash(4, h);
    PrintHash(h);
    RemoveHash(16, h);
    PrintHash(h);
    int i;
    i = FindHash(1,h);
    printf("%d", i);
	return 0;
}
