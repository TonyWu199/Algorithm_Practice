#include <stdio.h>


int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		int result[150000];	
		int wei = 0;
		while(n != 0){
			result[wei++] = n % 8;
			n /= 8;
		}
		
		for(int i=wei-1; i>=0; i--){
			printf("%d", result[i]);
		}
		putchar('\n');
	}
}
