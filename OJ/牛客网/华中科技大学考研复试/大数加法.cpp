#include <stdio.h>
#include <string.h>

void inverse(char* str, int* digit){
	int len = strlen(str);
	
	for(int i=len-1;i>=0;i--){
		digit[len-1-i] = str[i] - '0';
	}
	
//	for(int i=0; i< len; i++)
//	printf("%d", digit[i]);
}

int main(){
	char a[1000], b[1000];
	
	while(scanf("%s%s", a, b) != EOF){
		int a_len = strlen(a);
		int b_len = strlen(b);
		int a_n[1000] = {0};
		int b_n[1000] = {0};
		
		//�Ƚ��ַ�������������������� 
		inverse(a, a_n);
		inverse(b, b_n);
		int len = a_len >= b_len ? a_len : b_len;
		
		int flag = 0;
		for(int i=0; i<len; i++){
			int tmp = (a_n[i] + b_n[i] + flag) / 10;    //��ʱ�����λ 
			a_n[i] = (a_n[i] + b_n[i] + flag) % 10;
			flag = tmp;
		}
		
		if(flag == 1){
			a_n[len] = 1;
			len++;   //����� 
		}
		
		//�����������ٴ�������� 
		for(int i= len-1; i>=0; i--){
			printf("%d",a_n[i]);
		}
		
	}
}
