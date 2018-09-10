#include <iostream>

using namespace std;

int q[1010];
int n, m;

int get_index(int num){
	for(int i=1; i<=n; i++){
		if(q[i] == num)
			return i;
	}
}

int main(){
	cin >> n >> m;
	
	for(int i=1; i<=n; i++){
		q[i] = i;
	}
	
	int p, move;
	for(int i=0; i<m; i++){
		cin >> p >> move;
		if(move > 0){
			int p_index = get_index(p);
			int tmp = q[p_index];
			int j;
			for(j=p_index+1; j<=p_index+move; j++){
				q[j-1] = q[j];
			}
			q[j-1] = tmp;
		}else if(move < 0){
			int p_index = get_index(p);
			int tmp = q[p_index];
			int j;
			for(j=p_index-1; j>=p_index+move; j--){
				q[j+1] = q[j];
			}
			q[j+1] = tmp;
		}	
	}
	for(int i=1; i<=n; i++){
		cout << q[i] << " ";
	}
	cout << endl;
}
