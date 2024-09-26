//Beakjoon Online Judge
#include <bits/stdc++.h>
using namespace std;

int N, M, tmp;
vector<int> num;
bool is_in[10001];
int res[8];
void print_seq(int cnt, int idx){
    if(cnt>=M){
        for(int i = 0; i<M; i++){
            cout << res[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = idx; i<num.size(); i++){
        res[cnt] = num[i];
        print_seq(cnt+1, i);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i<N; i++){
        cin >> tmp;
        if(!is_in[tmp]){
            num.push_back(tmp);
            is_in[tmp] = true;
        }
    }
    sort(num.begin(), num.end());

    print_seq(0, 0);
    return 0;
}