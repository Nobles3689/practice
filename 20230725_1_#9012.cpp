//Beakjoon Online Judge #9012
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    int num;
    string tmp;
    stack<char> PS;
    cin >> num;
    for(int i = 0; i<num; i++){
        cin >> tmp;
        int flag = 0;
        for(int j = 0; j<tmp.length(); j++){
            if(tmp[j]=='('){
                flag++;
            }else if(tmp[j]==')'){
                flag--;
            }

            if(flag<0){
                break;
            }
        }
        if(flag==0){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }

    }
    return 0;
}