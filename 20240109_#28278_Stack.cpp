//Beakjoon Online Judge #28278
#include <iostream>
#include <vector>
using namespace std;

enum Com{

    Com_push = 1,
    Com_pop = 2,
    Com_size = 3,
    Com_empty = 4,
    Com_top = 5,

};

class Stack
{
public:
    vector<int> data;
    int size = 0;
    int top = -1;

    void push_Data(int n){
        this->data.push_back(n);
        this->top = n;
        this->size++;
    }
    int pop_Data(){
        if(this->size <= 0) return -1;
        this->size--;
        int p_data = this->data.back();
        this->data.pop_back();
        this->top = this->data.back();
        return p_data;
    }
    int stack_Size(){
        return this->size;
    }

    bool isEmpty(){
        if(this->size>0) return false;
        else return true;
    }

    int top_Data(){
        if(this->size <= 0) return -1;
        return this->top;
    }

};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    Stack s;
    int n;
    cin >> n;
    for(int i = 0; i<n; i++)
    {
        int command;
        cin >> command;
        switch (command)
        {
        case Com_push:
            int d;
            cin >> d;
            s.push_Data(d);
            break;
        case Com_pop:
            cout << s.pop_Data() << '\n';
            break;
        case Com_size:
            cout << s.stack_Size() << '\n';
            break;
        case Com_empty:
            cout << s.isEmpty() << '\n';
            break;
        case Com_top:
            cout << s.top_Data() << '\n';
            break;
        }
    }
    return 0;

}