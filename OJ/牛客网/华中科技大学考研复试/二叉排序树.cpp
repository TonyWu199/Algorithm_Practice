#include <stdio.h>

typedef struct NODE{
	int value;
	NODE * left = NULL;
	NODE * right = NULL;
}node;

void search(node* father, node* son);

int main(){
	int n;
	scanf("%d", &n);
	
	node nodes[n];
	for(int i=0; i<n; i++){
		scanf("%d", &nodes[i].value);
	}
	
	
	for(int i=0; i<n; i++){
		if(i==0){
			printf("-1\n");
			continue;
		}
		search(&nodes[0], &nodes[i]);
	}
} 

void search(node* father, node* son){
	if(son->value < father->value){
		if(father->left == NULL){
			father->left = son;
			printf("%d\n", father->value);
		}else{
			search(father->left, son);
		}
	}else if(son->value >= father->value){
		if(father->right == NULL){
			father->right = son;
			printf("%d\n", father->value);
		}else{
			search(father->right, son);
		}
	}
}
