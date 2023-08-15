//Beakjoon Online Judge #15654, #15663
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> list;
vector<int> v;

void per(int n, int m){
    for(int i = 0; i<n; i++){
        int tmp;
        cin >> tmp;
        list.emplace_back(tmp);
        v.emplace_back(1);
    }
    sort(list.begin(), list.end());
    sort(v.begin(), v.end());
    do
    {
        for(int i = 0; i<m; i++){
            if(v[i]==1){
                cout << list[i] << ' ';
            }
        }
        cout << '\n';
        reverse(list.begin()+m, list.end());
    } while (next_permutation(list.begin(), list.end()));

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    per(n, m);
    return 0;
}