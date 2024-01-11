//Beakjoon Online Judge #15652
#include <iostream>
#include <vector>
using namespace std;

int visit[8];
int N, M;
vector<int> tmp;


void backtrack(int a){
    if(tmp.size() == M){
        for(int i = 0; i < M; i++){
            cout << tmp[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = a; i <= N; i++){
        tmp.push_back(i);
        backtrack(i);
        tmp.pop_back();
        
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    backtrack(1);
    return 0;

}