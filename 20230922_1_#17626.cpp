//Beakjoon Online Judge #17626
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int ex[50001];
    int DP[50001] = {0, 1, };
    for(int i = 2; i<50001; i++){
        DP[i] = 4;
        int sq = sqrt(i);
        for(int j = 1; j<=sq; j++){
            DP[i] = min(DP[i], DP[i-(int)pow(j, 2)]+1);
        }
    }

    /*for(int i = 1; i<225; i++){
        ex[i] = pow(i, 2);
    }
    int num;
    cin >> num;
    int lim = sqrt(num);
    for(int i = 1; i<lim+1; i++){
        int data = num;
        int j = i;
        while (data != 0)
        {
            if(DP[i]>4)
                break;
            if(ex[j]<=data){
                data-=ex[j];
                DP[i]++;
            }
            else
                j--;

        }
        
    }

    int min = 4;
    for(int i=1; i<lim+1; i++){
        if(DP[i]<min){
            min = DP[i];
        }
    }
    */
    int target;
    cin >> target;
    cout << DP[target];
    return 0;
    
}