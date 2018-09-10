#include <iostream>
#include <algorithm>
#include <string.h>
#define maxv 10000

using namespace std;

int f[maxv][maxv];
int c[4] = {0, 1, 2, 3};
int w[4] = {0, 60, 100, 120};

int main(){
	int N=3, V=5;
	for(int j=0; j<=V; j++){
		f[0][j] = 0;
		for(int i=1; i<=N; i++){
			if(j < c[i])
				f[i][j] = f[i-1][j];
			else
				f[i][j] = max(f[i-1][j], f[i-1][j-c[i]] +  w[i]);
		}
	}
	
	for(int i=0; i<=5; i++){
		for(int j=3; j>=0; j--){
			cout << f[j][i] << " ";
		}
		cout << endl;
	}
} 
