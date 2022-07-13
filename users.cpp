#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;


string su,sp;
char username[10],passwd[10];


int signup(){
        fstream usr_info;
        usr_info.open("users.txt",ios::app);
        cout << "Enter the Username";
        cin >> su;
        usr_info << su << "|";
        cout << "\nEnter the Password";
        cin >> sp;
        usr_info << sp << "\n";
        return 0;
}

    int login(){
        fstream usr_data;
        string data;
        char un[10],pwd[10];
        cout << "\nEnter Username: ";
        cin >> username;
        cout << "\nEnter Password: ";
        cin >> passwd;
        usr_data.open("users.txt",ios::in);
        
        while(!usr_data.eof()){
            usr_data.getline(un,10,'|');
            usr_data.getline(pwd,10,'\n');
            if((strcmp(un,username) || strcmp(pwd,passwd)) == 0){
                return 1;
            }
        }
        return 0;
}