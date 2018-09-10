#include <stdio.h>
#define maxv 1000

typedef struct stu{
	char name[20];
	int score;
}stu;

stu s[maxv];

void Sort(stu* s, int len, int type){
	if(type == 0){
		for(int i=1; i<len; i++){
			stu tmp = s[i];
			int j;
			for(j = i-1; j>=0 && s[j].score < tmp.score; j--)
				s[j+1] = s[j];
			s[j+1] = tmp;
		}
	}else if(type == 1){
		for(int i=1; i<len; i++){
			stu tmp = s[i];
			int j;
			for(j = i-1; j>=0 && s[j].score > tmp.score; j--)
				s[j+1] = s[j];
			s[j+1] = tmp;
		}
	}
	
} 

int main(){
	int n, m;
	
	while(scanf("%d %d", &n, &m) != EOF){
		for(int i=0; i<n; i++){
			scanf("%s %d", s[i].name, &s[i].score);
		}
		
		Sort(s, n, m);
		
		for(int i=0; i<n; i++){
			printf("%s %d\n", s[i].name, s[i].score);
		}
	}
} 
