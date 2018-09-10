#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	int M[n][n];
	
	//00-03 04-34 44-41 40-10
	//11-12 13-23 33-32 31-21
	//22
	int flag = 1;
	
	for(int i=1; i<=n/2+1; i++){
		if(i == n/2+1 && (n % 2 == 1)){
			M[n-i][n-i] = flag; 
			break;
		}
		for(int i1=i-1; i1<=n-i-1; i1++)
			M[i-1][i1] = flag++;
		for(int i2=i-1; i2<=n-i-1; i2++)
			M[i2][n-i] = flag++;
		for(int i3=n-i; i3>=i; i3--)
			M[n-i][i3] = flag++;
		for(int i4=n-i; i4>=i; i4--)
			M[i4][i-1] = flag++;
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("%03d ", M[i][j]);
		}
		putchar('\n');
	} 
}
