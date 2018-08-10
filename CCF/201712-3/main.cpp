#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <string.h>
#include <sstream>
#include <map>
#include <ctype.h>
#include <algorithm>

using namespace std;

void add(long long* T);
int get_week(long long T);
vector<string> string2vector(string s, char c);

typedef struct crontab{
    string minutes;
    string hours;
    string dom;
    string mon;
    string dow;
    string action;
}crontab;

typedef struct crontab_int{
    vector<long long> minutes;
    vector<long long> hours;
    vector<long long> dom;
    vector<long long> mon;
    vector<long long> dow;
    string action;
}crontab_int;

map<string, int> week_table;
map<string, int> month_table;

void init(){
    week_table["SUN"] = 0;
    week_table["MON"] = 1;
    week_table["TUE"] = 2;
    week_table["WED"] = 3;
    week_table["THU"] = 4;
    week_table["FRI"] = 5;
    week_table["SAT"] = 6;

    month_table["JAN"] = 1;
    month_table["FEB"] = 2;
    month_table["MAR"] = 3;
    month_table["APR"] = 4;
    month_table["MAY"] = 5;
    month_table["JUN"] = 6;
    month_table["JUL"] = 7;
    month_table["AUG"] = 8;
    month_table["SEP"] = 9;
    month_table["OCT"] = 10;
    month_table["NOV"] = 11;
    month_table["DEC"] = 12;

}

