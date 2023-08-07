//Beakjoon Online Judge #11724
#include <iostream>
#include <vector>
using namespace std;
vector<int> edge_v[1001];
bool visited[1001] = { false, };

void DFS(int n){
    visited[n] = true;
    for(int i=0; i<edge_v[n].size(); i++){
        if(!visited[edge_v[n][i]]){
            DFS(edge_v[n][i]);
        }
    }

}

int main(){
    
    int result = 0;
    int node, edge;
    cin >> node >> edge;
    for(int i = 0; i<edge; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        edge_v[tmp1].push_back(tmp2);
        edge_v[tmp2].push_back(tmp1);
    }

    for(int i = 1; i<node+1; i++){
        if(!visited[i]){
            result++;
            DFS(i);
        }
    }
    cout << result;
    return 0;
}