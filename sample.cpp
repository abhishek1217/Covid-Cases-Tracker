#include<iostream>
// #include<atoi>
#include<fstream>

using namespace std;

int main(){
    fstream file;
    file.open("cases.txt",ios::in);
    char some[20];
    char buffer[100];
    while(!file.eof()){
        file.getline(some,20,'|');
        cout << some << " ";
        file.getline(buffer,100,'\n');
    }
}