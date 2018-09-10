#include <stdio.h>

#define len 11 

void StraightInsertionSort(int* q, int n);   //直接插入排序 
void BinaryInsertionSort(int *q, int n);     //二分插入帕西女 
void ShellSort(int *q, int n);               //希尔排序 
void BubbleSort(int *q, int n);              //冒泡排序 
void QuickSort(int *q, int low, int high);   //快速排序 
int Partition(int *q, int low, int high);
void SelectSort(int *q, int n);              //选择排序 
int SelectMin(int *q, int low, int n);
//void HeapSort();                           //堆排序 
void MergeSort(int *q, int low, int high);   //归并排序 
void Merge(int *q, int low, int mid, int high);

int main(){
	int number[len] = {10,3,4,8,1,9,2,7,6,5,0};
	
	StraightInsertionSort(number, len);
	printf( "直接插入排序结果：\t"); 
	for(int i=0; i<len; i++){
		printf("%d ", number[i]);
	}
	putchar('\n'); 
	
	BinaryInsertionSort(number, len);
	printf("二分插入排序结果：\t"); 
	for(int i=0; i<len; i++){
		printf("%d ", number[i]);
	}
	putchar('\n'); 
	
	ShellSort(number, len);
	printf("Shell排序结果：\t\t"); 
	for(int i=0; i<len; i++){
		printf("%d ", number[i]);
	}
	putchar('\n'); 
	
	BubbleSort(number, len);
	printf("冒泡排序结果：\t\t"); 
	for(int i=0; i<len; i++){
		printf("%d ", number[i]);
	}
	putchar('\n'); 
	
	QuickSort(number, 0, len-1);
	printf("快速排序结果：\t\t"); 
	for(int i=0; i<len; i++){
		printf("%d ", number[i]);
	}
	putchar('\n'); 
	
	SelectSort(number, len);
	printf("选择排序结果：\t\t"); 
	for(int i=0; i<len; i++){
		printf("%d ", number[i]);
	}
	putchar('\n');
	
	MergeSort(number, 0, len-1);
	printf("归并排序结果：\t\t"); 
	for(int i=0; i<len; i++){
		printf("%d ", number[i]);
	}
} 

/*
*直接插入排序
*/
void StraightInsertionSort(int* q, int n){
	int tmp;
	for(int i=1; i<n; i++){
		tmp = q[i];
		int j;
		for(j=i; j>0 && tmp<q[j-1] ; j--){   //这里在有序数列中从后向前查找 
			q[j] = q[j-1];
		}
		q[j] = tmp;
	} 
}

/*
*折半插入排序 
*在插入排序的基础上改进了查找的过程 
*/
void BinaryInsertionSort(int *q, int n){
	int tmp, low, high, m;
	for(int i=1; i<n; i++){
		tmp = q[i];
		low = 0;
		high = i - 1;
		//二分查找 
		while(low <= high){
			m = (low + high) / 2;
			if(tmp < q[m])
				high = m - 1;
			else
				low = m + 1;
		}
		//移动过程 
		for(int j=i; j>=high+1; j--){
			q[j] = q[j-1];
		} 
		q[high+1] = tmp;	
	}
}

/*
*希尔排序 
*【对间隔不同增量的序列进行排序，并不断减小分量】 
*/
void ShellSort(int *q, int n){
	int tmp;
	int gap = n;
	//这里把gap当做插入排序中的1即可 
	do{
		gap = gap/3 + 1;   //选择gap 
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
*冒泡排序 
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
*快速排序【左右摇晃】 
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
*选择排序【选一个最小的放前面】 
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
*归并排序【分治的思想】 
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
	
	//这里等于的话代表这个值还未处理 
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
