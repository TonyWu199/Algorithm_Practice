#include<stdio.h>

int main(){
	int a,b,c,d;
	while(~scanf("%d.%d.%d.%d", &a,&b,&c,&d)){	
		if(a>=0 && a<=255 && b>=0 && b<=255 && c>=0 && c<=255 && d>=0 && d<=255){
			printf("Yes!\n");
		}else{
			printf("No!\n");
		}
	} 
} 
