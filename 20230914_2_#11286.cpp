//beakjoon Online Judge #11286
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct Abs_cmp{
    bool operator()(int a, int b) {
        if(abs(a) == abs(b)){
            return a > b;
        }else{
            return abs(a) > abs(b);
        }
    }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num;
    cin >> num;
    priority_queue<int, vector<int>, Abs_cmp> pq;
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