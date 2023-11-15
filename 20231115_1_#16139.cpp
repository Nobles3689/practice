//Beakjoon Online Judge #16139
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string S;
    int num;
    vector<vector<int>> v(26, vector<int>(200001, 0));
    cin >> S >> num;
    for(int i = 0; i<26; i++){
        char a = 97+i;
        int sum = 0;
        for(int j = 0; j<S.length(); j++){
            if(S[j] == a) sum++;
            v[i][j+1] = sum;
        }
    }
    for(int j = 0; j<num; j++){
        char tmp;
        int l, r, s=0;
        cin >> tmp >> l >> r;
        s = v[tmp-97][r+1] - v[tmp-97][l];
        cout << s << '\n';
    }
    return 0;
    
}