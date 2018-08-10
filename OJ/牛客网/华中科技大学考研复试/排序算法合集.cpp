#include <stdio.h>

#define len 11 

void StraightInsertionSort(int* q, int n);   //ֱ�Ӳ������� 
void BinaryInsertionSort(int *q, int n);     //���ֲ�������Ů 
void ShellSort(int *q, int n);               //ϣ������ 
void BubbleSort(int *q, int n);              //ð������ 
void QuickSort(int *q, int low, int high);   //�������� 
int Partition(int *q, int low, int high);
void SelectSort(int *q, int n);              //ѡ������ 
int SelectMin(int *q, int low, int n);
//void HeapSort();                           //������ 
void MergeSort(int *q, int low, int high);   //�鲢���� 
void Merge(int *q, int low, int mid, int high);

int main(){
	int number[len] = {10,3,4,8,1,9,2,7,6,5,0};
	
	StraightInsertionSort(number, len);
	printf( "ֱ�Ӳ�����������\t"); 
	for(int i=0; i<len; i++){
		printf("%d ", number[i]);
	}
	putchar('\n'); 
	
	BinaryInsertionSort(number, len);
	printf("���ֲ�����������\t"); 
	for(int i=0; i<len; i++){
		printf("%d ", number[i]);
	}
	putchar('\n'); 
	
	ShellSort(number, len);
	printf("Shell��������\t\t"); 
	for(int i=0; i<len; i++){
		printf("%d ", number[i]);
	}
	putchar('\n'); 
	
	BubbleSort(number, len);
	printf("ð����������\t\t"); 
	for(int i=0; i<len; i++){
		printf("%d ", number[i]);
	}
	putchar('\n'); 
	
	QuickSort(number, 0, len-1);
	printf("������������\t\t"); 
	for(int i=0; i<len; i++){
		printf("%d ", number[i]);
	}
	putchar('\n'); 
	
	SelectSort(number, len);
	printf("ѡ����������\t\t"); 
	for(int i=0; i<len; i++){
		printf("%d ", number[i]);
	}
	putchar('\n');
	
	MergeSort(number, 0, len-1);
	printf("�鲢��������\t\t"); 
	for(int i=0; i<len; i++){
		printf("%d ", number[i]);
	}
} 

/*
*ֱ�Ӳ�������
*/
void StraightInsertionSort(int* q, int n){
	int tmp;
	for(int i=1; i<n; i++){
		tmp = q[i];
		int j;
		for(j=i; j>0 && tmp<q[j-1] ; j--){   //���������������дӺ���ǰ���� 
			q[j] = q[j-1];
		}
		q[j] = tmp;
	} 
}

/*
*�۰�������� 
*�ڲ�������Ļ����ϸĽ��˲��ҵĹ��� 
*/
void BinaryInsertionSort(int *q, int n){
	int tmp, low, high, m;
	for(int i=1; i<n; i++){
		tmp = q[i];
		low = 0;
		high = i - 1;
		//���ֲ��� 
		while(low <= high){
			m = (low + high) / 2;
			if(tmp < q[m])
				high = m - 1;
			else
				low = m + 1;
		}
		//�ƶ����� 
		for(int j=i; j>=high+1; j--){
			q[j] = q[j-1];
		} 
		q[high+1] = tmp;	
	}
}

/*
*ϣ������ 
*���Լ����ͬ���������н������򣬲����ϼ�С������ 
*/
void ShellSort(int *q, int n){
	int tmp;
	int gap = n;
	//�����gap�������������е�1���� 
	do{
		gap = gap/3 + 1;   //ѡ��gap 
		for(int i=gap; i<n; i+=gap){
			tmp = q[i];
			int j=0;
			for(j=i; j>0 && tmp<q[j-1]; j-=gap){
				q[j] = q[j-gap];
			}
			q[j] = tmp;
		} 	
	}while(gap > 1);
} 

/*
*ð������ 
*/ 
void BubbleSort(int *q, int n){
	int tmp=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n-i-1; j++){
			if(q[j] > q[j+1]){
				tmp = q[j];
				q[j] = q[j+1];
				q[j+1] = tmp;
			}
		}
	}
} 

/*
*������������ҡ�Ρ� 
*/
void QuickSort(int *q, int low, int high){
	if(low < high){
		int mid = Partition(q, low, high);
		QuickSort(q, low, mid-1);
		QuickSort(q, mid+1, high);
	}	
}

int Partition(int *q, int low, int high){
	int tmp = q[low];
	while(low < high){
		while(low < high && q[high] >= tmp)
			high--;
		q[low] = q[high];
		while(low < high && q[low] <= tmp)
			low++;
		q[high] = q[low];
	}
	
	q[low] = tmp;
}

/*
*ѡ������ѡһ����С�ķ�ǰ�桿 
*/
void SelectSort(int *q, int n){
	int tmp;
	for(int i=0; i<n; i++){
		int min=SelectMin(q, i, n);
		if(q[i] != min){
			tmp = q[i];
			q[i] = min;
			min = tmp;
		}
	}
}     

int SelectMin(int *q, int low, int n){
	int min=q[low];
	for(int j=low; j<len; j++){
		if(q[j] <= min){
			min = q[j];
		}
	}
	return min;
}       

/*
*�鲢���򡾷��ε�˼�롿 
*/
void MergeSort(int *q, int low, int high){
	if(low < high){
		int mid = (low+high) / 2;
		MergeSort(q, low, mid);
		MergeSort(q, mid+1, high);
		Merge(q, low, mid, high);
	}
}    

void Merge(int *q, int low, int mid, int high){
	int t1 = low;
	int t2 = mid + 1;
	int tmp[high-low+1];
	int k=0;
	
	while(t1 <= mid && t2 <= high){
		if(q[t1] <= q[t2]){
			tmp[k++] = q[t1++];
		}else{
			tmp[k++] = q[t2++];
		}
	}
	
	//������ڵĻ��������ֵ��δ���� 
	while(t1 <= mid){
		tmp[k++] = q[t1++];
	}
	
	while(t2 <= high){
		tmp[k++] = q[t2++];
	}
	
	for(int i=0; i<high-low+1; i++){
		q[low++] = tmp[i];
	}
}
