//Beakjoon Online Judge #10828
#include <iostream>
#include <string>
using namespace std;

void sPush(int* stack, int num, int& index){
    index++;
    stack[index] = num;
    
    //return index;
}

int sPop(int* stack, int& index){
    int result;
    if(index<0){
        return -1;
    }else{
        result = stack[index];
        index--;
        return result;
    }
}

int sSize(int* stack, int& index){
    return index+1;
}

int sEmpty(int* stack, int& index){
    if(index<0){
        return 1;
    }else{
        return 0;
    }
}

int sTop(int* stack, int& index){
    if(index<0){
        return -1;
    }else{
        return stack[index];
    }
}

int main(){
    int cmdNum;
    int stack[10000];
    int result[10000];
    int index = -1;
    int num, flag = 0;
    string cmd;
    cin >> cmdNum;
    for(int i=0; i<cmdNum; i++){
        cin >> cmd;
        if(cmd == "push"){
            cin >> num;
            sPush(stack, num, index);
        }else if(cmd == "pop"){
            result[flag] = sPop(stack, index);
            flag++;
        }else if(cmd == "size"){
            result[flag] = sSize(stack, index);
            flag++;
        }else if(cmd == "empty"){
            result[flag] = sEmpty(stack, index);
            flag++;
        }else if(cmd == "top"){
            result[flag] = sTop(stack, index);
            flag++;
        }
    }
    for(int i=0; i<flag; i++){
        cout << result[i];
        if(i<flag-1){
            cout << '\n';
        }
    }
    return 0;
}