int main()
{
    init();
    int n;
    long long s,t;
//    cin >> n >> s >> t;
    ifstream infile;
    infile.open("input.txt", ios::in);
    infile >> n >> s >> t;

    vector<crontab> crontab_list;
    vector<crontab_int> crontab_int_list;

    crontab crontab_tmp;
    for(int i=0; i<n; i++){
        infile >> crontab_tmp.minutes >> crontab_tmp.hours >> crontab_tmp.dom >> crontab_tmp.mon >> crontab_tmp.dow >> crontab_tmp.action;
        crontab_list.push_back(crontab_tmp);
    }

    /*
    * 对时间进行进一步处理
    */
    vector<crontab>::iterator crontab_it = crontab_list.begin();
    for(; crontab_it != crontab_list.end(); crontab_it++){
        crontab_int tmp;

        int flag = 1;

        string a = crontab_it->minutes;
        string b = crontab_it->hours;
        string c = crontab_it->dom;
        string d = crontab_it->mon;
        string e = crontab_it->dow;
        string f = crontab_it->action;


        /*minute处理
        */
        vector<long long> vec_a;             //存储a所有可能的取值
        string::size_type idex1;
        string::size_type idex2;

        if(a == "*"){
            a = "0-59";
        }
        idex1 = a.find(",");
        idex2 = a.find("-");

        if(idex1 != string::npos && idex2 != string::npos){    //,-均有
            vector<string> vec_1 = string2vector(a, ',');
            for(int i=0; i<vec_1.size(); i++){
                string::size_type idex3 = vec_1[i].find("-");
                if(idex3 != string::npos){
                    vector<string> vec_2 = string2vector(vec_1[i],'-');
                    for(int i=atoi(vec_2[0].c_str()); i<=atoi(vec_2[1].c_str()); i++){
                        vec_a.push_back(i);
                    }
                }else{
                    vec_a.push_back(atoi(vec_1[i].c_str()));
                }
            }
        }else if(idex1 == string::npos && idex2 != string::npos){    //只有-
            vector<string> vec_1 = string2vector(a, '-');
            for(int i=atoi(vec_1[0].c_str()); i<=atoi(vec_1[1].c_str()); i++){
                vec_a.push_back(i);
            }
        }else if(idex1 != string::npos && idex2 == string::npos){    //只有,
            vector<string> vec_1 = string2vector(a, ',');
            for(int i=0; i<vec_1.size(); i++){
                vec_a.push_back(atoi(vec_1[i].c_str()));
            }

        }else{  //没有,也没有-
            vec_a.push_back(atoi(a.c_str()));
        }
//            for(int i=0; i<vec_a.size();i++){
//                cout << vec_a[i];
//            }

        /*hours处理
        */
        vector<long long> vec_b;             //存储b所有可能的取值
        if(b == "*"){
            b = "0-23";
        }
        idex1 = b.find(",");
        idex2 = b.find("-");

        if(idex1 != string::npos && idex2 != string::npos){    //,-均有
            vector<string> vec_1 = string2vector(b, ',');
            for(int i=0; i<vec_1.size(); i++){
                string::size_type idex3 = vec_1[i].find("-");
                if(idex3 != string::npos){
                    vector<string> vec_2 = string2vector(vec_1[i],'-');
                    for(int i=atoi(vec_2[0].c_str()); i<=atoi(vec_2[1].c_str()); i++){
                        vec_b.push_back(i);
                    }
                }else{
                    vec_b.push_back(atoi(vec_1[i].c_str()));
                }
            }
        }else if(idex1 == string::npos && idex2 != string::npos){    //只有-
            vector<string> vec_1 = string2vector(b, '-');
            for(int i=atoi(vec_1[0].c_str()); i<=atoi(vec_1[1].c_str()); i++){
                vec_b.push_back(i);
            }
        }else if(idex1 != string::npos && idex2 == string::npos){    //只有,
            vector<string> vec_1 = string2vector(b, ',');
            for(int i=0; i<vec_1.size(); i++){
                vec_b.push_back(atoi(vec_1[i].c_str()));
            }

        }else{ //没有, 也没有-
            vec_b.push_back(atoi(b.c_str()));
        }
//        for(int i=0; i<vec_b.size();i++){
//            cout << vec_b[i];
//        }

        /*
        *day of month处理
        */
        vector<long long> vec_c;             //存储c所有可能的取值
        if(c == "*"){
            c = "1-31";
        }
        idex1 = c.find(",");
        idex2 = c.find("-");

        if(idex1 != string::npos && idex2 != string::npos){    //,-均有
            vector<string> vec_1 = string2vector(c, ',');
            for(int i=0; i<vec_1.size(); i++){
                string::size_type idex3 = vec_1[i].find("-");
                if(idex3 != string::npos){
                    vector<string> vec_2 = string2vector(vec_1[i],'-');
                    for(int i=atoi(vec_2[0].c_str()); i<=atoi(vec_2[1].c_str()); i++){
                        vec_c.push_back(i);
                    }
                }else{
                    vec_c.push_back(atoi(vec_1[i].c_str()));
                }
            }
        }else if(idex1 == string::npos && idex2 != string::npos){    //只有-
            vector<string> vec_1 = string2vector(c, '-');
            for(int i=atoi(vec_1[0].c_str()); i<=atoi(vec_1[1].c_str()); i++){
                vec_c.push_back(i);
            }
        }else if(idex1 != string::npos && idex2 == string::npos){    //只有,
            vector<string> vec_1 = string2vector(c, ',');
            for(int i=0; i<vec_1.size(); i++){
                vec_c.push_back(atoi(vec_1[i].c_str()));
            }

        }else{ //没有, 也没有-
            vec_c.push_back(atoi(c.c_str()));
        }
//        for(int i=0; i<vec_c.size();i++){
//            cout << vec_c[i];
//        }

        /*
        *month处理
        */
        vector<long long> vec_d;             //存储d所有可能的取值
        if(d == "*"){
            d = "1-12";
        }
        idex1 = d.find(",");
        idex2 = d.find("-");

        if(idex1 != string::npos && idex2 != string::npos){    //,-均有
            vector<string> vec_1 = string2vector(d, ',');
            for(int i=0; i<vec_1.size(); i++){
                if(!isalpha(vec_1[i][0])){
                    string::size_type idex3 = vec_1[i].find("-");
                    if(idex3 != string::npos){
                        vector<string> vec_2 = string2vector(vec_1[i],'-');
                        for(int i=atoi(vec_2[0].c_str()); i<=atoi(vec_2[1].c_str()); i++){
                            vec_d.push_back(i);
                        }
                    }else{
                        vec_d.push_back(atoi(vec_1[i].c_str()));
                    }
                }else{
                    string::size_type idex3 = vec_1[i].find("-");
                    if(idex3 != string::npos){
                        vector<string> vec_2 = string2vector(vec_1[i],'-');
                        transform(vec_2[0].begin(), vec_2[0].end(), vec_2[0].begin(), ::toupper);
                        transform(vec_2[1].begin(), vec_2[1].end(), vec_2[1].begin(), ::toupper);
                        for(int i=month_table[vec_2[0]]; i<=month_table[vec_2[1]]; i++){
                            vec_d.push_back(i);
                        }
                    }else{
                        transform(vec_1[i].begin(), vec_1[i].end(), vec_1[i].begin(), ::toupper);
                        vec_d.push_back(month_table[vec_1[i]]);
                    }
                }
            }
        }else if(idex1 == string::npos && idex2 != string::npos){    //只有-
            vector<string> vec_1 = string2vector(d, '-');
            if(!isalpha(d[0])){
                for(int i=atoi(vec_1[0].c_str()); i<=atoi(vec_1[1].c_str()); i++){
                    vec_d.push_back(i);
                }
            }else{
                transform(vec_1[0].begin(), vec_1[0].end(), vec_1[0].begin(), ::toupper);
                transform(vec_1[1].begin(), vec_1[1].end(), vec_1[1].begin(), ::toupper);
                for(int i=month_table[vec_1[0]]; i<=month_table[vec_1[1]]; i++){
                    vec_d.push_back(i);
                }
            }
        }else if(idex1 != string::npos && idex2 == string::npos){    //只有,
            vector<string> vec_1 = string2vector(d, ',');
            for(int i=0; i<vec_1.size(); i++){
                if(!isalpha(vec_1[i][0])){
                    vec_d.push_back(atoi(vec_1[i].c_str()));
                }else{
                    transform(vec_1[i].begin(), vec_1[i].end(), vec_1[i].begin(), ::toupper);
                    vec_d.push_back(month_table[vec_1[i]]);
                }
            }

        }else{ //没有, 也没有-
            if(isalpha(d[0])){
                transform(d.begin(), d.end(), d.begin(), ::toupper);   //转为大写
                vec_d.push_back(month_table[d]);
            }else{
                vec_d.push_back(atoi(d.c_str()));
            }
        }
//        for(int i=0; i<vec_d.size();i++){
//            cout << vec_d[i];
//        }


        /*
        *day of week处理
        */
        vector<long long> vec_e;             //存储d所有可能的取值
        if(e == "*"){
            e = "0-6";
        }
        idex1 = e.find(",");
        idex2 = e.find("-");

        if(idex1 != string::npos && idex2 != string::npos){    //,-均有
            vector<string> vec_1 = string2vector(e, ',');
            for(int i=0; i<vec_1.size(); i++){
                if(!isalpha(vec_1[i][0])){
                    string::size_type idex3 = vec_1[i].find("-");
                    if(idex3 != string::npos){
                        vector<string> vec_2 = string2vector(vec_1[i],'-');
                        for(int i=atoi(vec_2[0].c_str()); i<=atoi(vec_2[1].c_str()); i++){
                            vec_e.push_back(i);
                        }
                    }else{
                        vec_e.push_back(atoi(vec_1[i].c_str()));
                    }
                }else{
                    string::size_type idex3 = vec_1[i].find("-");
                    if(idex3 != string::npos){
                        vector<string> vec_2 = string2vector(vec_1[i],'-');
                        transform(vec_2[0].begin(), vec_2[0].end(), vec_2[0].begin(), ::toupper);
                        transform(vec_2[1].begin(), vec_2[1].end(), vec_2[1].begin(), ::toupper);
                        for(int i=week_table[vec_2[0]]; i<=week_table[vec_2[1]]; i++){
                            vec_e.push_back(i);
                        }
                    }else{
                        transform(vec_1[i].begin(), vec_1[i].end(), vec_1[i].begin(), ::toupper);
                        vec_e.push_back(week_table[vec_1[i]]);
                    }
                }
            }
        }else if(idex1 == string::npos && idex2 != string::npos){    //只有-
            vector<string> vec_1 = string2vector(e, '-');
            if(!isalpha(vec_1[0][0])){
                for(int i=atoi(vec_1[0].c_str()); i<=atoi(vec_1[1].c_str()); i++){
                    vec_e.push_back(i);
                }
            }else{
                transform(vec_1[0].begin(), vec_1[0].end(), vec_1[0].begin(), ::toupper);
                transform(vec_1[1].begin(), vec_1[1].end(), vec_1[1].begin(), ::toupper);
                for(int i=week_table[vec_1[0]]; i<=week_table[vec_1[1]]; i++){
                    vec_e.push_back(i);
                }
            }
        }else if(idex1 != string::npos && idex2 == string::npos){    //只有,
            vector<string> vec_1 = string2vector(e, ',');
            for(int i=0; i<vec_1.size(); i++){
                if(!isalpha(vec_1[i][0])){
                    vec_e.push_back(atoi(vec_1[i].c_str()));
                }else{
                    transform(vec_1[i].begin(), vec_1[i].end(), vec_1[i].begin(), ::toupper);
                    vec_e.push_back(week_table[vec_1[i]]);
                }
            }

        }else{ //没有, 也没有-
            if(isalpha(e[0])){
                transform(e.begin(), e.end(), e.begin(), ::toupper);   //转为大写
                vec_e.push_back(week_table[e]);
            }else{
                vec_e.push_back(atoi(e.c_str()));
            }
        }

//            for(int i=0; i<vec_e.size();i++){
//            cout << vec_e[i];
//        }

        tmp.minutes = vec_a;
        tmp.hours = vec_b;
        tmp.dom = vec_c;
        tmp.mon = vec_d;
        tmp.dow = vec_e;
        tmp.action = f;
        crontab_int_list.push_back(tmp);
    }

//    for(int i=0; i<crontab_int_list.size(); i++){
//        for(int j=0; j<crontab_int_list[i].dom.size(); j++){
//            cout << crontab_int_list[i].dom[j];
//        }
//        cout << endl;
//    }

    //时间模拟
    long long year, minute, hour, day, month, week;
    for(long long T = s; T <= t;){
        //匹配操作
        year = T / 100000000;
        month = (T - year * 100000000) / 1000000;
        day = (T - year * 100000000 - month * 1000000) / 10000;
        hour = (T - year * 100000000 - month * 1000000 - day * 10000) / 100;
        minute = (T - year * 100000000 - month * 1000000 - day * 10000 - hour * 100);
        week = get_week(T);

        for(int i=0; i<crontab_int_list.size(); i++){
            int flag = 0;

            for(int j1=0; j1<crontab_int_list[i].minutes.size(); j1++){
                if(crontab_int_list[i].minutes[j1] == minute){
                    flag++;
                    break;
                }
            }

            for(int j2=0; j2<crontab_int_list[i].hours.size(); j2++){
                if(crontab_int_list[i].hours[j2] == hour){
                    flag++;
                    break;
                }
            }

            for(int j3=0; j3<crontab_int_list[i].dom.size(); j3++){
                if(crontab_int_list[i].dom[j3] == day){
                    flag++;
                    break;
                }
            }

            for(int j4=0; j4<crontab_int_list[i].mon.size(); j4++){
                if(crontab_int_list[i].mon[j4] == month){
                    flag++;
                    break;
                }
            }

            for(int j5=0; j5<crontab_int_list[i].dow.size(); j5++){
                if(crontab_int_list[i].dow[j5] == week){
                    flag++;
                    break;
                }
            }

            if(flag == 5){
                cout << T << " " <<crontab_int_list[i].action << endl;
            }
        }

        add(&T);
    }


    return 0;
}

