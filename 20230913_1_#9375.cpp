//Beakjoon Online Judge #9375
#include <iostream>
#include <map>
#include <vector>
#include <sstream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin >> test;
    for(int z = 0; z<test; z++){
        int num;
        cin >> num;
        map<string, vector<string>> m;
        for(int i = 0; i<num; i++){
            string tmp1, tmp2;
            cin >> tmp1 >> tmp2;
            if(m.find(tmp2)!=m.end()){
                m[tmp2].push_back(tmp1);
            }else{
                vector<string> v;
                v.push_back(tmp1);
                m.insert({tmp2, v});
            }
        }
        int ans = 1;
        for(auto iter = m.begin(); iter!=m.end(); iter++){
            ans = ans*(iter->second.size() + 1);
        }
        cout << ans-1 << '\n';
    }
    return 0;
}