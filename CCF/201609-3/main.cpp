/*
CCF 201609-3 纪念自己第三题第一次一次AC！
*/
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

typedef struct follower{
	int a;
	int health;
}follower;

typedef struct player{
	int id;
	int health;
	vector<follower> fs;
}player;

int main(){
	int n;
	cin >> n;

	player p1, p2, cur_p, op_p;
	p1.id = 1;
	p1.health = 30;
	p2.id = 2;
	p2.health = 30;

	cur_p = p1;   //将当前玩家设置为p1
	op_p = p2;    //对方玩家设置成p2
	string str;
	int a,b,c, win1=0, win2=0;
	for(int i=0; i<n; i++){
		//cout << "current_player:" << cur_p.id << endl;
		cin >> str;
		if(str == "summon"){
			cin >> a >> b >> c;
			follower temp;
			temp.a = b;
			temp.health = c;

			vector<follower>::iterator it = cur_p.fs.begin();
			cur_p.fs.insert(it+a-1, temp);

            //保存这一轮操作的结果
		    if(cur_p.id == 1){
                p1 = cur_p;
                p2 = op_p;
		    }else{
                p1 = op_p;
                p2 = cur_p;
		    }
		}else if(str == "attack"){
			cin >> a >> b;

            //当前玩家直接对对方玩家造成伤害
            if(b == 0){
                op_p.health = op_p.health - cur_p.fs[a-1].a;
                //保存这一轮操作的结果
                if(cur_p.id == 1){
                    p1 = cur_p;
                    p2 = op_p;
                }else{
                    p1 = op_p;
                    p2 = cur_p;
                }

                if(p2.health <= 0){
                    win1 = 1;
                    break;
                }
                if(p1.health <= 0){
                    win2 = 1;
                    break;
                }
                continue;
            }

            //对随从造成伤害
			cur_p.fs[a-1].health = cur_p.fs[a-1].health - op_p.fs[b-1].a;
			op_p.fs[b-1].health = op_p.fs[b-1].health - cur_p.fs[a-1].a;

            vector<follower>::iterator it1 = cur_p.fs.begin();
            vector<follower>::iterator it2 = op_p.fs.begin();
            if(cur_p.fs[a-1].health <= 0){
                cur_p.fs.erase(it1+a-1);
            }
			if(op_p.fs[b-1].health <= 0){
                op_p.fs.erase(it2+b-1);
			}

		    //保存这一轮操作的结果
		    if(cur_p.id == 1){
                p1 = cur_p;
                p2 = op_p;
		    }else{
                p1 = op_p;
                p2 = cur_p;
		    }

            if(p2.health <= 0){
                win1 = 1;
                break;
            }
            if(p1.health <= 0){
                win2 = 1;
                break;
            }
		}else if(str == "end"){   //更换操作玩家

		    //更换玩家会和
		    player tmp;
			tmp = cur_p;
			cur_p = op_p;
			op_p = tmp;
		}
	}



//    cout << "p1-" << p1.health << ":";
//	for(int i=0; i<p1.fs.size(); i++){
//        cout << p1.fs[i].a << "-" << p1.fs[i].health << endl;
//	}
//
//	cout << "p2-" << p2.health << ":";
//    for(int i=0; i<p2.fs.size(); i++){
//        cout << p2.fs[i].a << "-" << p2.fs[i].health << endl;
//	}
    int res=0;
	if(win1 || win2){
        if(win1 == 1){
            res = 1;
        }
        if(win2 == 1){
            res = -1;
        }
	}
	cout << res << endl;
	cout << p1.health << endl;
	cout << p1.fs.size() << " ";
	for(int i=0; i<p1.fs.size(); i++){
        cout << p1.fs[i].health << " ";
	}
	cout << endl;
	cout << p2.health << endl;
	cout << p2.fs.size() << " ";
    for(int i=0; i<p2.fs.size(); i++){
        cout << p2.fs[i].health << " ";
	}
}

/*
12
summon 1 100 10
summon 1 20 10
summon 1 10 10
end
summon 1 30 10
summon 2 20 10
end
attack 1 2
attack 1 0
attack 2 0
*/
