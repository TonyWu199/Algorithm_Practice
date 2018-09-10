#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> in;

int main(){
	int n, m;
	cin >> n;

	for(int i=0; i<n; i++){
		cin >> m;
		in.push_back(m);
	}
	
	sort(in.begin(), in.end());
	
	int res;
	if(n % 2 == 0){
		int num = in[in.size() / 2];
		int left = 0, right = 0;
		for(int i=0; i<in.size(); i++){
			if(in[i] < num)
				left++;
			if(in[i] > num)
				right++;
		}
		if(left == right)
			res = num;
		else
			res = -1;
		
	}else{
		int num = in[in.size() / 2];
		int left = 0, right = 0;
		for(int i=0; i<in.size(); i++){
			if(in[i] < num)
				left++;
			if(in[i] > num)
				right++;
		}
		if(left == right)
			res = num;
		else 
			res = -1;
	}
	
	cout << res << endl;
	
	return 0;
}
