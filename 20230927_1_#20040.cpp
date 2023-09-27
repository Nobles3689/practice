//Beakjoon Online Judge #20040
#include <iostream>
#include <vector>
using namespace std;

class DS{
public:
    int node;
    int turn;
    vector<int> parent;
    vector<int> rank;
    DS(int n){
        node = n;
        turn = 0;
    }
    void init();
    int find(int u);
    int union_(int u, int v);


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

int DS::union_(int u, int v){
    turn++;
    u = find(u);
    v = find(v);

    if(u == v) return turn;

    if(rank[u] > rank[v])
        swap(u, v);
    
    parent[u] = v;

    if(rank[u] == rank[v])
        rank[v]++;

    return 0;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int node, turn, ans;
    cin >> node >> turn;
    DS DS(node);
    DS.init();
    for(int i = 0; i<turn; i++){
        int u, v;
        cin >> u >> v;
        ans = DS.union_(u, v);
        if(ans!=0)
            break;
    }
    cout << ans;
    return 0;
}