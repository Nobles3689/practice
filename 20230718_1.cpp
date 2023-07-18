//Beakjoon Online Judge #5430
#include <iostream>
#include <vector>
#include <string>
#include <deque>
using namespace std;


int main(){
    deque<int> d;
    vector<int> res;
    int num;
    char tmp;
    int list;
    int lNum;
    
    cin >> num;
    for(int i = 0; i<num; i++){
        string cmd;
        int flag = 1;
        cin >> cmd;
        cin >> lNum;
        cin >> tmp;
        for(int j = 0; j<lNum; j++){
            cin >> list >> tmp;
            d.push_back(list);
        }
        if(lNum==0){
            cin >> tmp;
        }
        for(int j = 0; j<cmd.length(); j++){//함수수행
            if(cmd[j]=='R'){
                flag = flag * -1;
            }else if(cmd[j]=='D'){
                if(d.empty()){
                    flag = 0;
                    break;
                }
                else if(flag == 1){
                    d.pop_front();
                }else if(flag == -1){
                    d.pop_back();
                }
            }
        }
        
        if(flag == 0){
            res.push_back(0);
        }else if(flag == 1){
            res.push_back(-1);
            while (!d.empty())
            {
                res.push_back(d.front());
                d.pop_front();
            }
            res.push_back(-2);
        }else{
            res.push_back(-1);
            while (!d.empty())
            {
                res.push_back(d.back());
                d.pop_back();
            }
            res.push_back(-2);
        }
               
    }
    for(int i = 0; i<res.size(); i++){
        if(res[i]==0){
            cout << "error\n";
        }else if(res[i] == -1){
            cout << '[';
        }else if(res[i]==-2){
            cout << "]\n";
        }else if(res[i+1] == -2){
            cout << res[i];
        }else{
            cout << res[i] << ',';
        }
    }
    return 0;
}