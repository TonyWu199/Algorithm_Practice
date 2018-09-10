#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	
	int num = n / 10;
	
	int num_5 =num / 5;
	int rst_5 = num % 5;
	
	int num_3 = rst_5 / 3;
	int rst_3 = rst_5 % 3;
	
	int rst = num_5 * 7 + num_3 * 4 + rst_3;
	
	printf("%d", rst);	
} 
