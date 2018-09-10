#include <stdio.h>
#include <math.h>
#define maxv 1010
long s[maxv];

long count(long n){
	if(n == 1){
		return 1;	
	} 
	
	int sum = 0; 
	for(int i=1; i<=sqrt(n); i++){
		if(n % i == 0)
			sum+=2;
	}
	return sum;
}

int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		if(n == 0)
			return 0;
		for(int i=0; i<n; i++){
			scanf("%ld", &s[i]);
			printf("%ld\n", count(s[i]));
		}
	}
	
	return 0;
}
