//Beakjoon Online Judge #18870
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num;
    vector<int> cor;
    map<int, int> cor2;

    cin >> num;
    for(int i = 0; i<num; i++){
        int tmp;
        cin >> tmp;
        cor.push_back(tmp);
        cor2.insert({tmp, 0});
    }
    int flag = 0;
    for(auto iter = cor2.begin(); iter!=cor2.end(); iter++){
        iter->second = flag;
        flag++;
    }

    for(int i = 0; i<num; i++){
        cout << cor2.find(cor[i])->second << ' ';
    }
    return 0;
}