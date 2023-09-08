//Beakjoon Online Judge #2805
#include <iostream>
#include <vector>
using namespace std;

bool check(int mid, int goal, vector<int> &tree){
    long long sum = 0;
    for(int i = 0; i<tree.size(); i++){
        if(tree[i]>mid) sum += tree[i] - mid;
    }
    return sum >= goal;
}

int bi(vector<int> &tree, int goal){
    int min = 0;
    int max = 1000000000;
    while (min+1<max)
    {
        int mid = (min+max)/2;
        if(check(mid, goal, tree)) min = mid;
        else max = mid;
    }
    return min;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num, goal;
    cin >> num >> goal;
    vector<int> tree(num);
    for(int i = 0; i<num; i++){
        cin >> tree[i];
    }
    cout << bi(tree, goal);
    return 0;
}