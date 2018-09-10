#include <stdio.h>

int main(){
	char s[5];
	
	while(scanf("%s", s) != EOF){
		printf("%c%c%c%c\n", s[3], s[2], s[1], s[0]);
	}
} 
