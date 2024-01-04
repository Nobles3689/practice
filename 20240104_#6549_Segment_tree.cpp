//Beakjoon Online Judge #6549
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 2000000000

long long seg[1000001];
long long hight[100001];
long long ans;
int N;

int init(int s, int e, int node){
    if(s==e) return seg[node] = s;
    int mid = (s+e)/2;
    int l_index = init(s, mid, node*2);
    int r_index = init(mid+1, e, node*2+1);

    return seg[node] = hight[l_index] < hight[r_index] ? l_index : r_index;
}

int find(int s, int e, int node, int l, int r){
    if(e<l || r<s) return INF;
    if(l<=s && e<=r) return seg[node];
    int mid = (s + e) / 2;
    int l_index = find(s, mid, node * 2, l, r);
    int r_index = find(mid + 1, e, node * 2 + 1, l, r);

    if(l_index == INF) return r_index;
    else if(r_index == INF) return l_index;
    else return hight[l_index] < hight[r_index] ? l_index : r_index;
}

void sol(long long s, long long e){
    if(s>e) return;

    long long index = find(0, N-1, 1, s, e);
    ans = max(ans, hight[index] * (e - s + 1));

    sol(s, index - 1);
    sol(index + 1, e);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while (true)
    {
        ans = 0;
        cin >> N;
        if(N == 0) break;
        for(int i = 0; i<N; i++){
            cin >> hight[i];
        }

        init(0, N-1, 1);
        sol(0, N-1);
        cout << ans << '\n';
    }

    return 0;
    
}