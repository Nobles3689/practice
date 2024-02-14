//Beakjoon Online Judge #1068
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int value;
    vector<Node> child;

};

vector<vector<int>> tree(50);
bool check[50];
int input[50];

void remove(int n){
    check[n] = true;
    for(int i = 0; i<tree[n].size(); i++){
        remove(tree[n][i]);
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> input[i];
        if(input[i] != -1)
            tree[input[i]].push_back(i);
    }
    int erase_Node;
    cin >> erase_Node;
    remove(erase_Node);
    for(int i = 0; i<tree[input[erase_Node]].size(); i++){
        if(tree[input[erase_Node]][i] == erase_Node)
            tree[input[erase_Node]].erase(tree[input[erase_Node]].begin()+i);
    }
    int ans = 0;
    for(int i = 0; i<n; i++){
        if(!check[i] && tree[i].size() == 0)
            ans++;
    }
    cout << ans;
    return 0;

}