//将string按照某个字符切割成vector
vector<string> string2vector(string s, char c){
    int len = s.length();
    for(int i=0; i<len; i++){
        if(s[i] == c){
            s[i] = ' ';
        }
    }

    vector<string> ret;
    string str;
    stringstream in(s);
    while(in >> str){
        ret.push_back(str);
    }

    return ret;
}

//模拟时间流逝，注意闰月的处理
void add(long long* T){
    long long tmp = *T;
    long long year = *T / 100000000;
    long long month = (tmp - year * 100000000) / 1000000;
    long long day = (tmp - year * 100000000 - month * 1000000) / 10000;
    long long hour = (tmp - year * 100000000 - month * 1000000 - day * 10000) / 100;
    long long minute = (tmp - year * 100000000 - month * 1000000 - day * 10000 - hour * 100);

    minute++;
    if(minute==60){
        minute = 0;
        hour++;
        if(hour==24){
            hour = 0;
            //day++; //这里不注释的话20160229会出错，day的转换和minute和hour的转换略不同，hour==24即hour==0，这是进制的转换，
                     //但是日期上则不是单纯的进制，month和day类似。
            //大月
            if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month ==12){
                if(day == 31){
                    day = 1;   //day=0则相当于日期+1
                    if(month==12){
                        month = 1;
                        year++;
                    }
                }else{
                    day++;
                }
            //闰年二月
            }else if(year % 4 == 0 && month == 2){
                if(day == 29){
                    day = 1;
                    if(month==12){
                        month = 1;
                        year++;
                    }
                }else{
                    day++;
                }
            //非闰年二月
            }else if(year % 4 != 0 && month == 2){
                if(day == 28){
                    day = 1;
                    if(month==12){
                        month = 1;
                        year++;
                    }
                }else{
                    day++;
                }
            //其他小月
            }else{
                if(day == 30){
                    day = 1;
                    if(month==12){
                        month = 1;
                        year++;
                    }
                }else{
                    day++;
                }
            }
        }
    }else{
        ;
    }

    *T = year * 100000000 + month * 1000000 + day * 10000 + hour * 100 + minute;
}

//获取星期
int get_week(long long T){
    //19700101 是周四 为4
    long long year = T / 100000000;
    long long month = (T - year * 100000000) / 1000000;
    long long day = (T - year * 100000000 - month * 1000000) / 10000;

    int sum = 0;

    int run = 0;
    for(int a=1970; a<year; a++){
        if(a % 4 == 0){
            run ++;
        }
    }
    sum += (year - 1970 - run) * 365 + run * 366;

    //cout << sum;
    int run_month[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
    int norun_month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if(year % 4 == 0){
        for(int i=1; i<month; i++){
            sum += run_month[i-1];
        }
    }else{
        for(int i=1; i<month; i++){
            sum += norun_month[i-1];
        }
    }

    sum += day - 1;
    return (4 + sum) % 7;
}



