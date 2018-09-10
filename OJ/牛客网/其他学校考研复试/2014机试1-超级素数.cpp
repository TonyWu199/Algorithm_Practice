#include <stdio.h>
#include <math.h>

int isPrim(int n){
	for(int i=2; i<=sqrt(n); i++){
		if(n % i == 0){
			return 0;
		}
	}
	return 1;
}

int main(){
	int flag = 0;
	for(int i=1000; i<=9999; i++){
		if(isPrim(i) && isPrim(i / 10) && isPrim(i / 100) && isPrim(i / 1000)){
			printf("%d ", i);
			flag++;
			if(flag % 6 == 0)
				putchar('\n');
		}
	}
} 
