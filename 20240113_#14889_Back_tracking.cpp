//Beakjoon Online Judge #14889
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define MAX 1000000000

int N;
int M = MAX;
int sheet[21][21];
bool visit[21];
vector<int> tmp;

void backtrack(int a){
    int m = N/2;
    if(tmp.size() == 1 && tmp.back() != 1) return;
    if(tmp.size() == m){
        int a = 0, b = 0;
        for(int i = 1; i <= N; i++){
            if(visit[i]){
                for(int j = 1; j<=N; j++){
                    if(j!=i&&visit[j]) a+=sheet[i][j];
                }
            }else{
                for(int j = 1; j<=N; j++){
                    if(j!=i&&!visit[j]) b+=sheet[i][j];
                }
            }
            
        }
        int tmp_cal = abs(a-b);
        if(M>tmp_cal) M = tmp_cal;
        return;
    }

    for(int i = a; i <= N; i++){
        tmp.push_back(i);
        visit[i] = true;
        backtrack(i+1);
        tmp.pop_back();
        visit[i] = false;
        
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            cin >> sheet[i][j];
        }
    }
    backtrack(1);
    cout << M;
}