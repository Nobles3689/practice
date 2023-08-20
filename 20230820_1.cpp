//Beakjoon Online Judge #11660
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int DP[1025][1025] = { 0, };

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M, sum, tmp;
    cin >> N >> M;
    for(int i = 1; i<=N; i++){
        sum=0;
        for(int j = 1; j<=N; j++){
            cin >> tmp;
            sum+=tmp;
            DP[i][j]=sum;
        }
    }
    int x1, y1, x2, y2;

    for(int i = 0; i<M; i++){
        sum = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int j = 0; j<=x2-x1; j++){
            sum += DP[x2-j][y2] - DP[x2-j][y1-1];
        }
        cout << sum << '\n';
    }

    return 0;
}