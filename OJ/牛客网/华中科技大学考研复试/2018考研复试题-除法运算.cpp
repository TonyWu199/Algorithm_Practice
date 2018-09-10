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
		p[r] = t;      //r��q�е�һ�γ��ֵ�λ�� 
		r = 10*r;
		t++;
		q[t] = r/b;    //q�����洢С������ֵ 
		r = r%b;
	}
}

int main(){
	char input[len];
	int flag = 0;
	scanf("%s", input);
	
	char a[len], b[len];  //���������� 
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
		for(int i=1; i<=p[r]; i++){   //ѭ��֮ǰ��С�� p[r]��ʾ��һ���ظ������ֵ�λ�� 
			printf("%d", q[i]); 
		}
		
		printf("(");
		
		for(int i = p[r]+1; i<=t; i++){
			printf("%d", q[i]);
		} 
		
		printf(")");
	}else{   //��ѭ�� 
		for(int i=1; i<=t; i++)
			printf("%d", q[i]); 
	}
} 
