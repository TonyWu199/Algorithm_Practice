#include<stdio.h>

int main(){
	int n,tmp,column,row;
	scanf("%d", &n);
	int matrix[n][n];
	int i=0;
	
	while(i < n*n){
		scanf("%d", &tmp);
		column = i / n;
		row = i % n;
//		printf("%d %d", row, column);
		matrix[row][column] = tmp; 
		i++;
	}
	
	i = 0;
	while(i < n*n){
		row = i / n;
		column = i % n;
		printf("%d ", matrix[row][column]);
		if(i % n == n-1)
			printf("\n");
		i++;
	} 
	
} 
