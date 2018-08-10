#poj 100提交 

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

void print(string s, int len);
vector<string> line[1010];
int length[200];

int main(){
//	ifstream ifile("3959para.txt");
//	if(!ifile.is_open()){
//		cerr << "Error opening file" << endl;
//		exit(-1);
//	}
	
	string s;
	string k;
	int line_num = 0;
	while(getline(cin, s)){
		//注意stringstream 的用法 
		stringstream ss;
		ss << s;
		
		int index = 0;
		while(ss >> k){
			line[line_num].push_back(k);
			length[index] = max(length[index], (int)k.size());
			index++;
		}
		line_num++;
	}
	
	for(int i=0; i<line_num; i++){
		for(int j=0; j<line[i].size(); j++){
			print(line[i][j], length[j]);
		}
		cout << endl;
	}
}

void print(string s, int len){
	int rst = len - s.size();
	cout << s;
	for(int i=0; i<=rst; i++)
		cout << " ";
}
