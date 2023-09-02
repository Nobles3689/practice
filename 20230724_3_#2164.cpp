//Beakjoon Online Judge #2164
#include <iostream>
#include <queue>
using namespace std;




int main(){
    queue<int> card;
    int num;
    cin >> num;
    for(int i = 1; i<num+1; i++){
        card.push(i);
    }

    while (card.size()>1)
    {
        card.pop();
        int tmp = card.front();
        card.pop();
        card.push(tmp);
    }

    cout << card.front();
    
}