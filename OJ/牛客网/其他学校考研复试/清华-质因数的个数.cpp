#include <stdio.h>
#include <math.h>

int sum = 0;

void count(long n){
	if(n == 1){
		return;
	}
	int i=0;
	for(i=2; i<=sqrt(n); i++){   //ע��������жϺ��ж��������ƣ����û���ҵ���Ϊ��С������ 
		if(n % i == 0){
			sum++;
			count(n / i);
			break; 
		}
	}
	
	if(i > sqrt(n)){
		sum++;
		count(1);	
	}
}

int main(){
	long n;
	
	while(scanf("%ld", &n) != EOF){
		count(n);
		printf("%d\n", sum); 
		sum = 0;
	}
}
