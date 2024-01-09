//Beakjoon Online Judge #12789
#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    stack<int> s;
    int num, order = 1, flag = 0;
    cin >> num;
    s.push(num+1);
    for(int i = 0; i<num; i++){
        int tmp;
        cin >> tmp;
        while (!s.empty())
        {
            if(tmp==order){
                order++;
                tmp = 0;
            }else if(s.top() == order){
                order++;
                s.pop();
            }else{
                if(tmp != 0){
                    if(s.top()<tmp){
                        flag = 1;
                        break;
                    }else{
                        s.push(tmp);
                        break;
                    }
                }else{
                    break;
                }
                
            }
        }
        
    }
    if(flag == 0) cout << "Nice";
    else cout << "Sad";
    return 0;
}