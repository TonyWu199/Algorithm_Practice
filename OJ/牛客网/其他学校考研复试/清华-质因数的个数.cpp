#include <stdio.h>
#include <math.h>

int sum = 0;

void count(long n){
	if(n == 1){
		return;
	}
	int i=0;
	for(i=2; i<=sqrt(n); i++){   //注意这里的判断和判断质数类似，如果没查找到则为最小质因数 
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
