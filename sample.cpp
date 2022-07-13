#include<iostream>
// #include<atoi>
#include<fstream>

using namespace std;

int main(){
    fstream file;
    fstream file2;
    file.open("cases.txt",ios::in);
    file2.open("cases.txt",ios::out);
    char some[20];
    char buffer[100];
    while(!file.eof()){
        file.getline(some,20,'|');
        cout << some << " ";
    }
    file2 << "something";
}