#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define len 32

static int q[len], p[len], r, t;

void solve(int a, int b){
	memset(p, -1, sizeof(int)*len);
	memset(q, 0, sizeof(int)*len);
	
	t = 0;
	r = a%b;
	while(r != 0 && (p[r] == -1)){
		printf("%d ", r);
		p[r] = t;      //r在q中第一次出现的位置 
		r = 10*r;
		t++;
		q[t] = r/b;    //q用来存储小数点后的值 
		r = r%b;
	}
}

int main(){
	char input[len];
	int flag = 0;
	scanf("%s", input);
	
	char a[len], b[len];  //除数被除数 
	memset(a, 0, sizeof(char)*len);
	memset(b, 0, sizeof(char)*len);
	
	for(int i=0; i<strlen(input); i++){
		if(input[i] == '/'){
			flag = 1;
			continue;
		}
		
		if(flag == 0){
			a[i] = input[i]; 
		}else{
			b[i-strlen(a)-1] = input[i];
		}
	}
	
	int i_a = atoi(a);
	int i_b = atoi(b);
	if(i_a / i_b > 0)
		printf("%d.", i_a/i_b);
	else printf(".");
	
	solve(i_a, i_b);
	
	if(r != 0){
		for(int i=1; i<=p[r]; i++){   //循环之前的小数 p[r]表示第一个重复的数字的位置 
			printf("%d", q[i]); 
		}
		
		printf("(");
		
		for(int i = p[r]+1; i<=t; i++){
			printf("%d", q[i]);
		} 
		
		printf(")");
	}else{   //不循环 
		for(int i=1; i<=t; i++)
			printf("%d", q[i]); 
	}
} 
