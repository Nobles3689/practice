//Beakjoon Online Judge #11478
#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(){
    
    string s_Input;
    int num;
    set<string> list;
    cin >> s_Input;
    num = s_Input.size();
    for(int i = 1; i<num+1; i++){
        for(int j = 0; j<num+1-i; j++){
            list.insert(s_Input.substr(j,i));
        }
    }
    cout << list.size();
    return 0;
}