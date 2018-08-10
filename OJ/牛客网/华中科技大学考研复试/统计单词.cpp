#include<stdio.h>
#include<string.h>

int main(){

	/*第一种解法，
	/*用getchar()来读取字符 
	/*利用last记录上一个字符来删除多余空格 
	*/
	 
//	char a[1000] = {};
//	char p = ' ';
//	char ch;
//	char last;
//	int count = 0;
//	
//	
//	while((ch = getchar()) !=  '\n'){
//		if(ch == p){
//			last = ch;
//		}else{
//			if(last == p){
//				printf("%d", count);
//				count = 0;
//			}
//			count++;
//			last = ch;
//		}	
//	}
//	
//	//最后一个字符不为空格 
//	if(count != 0){
//		printf("%d ", count-1);
//	}


	/*这里为第二种解法，
	/*巧妙地利用了scanf遇见' '会跳过的特点 
	*/

	char a[200];
	
	while(scanf("%s",a) != EOF){
		if(a[strlen(a)-1] == '.'){
			printf("%d\n", strlen(a) - 1);
		}else{
			printf("%d ", strlen(a));	
		}
	}
	
	return 0;
} 
