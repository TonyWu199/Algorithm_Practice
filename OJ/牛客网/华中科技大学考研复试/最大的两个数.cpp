#include <stdio.h>

int main(){
	int M[4][5];
	int output[5][2];
	
	for(int i=0; i<4; i++){
		for(int j=0; j<5; j++){
			scanf("%d", &M[i][j]);
		}
	}
	
	for(int j=0; j<5; j++){
		int Max=-10000, Max_2=-10000;
		for(int i=0; i<4; i++){
			if(M[i][j] > Max){
				Max_2 = Max; 
				Max = M[i][j];
			}else if(M[i][j] <= Max && M[i][j] > Max_2){
				Max_2 = M[i][j];
			}
		}
		//printf("%d %d\n", Max, Max_2);
		int m=0;
		int flag=-10000;
		for(int k=0; k<4 && m!=2; k++){
			if((M[k][j] == Max || M[k][j] == Max_2) && M[k][j] != flag){
				output[j][m++] = k;
				flag = M[k][j];
			}
		}
	}
	
	for(int i=0; i<2; i++){
		for(int j=0; j<5; j++){
			printf("%d ", M[output[j][i]][j]);
		}
		putchar('\n');
	}
}
 
