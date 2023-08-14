//Beakjoon Online Judge #15650
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> list;
vector<int> tmp;
/*
int com(int n, int r){
    if(n==r || r == 0) return 1;
    else return com(n-1, r-1) + com(n-1, r);
}
*/

void com(int n, int m){
    
    for(int i = 0; i<m; i++) tmp.emplace_back(1);
    for(int i = 0; i<n-m; i++) tmp.emplace_back(0);
    do{
        for(int i = 0; i<tmp.size(); i++){
            if(tmp[i]==1) cout << list[i] << ' ';
        }
        cout << '\n';

    }while(prev_permutation(tmp.begin(), tmp.end()));
    
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    for(int i = 1; i<N+1; i++){
        list.emplace_back(i);
    }

    com(N, M);
    return 0;
    
}