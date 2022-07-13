#include<iostream>
#include<string>
#include"users.cpp"

using namespace std;

class Cases {
    public:
        char state[20],city[20],total_cases[20],active_cases[20],recovered[20],deaths[20];
};

int no_of_records(char s[100]){
    fstream file;
    file.open(s,ios::in);
    int counter=0;
    char buffer[120];
    while(!file.eof()){
        file.getline(buffer,120,'\n');
        counter ++;
    }
    return counter;
}
void update_city(){
    Cases update[2];
    char s[100] = "city_data.txt";
    int count = no_of_records(s);
    cout << "\nEnter State: ";
    cin >> update[0].state;
    cout << "\nEnter City: ";
    cin >> update[0].city;
    cout << "\nEnter details for today\n";
    cout << "\nEnter New Cases: ";
    cin >> update[0].active_cases;
    cout << "\nEnter Recovered: ";
    cin >> update[0].recovered;
    cout << "\nEnter Deaths: ";
    cin >> update[0].deaths;

    fstream city_update,temp;

    city_update.open("city_data.txt",ios::in);
    temp.open("cityout.txt",ios::app);
    int total,active,recover,death;
    while((count--)!=1){
        city_update.getline(update[1].state,20,'|');
        city_update.getline(update[1].city,20,'|');
        city_update.getline(update[1].total_cases,20,'|');
        city_update.getline(update[1].active_cases,20,'|');
        city_update.getline(update[1].recovered,20,'|');
        city_update.getline(update[1].deaths,20,'\n');
        if(!strcmp(update[0].city,update[1].city)){
            total = atoi(update[1].total_cases) + atoi(update[0].active_cases) ;
            active = atoi(update[1].active_cases) - (atoi(update[0].recovered) + atoi(update[0].deaths));
            recover = atoi(update[1].recovered) + atoi(update[0].recovered);
            death = atoi(update[1].deaths) + atoi(update[0].deaths);
            temp << update[1].state << "|" << update[0].city << "|" << total << "|" << active << "|" << recover << "|" << death << "\n";
        }
        else{
        temp << update[1].state << "|" << update[1].city << "|" << update[1].total_cases << "|" << update[1].active_cases << "|" << update[1].recovered << "|" << update[1].deaths << "\n";
        }
    }
    city_update.close();
    temp.close();
    remove("city_data.txt");
    rename("cityout.txt","city_data.txt");
}

void update_state(char *state_name){
    cout << "Updated";
}



void insert_cases(){
    Cases insert;
    fstream city,state,buff;
    char s_name[20],buffer[80];
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
            state.getline(buffer,80,'\n');
            cout << s_name << " " << insert.state << endl;
            if(!(strcmp(s_name,insert.state))){
                update_state(s_name);
                break;
            }
            // else{
            //     state.close();
            //     buff.open("state_data.txt",ios::app);
            //     buff << insert.state << "|" << insert.total_cases << "|" << insert.active_cases << "|"<< insert.recovered << "|"<< insert.deaths << "\n";
            //     buff.close();
            //     break;
            // }
        }
        if(strcmp(s_name,insert.state)){
            state.close();
            buff.open("state_data.txt",ios::app);
            buff << insert.state << "|" << insert.total_cases << "|" << insert.active_cases << "|"<< insert.recovered << "|"<< insert.deaths << "\n";
            buff.close();
        }
        city << insert.state << "|" << insert.city << "|" << insert.total_cases << "|" << insert.active_cases << "|"<< insert.recovered << "|"<< insert.deaths << "\n";
    }
    state.close();
    city.close();
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
    cout << "\n1. Insert Record\n2. Update City Details\n4. Exit\n";
    cout << "\nEnter your choice: ";
    cin >> choice;
    switch(choice){
        case 1: insert_cases();
        break;
        case 2: update_city();
        break;
        case 4: exit(1);
        default: cout << "\nInvalid Choice";
        }
    }
}