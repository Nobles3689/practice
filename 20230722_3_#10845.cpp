//Beakjoon Online Judge #10845
#include <iostream>
#include <string>
using namespace std;

class Queue{
public:
    int fIndex;
    int bIndex;
    int que[10000];
    Queue(){
        fIndex = 0;
        bIndex = -1;
    }

    void push(int x);
    int pop();
    int size();
    int empty();
    int front();
    int back();
};

void Queue::push(int x){
    bIndex++;
    que[bIndex] = x;
}

int Queue::pop()
{   
    if(fIndex>bIndex){
        return -1;
    }else{
        int tmp = que[fIndex];
        fIndex ++;
        return tmp;
    }
}

int Queue::size(){
    return bIndex-fIndex+1;
}

int Queue::empty(){
    if(fIndex>bIndex){
        return 1;
    }else{
        return 0;
    }
}

int Queue::front(){
    if(fIndex>bIndex){
        return -1;
    }else{
        return que[fIndex];
    }
}

int Queue::back(){
    if(fIndex>bIndex){
        return -1;
    }else{
        return que[bIndex];
    }
}


int main(){
    int num;
    string cmd;
    int tmp;
    Queue que;
    cin >> num;
    for(int i = 0; i<num; i++){
        cin >> cmd;
        if(!cmd.compare("push")){
            cin >> tmp;
            que.push(tmp);
        }else if(!cmd.compare("pop")){
            cout << que.pop() << '\n';
        }else if(!cmd.compare("size")){
            cout << que.size() << '\n';
        }else if(!cmd.compare("empty")){
            cout << que.empty() << '\n';
        }else if(!cmd.compare("front")){
            cout << que.front() << '\n';
        }else if(!cmd.compare("back")){
            cout << que.back() << '\n';
        }
    }
    return 0;
}