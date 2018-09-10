#include <stdio.h>

int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		int y1=0;
		int s1 = 1;
		for(int i=1; i<=n; i+=2){
			if(i != 1)
				s1 = s1 * i * (i-1);
			y1 += s1; 
		}
		
		int y2=0;
		int s2 = 1;
		for(int i=2; i<=n; i+=2){
			s2 = s2 * i * (i-1);
			y2 += s2; 
		}
		
		printf("%d %d\n", y1, y2);
	}
} 
