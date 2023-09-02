//Beakjoon Online Judge #2751
#include <iostream>
#include <set>
using namespace std;

int main(){
    int num;
    set<int> list;
    cin >> num;
    int tmp;
    for(int i = 0; i<num; i++){
        cin >> tmp;
        list.insert(tmp);
    }

    for(const auto& a : list){
        cout << a << '\n';
    }

    return 0;
}