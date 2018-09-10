#include <stdio.h>
#include <string.h>

int main(){
	char s[20];
	int flag = 0;
	int tag = 0;
	
	while(scanf("%s", s) != EOF){
		tag = 0;
		if(s[strlen(s) - 1] == 'L' || s[strlen(s) - 1] == 'l'){
			flag++;
		}
		
		if(s[strlen(s) - 2] == 'u' || s[strlen(s) - 2] == 'U'){
			flag++;
		}
		
		if(s[0] == '0'){     //八进制 
			for(int i=1; i<strlen(s)-flag; i++){
				if(!(s[i] >= '0' && s[i] <='7')){
					printf("No\n");
					tag = 1;
					break;
				}
			}
			if(tag) continue; 
		}else if(s[0] == '0' && s[1] == 'x'){    //十六进制 
			for(int i=2; i<strlen(s)-flag; i++){
				if(!(s[i] >= '0' && s[i] <='9' && (s[i] >= 'a' && s[i] <= 'f'))){
					printf("No\n");
					tag = 1;
					break;
				}
			}
			if(tag) continue;
		}else if(s[0] == '0' && s[1] == 'X'){
			for(int i=2; i<strlen(s)-flag; i++){
				if(!(s[i] >= '0' && s[i] <='9' && (s[i] >= 'A' && s[i] <= 'F'))){
					printf("No\n");
					tag = 1;
					break;
				}	
			}
			if(tag) continue;
		}else{
			for(int i=2; i<strlen(s)-flag; i++){
				if(!(s[i] >= '0' && s[i] <='9')){
					printf("No\n");
					tag = 1;
					break;
				}
			}
			if(tag) continue;
		}
		
		printf("Yes\n"); 
	}
} 
