//Beakjoon Online Judge #2263
#include <iostream>
#include <vector>
using namespace std;

vector<int> order(100001);
vector<int> inorder;
vector<int> postorder;


void findroot(pair<int, int> i_range, pair<int, int> r_range){
    pair<int, int> i_left, i_right, r_left, r_right;
    int root = postorder[r_range.second];
    cout << root << ' ';
    i_left.first = i_range.first;
    i_left.second = order[root] - 1;
    i_right.first = order[root] + 1;
    i_right.second = i_range.second;
    int il = i_left.second - i_left.first + 1;
    int ir = i_right.second - i_right.first + 1;
    if(il > 0){
        
        r_left.second = r_range.second - 1 - ir;
        r_left.first = r_left.second + 1 - il;
        findroot(i_left, r_left);
    }
    if(ir > 0){
        
        r_right.second = r_range.second - 1;
        r_right.first = r_range.second - ir;
        findroot(i_right, r_right);
    }

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int tmp;
    for(int i = 0; i<n; i++){
        cin >> tmp;
        inorder.push_back(tmp);
        order[tmp] = i;
    }
    for(int i = 0; i<n; i++){
        cin >> tmp;
        postorder.push_back(tmp);
        
    }
    findroot({0, n-1}, {0, n-1});
    return 0;

}