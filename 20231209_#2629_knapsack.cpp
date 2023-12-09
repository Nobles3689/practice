//Beakjoon Online Judge #2629
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

bool DP[31][15001];
int marble[31];

void knapsack(int n, int i, int w){
    
    if( i>n || DP[i][w]) return;
    DP[i][w] = true;
    knapsack(n, i+1, w + marble[i]);
    knapsack(n, i+1, abs(w-marble[i]));
    knapsack(n, i+1, w);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> marble[i];
    }
    knapsack(n, 0, 0);

    cin >> m;
    for(int i = 0; i<m; i++){
        int tmp;
        cin >> tmp;
        if(tmp > 15000) cout << "N ";
        else if(DP[n][tmp]) cout << "Y ";
        else cout << "N ";
    }

    return 0;

}