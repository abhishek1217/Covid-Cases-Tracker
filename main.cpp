#include<iostream>
#include<string>
#include"users.cpp"

using namespace std;

class Cases {
    public:
        string state,city;
        int total_cases,active_cases,recovered,deaths;
};


int main(){
    // signup();
    if(login()){
        cout << "\nSuccessfully Logged In";
    }
    else
        cout <<"\nCant remember password also, thu";
}