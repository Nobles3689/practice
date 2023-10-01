//Beakjoon Online Judge #1197
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
    int node, edge;
    cin >> node >> edge;
    vector<pair<int, pair<int, int>>> grap(edge);
    DS DS(node);
    DS.init();

    for(int i = 0 ; i<edge; i++){
        cin >> grap[i].second.first >> grap[i].second.second >> grap[i].first;
    }
    sort(grap.begin(), grap.end());
    for(int i = 0 ; i<edge; i++){
        DS.union_(grap[i].second.first, grap[i].second.second, grap[i].first);
    }

    cout << DS.mst;
    return 0;
}