#include <stdio.h>
#define len 8

typedef struct STATE{
	int length;
	int parent;
}STATE; 

int main(){
	int xl[len] = {1, -1, 2, -3, 4, -5, 6, -7};
	STATE state[len]; 
	for(int i=0; i<len; i++){
		state[i].length = 1;
		state[i].parent = 0;
	}
	
	for(int i=0; i<len; i++){
		for(int j=0; j<i; j++){
			if(xl[j] < xl[i] && state[j].length + 1 > state[i].length){
				state[i].length = state[j].length + 1;
				state[i].parent = j;
			}
		}
	} 
	
	//这里还需要比较每一位数中最大的Length，从而获得最长的递增序列 
	printf("%d",state[len-2].length);	 
} 
