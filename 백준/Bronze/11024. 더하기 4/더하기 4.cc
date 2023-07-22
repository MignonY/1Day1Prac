#include <stdio.h>

int main(void) {
	int t = 0;
	scanf("%d", &t); 
	getchar(); 
	    while(t--) {
	    char tmp = 0;
	    tmp = getchar();
	    int sum = 0;
	    int a = 0;
	    int count = 0;
	
	    while(1==1) {
		    if(tmp == '\n') { 
			    sum += a; 
			    break;
		    } 
		    if(tmp == ' ') { 
			    sum += a; 
			    count = -1; 
			    a = 0;
		    }
		    if(count == 0) a = tmp-48; 
		    else {
			    a *= 10; 
			    a += tmp-48; 
		    }
		    count++;
		    tmp = getchar(); 
	    }
	printf("%d\n", sum); 
    }
	return 0;	
}