//Beakjoon Online Judge #9019
#include <iostream>
#include <queue>
#include <string>
using namespace std;

void ClearQ(queue<pair<int, string>> &q){
    queue<pair<int, string>> empty;
    swap(q, empty);
}

int cal(int num, int flag){
    int tmp = num;
    int tmp2;
    switch (flag)
    {
    case 0:
        tmp = (tmp*2)%10000;
        break;
    case 1:
        tmp-=1;
        if(tmp<0)
            tmp = 9999;
        break;
    case 2:
        tmp*=10;
        tmp2 = tmp/10000;
        tmp = (tmp%10000)+tmp2;
        break;
    case 3:
        tmp2 = tmp%10;
        tmp/=10;
        tmp+=(tmp2*1000);
        break;
    }
    return tmp;
}

string test(int ori, int res){
    queue<pair<int, string>> q;
    q.push({ori, ""});
    bool check[10001] = {false, };
    check[ori] = true;
    int num;
    int tnum;
    string ts;
    char tmp;
    while (!q.empty())
    {
        num = q.front().first;
        ts = q.front().second;
        q.pop();
        if(num == res){
            break;
        }
        
        for(int i = 0; i<4; i++){
            tnum = cal(num, i);
            if(!check[tnum]){
                tmp = i + '0';
                q.push({tnum, ts+tmp});
                check[tnum] = true;
            }
        }
    }
    ClearQ(q);
    return ts;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int testnum;
    cin >> testnum;
    for(int i = 0; i<testnum; i++){
        int origin, result;
        cin >> origin >> result;
        string res = test(origin, result);
        for(int j = 0; j<res.size(); j++){
            if(res[j] == '0'){
                cout << 'D';
            }else if(res[j] == '1'){
                cout << 'S';
            }else if(res[j] == '2'){
                cout << 'L';
            }else if(res[j] == '3'){
                cout << 'R';
            }
        }
        cout << '\n';
    }
    return 0;
}