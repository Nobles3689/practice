//Beakjoon Online Judge #10866
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Deque{
public:
    int fIndex;
    int bIndex;
    int deq[20001];
    Deque(){
        fIndex = 10001;
        bIndex = 10000;
    }

    void push_front(int x);
    void push_back(int x);
    int pop_front();
    int pop_back();
    int size();
    int empty();
    int front();
    int back();

};

void Deque::push_front(int x){
    fIndex--;
    deq[fIndex] = x;
}

void Deque::push_back(int x){
    bIndex++;
    deq[bIndex] = x;
}

int Deque::pop_front(){
    int result;
    if(fIndex>bIndex){
        return -1;
    }else{
        result = deq[fIndex];
        fIndex++;
        return result;
    }
}

int Deque::pop_back(){
    int result;
    if(fIndex>bIndex){
        return -1;
    }else{
        result = deq[bIndex];
        bIndex--;
        return result;
    }
}

int Deque::size(){
    return bIndex-fIndex+1;
}

int Deque::empty(){
    if(fIndex>bIndex){
        return 1;
    }else{
        return 0;
    }
}

int Deque::front(){
    if(fIndex>bIndex){
        return -1;
    }else{
        return deq[fIndex];
    }
}

int Deque::back(){
if(fIndex>bIndex){
        return -1;
    }else{
        return deq[bIndex];
    }
}

int main(){
    int num;
    int tmp;
    vector<int> ans;
    string cmd;
    Deque Deque;
    cin >> num;
    for(int i = 0; i<num; i++){
        cin >> cmd;
        if(!cmd.compare("push_front")){
            cin >> tmp;
            Deque.push_front(tmp);
        }else if(!cmd.compare("push_back")){
            cin >> tmp;
            Deque.push_back(tmp);
        }else if(!cmd.compare("pop_front")){
            ans.push_back(Deque.pop_front());
        }else if(!cmd.compare("pop_back")){
            ans.push_back(Deque.pop_back());
        }else if(!cmd.compare("size")){
            ans.push_back(Deque.size());
        }else if(!cmd.compare("empty")){
            ans.push_back(Deque.empty());
        }else if(!cmd.compare("front")){
            ans.push_back(Deque.front());
        }else if(!cmd.compare("back")){
            ans.push_back(Deque.back());
        }
    }

    for(int i = 0; i<ans.size(); i++){
        cout << ans[i] << '\n';
    }
    return 0;
}