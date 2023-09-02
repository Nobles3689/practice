//Beakjoon Online Judge #1874
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    int num;
    int index = 0;
    int seq[100000];
    stack<int> st;
    int flag = 0;
    vector<char> result;

    cin >> num;
    for(int i = 0; i<num; i++){
        cin >> seq[i];
    }
    seq[num] = -1;
    for(int i = 1; i<num+2; i++){
        
        if(seq[index]>=i){
            st.push(i);
            result.push_back('+');
        }else{
            if(st.empty()){
                break;
            }else if(seq[index]==st.top()){
                st.pop();
                result.push_back('-');
                i--;
                if(seq[index] != -1){
                    index++;
                }
            }else{
                flag = -1;
                break;
            }
        }

        if(i>=num+1){
            i--;
        }
    }
    if(flag==-1){
        cout << "NO";
    }else{
        for(int i = 0; i<num*2; i++){
            cout << result[i] << '\n';
        }
    }
    return 0;
}