//Beakjoon Online Judge - Time Complexity
#include <iostream>
using namespace std;

class Time_Complexity
{

public:
    int n;
    int level;
    int a1, a0, c, n0;

    Time_Complexity();
    ~Time_Complexity();
    void setLevel(int lv);
    void cal();
    void init();
};

Time_Complexity::Time_Complexity()
{
}


Time_Complexity::~Time_Complexity()
{
}

void Time_Complexity::setLevel(int lv){
    level = lv;
}

void Time_Complexity::init(){
    if(level == 7)
        cin >> a1 >> a0 >> c >> n0;
    else
        cin >> n;
}

void Time_Complexity::cal(){
    unsigned long long res = n;
    switch (level)
    {
    case 1: //#24262
        cout << 1 << '\n' << 0;
        break;
    case 2: //#24263
        cout << res << '\n' << 1;
        break;
    case 3: //#24264
        cout << res*res << '\n' << 2;
        break;
    case 4: //#24265
        cout << (res*(res-1))/2 << '\n' << 2;
        break;
    case 5: //#24266
        cout << res*res*res << '\n' << 3;
        break;
    case 6: //#24267
        cout << (res*(res-1)*(res-2))/6 << '\n' << 3;
        break;
    case 7: //#24313
        int tmp1 = a1*n0 + a0;
        int tmp2 = c*n0;
        if(tmp1<=tmp2 && a1<=c){
            cout << 1;
        }else{
            cout << 0;
        }
        break;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    Time_Complexity TC;
    TC.setLevel(3);
    TC.init();
    TC.cal();
    return 0;
}


