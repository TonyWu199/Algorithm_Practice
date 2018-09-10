#include <stdio.h>
#include <string.h>

void Sort(char* s){
	int len = strlen(s);
	for(int i=1; i<len; i++){
		char tmp = s[i];
		int j;
		for(j=i-1; j>=0 && s[j]>tmp; j--){
			s[j+1] = s[j];
		}
		s[j+1] = tmp;
	}
}

int main(){
	char a[100], b[100], c[200];
	scanf("%s %s", a, b);
	
	for(int i=0; i < 200; i++){
		if(i < strlen(a)){
			c[i] = a[i];
		}else{
			c[i] = b[i - strlen(a)];
		}
	}
	
	char j[100], o[100];
	int len_j=0, len_o=0;
	for(int i=0; i<strlen(c); i++){
		if(i % 2 == 1){   //ÆæÊý
			j[len_j++] = c[i];
		}else{
			o[len_o++] = c[i];
		} 
	}
	j[len_j] = '\0';
	o[len_o] = '\0';
	
	printf("%s %s\n", j, o);
	Sort(j);
	Sort(o);
	
	printf("%s %s", j, o);
} 
