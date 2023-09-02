//Beakjoon Online Judge #11723
#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num;
    set<int> s;
    cin >> num;
    for(int i = 0; i<num; i++){
        string flag;
        int fnum;
        cin >> flag;
        if(!flag.compare("add")){
            cin >> fnum;
            s.insert(fnum);
        }else if(!flag.compare("remove")){
            cin >> fnum;
            s.erase(fnum);
        }else if(!flag.compare("check")){
            cin >> fnum;
            cout << s.count(fnum) << '\n';
        }else if(!flag.compare("toggle")){
            cin >> fnum;
            if(s.find(fnum)!=s.end()){
                s.erase(fnum);
            }else{
                s.insert(fnum);
            }
        }else if(!flag.compare("all")){
            for(int j = 1; j<21; j++){
                s.insert(j);
            }
        }else if(!flag.compare("empty")){
            s.clear();
        }
    }

    return 0;
}