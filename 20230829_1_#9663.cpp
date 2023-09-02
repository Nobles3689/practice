//Beakjoon Online Judge #9663 (브루트포스 알고리즘 백트레킹)
#include <iostream>
#include <vector>
using namespace std;

int n;
bool row[15];
bool col[15];
bool p_dia[30];
bool m_dia[30];

bool check(int x, int y){
    if(row[x])
        return true;
    if(col[y])
        return true;
    if(p_dia[x+y])
        return true;
    if(m_dia[n+x-y-1])
        return true;
    return false;
}

int find(int r){
    if(r==n){
        return 1;
    }

    int tmp = 0;

    for(int i = 0; i<n; i++){
        if(!check(r, i)){
            row[r] = true;
            col[i] = true;
            p_dia[r+i] = true;
            m_dia[n+r-i-1] = true;
            tmp += find(r+1);
            row[r] = false;
            col[i] = false;
            p_dia[r+i] = false;
            m_dia[n+r-i-1] = false;
        }
    }
    return tmp;
} 


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    cout << find(0);
    return 0;

}