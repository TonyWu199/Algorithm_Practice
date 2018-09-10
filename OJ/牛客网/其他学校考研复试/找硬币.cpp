#include <stdio.h>

typedef struct STATE{
	int nCoins;
	int lastnum;
	int lastadd;
}STATE;

void print(STATE* state, int index);

int main(){
	int Coins[3] = {1,3,5};
	int total;
	scanf("%d", &total);
	STATE state[total+1];
	for(int i=0; i<=total; i++){
		state[i].nCoins = 1000000;
	}
	state[0].nCoins = 0;
	state[0].lastnum = 0;
	state[0].lastadd = 0;
	
	for(int i=1; i<=total; i++){
		for(int j=0; j<3; j++){
			if(i-Coins[j] >=0 && state[i-Coins[j]].nCoins + 1 < state[i].nCoins){
				state[i].nCoins = state[i-Coins[j]].nCoins + 1;
				state[i].lastnum = i - Coins[j];
				state[i].lastadd = Coins[j];
			} 
		}
	}
	//printf("%d", state[total].nCoins);
	print(state, total);
} 

//µÝ¹éÊä³ö 
void print(STATE* state, int index){
	if(index == 0){
		return;
	}else{
		print(state, state[index].lastnum);
		printf("%d", state[index].lastadd);
	}
}
