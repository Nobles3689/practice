//Beakjoon Online Judge #14888
#include <iostream>
#include <vector>
using namespace std;
#define ANS_MIN -1000000001
#define ANS_MAX 1000000001

int N, Min = ANS_MAX, Max = ANS_MIN;
vector<int> list;
vector<int> oper_v;
vector<int> oper_tmp;
bool visit[10];

enum oper{
    oper_Plus = 0,
    oper_Minus = 1,
    oper_Times = 2,
    oper_Obelus = 3,
};

void init(){
    for(int i = 0; i<4; i++){
        int tmp;
        cin >> tmp;
        for(int j = 0; j<tmp; j++){
            oper_v.push_back(i);
        }
    }
}  

int cal(int a, int b, int o){
    int cal_res;
    switch (o)
    {
    case oper_Plus:
        cal_res = a + b;
        break;
    case oper_Minus:
        cal_res = a - b;
        break;
    case oper_Times:
        cal_res = a * b;
        break;
    case oper_Obelus:
        cal_res = a / b;
        break;
    
    }
    return cal_res;
}

void backtrack(int a, int cnt){
    if(cnt==N){
        if(a>Max) Max = a;
        if(a<Min) Min = a;
        return;
    }
    int sum = a;
    for(int i = 0; i<N-1; i++){
        if(!visit[i]){
            visit[i] = true;
            backtrack(cal(sum, list[cnt], oper_v[i]), cnt+1);
            visit[i] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    
    for(int i = 0; i<N; i++){
        int tmp;
        cin >> tmp;
        list.push_back(tmp);
    }
    init();
    backtrack(list[0], 1);
    cout << Max << '\n' << Min;
    return 0;
}