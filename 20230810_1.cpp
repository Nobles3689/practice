//Beakjoon Online Judge #1932
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int tri[500][500];
int DP[500][500];

int Max(int a, int b){
    return a > b ? a : b;
}

int trisum(int s_index, int max, int l_index){
    int sum = 0;
    if(s_index>=max) return 0;
    if(DP[s_index][l_index]!=0) return DP[s_index][l_index];
    sum += Max(trisum(s_index+1, max, l_index), trisum(s_index+1, max, l_index+1));

    return DP[s_index][l_index] = sum + tri[s_index][l_index];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num;
    cin >> num;
    for(int i = 0; i<num; i++){
        for(int j = 0; j<i+1; j++){
            cin >> tri[i][j];
        }
    }
    cout << trisum(0, num, 0);
    return 0;
}