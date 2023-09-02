//Beakjoon Online Judge #1620
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main(){
    int num, quiz_num;
    string poke;
    string tmp;
    map<int, string> list;
    map<string, int> list2;
    vector<string> res;
    cin >> num >> quiz_num;
    for(int i=1; i<num+1; i++){
        cin >> poke;
        list.insert({i, poke});
        list2.insert({poke, i});

    }
    for(int i=0; i<quiz_num; i++){
        cin >> tmp;
        int key = atoi(tmp.c_str());
        if(key != 0 || tmp.compare("0") == 0){
            res.push_back(list.at(key));
        }else{
            res.push_back(to_string(list2.at(tmp)));
        }
    }

    for(int i=0; i<res.size(); i++){
        cout << res[i] << '\n';
    }
    return 0;

}