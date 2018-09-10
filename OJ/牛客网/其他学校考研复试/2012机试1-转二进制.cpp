#include <stdio.h>
#include <string.h>
int BIT[32];

int high(unsigned long n, int w){
	if(n == 1){
//		if(w % 8 == 0)
//			putchar(' ');
//		printf("1");
		BIT[w] = 1;
		return w;
	}
	int tmp = high(n/2, w+1);
//	if(w % 8 == 0)
//		putchar(' ');
	BIT[w] = n % 2;
//	printf("%d", n%2);
	return tmp;
}

int main(){
	memset(BIT, 0, 32);
	unsigned long n,m;
	scanf("%d",&n);
	int len = high(n, 0);
	
	for(int i=31; i>=0; i--){
		if((i+1) % 8 == 0 && i+1 != 32){
			printf(" ");
		}
		printf("%d", BIT[i]);
	}
} 
