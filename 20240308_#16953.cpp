//Beakjoon Online Judge #16953
#include <bits/stdc++.h>
using namespace std;

int A, B;

int cal(){
    queue<pair<int, int>> q;
    q.push({A, 0});
    while (!q.empty())
    {
        int num = q.front().first;
        int cnt = q.front().second + 1;
        q.pop();
        if(num>B) continue;

        if(num>500000000) continue;
        int tmp_num = num*2;
        if(tmp_num == B) return cnt+1;
        q.push({tmp_num, cnt});
        if(num>100000000) continue;
        tmp_num = (num*10)+1;
        if(tmp_num == B) return cnt+1;
        q.push({tmp_num, cnt});
    }
    return -1;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> A >> B;
    cout << cal();
    return 0;
}