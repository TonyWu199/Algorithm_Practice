/*
*二叉树类型的题目要注意节点的初始化要分配空间！不然会卡死 
*/

#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct BinaryTree{
	char value;
	BinaryTree* left = NULL;
	BinaryTree* right = NULL;
}NODE;

//ABCDE CBADE
NODE* CreateBinaryTree(char* Pre, char* In, int length){
	if(length == 0){
		return NULL;
	}
	
	NODE* node = (NODE*)malloc(sizeof(NODE*));
	node->value = *Pre;
	int len;
	for(len=0; len < length; len++){
		if(node->value == In[len]){
			break;
		}
	}			
	node->left = CreateBinaryTree(Pre+1, In, len);
	node->right = CreateBinaryTree(Pre+len+1, In+len+1, length-len-1); 	
	
//	printf("%c\n", node->value);
	return node;	
}

void PrtPostOrder(NODE* root){
	if(root){
		//printf("left");
		PrtPostOrder(root->left);
		PrtPostOrder(root->right);
		printf("%c",root->value);
	}
}

int main(){
	NODE * root = (NODE*)malloc(sizeof(NODE*));
	char a[27], b[27];
	while(scanf("%s %s",a,b) != EOF){
		int length = strlen(a);
		root = CreateBinaryTree(a, b, length); 
		PrtPostOrder(root);
		printf("\n");
	}
	
	return 0;
} 
