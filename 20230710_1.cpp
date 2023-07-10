#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
    ifstream file("testdata.txt");
    if(!file.is_open()){
        cerr << "Failed to read file\n";
        return 1;
    }
    string data;
    while (!file.eof())
    {
        string str;
        getline(file, str);//file에서 str로 string 읽기
        data += str + '\n';
    }
    cout << data << '\n';
    string findstr, replacestr;
    cout << "Enter a string to find : ";
    getline(cin, findstr);
    cout << "Enter a string to replace : ";
    getline(cin, replacestr);
    int flag = 0;
    int errnum = 0;
    while (flag == 0)
    {
        size_t pos = data.find(findstr, 0);
        if(pos == string::npos){
            if(errnum < 1){
                cerr << "No strings found or all replaced\n";
            }
            else{
                flag = 1;
            }
        }
        else{
            data = data.replace(pos, findstr.length(), replacestr);
            errnum++;
        }
    }
    cout << data << '\n';
    return 0;
    
    
}