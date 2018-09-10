#include <stdio.h>

typedef struct state{
	int index;
	int Start;
	int Time;
	int End;
}STATE;

//����index��state�������� 
//�������ǰ�ύֻ��40�֣���Ϊ�ڲ���������tmp.indexд����state[i].index��������state[j+1] = state[j]�Ĺ�����state[i]�ǻ��ã�����һ�����޴��Ĵ����ˣ� 
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
	
	//��ʼ��Կ�׺� 
	for(int i=0; i<=N; i++){
		YSH[i] = i;
	}
	
	//�Ȱ���Կ�ױ�Ŷ������������ 
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
		//�ȷŻ� 
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
		
		//��ȡ 
		for(int i=0; i<K; i++){ 
			if(state[i].Start == time){
				for(int j=1; j<=N; j++){
					if(YSH[j] == state[i].index)
						YSH[j] = 0;             //0��ʾԿ�ױ�ȡ�� 
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

