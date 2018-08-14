//�������Ҫע��char����Ķ�ȡ��int����Ķ�ȡ��ͬ����Ҫ��getchar()����ȡ������Ļ��� 
#include <stdio.h>

void dfs(int line, int count, char * M); 
int isCorrect(int i, int j, char *M);

int n,k,num=0;

int main(){
	while(1){
		num = 0;
		scanf("%d %d", &n, &k);
		if(n == -1 && k == -1)   //ע�ⲻ��дn == k == -1����Ϊ==�����������Ȼ��������ȵ�ʽ��������n,k��Ϊ-1ʱ���� ��==���ȼ������� 
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

//ע��������˻ʺ����ⲻͬ������������Ӳ�һ��ÿ�ж��� 
//ע�������һ��С���ɣ���line��ʼ����
void dfs(int line, int count, char * M){
	//printf("%d",k);
	if(count == k){
		num++;
	}else{
		for(int i=line; i<n; i++){   //��һ������������ж���Ч���ڶ��������n-1����Ч 
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
	
	//ͬһ��
	for(int tmp=j; tmp<n; tmp++){
		if(*(M + i*n + tmp) == 'T')
			return 0;
	} 
	for(int tmp=j; tmp>=0; tmp--){
		if(*(M + i*n + tmp) == 'T')
			return 0;
	}
	
	//ͬһ�� 
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
