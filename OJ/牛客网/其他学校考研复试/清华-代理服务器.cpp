/*
比较经典的贪心算法问题，每一次贪心都要注意外层循环i的变化 
*/

#include <stdio.h>
#include <string.h>

char N[1010][16], M[5010][16];

int main(){
	int n, m;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%s", N[i]);
	}
	scanf("%d", &m);
	for(int i=0; i<m; i++){
		scanf("%s", M[i]);
	}	

	int max_index = 0, count=0, flag = 0;
	for(int i=0; i<m;){
		for(int k=0; k<n; k++){		
			int tmp = i;
			//printf("%d-", tmp);
			while(strcmp(N[k], M[tmp]) != 0 && tmp < m){
				tmp++;
			}
			if(tmp > max_index)
				max_index = tmp;
			//printf("%d ",max_index);
		}
		i = max_index;
		if(max_index==0)
			break;
		count++;
	}
	
	if(max_index == 0)
		count = 0;   //0-1=-1
	
	printf("%d", count-1);
}
