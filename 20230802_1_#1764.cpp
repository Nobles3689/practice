//Beakjoon Online Judge #1764
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
    int k, m;
    map<string, int> km;
    cin >> k >> m;
    for(int i = 0; i<k; i++){
        string tmp;
        cin >> tmp;
        km.insert({tmp, 1});
    }
    int flag = 0;
    for(int i = 0; i<m; i++){
        string tmp;
        cin >> tmp;
        auto iter = km.find(tmp);
        if(iter!=km.end()){
           iter->second = 2;
           flag++;
        }
    }
    cout << flag << '\n';
    for(auto iter = km.begin(); iter!=km.end(); iter++){
        if(iter->second==2){
            cout << iter->first << '\n';
        }
    }

    return 0;
}