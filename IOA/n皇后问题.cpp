#include <stdio.h>

#define len 8


int count=0;
//ע������Ķ�ά���鴫�ݷ�ʽ�� 
void solve(int n, int(*M)[len]);
int isCorrect(int i, int j, int(*M)[len]);

int main(){
	int M[len][len];
	for(int i=0; i<len; i++){
		for(int j=0; j<len; j++){
			M[i][j] = 0;   //0��ʾδ���� 
		}
	}
	
	solve(0, M);      //4�ʺ�����һ��ֻ����һ�������Կ���ͨ��solve�����Ĳ���n���жϣ�����������Ӹ��������� 
	printf("����%d�ֽⷨ",count);
}

void solve(int n, int(*M)[len]){
	
	if(n == len){       //��ʱ���һ���������д 
		count++;
		printf("--��%d�ֽⷨ--\n", count); 
 		for(int i=0; i<len; i++){
 			for(int j=0; j<len; j++){
 				printf("%d ", M[i][j]);
			}
			printf("\n");
		} 
	}else{
		for(int i=0; i<len; i++){
			if(isCorrect(n, i, M)){   //�������ǰ�ж����㷨�Ľ��Ĺؼ� 
				M[n][i] = 1;          //��д���� 
				solve(n+1, M);        //�ݹ� 
				M[n][i] = 0;          //�ָ�������������һ�����ӳ��� 
			}
		}
	} 
}

int isCorrect(int i, int j, int(*M)[len]){
	
	//�����Ͻ��м�� 
	for(int tmp = i; tmp < len; tmp++){
		if(M[tmp][j] == 1)
			return 0;
	}
	for(int tmp = i; tmp >= 0; tmp--){
		if(M[tmp][j] == 1)
			return 0;
	}
	
	//�����Ͻ��м�� 
	for(int tmp = j; tmp < len; tmp++){
		if(M[i][tmp] == 1)
			return 0;
	}
	for(int tmp = j; tmp >= 0; tmp--){
		if(M[i][tmp] == 1)
			return 0;
	}
	
	//���µ����ϼ��
	for(int x=i, y=j; x<len && y<len; x++, y++){
		if(M[x][y] == 1)
			return 0;
	} 
	for(int x=i, y=j; x>=0 && y>=0; x--, y--){
		if(M[x][y] == 1)
			return 0;
	} 
	
	//���ϵ����¼�� 
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
