//Beakjoon Online Judge # 11279
#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num;
    cin >> num;
    priority_queue<int> pq;
    for(int i = 0; i<num; i++){
        int tmp;
        cin >> tmp;
        if(tmp==0){
            if(pq.empty()){
                cout << 0 << '\n';
            }else{
                cout << pq.top() << '\n';
                pq.pop();
            }
        }else{
            pq.push(tmp);
        }
    }
    return 0;
}