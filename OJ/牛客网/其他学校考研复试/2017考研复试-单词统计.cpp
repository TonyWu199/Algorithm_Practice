#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxn 100

int main(){
	char a[maxn], b[26];
	int cipin[26] = {0};
	int alpha_num=0, word_num=0, b_num=0;
	
	while(scanf("%s", a) != EOF){
		word_num++;
		alpha_num += strlen(a);
		for(int i=0; i<strlen(a); i++){
			if(a[i] >= 'a' && a[i] <='z'){
				cipin[a[i] - 'a']++;
			}else{
				cipin[a[i] - 'A']++;
			}
		}
		
		//ע�⣡ 
		if(getchar() == '\n'){
			break;
		}
	}
	
	int max = 0;
	for(int i=0; i<26; i++){
		if(cipin[i] > max){
			max = cipin[i];
		} 
	}
	
	for(int i=0; i<26; i++){
		if(cipin[i] == max){
			printf("%c", i+'a');
		}
	}
}
