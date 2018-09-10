#include <stdio.h>
#include <math.h>
#define maxv 1000010
#define MOD 1000000000

int f[maxv];


int main(){
	int n;
	f[1] = 1;
	f[2] = 2;
	while(scanf("%d", &n) != EOF){
		for(int i=3; i<=n; i++){
			if(i % 2 == 0){
				f[i] = (f[i/2] + f[i-1]) % MOD;
			}else{
				f[i] = f[i-1] % MOD;
			}
		}
		printf("%d\n", f[n]);
	}
	
	return 0;
} 
