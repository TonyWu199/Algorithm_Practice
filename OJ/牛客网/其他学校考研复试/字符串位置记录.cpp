#include <stdio.h>
#include <string.h>
#define maxv 100000

int main(){
	char s[maxv];
	scanf("%s", s);
	int flag = 0;
	
	for(int i=0; i<strlen(s); i++){
		char tmp = s[i];
		flag = 0;
		if(s[i] == '*')
			continue;
		else{
			s[i] = '*';
			for(int j=i+1; j<strlen(s); j++){
				if(s[j] == tmp){
					if(flag == 0){
						flag = 1;
						printf("%c: %d", tmp, i);
					}
					printf(",%c: %d", tmp, j);
					s[j] = '*';
				}
			}
			if(flag)
				printf("\n");
		}

	}
} 
