#include <stdio.h>
#include <malloc.h>
#include <string.h> 

/*
6
hello
hell
helloa
helk
helm
hellob
*/ 

typedef struct NODE{
	char str[100];
	NODE *left;
	NODE *right;
}node;

//a>b·µ»Ø1 
int cmp(char* a, char* b){
	if(strlen(a) == strlen(b)){
		if(strcmp(a, b) > 0)
			return 1;
		else if(strcmp(a, b) < 0)
			return 0; 
	}else if(strlen(a) > strlen(b)){
		return 1;
	}else{
		return 0;
	}
}

void insert(node* root, node* p){
	//p>root 
	if(cmp(p->str, root->str) == 1){
		if(root->right == NULL)
			root->right = p;
		else
			insert(root->right, p); 
	}else{
		if(root->left == NULL)
			root->left = p;
		else
			insert(root->left, p);
	} 
}

void PreTravel(node* root){
	if(root){
		printf("%s\n", root->str);
		PreTravel(root->left);
		PreTravel(root->right);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	char s[n][100];
	
	for(int i=0; i<n; i++){
		scanf("%s", s[i]);
	}
	
	node* root = (node*)malloc(sizeof(node));
	memcpy(root->str, s[0], strlen(s[0]));
	root->left = NULL;
	root->right = NULL;
	
	for(int i=1; i<n; i++){
		node* p = (node*)malloc(sizeof(node));
		memcpy(p->str, s[i], strlen(s[i]));
		p->left = NULL;
		p->right = NULL;
		insert(root, p);		
	}
	
	PreTravel(root);
}
