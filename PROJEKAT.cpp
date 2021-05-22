#include<iostream>
#include<cmath>
#include<algorithm>
#include<stdlib.h>
#include<ctime>
#include<iomanip>
#include<string>
#include<vector>
#include<fstream>   
#include<sstream> 
using namespace std;

struct mobitel{
    string nazivMobitela;
    string modelMobitela;

};
/*
int unosMobitela() {
	int izbor;
	system("cls");
	do
	{
		cout << crt << "\t::ADMIN::" << crt;
		cout << "1. Unos naziva mobitela: " << endl;
		cout << "2. Unos modela mobitela: " << endl;
		cout << "3. Unos godine proizvodnje: " << endl;
		cout << "4. RAM: " << endl;
		cout << "5. Resetuj test za studenta" << endl;		
		cout << "6. Prikazi sve studente" << endl;
		cout << "7. Priakzi sva pitanja sa testa" << endl;
		cout << "8. Kraj rada" << crt;
		cout << "Unesite izbor: ";
		cin >> izbor;
	} while (izbor<1 || izbor>8);
	return izbor;
}
*/
void mainmenu();


int choice; 
bool cinfail; 
int confirmation; 
string username, password, password2;

void writetofile(string username){
    ofstream writefile;
    string file = username+".txt";
    writefile.open(file.c_str());
    writefile << password;
    writefile.close();
    mainmenu(); }

void login(){
    cout << "You are being logged in!";}


void registerpassword(){
    cout << "Ukucajte vasu sifru:" << endl;
    cin >> password;
    cout << "Ukucajte ponovo vasu sifru:" << endl;
    cin >> password2;
    if (password == password2){
        cin.clear();
        cin.ignore(10000,'\n');
        writetofile(username);
        exit(1);
    }
    else;{
        cout << "Neispravna sifra" << endl;
        registerpassword();
    }}


void registerme(){
    cout << "Molimo ukucajte vase korisnicko ime: " << endl;
    getline(cin, username);
    cout << "\nKorisnicko ime -  \""<< username << "\"\nPotvrditi? \n\n[1] Da\n[2] Ne" << endl;
    cin >> confirmation;
    if (confirmation == 1){
        registerpassword();
    }

    else; {
        cout << "Sorry invalid input, Please try again" << endl;
        cin.clear();
        cin.ignore(10000,'\n');
        registerme();
    }}


void exit(){
    exit(0);}

void mainmenu(){ cout << "Hello, Would you like to log in or register\n\t[1] Login\n\t[2] Register\n\t[3] Exit" <<endl; cin >> choice; do{
    cinfail = cin.fail();
    cin.clear();
    cin.ignore(10000,'\n');

    }while(cinfail == true);{
        switch(choice){
            case 1:
                login();
                break;

            case 2:
                registerme();
                break;

            case 3:
                exit();}}} 

main(){ 
mainmenu(); 
}






