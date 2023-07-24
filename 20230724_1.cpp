//Beakjoon Online Judge #1920
#include <iostream>
#include <set>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int num;
    set<int> list;
    cin >> num;
    for(int i = 0; i<num; i++){
        int tmp;
        cin >> tmp;
        list.insert(tmp);
    }
    cin >> num;
    for(int i = 0; i<num; i++){
        int tmp;
        cin >> tmp;
        if(list.find(tmp) == list.end()){
            cout << 0 << '\n';
        }else{
            cout << 1 << '\n';
        }
    }
    return 0;
}