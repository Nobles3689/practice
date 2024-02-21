//Beakjoon Online Judge #2618
#include <bits/stdc++.h>
using namespace std;

int N, W;
pair<int, int> event[1001];
int DP[1001][1001];
int checked[1001][1001];

int dist(pair<int, int> a, pair<int, int> b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> W;

    int tmp1, tmp2;
    for(int i = 1; i<=W; i++){
        cin >> tmp1 >> tmp2;
        event[i] = make_pair(tmp1, tmp2);
    }


    for(int i = W-1; i>=0; --i){
        pair<int, int> pos1;
        if(i == 0) pos1 = make_pair(1, 1);
        else pos1 = event[i];

        for(int j = W-1; j>=0; --j){
            if(i && i == j) continue;

            pair<int, int> pos2;
            if(j == 0) pos2 = make_pair(N, N);
            else pos2 = event[j];

            int k = max(i, j) + 1;
            int dist1 = dist(pos1, event[k]) + DP[k][j];
            int dist2 = dist(pos2, event[k]) + DP[i][k];
            if(dist1 < dist2){
                DP[i][j] = dist1;
                checked[i][j] = 1;
            }else{
                DP[i][j] = dist2;
                checked[i][j] = 2;
            }
        }
    }

    cout << DP[0][0] << '\n';

    int i = 0, j = 0;
    for(int k = 1; k<=W; k++){
        if(checked[i][j] == 1){
            cout << "1\n";
            i = k; 
        }else if(checked[i][j] == 2){
            cout << "2\n";
            j = k;
        }
    }

    return 0;
}