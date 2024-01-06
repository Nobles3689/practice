//Beakjoon Online Judge #1715
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue<int, vector<int>, greater<int>> decks;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
        int deck_num;
        cin >> deck_num;
        decks.push(deck_num);
    }
    int cost = decks.top(), res = 0, tmp1, tmp2;
    decks.pop();
    while(!decks.empty()){
        tmp1 = decks.top();
        decks.pop();
        if(!decks.empty()){
            tmp2 = tmp1 + decks.top();
            if(cost+tmp1>tmp2){
                res+=tmp2;
                decks.pop();
                decks.push(tmp2);
                continue;
            }
        }
        cost+=tmp1;
        res+=cost;
        
        
    }
    cout << res;
    return 0;
}