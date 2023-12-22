//Beakjoon Online Judge #1976
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class DS{
public:
    int node;
    vector<int> parent;
    vector<int> rank;
    DS(int n){
        node = n;
    }
    void init();
    int find(int u);
    void union_(int u, int v);


};

void DS::init(){
    for(int i = 0; i<=node; i++){
        parent.push_back(i);
        rank.push_back(0);
    }
}

int DS::find(int u){
    if(u == parent[u])
        return u;
    return parent[u] = find(parent[u]);
}

void DS::union_(int u, int v){
    u = find(u);
    v = find(v);

    if(u == v) return;

    if(rank[u] > rank[v])
        swap(u, v);
    
    parent[u] = v;

    if(rank[u] == rank[v])
        rank[v]++;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> plan(m);
    DS DS(n);
    DS.init();
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            int tmp;
            cin >> tmp;
            if(tmp == 1){
                DS.union_(i, j);
            }
        }
    }
    bool flag = true;
    for(int i = 0; i<m; i++){
        cin >> plan[i];
        if(i!=0){
            if(DS.find(plan[i-1]) != DS.find(plan[i])) flag = false;
        }
    }
    if(flag) cout << "YES";
    else cout << "NO";

    return 0;
}