#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include"users.cpp"

using namespace std;

class Cases {
    public:
        char state[20],city[20],total_cases[20],active_cases[20],recovered[20],deaths[20];
};


//Function to get number of records a particular file.
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

void display_states(){
    Cases display_state;
    fstream f;
    f.open("state_data.txt",ios::in);
    // cout << "\n\nState\t\t\tTotal Cases\t\tActive Cases\t\tRecovered\t\tDeaths\n";
    // cout << "------\t\t\t-----------\t\t-------\t\t\t------\t\t\t------\n";
    cout << left << setw(15) << "State"<< left << setw(15) << "Total Cases" << left << setw(15) << "Active Cases" << left << setw(15) << "Recovered" << left << setw(15) << "Deaths" << endl;
    //cout << "------\t\t------\t\t\t-----------\t\t-------\t\t\t------\t\t\t------\n";
    cout << left << setw(15) << "-----" << left << setw(15) << "-----------" << left << setw(15) << "-----------" << left << setw(15) << "---------" << left << setw(15) << "------" << endl;
    while(!f.eof()){
        f.getline(display_state.state,20,'|');
        f.getline(display_state.total_cases,20,'|');
        f.getline(display_state.active_cases,20,'|');
        f.getline(display_state.recovered,20,'|');
        f.getline(display_state.deaths,20,'\n');
        // cout << "\n" << display_state.state << "\t\t\t" << display_state.total_cases << "\t\t\t" << display_state.active_cases << "\t\t\t" << display_state.recovered << "\t\t\t" << display_state.deaths;
        cout << "\n";
        cout << left << setw(15) << display_state.state << left << setw(15) << display_state.total_cases << left << setw(15) << display_state.active_cases << left << setw(15) << display_state.recovered << left << setw(15) << display_state.deaths << endl;
    }
    f.close();
}
//updating state data
void update_state(char state_name[],int total_cases,int active_cases,int recovered,int deaths){
    fstream state_update,temp2;
    Cases up;
    char s2[20] = "state_data.txt";
    int cnt = no_of_records(s2);
    int t_cases,a_cases,recov,death;
    state_update.open("state_data.txt",ios::in);
    temp2.open("state_temp.txt",ios::out);
    while((cnt--)!=1){
        state_update.getline(up.state,20,'|');
        state_update.getline(up.total_cases,20,'|');
        state_update.getline(up.active_cases,20,'|');
        state_update.getline(up.recovered,20,'|');
        state_update.getline(up.deaths,20,'\n');
        if(!strcmp(up.state,state_name)){
            t_cases = atoi(up.total_cases) + total_cases;
            a_cases = atoi(up.active_cases) + active_cases - (recovered + deaths);
            recov = atoi(up.recovered) + recovered;
            death = atoi(up.deaths) + deaths;
            temp2 << up.state << "|" << t_cases << "|" << a_cases << "|" << recov << "|" << death << "\n";
        }
        else{
            temp2 << up.state << "|" << up.total_cases << "|" << up.active_cases << "|" << up.recovered << "|" << up.deaths << "\n";
        }
    }
    state_update.close();
    temp2.close();
    remove("state_data.txt");
    rename("state_temp.txt","state_data.txt");
}

//Updating the values in city_data text file.
void update_city(){
    Cases update[2]; //Creating an array of objects to store values of multiple variables.
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
            update_state(update[1].state,total,active,recover,death);
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

void city_search(){
    Cases search;
    char c_name[20];
    char buffer[100];
    fstream s;
    s.open("city_data.txt",ios::in);
    cout << "\nEnter the city whose details you require";
    cin >> c_name;
    while(!s.eof()){
        s.getline(search.state,20,'|');
        s.getline(search.city,20,'|');
        s.getline(search.total_cases,20,'|');
        s.getline(search.active_cases,20,'|');
        s.getline(search.recovered,20,'|');
        s.getline(search.deaths,20,'\n');
        if(strcmp(search.city,c_name)==0){
            cout << "\nCity Record Exists\n";
            // cout << "\n\nState\t\tCity\t\t\tTotal Cases\t\tActive Cases\t\tRecovered\t\tDeaths\n";
            // cout << "------\t\t------\t\t\t-----------\t\t-------\t\t\t------\t\t\t------\n";
            // cout << "\n" << search.state << "\t\t" << search.city << "\t\t\t" << search.total_cases << "\t\t" << search.active_cases << "\t\t" << search.recovered << "\t\t" << search.deaths << "\n";
            cout << left << setw(15) << "State" << left << setw(15) << "City" << left << setw(15) << "Total Cases" << left << setw(15) << "Active Cases" << left << setw(15) << "Recovered" << left << setw(15) << "Deaths" << endl;
            //cout << "------\t\t------\t\t\t-----------\t\t-------\t\t\t------\t\t\t------\n";
            cout << left << setw(15) << "-----" << left << setw(15) << "-----" << left << setw(15) << "-----------" << left << setw(15) << "-----------" << left << setw(15) << "---------" << left << setw(15) << "------" << endl;
            cout << left << setw(15) << search.state << left << setw(15) << search.city << left << setw(15) << search.total_cases << left << setw(15) << search.active_cases << left << setw(15) << search.recovered << left << setw(15) << search.deaths << endl;
            s.close();
            return;
        }
    }
    cout << "\nCity doesn't exit in the records";
}

//Inserting records into the city_data and state_data text file.
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
            if(!(strcmp(s_name,insert.state))){
                update_state(s_name,atoi(insert.total_cases),atoi(insert.active_cases),atoi(insert.recovered),atoi(insert.deaths));
                break;
            }
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

void display_cities(){
    fstream cityf;
    Cases display_city;
    cityf.open("city_data.txt",ios::in);
    cout << "\n";
    cout << left << setw(15) << "State" << left << setw(15) << "City" << left << setw(15) << "Total Cases" << left << setw(15) << "Active Cases" << left << setw(15) << "Recovered" << left << setw(15) << "Deaths" << endl;
    cout << left << setw(15) << "-----" << left << setw(15) << "-----" << left << setw(15) << "-----------" << left << setw(15) << "-----------" << left << setw(15) << "---------" << left << setw(15) << "------" << endl;
    while(!cityf.eof()){
        cityf.getline(display_city.state,20,'|');
        cityf.getline(display_city.city,20,'|');
        cityf.getline(display_city.total_cases,20,'|');
        cityf.getline(display_city.active_cases,20,'|');
        cityf.getline(display_city.recovered,20,'|');
        cityf.getline(display_city.deaths,20,'\n');
        cout << "\n";
        cout << left << setw(15) << display_city.state << left << setw(15) << display_city.city << left << setw(15) << display_city.total_cases << left << setw(15) << display_city.active_cases << left << setw(15) << display_city.recovered << left << setw(15) << display_city.deaths << endl;
    }
    cityf.close();
}

int main(){
    int choice,dummy;
    cout << "\nCovid Management System\n";
    cout << "\nCurrent Situation in States\n";
    display_states();
    cout << "\n1. SignUp\t2. Login\t3. Exit\n";
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
    cout << "\n1. Insert Record\n2. Display City Details\n3. Update City Details\n4. Search City\n5. Display State Details\n6. Exit\n";
    cout << "\nEnter your choice: ";
    cin >> choice;
    switch(choice){
        case 1: insert_cases();
        break;
        case 2: display_cities();
        break;
        case 3: update_city();
        break;
        case 4: city_search();
        break;
        case 5: display_states();
        break;
        case 6: exit(1);
        default: cout << "\nInvalid Choice";
        }
    }
}