#include <iostream>

using namespace std;

int GREEDY_ACTIVITY_SELECTOR(int* s, int* f, int length){
	int k = 0;
	int A[11] = {1};
	int a_count = 1;

	for(int m=1; m < length; m++){
		if(s[m] >= f[k]){
			A[a_count] = m;
			a_count++;
			k = m;
		}
	}

	for(int i=0; i < 11; i++){
		cout << A[i] << endl;
	}

	return 0;
}

int main(int argc, char const *argv[])
{
	int s[11] = {1,3,0,5,3,5,6,8,8,2,12};
	int f[11] = {4,5,6,7,9,9,10,11,12,14,16};

	GREEDY_ACTIVITY_SELECTOR(s,f,sizeof(s)/sizeof(s[0]));

	return 0;
}