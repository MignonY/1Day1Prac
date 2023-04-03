#include <stdio.h>

int T, m_size;
char munjayol[1005];


int main(){
	scanf("%d", &T);
	for(int i=0; i<T; ++i){
		scanf("%s", munjayol);
		while(munjayol[m_size] != NULL)
			m_size++;

		printf("%c",munjayol[0]);
		printf("%c\n",munjayol[m_size-1]);
		m_size = 0;
		}
	
	return 0;
	}