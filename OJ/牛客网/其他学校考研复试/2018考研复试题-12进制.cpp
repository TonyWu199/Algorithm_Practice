#include <stdio.h>
#include <string.h>
#define maxn 100

int POW(int a, int b){
	if(b == 0){
		return 1;
	}
	for(int i=0; i<b-1; i++){
		a = a*a;
	}
	return a;
}

void _2b(int sum){
	if(sum == 1){
		printf("1"); 
		return;
	}else{
		int t = sum / 2;
		_2b(t);
		printf("%d", sum % 2); 
	}
}

int main(){
	char input[maxn];
	scanf("%s", input);
	long long sum_0 = 0;;
	
	for(int i=strlen(input)-1; i>=0; i--){
		if(input[i] >= 'a' && input[i] <= 'b'){
			sum_0 += (input[i] - 'a' + 10) * POW(12, strlen(input) - i - 1);
		}else if(input[i] >= '0' && input[i] <= '9'){
			sum_0 += (input[i] - '0') * POW(12, strlen(input) - i - 1);
		}
		printf("%d\n", sum_0); 
	}
	
	_2b(sum_0);
}
