#include <stdio.h>

#define len 8


int count=0;
//注意这里的二维数组传递方式！ 
void solve(int n, int(*M)[len]);
int isCorrect(int i, int j, int(*M)[len]);

int main(){
	int M[len][len];
	for(int i=0; i<len; i++){
		for(int j=0; j<len; j++){
			M[i][j] = 0;   //0表示未访问 
		}
	}
	
	solve(0, M);      //4皇后问题一行只能填一个，所以可以通过solve函数的参数n来判断，其代表了填子个数和行数 
	printf("共计%d种解法",count);
}

void solve(int n, int(*M)[len]){
	
	if(n == len){       //此时完成一种情况的填写 
		count++;
		printf("--第%d种解法--\n", count); 
 		for(int i=0; i<len; i++){
 			for(int j=0; j<len; j++){
 				printf("%d ", M[i][j]);
			}
			printf("\n");
		} 
	}else{
		for(int i=0; i<len; i++){
			if(isCorrect(n, i, M)){   //这里的提前判断是算法改进的关键 
				M[n][i] = 1;          //填写棋子 
				solve(n+1, M);        //递归 
				M[n][i] = 0;          //恢复环境，进行下一次填子尝试 
			}
		}
	} 
}

int isCorrect(int i, int j, int(*M)[len]){
	
	//在行上进行检查 
	for(int tmp = i; tmp < len; tmp++){
		if(M[tmp][j] == 1)
			return 0;
	}
	for(int tmp = i; tmp >= 0; tmp--){
		if(M[tmp][j] == 1)
			return 0;
	}
	
	//在列上进行检查 
	for(int tmp = j; tmp < len; tmp++){
		if(M[i][tmp] == 1)
			return 0;
	}
	for(int tmp = j; tmp >= 0; tmp--){
		if(M[i][tmp] == 1)
			return 0;
	}
	
	//左下到右上检查
	for(int x=i, y=j; x<len && y<len; x++, y++){
		if(M[x][y] == 1)
			return 0;
	} 
	for(int x=i, y=j; x>=0 && y>=0; x--, y--){
		if(M[x][y] == 1)
			return 0;
	} 
	
	//左上到右下检查 
	for(int x=i, y=j; x>=0 && y<len; x--, y++){
		if(M[x][y] == 1)
			return 0;
	} 
	for(int x=i, y=j; x<len && y>=0; x++, y--){
		if(M[x][y] == 1)
			return 0;
	} 
	
	return 1;
}
