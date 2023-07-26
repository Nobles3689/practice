//Beakjoon Online Judge #10816
#include <iostream>
#include <map>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int Num, tmp;
    cin >> Num;
    map<int, int> sCard;
    for(int i = 0;  i<Num; i++){
        cin >> tmp;
        if(sCard.find(tmp) != sCard.end()) sCard[tmp] += 1;
        else sCard.insert({tmp, 1});
    }
    cin >> Num;
    for(int i = 0; i<Num; i++){
        cin >> tmp;
        cout << sCard[tmp] << ' ';
    }

    return 0;
}