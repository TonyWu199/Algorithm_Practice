#include <stdio.h>

typedef struct state{
	int index;
	int Start;
	int Time;
	int End;
}STATE;

//根据index对state进行排序 
//这道题先前提交只有40分，因为在插入排序中tmp.index写成了state[i].index，但是在state[j+1] = state[j]的过程中state[i]是会变得，算是一个很愚蠢的错误了！ 
void Sort(STATE* state, int len){
	for(int i=1; i<len; i++){
		STATE tmp = state[i];
		int j=0;
		for(j=i-1; j>=0 && state[j].index > tmp.index; j--){
			state[j+1] = state[j];
		}
		state[j+1] = tmp; 
	} 
} 

int main(){
	int N,K;
	scanf("%d %d", &N, &K);
	int YSH[N+1]; 
	STATE state[K];

	for(int i=0; i<K; i++){
		scanf("%d %d %d", &state[i].index, &state[i].Start, &state[i].Time);
		state[i].End = state[i].Start + state[i].Time;
	}
	
	//初始化钥匙盒 
	for(int i=0; i<=N; i++){
		YSH[i] = i;
	}
	
	//先按照钥匙编号对输入进行排序 
	Sort(state, K);
	for(int i=0; i<K; i++){
		printf("%d %d %d\n", state[i].index, state[i].Start, state[i].Time);
	}
	
	int Max = 0;
	for(int i=0; i<K; i++){
		if(state[i].End > Max)
			Max = state[i].End; 
	}
	
	for(int time=1; time <= Max; time++){
		//先放回 
		for(int i=0; i<K; i++){
			if(state[i].End == time){
				for(int j=1; j<=N; j++){
					if(YSH[j] == 0){
						YSH[j] = state[i].index;
						break;
					}
				}
			} 
		}
		
		//再取 
		for(int i=0; i<K; i++){ 
			if(state[i].Start == time){
				for(int j=1; j<=N; j++){
					if(YSH[j] == state[i].index)
						YSH[j] = 0;             //0表示钥匙被取走 
				}
			}
		} 
	}
	
	for(int i=1; i<=N; i++){
		printf("%d", YSH[i]);
		if(i!=N)
			printf(" ");
	}
	printf("\n"); 
}

