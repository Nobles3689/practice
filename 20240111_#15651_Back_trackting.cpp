//Beakjoon Online Judge #15651
#include <iostream>
#include <vector>
using namespace std;

int list[7] = { 1, 2, 3, 4, 5, 6, 7 };
int N, M;
vector<int> tmp;

void backtrack(){
    if(tmp.size() == M){
        for(int i = 0; i < M; i++){
            cout << tmp[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = 0; i < N; i++){
        tmp.push_back(list[i]);
        backtrack();
        tmp.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    backtrack();
    return 0;

}