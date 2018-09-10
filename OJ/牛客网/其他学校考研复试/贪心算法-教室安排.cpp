#include <stdio.h>

int s[11] = {1,3,0,5,3,5,6,8,8,2,12};
int f[11] = {4,5,6,7,8,9,10,11,12,13,14}; 

void greedy(int start, int end){
	printf("%d-%d\n", s[start], f[start]);
	for(int i=start; i<=end; i++){
		if(s[i] > f[start]){
			greedy(i, end);
			break;
		} 
	}
}

int main(){
	
	//需要按照f进行一次排序
	 
	greedy(0, 10);
} 


