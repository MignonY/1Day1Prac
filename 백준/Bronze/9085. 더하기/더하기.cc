#include <stdio.h>

int a, b, c;

int main() {
    scanf("%d", &a);           
    for (int i = 0; i < a; i++) {
        scanf("%d", &b);
        int sum = 0;      
 
        for (int j = 0; j < b; j++) {
            scanf("%d", &c);           
            sum += c;       
        }
        printf("%d\n", sum);
    }
}
 