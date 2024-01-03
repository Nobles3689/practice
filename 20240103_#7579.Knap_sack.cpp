//Beakjoon Online Judge #7579
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dp[11001];
vector<pair<int, int>> list;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    int _size = 0;
    cin >> N >> M;
    list.emplace_back(make_pair(0, 0));

    for(int i = 0; i<N; i++){
        int _memory;
        cin >> _memory;
        list.emplace_back(make_pair(_memory, 0));
    }
    for(int i = 1; i<=N; i++){
        int _cost;
        cin >> _cost;
        _size += _cost;
        list[i].second = _cost;

    }

    for(int i = 1; i<=N; i++){
        for(int j = 11000; j>=0; j--){
            if(j>=list[i].second)
                dp[j] = max(dp[j], dp[j-list[i].second] + list[i].first);
        }
    }
    
    int cost=0;
 
    while(dp[cost]<M) cost+=1;
 
    cout << cost;

    return 0;

}