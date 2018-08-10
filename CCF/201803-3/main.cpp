#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include <fstream>

using namespace std;

typedef struct RULE{
    string path[101];
    string name;
    int len;  //切割以后字符串个数
    int p;    //是否以斜杠结尾
}rule_struct;

typedef struct URL{
    string path[101];
    int len;
    int p;
}url_struct;

int check(string url);
void trans(string s1, string s2[], int &p, int &t);
int match(vector<rule_struct> rules, url_struct url, string& ret_str);
string int_judge(string str);

int main()
{
    int m,n;
    vector<rule_struct> rules;
    vector<url_struct> urls;
    string ret_str;

    //cin >> n >> m;
    // delete
//    ifstream infile;
//    infile.open("input.txt", ios::in);
    cin >> m >> n;


    //------参数读取
    string tmp1;
    string tmp2;
    for(int i=0; i<m; i++){
//        infile >> tmp1 >> tmp2;
        cin >> tmp1 >> tmp2;
        rule_struct tmp_rule;
        tmp_rule.name = tmp2;
        trans(tmp1, tmp_rule.path, tmp_rule.p, tmp_rule.len);
        rules.push_back(tmp_rule);
    }

    for(int i=0; i<n; i++){
//        infile >> tmp1;
        cin >> tmp1;
        if(!check(tmp1)){
            cout << "404" << endl;
            break;
        }
        url_struct tmp_url;
        trans(tmp1, tmp_url.path, tmp_url.p, tmp_url.len);
        urls.push_back(tmp_url);
    }
    //---------------

    vector<url_struct>::iterator url_it = urls.begin();

    for(; url_it != urls.end(); url_it++){
        if(match(rules, *url_it, ret_str)){
            cout << ret_str << endl;
        }else{
            cout << "404" << endl;
        }
    }

}


//将规则列表和某一条url传入，通过遍历规则列表来进行匹配
//这里因为长期没写c/c++将break和continue的用法混淆
int match(vector<rule_struct> rules, url_struct url, string& ret_str){
    //cout << url.path[1] << " ";
    vector<rule_struct>::iterator rules_it = rules.begin();
    for(; rules_it != rules.end(); rules_it++){
        //cout << rules_it->name << " ";
        ret_str = rules_it->name;
        int p=0,q=0;
        if(rules_it->len > url.len){
            continue;   //我擦，这里是continue不是break啊。
        }else{
            for(; p<rules_it->len && q<url.len; p++, q++){
                if(rules_it->path[p] == url.path[q]){
                    ;//cout << url.path[q] << endl;
                }else if(rules_it->path[p] == "<int>"){
                    string int2string = int_judge(url.path[q]);
                    if(int2string != "")
                        ret_str += " " + int2string;
                    else
                        break;    //<int>不匹配
                }else if(rules_it->path[p] == "<str>"){
                    ret_str += " " + url.path[q];
                }else if(rules_it->path[p] == "<path>"){
                    ret_str += " " + url.path[q++];
                    for(; q<url.len; q++){
                        ret_str += "/" + url.path[q];
                    }
                    if(url.p)
                        ret_str += "/";
                    //cout << ret_str;
                    return 1;               //必匹配
                }else{
                    break;
                }
            }
            //如果规则结尾不是<path>则两个规则结尾"/"是否有需要保持一致
            if(p == url.len && rules_it->p != url.p)
                continue;
            if(p == url.len){  //匹配到终点，结束的标志
                return 1;
            }
        }
    }

    //遍历完规则列表还没有匹配的则返回0
    return 0;
}

//判断是否为int
string int_judge(string str){
    string ret = "";
    string notint = "";
    int flag = 0;
    int len = str.length();

    for(int i=0; i<len; i++){
        if(str[i] < '0' || str[i] > '9')
            return notint;
        else{
            if(flag == 0 && str[i] == '0')
                ;
            else{
                flag = 1;
                ret += str[i];
            }
        }
    }
    return ret;
}

//源字符串，切割转换之后的字符串，结尾是否为"/"
void trans(string s1, string s2[], int &p, int &t){
    t = p = 0;
    int len = s1.length();
    if(s1[len-1] == '/')
        p = 1;
    for(int i=0; i<len; i++){
        if(s1[i] == '/')
            s1[i] = ' ';
    }

    string ss;
    stringstream in(s1);    //注意这里的stringstream的用法
    while(in >> ss){
        s2[t++] = ss;
    }
}

//检查url是否合法
int check(string url){
    int flag = 1;
    for(int i=0; i< url.size(); i++){
        if((url[i]>='a' && url[i]<='z') || (url[i]>='A' && url[i]<='Z') || (url[i]>='0' && url[i]<='9') || url[i]=='-' || url[i]=='_' || url[i] == '.' || url[i] == '/')
            ;
        else{
            flag = 0;
        }
    }
    return flag;
}
