#include<iostream>
#include<string>
#include"users.cpp"

using namespace std;

class Cases {
    public:
        char state[20],city[20],total_cases[20],active_cases[20],recovered[20],deaths[20];
};

void insert_cases(){
    Cases insert;
    fstream cases;
    int n;
    cases.open("cases.txt",ios::app);
    cout << "\nEnter the no of Records:  ";
    cin >> n;
    for(int i = 0;i < n; i++){
        cout << "\nEnter State Name: ";
        cin >> insert.state;
        cout << "\nEnter City: ";
        cin >> insert.city;
        cout << "\nEnter Total Cases: ";
        cin >> insert.total_cases;
        cout << "\nEnter Active Cases: ";
        cin >> insert.active_cases;
        cout << "\nEnter Recovered: ";
        cin >> insert.recovered;
        cout << "\nEnter Deaths: ";
        cin >> insert.deaths;
        cases << insert.state << "|" << insert.city << "|"<< insert.total_cases << "|"<< insert.active_cases << "|"<< insert.recovered << "|"<< insert.deaths << "\n";
    }
}

int no_of_records(){
    fstream file;
    file.open("cases.txt",ios::in);
    int counter=0;
    char buffer[120];
    while(!file.eof()){
        file.getline(buffer,120,'\n');
        counter ++;
    }
    return counter;
}

int main(){
    int choice;
    fstream display;
    display.open("cases.txt",ios::in);
    char state_name[20];
    char t_cases[20];
    int sum;
    char buffer[80];
    int record_count = no_of_records();
    int i = 0;
    display.getline(state_name,20,'|');
    display.getline(t_cases,20,'|');
    sum += atoi(t_cases);
    char state_name2[20];
    char t_cases2[20];
    while(i < record_count){
        display.getline(buffer,80,'\n');
        i++;
        display.getline(state_name2,20,'|');
        display.getline(t_cases2,20,'|');
        if(strcmp(state_name,state_name2)==0)
            sum += atoi(t_cases2);
        if(i==record_count){
            cout << "\nState\t" << "Total Cases\n";
            cout << "\n" << state_name << "\t" << sum;
            record_count--;
            i=0;
            sum=0;
        }
    }
    cout << "\nCovid Dump\n";
    cout << "\nThis is FS Project(not dbms)\n";
    cout << "\nMenu\n";
    cout << "1.SignUp\n2.Login\n3.Insert Record\n4.Exit\n";
    while(1){
    cout << "\nEnter your choice: ";
    cin >> choice;
    switch(choice){
        case 1: signup();
        break;
        case 2: login();
        break;
        case 3: insert_cases();
        break;
        case 4: exit(1);
        default: cout << "\nInvalid Choice";
        }
    }

    // signup();
    // if(login()){
    //     cout << "\nSuccessfully Logged In";
    // }
    // else
    //     cout <<"\nCant remember password also, thu";
}