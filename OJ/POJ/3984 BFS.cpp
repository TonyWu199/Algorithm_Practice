#include <stdio.h>

typedef struct node{
	int x;
	int y;
	int value;
	int flag;    //0Ϊδ��⣬1Ϊ���� 
	int pre;
}node;

typedef struct queue{
	node M[25];
	int front;
	int rear;
}queue;

void insert(queue* q, node n);
node out(queue* q);
int isempty(queue q);
int isvalid(node n);
void pre_print(int x, int y);
void print(node n); 

node matrix[5][5];
queue Q;

int main(){
	node final_node;
	
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			scanf("%d", &matrix[i][j].value);
			matrix[i][j].x = i;
			matrix[i][j].y = j;
			matrix[i][j].flag = 0;
		}
	}
	
	matrix[0][0].flag = 1; 
	matrix[0][0].pre = -1;
	insert(&Q, matrix[0][0]);
	
	//�����鶨�巽��ֵ��ѧϰ�� 
	int dir[4][2] = {
		{0, 1}, {1, 0},
		{0, -1}, {-1, 0}
	};
	
	while(!isempty(Q)){
		node head = out(&Q);
		//printf("%d", Q.front);
		
		//printf("current point (%d,%d)\n", head.x, head.y);
		
		//�����ܵĵ���г��� 
		for(int i=0; i<4; i++){
			if(head.x + dir[i][0] < 0 || head.x + dir[i][0] > 4 || head.y + dir[i][1] < 0 || head.y + dir[i][1] > 4)
				continue;
			
			node after_move = matrix[head.x + dir[i][0]][head.y + dir[i][1]];
			
			if(after_move.x == matrix[4][4].x && after_move.y == matrix[4][4].y){
				//printf("�����յ�\n"); 
				matrix[after_move.x][after_move.y].pre = Q.front-1;
				break;
			}
			
			if(after_move.flag == 0 && after_move.value == 0){  //λ����ͨ·��δ������ 
				//printf("���������(%d,%d)\n", after_move.x, after_move.y);
				matrix[after_move.x][after_move.y].pre = Q.front-1;
				matrix[after_move.x][after_move.y].flag = 1; 
				insert(&Q, matrix[after_move.x][after_move.y]);
			}
			
		} 
	}
	
	pre_print(4, 4);
	
	for(int i=0; i<25; i++){
		if(Q.M[i].flag == 2){
			printf("(%d, %d)\n", Q.M[i].x, Q.M[i].y);
		}
	}
	printf("(4, 4)\n");

	//���õݹ���� 
	//print(matrix[4][4]);

} 

//���1�������� 
void pre_print(int x, int y){
	if(x == 0 && y == 0){
		Q.M[0].flag = 2;
	}else{
		Q.M[matrix[x][y].pre].flag = 2;
		pre_print(Q.M[matrix[x][y].pre].x, Q.M[matrix[x][y].pre].y);
	}
} 

//���2���ݹ����
void print(node n){
	if(n.pre == -1){
		printf("(0, 0)\n");
	}else{
		print(Q.M[n.pre]);
		printf("(%d, %d)\n", n.x, n.y);
	}
}
 

//������в���Ԫ�� 
void insert(queue* q, node n){
	q->M[q->rear] = n;
	q->rear++; 
}

//���ض���ͷԪ�� 
node out(queue* q){
	return q->M[q->front++];
}

//�ж϶����Ƿ�Ϊ�� 
int isempty(queue q){
	return q.rear == q.front;
}

int isvalid(node n){
	if(n.x >=0 && n.x <=4 && n.y >=0 && n.y <=4)
		return true;
	else
		return false;
}
