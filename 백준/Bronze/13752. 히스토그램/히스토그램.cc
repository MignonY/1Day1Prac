#include <stdio.h>
 
int main() {
 
    int n;
    int arr[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d" ,& arr[i]);
 
        for (int j = 0; j < arr[i]; j++) {
            printf("=");
        }
        printf("\n");
    }
}