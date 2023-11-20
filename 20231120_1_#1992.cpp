//Beakjoon Online Judge #1992
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
vector<string> video(65);
string res = "";
int xx[4] = {0, 1, 0, 1};
int yy[4] = {0, 0, 1, 1};


char check(int n, int y, int x){
    char flag = video[y][x];
    if(n == 1) return flag;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(flag != video[y+i][x+j]) return '2';
        }
    }
    return flag;
}

string qt(int n, int y, int x){
    string ans = "";
    char c = check(n, y, x);
    if(c == '2'){
        int half = n/2;
        ans += "(";
        for(int i = 0; i<4; i++){
            ans+= qt(half, y+(half*yy[i]), x+(half*xx[i]));
        }
        ans += ")";
        return ans;
    }
    else if(c == '1') return "1";
    else return "0";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> video[i];
    }
    cout << qt(n, 0, 0);
    return 0;

}