//Beakjoon Online Judge #1436
#include <iostream>
#include <vector>
using namespace std;

int find(int n){
    int tmp = 0, t_n = 0;
    while (true)
    {
        tmp++;
        string s = to_string(tmp);
        if(s.find("666")  == -1) continue;
        else{
            t_n++;
            if(t_n==n) break;
        }
    }
    return tmp;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    cout << find(n);
    return 0;
}