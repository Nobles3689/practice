//Beakjoon Online Judge #2503
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, tmp_s, tmp_b;
string tmp, tmp1, tmp2;
int check[1000];

void init(){
    for(int i = 123; i <= 987; i++){
        tmp = to_string(i);
            
        if(tmp[0] == tmp[1] || tmp[1] == tmp[2] || tmp[0] == tmp[2]) check[i] = true;
        if(tmp[0] - '0'  == 0 || tmp[1] - '0'  == 0 || tmp[2] - '0' == 0) check[i] = true;
    }
}


void check_num(){
    int ans, strike, ball;
    cin >> ans >> strike >> ball;
    for(int i = 123; i <= 987; i++){
        tmp_s = 0;
        tmp_b = 0;
        if(!check[i]){
            tmp1 = to_string(ans);
            tmp2 = to_string(i);
            for(int j = 0; j<3; j++){
                for(int k = 0; k<3; k++){
                    if(j==k && tmp1[j] == tmp2[k]) tmp_s++;
                    if(j!=k && tmp1[j] == tmp2[k]) tmp_b++;
                }
            }
            if(tmp_s != strike || tmp_b != ball) check[i] = true;
        }
    }
    
}

void print_ans(){
    int ans = 0;
    for(int i = 123; i<=987; i++){
        if(!check[i]) ans++;
    }
    cout << ans << '\n';
}

void play(){
    init();
    for(int i = 0; i<n; i++){
        check_num();
    }
    print_ans();
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    play();
    return 0;
    
}