//Beakjoon Online Judge #6497
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
    DS DS(n);
    DS.init();
    for(int i = 0; i<m; i++){
        int flag, a, b;
        cin >> flag >> a >> b;
        if(flag==0){
            if(a!=b) DS.union_(a, b); 
            
        }
        else{
            if(DS.find(a) == DS.find(b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}