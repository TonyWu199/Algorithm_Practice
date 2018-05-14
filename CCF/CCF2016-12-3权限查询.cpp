# �˴����ύֻ��60�֡� 

#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>

using namespace std;
/*	
	���ֽṹ��ĳ�ʼ���� 
*/ 
const int no_level = -1;
const int TRUE = -2;
const int FALSE = -3;

//Ȩ�޽ṹ�� 
struct previ{
	string previ_name;
	int level;
};
vector<previ> _previ;

struct role{
	string role_name;
	int s;    //��ɫȨ���� 
	vector<previ> r_previ;
};
vector<role> _role;

struct user{
	string user_name;
	int t;
	vector<string> u_role;
};
vector<user> _user;

string c_split_2_previ_name(string s);
int c_split_2_previ_level(string s);
int query(string name, string previlige);
int rolematch(string rl, string previlige);
int prematch(previ pre, string input_pre);

int main(){
//	ifstream para_file("CCF2016-12-3para_file.txt",ios::out|ios::app);
//	if(!para_file.is_open()){
//		cerr << "Error opening file" << endl;
//		exit(-1);
//	}
	
	previ p_tmp;
	role r_tmp;
	user u_tmp;
	string s_tmp;
	//����Ȩ����Ϣ
	int p;
//	para_file >> p;
	cin >> p; 
	for(int i=0; i<p; i++){
//		para_file >> s_tmp;
		cin >> s_tmp;	
		p_tmp.previ_name = c_split_2_previ_name(s_tmp);
		p_tmp.level = c_split_2_previ_level(s_tmp);
		_previ.push_back(p_tmp);
	}
	 
	//�����ɫ��Ϣ
	 int r;
//	 para_file >> r;
	 cin >> r;
	 for(int i=0; i<r; i++){
//	 	para_file >> r_tmp.role_name >> r_tmp.s;
		cin >> r_tmp.role_name >> r_tmp.s;
	 	
	 	for(int j=0; j<r_tmp.s; j++){
//	 		para_file >> s_tmp;
			cin >> s_tmp;
	 		//cout << s_tmp << endl;
	 		p_tmp.previ_name = c_split_2_previ_name(s_tmp);
	 		p_tmp.level = c_split_2_previ_level(s_tmp);
		 	r_tmp.r_previ.push_back(p_tmp);
		 }
		 _role.push_back(r_tmp);
		 r_tmp.r_previ.clear();
	 } 
	 
	 //�����û���Ϣ
	 int u;
//	 para_file >> u;
	 cin >> u;
	 for(int i=0; i<u; i++){
//	 	para_file >> u_tmp.user_name >> u_tmp.t;
		cin >> u_tmp.user_name >> u_tmp.t;
	 	
	 	for(int j=0; j<u_tmp.t; j++){
//	 		para_file >> s_tmp;
	 		cin >> s_tmp;
	 		u_tmp.u_role.push_back(s_tmp);
		 }
		 _user.push_back(u_tmp);
		 u_tmp.u_role.clear();    //ע�Ⱑ������Ҫ��� 
	 }	  
	  
	//�����ѯ
	int q;
//	para_file >> q;
	cin >> q;
	string Name;
	string Previlige;
	for(int i=0; i<q; i++){
//		para_file >> Name >> Previlige;
		cin >> Name >> Previlige;
		int ans = query(Name, Previlige); 
		
		if(ans == TRUE)
			cout << "true" << endl;
		else if(ans == FALSE)
			cout << "false" << endl;
		else
			cout << ans;
	}
}

string c_split_2_previ_name(string s){
	int pos = s.find(":");
	
	//find�������Ҳ���ָ��ֵ������»᷵��string::npos
	if(pos == (int)string::npos)
		return s;
	else
		return s.substr(0, pos);
}

int c_split_2_previ_level(string s){
	int pos = s.find(":");
	
	//find�������Ҳ���ָ��ֵ������»᷵��string::npos
	if(pos == (int)string::npos)
		return no_level;
	else
		//ע�������c_str��ת�� 
		return atoi(s.substr(pos+1, s.length()-1).c_str());
}

int prematch(previ pre, string input_pre){
	if(pre.previ_name != c_split_2_previ_name(input_pre))
		return FALSE;
	//�ֵȼ���ѯ 
	if(input_pre.find(":") != string::npos){
		if(pre.level == no_level)
			return TRUE;
		else{
			if(pre.level >= c_split_2_previ_level(input_pre))
				return TRUE;
			else
				return FALSE;
		} 
	}
	//���ֵȼ���ѯ 
	else{
		if(pre.level == no_level)
			return TRUE;
		else
			return pre.level;
	} 
}

int rolematch(string role, string previlige){
	int ans = FALSE;
	
	string pre_str = c_split_2_previ_name(previlige);
	for(int i=0; i<_role.size(); i++){
		if(_role[i].role_name == role){
			for(int j=0; j<_role[i].r_previ.size(); j++){
				if(_role[i].r_previ[j].previ_name == pre_str){
					int ret = prematch(_role[i].r_previ[j], previlige);
					if(ret > ans)
						ans = ret;
				}
			}
		}
	}
	return ans;
}

int query(string name, string previlige){
	for(int i=0; i<_user.size(); i++){
		//�û��б�������������û��� 
		if(_user[i].user_name == name){
			int ans = FALSE;
//			cout << "----" << name << endl;
			for(int j=0; j<_user[i].t; j++){
				int ret = rolematch(_user[i].u_role[j], previlige);
				if(ret > ans)
					ans = ret;
			}
			return ans;
		}
	}
	return FALSE;
}
