#include<stdio.h>
#include<string.h>

int main(){

	/*��һ�ֽⷨ��
	/*��getchar()����ȡ�ַ� 
	/*����last��¼��һ���ַ���ɾ������ո� 
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
//	//���һ���ַ���Ϊ�ո� 
//	if(count != 0){
//		printf("%d ", count-1);
//	}


	/*����Ϊ�ڶ��ֽⷨ��
	/*�����������scanf����' '���������ص� 
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
