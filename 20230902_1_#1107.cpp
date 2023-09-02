//Beakjoon Online Judge #1107
#include <iostream>
#include <vector>
#include <string>
using namespace std;


int num[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
vector<bool> b_num(10, false);
int start = 100;

int check(int num){
    string s = to_string(num);
    for(int i = 0; i<s.length(); i++){
        if(b_num[s[i]-'0']){
            return false;
        }
    }
    return true;
}

int find(int target){
    if(target==start) return 0;
    int ans = abs(target-start);
    int tmp = 0;
    for(int i = 0; i<=1000000; i++){
        if(check(i)){
            tmp = abs(i-target) + to_string(i).length();
            ans = min(ans, tmp);
        }
    }
    return ans;

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int channel, broken, broken_num;
    cin >> channel >> broken;
    
    for(int i = 0; i<broken; i++){
        cin >> broken_num;
        b_num[broken_num] = true;
    }
    
    cout << find(channel);
    return 0;
}