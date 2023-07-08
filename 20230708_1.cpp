#include <iostream>
#include <string>
#include <iomanip>//스트림 제어 헤더(출력 필드 폭 조정용)
using namespace std;
int i, j, x, y, z;
string flag;
void time_table(){
    for(int k = 1; k<=9; k++){
        for(int l = x; l <= y; l++){
            cout << l << " * " << k  << " = " << setw(3) << l*k << "    ";
        }
        cout << endl;
    }
}

int main(){
    cout << "Enter the range you want the multiplication table to output (start end) : ";
    cin >> x >> y;
    cout << endl;

    if(x > y){
        cout << "The second input number is greater. Do you want me to change the start and end values and print them out (y/n)?";
        cin >> flag;
        if(flag == "y"){
            z=x;
            x=y;
            y=z;
            time_table();
        }
        else if(flag == "n"){
            cout << "Second input number must be greater. Exit the program.";
        }
        else{
            cout << "You have entered the wrong one. Please retry.";
        }
    }
    else{
        time_table();
    }
    return 0;
}

