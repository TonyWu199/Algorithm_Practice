//这道题需要注意char数组的读取和int数组的读取不同，需要用getchar()来读取掉多余的换行 
#include <stdio.h>

void dfs(int line, int count, char * M); 
int isCorrect(int i, int j, char *M);

int n,k,num=0;

int main(){
	while(1){
		num = 0;
		scanf("%d %d", &n, &k);
		if(n == -1 && k == -1)   //注意不能写n == k == -1，因为==的无论左优先还是右优先等式都不会再n,k均为-1时成立 。==优先级从左到右 
			return 0;
		char M[n][n];
		getchar();
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				scanf("%c", &M[i][j]);
			}	
			getchar();
		}
		
		dfs(0, 0, (char *)M);	
		
		printf("%d\n", num);	
	}
} 

//注意这里与八皇后问题不同在于填入的棋子不一定每行都有 
//注意这里的一个小技巧，从line开始遍历
void dfs(int line, int count, char * M){
	//printf("%d",k);
	if(count == k){
		num++;
	}else{
		for(int i=line; i<n; i++){   //第一层遍历对所有行都有效，第二层遍历对n-1行有效 
			for(int j=0; j<n; j++){
				if(isCorrect(i, j, (char *)M)){
					*(M + i*n + j) = 'T';
					dfs(i+1, count+1, (char*)M);
					*(M + i*n + j) = '#';
				}
			}
		}	
	}
}

int isCorrect(int i, int j, char *M){
	if(*(M + i*n + j) == '.')
		return 0;
	
	//同一行
	for(int tmp=j; tmp<n; tmp++){
		if(*(M + i*n + tmp) == 'T')
			return 0;
	} 
	for(int tmp=j; tmp>=0; tmp--){
		if(*(M + i*n + tmp) == 'T')
			return 0;
	}
	
	//同一列 
	for(int tmp=i; tmp<n; tmp++){
		if(*(M + tmp*n + j) == 'T')
			return 0;
	} 
	for(int tmp=i; tmp>=0; tmp--){
		if(*(M + tmp*n + j) == 'T')
			return 0;
	}
	
	return 1;
}
