//字符串切割题目， 

#include <fstream>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

string handle_title(string line);
string handle_attri_link(string line);

int main(){
//	ifstream input_file("CCF2017-3-3para_file.txt");
	 
	string line;
	string para;
	string title;
	string list;
	string hlight;
	string link;
	int flag_para = 0;   //用来标注para的连续性 
	int flag_list = 0;   //用来标注List的连续性 
	
	//读取每行数据 
	while(getline(cin, line)){
		//行内内容的处理 
		line = handle_attri_link(line);
		//首先处理区块内容 
		if(line == ""){
			//对之前的list和para进行最后序号的添加
			if(flag_list == 1){
				cout << "</ul>\n";
				flag_list = 0;
				list = "";
			}
			else if(flag_para == 1){
				cout << "</p>\n";
				flag_para = 0;
				para = "";
			}
		}
		else if(line.find("#") != string::npos){
//			cout << "标题栏" << endl;
			title = handle_title(line);
			cout << title;
		}
		else if(line.find("*") != string::npos){
			if(flag_list == 1)
				cout << "<li>" + line.substr(1).erase(0, line.substr(1).find_first_not_of(" ")) + "<li>\n";
			else
				cout << string("<u1>\n") + "<li>" + line.substr(1).erase(0, line.substr(1).find_first_not_of(" ")) + "<li>\n";
			flag_list = 1;    //列表开始连续
		}
		else{
			if(flag_para == 1)
				cout << "\n" + line;
			else
				cout << "<p>" + line;
				
			flag_para = 1;
		} 
	}
	
	//文件读取结束
	if(flag_list == 1){
		cout << "</ul>\n\n";
		flag_list = 0;
		list = "";
	}
	else if(flag_para == 1){
		cout << "</p>\n\n";
		flag_para = 0;
		para = "";
	} 
	
}

string handle_title(string line){
	int num = count(line.begin(), line.end(), '#');
	if(num == 1)
		//find_first_not_of找到第一个不匹配的 
		return "<h1>" + line.substr(1).erase(0, line.substr(1).find_first_not_of(" ")) + "</h1>\n";
	else if(num == 2)
		return "<h2>" + line.substr(2).erase(0, line.substr(2).find_first_not_of(" ")) + "</h2>\n";
	else if(num == 3)
		return "<h3>" + line.substr(3).erase(0, line.substr(3).find_first_not_of(" ")) + "</h3>\n";
	else if(num == 4)
		return "<h4>" + line.substr(4).erase(0, line.substr(4).find_first_not_of(" ")) + "</h4>\n";
	else if(num == 5)
		return "<h5>" + line.substr(5).erase(0, line.substr(5).find_first_not_of(" ")) + "</h5>\n";
	else 
		return "<h6>" + line.substr(6).erase(0, line.substr(6).find_first_not_of(" ")) + "</h6>\n";
}

string handle_attri_link(string line){
	if(line.find("_") == string::npos && line.find("[") == string::npos)
		return line;
	
	string init_line = line;
	string attri_str = "";
	string final_str = "";
	//对强调的处理 
	if(line.find("_") != string::npos){
		int num = count(line.begin(), line.end(), '_'); //强调的数量 
		while(num){
			int index = line.find_first_of("_");
			string str_sub = line.substr(0, index);
			if(num % 2 == 0)
				attri_str += str_sub + "<em>";
			else
				attri_str += str_sub + "</em>";
			line = line.substr(index+1);
			num--;
		}
		attri_str += line;
	}
	
	string sec_string = "";
	if(attri_str != "")
		sec_string = attri_str;
	else
		sec_string = init_line;
	
	if(sec_string.find("[") != string::npos){
		int num = count(sec_string.begin(), sec_string.end(), '['); //link的数量
		while(num){
			int index_1 = sec_string.find_first_of("[");
			string str_sub_1 = sec_string.substr(0, index_1);
			string line_1 = sec_string.substr(index_1+1);
			
			int index_2 = line_1.find_first_of("]");
			string text = line_1.substr(0, index_2);
			string line_2 = line_1.substr(index_2+2);
			
			int index_3 = line_2.find_first_of(")");
			string href = line_2.substr(0, index_3);
			sec_string = line_2.substr(index_3+1);
			
			final_str += str_sub_1 + "<a href=\"" + href + "\">" + text + "</a>";
			num--;
		} 
	}
		
	final_str += sec_string;
	//对link的处理 
	return final_str; 
}
