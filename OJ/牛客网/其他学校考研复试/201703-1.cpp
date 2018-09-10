#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n,k,part;
	cin >> n >> k;
	vector<int> in;
	
	for(int i=0; i<n; i++){
		cin >> part;
		in.push_back(part);
	}
	
	int per_sum = 0, p=0;
	
	for(int i=0; i<in.size(); i++){
		per_sum += in[i];
		if(per_sum >= k){
			p++;
			per_sum = 0;
		}
	}
	if(per_sum != 0){
		p++;
	}
	
	cout << p << endl;
} 
