#include <stdio.h>
#include <string.h>

char keyboard[8][4] = {
{'a','b','c'}, {'d','e','f'},
{'g','h','i'}, {'j','k','l'}, {'m','n','o'},
{'p','q','r','s'}, {'t','u','v'}, {'w','x','y','z'}
}; 

void get_loc(char c, int* block, int* index){
	for(int i=0; i<8; i++){
		for(int j=0; j<4; j++){
			if(keyboard[i][j] == c){
				*block = i;
				*index = j;
			}
		}
	}
}

int main(){
	char in[110];
	
	while(scanf("%s", in) != EOF){
		int block=0, index = 0, t_block=0, t_index=0, time=0;
		get_loc(in[0], &block, &index);
		//printf("%d-%d\n", block, index);
		time += index + 1;
		for(int i=1; i<strlen(in); i++){
			get_loc(in[i], &t_block, &t_index);
			//printf("%d-%d\n", t_block, t_index);
			if(t_block == block){
				time += 2 + t_index + 1;	
			}else{
				time += t_index + 1;
			}		
			block = t_block;
		}
		
		printf("%d\n", time);
	}
}
