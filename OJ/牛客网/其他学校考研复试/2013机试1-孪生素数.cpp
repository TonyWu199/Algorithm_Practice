#include <stdio.h>
#include <math.h>

int isPrim(int s){
	for(int i=2; i<=sqrt(s); i++){
		if(s % i == 0)
			return 0;
	}
	return 1;
}

int main(){
	int n;
	scanf("%d", &n);
	
	int p=0, q=0;
	for(int i=0; i<=n-2; i++){
		if(isPrim(i) == 1 && isPrim(i+2) == 1){
			p = i;
			q = i+2; 
		}
	}
	
	printf("%d %d", p, q);
}
