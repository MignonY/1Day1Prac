#include <iostream>
#include <unordered_map>

#define alloc_node() (&pool[Pidx++])
using namespace std;

 
struct NODE{
	NODE *prev, *next;
	int ID;
	int W;
	int cnum; 	
};

unordered_map<int, NODE*> dic;

NODE pool[100005];
int Pidx;
NODE* BELT[15];
NODE *head, *new_node, *tempN, *TAIL, *MID, *MID_front, *traverse;
bool broken[15]; 

//unsigned long long cnt;
int q, n, m, r_id, f_id, b_num;
int C, comm,cidx, command[200005];

template<typename K, typename V>
void print_dic(unordered_map<K,V> const &dic){
	printf("dic = {");
	for(auto const &pair: dic){
		printf("%d:%d, " , pair.first, pair.second);
	}
	printf("}\n");
}

void Q_200(int w_max, unsigned long long cnt){
	cnt = 0;
	for(int i=1; i<=m; ++i){
		//해당노드 임시로 담고 
		tempN = BELT[i]->next;
		
		if(BELT[i]->next->W > w_max){
			//노드 떼서 맨뒤로
			
			// 헤드에서 분리  
			BELT[i]->next->next->prev = BELT[i];
			BELT[i]->next = BELT[i]->next->next;
			
			//해당노드에서도 앞뒤연결
			tempN->next = BELT[i];
			tempN->prev = BELT[i]->prev; 
			
			// 테일쪽에서 연결 
			BELT[i]->prev->next = tempN;
			BELT[i]->prev = tempN; 
			
			
		}
		else{
			cnt += BELT[i]->next->W;
//			printf("belt : %d, v: %d\n", i, BELT[i]->next->W);
			//노드 떼서 삭제
			BELT[i]->next = BELT[i]->next->next;
			BELT[i]->next->prev = BELT[i];
			dic[tempN->ID] = nullptr;
		}
	}
	
	printf("%llu\n", cnt);
}

void Q_300(int r_id){
	
	if(dic.find(r_id)== dic.end() || dic[r_id]== nullptr)
		printf("-1\n");
	
	else{
		tempN = dic[r_id];

		//노드 떼서 삭제
		tempN->prev->next = tempN->next;
		tempN->next->prev = tempN->prev;
		
		dic[r_id] = nullptr;
		printf("%d\n", r_id);
	}

}


void Q_400(int f_id){
	
	if(dic.find(f_id)== dic.end() || dic[f_id]== nullptr)
		printf("-1\n");
	
	else{
		tempN = dic[f_id];
		int CNUM = tempN->cnum;
		//줄기 마지막, 줄기 앞 절단부  저장  
		TAIL = BELT[CNUM]->prev;
		MID = tempN->prev; 
		MID_front = BELT[CNUM]->next;
		
		printf("%d\n", CNUM);
	
		
		//노드줄기 분리 (전체줄기관점) 
		BELT[CNUM]->prev = tempN->prev;
		tempN->prev->next = BELT[CNUM];		
			
		//맨앞에다 이식 (전체줄기관점) 
		BELT[CNUM]->next->prev = TAIL;
		BELT[CNUM]->next = tempN;
		
		//맨앞 이식 (해당 줄기 관점)
		TAIL->next = MID_front;
		tempN->prev = BELT[CNUM];		
	}	
}

void Q_500(int b_num, bool broken[]){
	if (broken[b_num] == 1) 
		printf("-1\n");
	else{
		printf("%d\n", b_num);
		broken[b_num] = 1;
		int temp_num =(b_num + 1) %(m+1); //m = 3   1 > 2 , 2 > 3, 3>1
		if (temp_num ==0)
			temp_num =1;
		while (broken[temp_num] == 1){
			temp_num = (temp_num +1) % (m+1);
			if (temp_num ==0)
				temp_num =1;
		}
		traverse = BELT[b_num]->next;
		while(traverse != BELT[b_num]){
			traverse->cnum = temp_num;
//			printf("500 //  {ID:%d , W:%d , cnum:%d }\n", traverse->ID, traverse->W, traverse->cnum);
			traverse = traverse->next;
		}
		
		tempN = BELT[b_num]->next;
		TAIL = BELT[b_num]->prev;
		//노드 이식 (분리줄기 관점) 
		tempN->prev = BELT[temp_num]->prev;
		TAIL->next = BELT[temp_num];
		
		//노드 이식(새줄기 관점)
		BELT[temp_num]->prev->next = tempN;
		BELT[temp_num]->prev = TAIL;
		
		//노드줄기 분리 (고장 줄기관점) 
		BELT[b_num]->next = BELT[b_num]->prev = BELT[b_num];	
		
	}
}


int main() {
	freopen("input.txt","r",stdin);
    scanf("%d", &q);
    // 100
    scanf("%d %d %d", &C, &n, &m);

    // 100 정보담기 (컨테이너, 노드개수, id, 무게) 
    for(int i=0; i<n*2; ++i){
    	scanf("%d", &command[i]);
	}
    for(int i = 1; i<=m; ++i){
    	//head 각 컨테이너 idx에 담고, 초기작업 
    	head = alloc_node();
    	head->cnum = i;
    	head->next = head->prev = head;
    	BELT[i] = head;
    	for(int j=0; j<n/m; ++j){
    		NODE* new_node = alloc_node();
    		//노드아이디로 노드주소 접근  
//    		dic[command[cidx]] = Pidx;
			dic[command[cidx]] = new_node;
    		new_node->ID = command[cidx];
    		new_node->W = command[cidx+n];
    		new_node->cnum = i;
    		cidx++;
    		
    		//노드연결 
    		new_node->next = head;
			new_node->prev = head->prev;
			
			head->prev->next = new_node;
			head->prev = new_node; 
//			printf("i:%d, j:%d\n",i, j);
		}
	
	}
//    printf("C:%d n:%d m:%d\n", C,n,m);
//    // 100- traverse 체크
//	for(int i=1; i<m+1; i++){
//		NODE *traverse = BELT[i]->next;
//		while(traverse != BELT[i]){
//			printf("B[%d] = {ID:%d , W:%d , cnum:%d }\n", i, traverse->ID, traverse->W, traverse->cnum);
//			traverse = traverse->next;
//		} 
//	}
	
//	// dic 체크  
//	print_dic(dic); 
//	printf("%d", dic[21]->W);

	
    //100 제외 나머지 명령 
    for(int A=1; A<q; ++A){
    	int Qnum, Q;
    	scanf("%d %d", &Qnum, &Q);
    	if(Qnum == 200)
    		Q_200(Q, 0);   
		else if (Qnum== 300)
			Q_300(Q);  		
		else if (Qnum== 400)
			Q_400(Q); 
		else if (Qnum== 500)
			Q_500(Q, broken); 
    	
//	    // traverse 체크
//	    printf("#### %d _ traverse ####\n", Qnum);
//		for(int i=1; i<m+1; i++){
//			NODE *traverse = BELT[i]->next;
//			while(traverse != BELT[i]){
//				printf("B[%d] = {ID:%d , W:%d , cnum:%d }\n", i, traverse->ID, traverse->W, traverse->cnum);
//				traverse = traverse->next;
//			} 
//		}
//		print_dic(dic);	
//	    
//		printf("-----------------\n");	
	}
//    for(int i=0; i<15; ++i){
//    	printf("%d ", broken[i]);
//	}
    
    return 0;
}
