
/*
���ﳢ�Բ��ö�̬�滮�ķ������������ 


#include <stdio.h>
#include <string.h>

int legal(char c){
	if((c >='0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return 1;
	return 0;
}

int start=0, max_len=0;

//����������У����� 
void get_huiwen(char* s){
	int dp[500][500];
	memset(dp, 0, 500*500);
	for(int i=0; i<strlen(s); i++){
		dp[i][i]=1;    //ע������ѭ���������j=i-1��Ҫ�������������ϸ�ڣ���Ȼi==j��������ǲ���,j=i���� 
		for(int j=i-1; j>=0; j--){
			if(i - j < 2)
				dp[j][i] = (s[j] == s[i]);         //dp[j][i]��ʾj-i�Ƿ�Ϊ���� 
			else
				dp[j][i] = (s[j] == s[i] && dp[j+1][i-1]);
			if(dp[j][i] && max_len < i-j+1){
				max_len = i-j+1;
				start = j;
			}
		}
	}
}

//����������У������� 
void get_sub_huiwen(char* s){
	int dp[500][500];
	memset(dp, 0, 500*500);
	for(int i=0; i<strlen(s); i++){
		dp[i][i] = 1;
		for(int j=i-1; j>=0; j--){
			if(s[i] == s[j])
				dp[j][i] = dp[j+1][i-1] + 2;
			else
				dp[j][i] = (dp[j+1][i] > dp[j][i-1] ? dp[j+1][i] : dp[j][i-1]);
		}
	}
	printf("%d\n", dp[0][strlen(s)-1]);
} 

int main(){
	char input[510];
	char s[510];
	scanf("%s", s);
	
	get_huiwen(s);
	for(int i=start; i<start+max_len; i++){
		printf("%c", s[i]);
	}
	
	get_sub_huiwen(s);
} 
*/ 


//��������������չ�ķ�������Ϊ��֪�������ַ������������Ȼ���ż�����ȶ����鷳 
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int legal(char c){
	if((c >='0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return 1;
	return 0;
}

int main(){
	char s[5010];
	scanf("%s", s);
	
	int m=0, n=0, Max=0;
	//�Ӵ�Ϊż�� 
	for(int i=0; i<strlen(s); i++){
		int flag = 0;
		int left = i;
		int right = i + 1;
		
		while(legal(s[left]) == 0){
			left--;
			if(left < 0)
				flag = 1;
		}
		if(flag) continue;
		while(legal(s[right]) == 0){
			right++;
			if(right >= strlen(s))
				flag = 1;
		}
		if(flag) continue;	
		while(left >= 0 && right < strlen(s) && tolower(s[left]) == tolower(s[right])){
			if(right - left + 1> Max){
				Max = right - left + 1;
				m = left;
				n = right;
			}
			left--;
			right++;
		}
	}
	//�Ӵ�Ϊ���� 
	for(int i=0; i<strlen(s); i++){
		int flag = 0;
		int left = i - 1;   //�Ӵ�Ϊ����  
		int right = i + 1;
		
		while(legal(s[left]) == 0){
			left--;
			if(left < 0)
				flag = 1;
		}
		if(flag) continue;
		while(legal(s[right]) == 0){
			right++;
			if(right >= strlen(s))
				flag = 1;
		}
		if(flag) continue;	
		while(left >= 0 && right < strlen(s) && tolower(s[left]) == tolower(s[right])){
			if(right - left + 1> Max){
				Max = right - left + 1;
				m = left;
				n = right;
			}
			left--;
			right++;
		}
	}
	
	for(int i=m; i<=n; i++){
		printf("%c", s[i]);
	}
}

