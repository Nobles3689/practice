//동적할당
#include <iostream>
#include <string>
using namespace std;



void Merge(int* arr, int* tmparr, int left, int right){
    for(int i=left; i<=right; i++){
        tmparr[i] = arr[i];
    }

    int mid = (left+right)/2;
    int tmpleft = left;
    int tmpright = mid+1;
    int index = left;
    

    while (tmpleft<=mid&&tmpright<=right)
    {
        if(tmparr[tmpleft]<=tmparr[tmpright]){
            arr[index] = tmparr[tmpleft];
            index++;
            tmpleft++;
        }else{
            arr[index] = tmparr[tmpright];
            index++;
            tmpright++;
        }
    }
    if(tmpleft>mid){
        int remain = right - tmpright;
        for(int i = 0; i<=remain; i++){
            arr[index+i] = tmparr[tmpright+i];
        }
    }
    else{
        int remain = mid - tmpleft;
        for(int i = 0; i<=remain; i++){
            arr[index+i] = tmparr[tmpleft+i];
        }
    }
    
}

void Part(int*arr, int*tmparr, int left, int right){
    if(left<right){
        int mid = (left+right) / 2;
        Part(arr, tmparr, left, mid);
        Part(arr, tmparr, mid+1, right);
        Merge(arr, tmparr, left, right);
    }
}

int main(){
    int num;
    cout << "Please enter the number of students : ";
    cin >> num;
    int* score = new int[num];
    int* tmpscore = new int[num];
    for(int i = 0; i<num; i++){
        cout << "Please enter student score : ";
        cin >> score[i];
    }
    Part(score, tmpscore, 0, num-1);
    for(int i=0; i<num; i++){
        cout << score[i];
        if(i!=(num-1)){
            cout << '\n';
        }
    }
    delete[] score;
    delete[] tmpscore;
    return 0;

}