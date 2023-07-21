//Beakjoon Online Judge #7785
#include <iostream>
#include <set>
#include <string>
using namespace std;


int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int num;
    cin >> num;
    set<string, greater<>> log;
    string tmp;
    string name, w_log;
    int pos;
    string sep = " ";
    for(int i = 0; i<num; i++){
        cin >> name >> w_log;
        if(log.find(name)==log.end()){
            if(!w_log.compare("enter")){
                log.insert(name);
            }
            continue;

        }else{
            if(!w_log.compare("leave")){
                log.erase(name);
            }
            continue;
        }
    }
    for(set<string>::iterator it = log.begin(); it!=log.end(); it++){
        cout << *it << '\n';
    }
    return 0;
}