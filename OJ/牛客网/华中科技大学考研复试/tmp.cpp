#include <stdio.h>

void StraightInsertionSort(int *q, int n){
    for(int i=1; i<n; i++){
        int tmp = q[i];
        int j;
        for(j=i-1; j>=0 && q[j] > tmp; j--){
            q[j+1] = q[j];
        }
        q[j+1] = tmp;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int number[n];
    
    for(int i=0; i<n; i++){
    	scanf("%d", &number[i]);
	}
    
    StraightInsertionSort(number, n);
    
    printf("%d\n", number[n-1]);
    if(n == 1){
        printf("-1");
        return 0;
    }
    for(int i=0; i<n-1; i++){
        printf("%d ", number[i]);
    }
}
