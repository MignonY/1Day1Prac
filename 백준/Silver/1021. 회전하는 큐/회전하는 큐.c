#include<stdio.h>


int N, M, TN, cnt, arr[55], numls[55];

typedef struct NODE{
	struct NODE *prev, *next;
	int value;
}NODE;

NODE pool[500];
NODE* Naccess[55];
NODE* head;
NODE* new_node;
int Pidx;

NODE* alloc_node(){
	return &pool[Pidx++];
}

int if_LR(NODE* current, int TN){
	int left = 0;
	int right = 0;
	NODE* traverse = current;
	while(traverse->value != TN){
		traverse = traverse->next;
//		printf("left_cur : %d\n", traverse->value);
		left++;
	}
	traverse = current;
	while(traverse->value != TN){
		traverse = traverse->prev;
//		printf("right_cur : %d\n", traverse->value);
		right++;
	}
	if (left>right)
		return right;
	else
		return left;	
}

int main(){
	scanf("%d %d", &N, &M);
	head = alloc_node();
	head->value = 1;
	Naccess[1] = head;
	head->next = head->prev = head;
	for(int i=2; i<N+1; ++i){
		new_node = alloc_node();
		new_node->value = i;
		new_node->next = head;
		new_node->prev = head->prev;
		
		head->prev->next = new_node;
		head->prev = new_node;
		Naccess[i] = new_node;
	}
	
//	printf("M:%d\n", M);
	NODE* current = head;
	for(int i=0; i<M; ++i){
		scanf("%d", &TN);
		NODE* traverse = current;
		int savev = traverse->value;
//		printf("traverse : %d", savev);
//		while(traverse->next->value != savev){
//			traverse = traverse->next;
//			printf(" %d", traverse->value);
//		}
//		printf("\n");
		cnt += if_LR(current, TN);
		current = Naccess[TN]->next;
		
		current->prev->prev->next =current;
		current->prev = current->prev->prev;
		
	}
	
	printf("%d", cnt);
	
	
	return 0;
}