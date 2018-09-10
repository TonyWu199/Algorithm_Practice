#include <stdio.h>
#include <string.h>

void print(int* direction, int x, int y, int line_length, char * s1){
	if(x == 0 || y == 0){
		return;
	}
	
	if(*(direction + x*line_length + y) == 0){
		print(direction, x-1, y-1, line_length, s1);
		printf("%c", s1[x-1]);
	}else if(*(direction + x*line_length + y) == 1){
		print(direction, x-1, y, line_length, s1);
	}else if(*(direction + x*line_length + y) == 2){
		print(direction, x, y-1, line_length, s1);
	}else if(*(direction + x*line_length + y) == 3){
		printf("(");
		print(direction, x, y-1, line_length, s1);
		printf("+");
		print(direction, x-1, y, line_length, s1);
		printf(")");
	} 
}

int main(){
	char s1[] = "ABCBDAB";
	char s2[] = "BDCABA";
	
	int l1 = strlen(s1);
	int l2 = strlen(s2);
	int direction[l1+1][l2+1]; 
	int len[l1+1][l2+1];
	
	for(int i=0; i<=l1; i++){
		for(int j=0; j<=l2; j++){
			direction[i][j] = -1;
		}
	}
	
	for(int i=0; i<=l1; i++){
		len[i][0] = 0;    //这里0表示空字符串 
	}
	
	for(int j=0; j<=l2; j++){
		len[0][j] = 0;
	}
	
	for(int i=1; i<=l1; i++){
		for(int j=1; j<=l2; j++){
			if(s1[i-1] == s2[j-1]){
				len[i][j] = len[i-1][j-1] + 1;
				direction[i][j] = 0;   //左上 
			}else if(len[i-1][j] > len[i][j-1]){
				len[i][j] = len[i-1][j];
				direction[i][j] = 1;   //上 
			}else if(len[i-1][j] < len[i][j-1]){
				len[i][j] = len[i][j-1];
				direction[i][j] = 2;   //左 
			}else if(len[i-1][j] == len[i][j-1]){
				len[i][j] = len[i][j-1];
				direction[i][j] = 3;   //左 | 上皆可 
			}
		}
	}
	
	print((int *)direction, l1, l2, l2+1, s1);	
} 
