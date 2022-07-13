#include<iostream>
// #include<atoi>
#include<fstream>

using namespace std;

int main(){
//     fstream file;
//     fstream file2;
//     file.open("cases.txt",ios::in);
//     file2.open("cases.txt",ios::out);
//     char some[20];
//     char buffer[100];
//     while(!file.eof()){
//         file.getline(some,20,'|');
//         cout << some << " ";
//     }
//     file2 << "something";
    // char *s = "sampl1.txt";
    // char *s1 = "sampl2.txt";
    // /*	Deletes the file if exists */
	// if (rename(s, s1) != 0)
	// 	perror("Error renaming file");
	// else
	// 	cout << "File renamed successfully";
    // int a = 10;
    // cout << (char *)a;
    // fstream f;
    // char s_name[20];
    // f.open("state_data.txt",ios::in);
    // char buffer[80];
    // while(!f.eof()){
    //     f.getline(s_name,20,'|');
    //     f.getline(buffer,80,'\n');
    //     cout << s_name <<endl;
    // }
    int a,b;
    a = 10;
    b = 20;
    if(a<b){
        goto label;
    }
    else{
        cout << "Goto doesn't work";
    }
    label:
            cout << "This is goto";
}