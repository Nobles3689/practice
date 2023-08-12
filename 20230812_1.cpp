//Beakjoon Online Judge #9465
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int st[2][100000];
int DP[3][100000] = { 0, };


int cal(int col){
    int ans = 0;
    for(int i = 1; i<col; i++){
        DP[0][i] = max(DP[1][i-1], DP[2][i-1]) + st[0][i];
        DP[1][i] = max(DP[0][i-1], DP[2][i-1]) + st[1][i];
        DP[2][i] = max(max(DP[0][i-1], DP[1][i-1]), DP[2][i-1]);

    }
    ans = max(max(DP[0][col-1], DP[1][col-1]), DP[2][col-1]);
    //DP[3][100000] = { 0, };
    return ans;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num;
    cin >> num;
    for(int i = 0; i<num; i++){
        int col;
        cin >> col;
        for(int j = 0; j<2; j++){
            for(int k = 0; k<col; k++){
                int tmp;
                cin >> tmp;
                st[j][k] = tmp;
                
            }
        }
        DP[0][0] = st[0][0];
        DP[1][0] = st[1][0];
        DP[2][0] = 0;
        cout << cal(col) << '\n';
    }
    return 0;
}