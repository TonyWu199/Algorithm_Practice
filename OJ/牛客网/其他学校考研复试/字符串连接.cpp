#include <stdio.h>
#include <string.h> 

int main(){
	char s1[100],s2[100],s3[210];
	
	//这里的输入方式是无限输入 
	while(~scanf("%s %s", s1, s2)){
		int len1 = strlen(s1);
		int len2 = strlen(s2);
		
		for(int i=0; i<len1; i++){
			s3[i] = s1[i];
		}
		
		for(int i=0; i<len2; i++){
			s3[i+len1] = s2[i];
		}
		
		s3[len1+len2] = '\0';	
		printf("%s", s3);
	}
}
