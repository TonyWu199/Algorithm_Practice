#include <stdio.h>
#include <string.h>

int main(){
	char s[11];
	while(scanf("%s", s) != EOF){
		int flag = 0;
		for(int i=0; i<11; i++){
			if(i == 0){
				if(s[i] != '1'){
					printf("No\n");
					flag = 1;
					break;
				}
			}else if(i == 1){
				if(!(s[i] == '3' || s[i] == '5' || s[i] == '6' || s[i] == '8')){
					printf("No\n");
					flag = 1;
					break;
				}
			}else{
				if(!(s[i] >= '0' && s[i] <= '9')){
					printf("No\n");
					flag = 1;
					break;
				}
			}
		}
		if(flag == 0)
			printf("Yes\n");
	}
} 
