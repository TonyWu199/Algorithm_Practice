#include <stdio.h>
#include <string.h> 


int distance(char * s1, char * s2){
	int opt[3];
	int dis[strlen(s1)+1][strlen(s2)+1];   //dis[0][0]表示两个字符串都为空 
	
	for(int i=0; i<=strlen(s1); i++){
		dis[i][0] = i;
	}
	
	for(int i=0; i<=strlen(s2); i++){
		dis[0][i] = i;
	}
	
	for(int i=1; i<=strlen(s1); i++){
		for(int j=1; j<=strlen(s2); j++){
			opt[0] = dis[i-1][j-1] + (s1[i-1] == s2[j-1] ? 0 : 1);
			//printf("%d", opt[0]);
			opt[1] = dis[i-1][j] + 1;
			opt[2] = dis[i][j-1] + 1;
			
			int min = 1000000;
			for(int k=0; k<3; k++){
				if(opt[k] < min){
					min = opt[k];
				}
				dis[i][j] = min;
			}
		}	
	}
	
	for(int i=0; i<=strlen(s2); i++){
		for(int j=0; j<=strlen(s1); j++){
			printf("%d ", dis[j][i]);
		}
		printf("\n");
	}
}

int main(){
	char s1[] = "you should not";
	char s2[] = "thou shalt not";
//	char s1[] = "jary";
//	char s2[] = "jerry";

	int result = distance(s1, s2);	
} 
