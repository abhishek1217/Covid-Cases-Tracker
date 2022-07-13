#include<iostream>
#include<string>
#include"users.cpp"

using namespace std;

class Cases {
    public:
        char state[20],city[20],total_cases[20],active_cases[20],recovered[20],deaths[20];
};

// void insert_cases(){
//     Cases insert;
//     fstream cases;
//     int n;
//     cases.open("cases.txt",ios::app);
//     cout << "\nEnter the no of Records:  ";
//     cin >> n;
//     for(int i = 0;i < n; i++){
//         cout << "\nEnter State Name: ";
//         cin >> insert.state;
//         cout << "\nEnter City: ";
//         cin >> insert.city;
//         cout << "\nEnter Total Cases: ";
//         cin >> insert.total_cases;
//         cout << "\nEnter Active Cases: ";
//         cin >> insert.active_cases;
//         cout << "\nEnter Recovered: ";
//         cin >> insert.recovered;
//         cout << "\nEnter Deaths: ";
//         cin >> insert.deaths;
//         cases << insert.state << "|" << insert.city << "|"<< insert.total_cases << "|"<< insert.active_cases << "|"<< insert.recovered << "|"<< insert.deaths << "\n";
//     }
// }
void update(char *){
    cout << "Updated";
}
void insert_cases(){
    Cases insert;
    fstream city,state,buff;
    char s_name[20];
    int n;
    cout << "Enter number of records";
    city.open("city_data.txt",ios::app);
    cin >> n;
    for(int i=0;i<n;i++){
        cout<<"Enter state name";
        cin>>insert.state;
        state.open("state_data.txt",ios::in);
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
        while (!state.eof())
        {
            state.getline(s_name,20,'|');
            if(!(strcmp(s_name,insert.state))){
                update(s_name);
            }
            else{
                state.close();
                buff.open("state_data.txt",ios::app);
                buff << insert.state << "|" << insert.total_cases << "|" << insert.active_cases << "|"<< insert.recovered << "|"<< insert.deaths << "\n";
                buff.close();
                break;
            }
        }
        city << s_name << "|" << insert.city << "|" << insert.total_cases << "|" << insert.active_cases << "|"<< insert.recovered << "|"<< insert.deaths << "\n";
    }
    state.close();
    city.close();
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

void display(){
    fstream filebuf;
    
}

int main(){
    int choice,dummy;
    cout << "\nCovid Dump\n";
    cout << "\nThis is FS Project(not dbms)\n";
    cout << "\n1. SignUp\n2. Login\n3. Exit\n";
    while(dummy!=1){
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch(choice){
            case 1: signup();
            break;
            case 2:  if(login()){
                        cout << "\nSuccessfully Logged In";
                        dummy = 1;
                    }
                    else
                        cout <<"\nYou have entered the wrong Username or Password";
                    break;
            case 3: exit(1);
            default: cout << "\nInvalid Choice\n";
        }
    }
    while(1){
    cout << "\n1. Insert Record\n4. Exit\n";
    cout << "\nEnter your choice: ";
    cin >> choice;
    switch(choice){
        case 1: insert_cases();
        break;
        case 4: exit(1);
        default: cout << "\nInvalid Choice";
        }
    }
}