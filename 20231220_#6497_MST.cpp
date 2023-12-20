//Beakjoon Online Judge #6497
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class DS{
public:
    int node;
    int mst;
    vector<int> parent;
    vector<int> rank;
    DS(int n){
        node = n;
        mst = 0;
    }
    void init();
    int find(int u);
    void union_(int u, int v, int cost);


};

void DS::init(){
    for(int i = 0; i<node; i++){
        parent.push_back(i);
        rank.push_back(0);
    }
}

int DS::find(int u){
    if(u == parent[u])
        return u;
    return parent[u] = find(parent[u]);
}

void DS::union_(int u, int v, int cost){
    u = find(u);
    v = find(v);

    if(u == v) return;

    if(rank[u] > rank[v])
        swap(u, v);
    
    parent[u] = v;
    mst+=cost;

    if(rank[u] == rank[v])
        rank[v]++;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while (true)
    {
        int node, edge;
        cin >> node >> edge;
        if(node==0 && edge==0) break;
        vector<pair<int, pair<int, int>>> grap(edge);
        DS DS(node);
        DS.init();
        int res = 0;
        for(int i = 0 ; i<edge; i++){
            cin >> grap[i].second.first >> grap[i].second.second >> grap[i].first;
            res+=grap[i].first;
        }
        sort(grap.begin(), grap.end());
        for(int i = 0 ; i<edge; i++){
            DS.union_(grap[i].second.first, grap[i].second.second, grap[i].first);
        }
        res-=DS.mst;
        cout << res << '\n';
    }
    
    
    return 0;
}