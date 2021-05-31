#include<iostream>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<stdlib.h>
#include<ctime>
#include<iomanip>
#include<cstring>
#include<vector>
#include<fstream>   
#include<sstream>
#include <algorithm>
using namespace std;

enum nazivMobitela {Samsung=1, iPhone, Huawei, Xiaomi,};

struct Admin{
	string username;
	string sifra;
};
struct mobitel{
    nazivMobitela naziv;
    string modelMobitela;
    int godinaProizvodnje;
    int RAM;
    int ROM;
};
void registracija(string *username,string *pasword,int j){
	cout<<"Unesite username:";
    getline(cin,username[j]);
    cout<<"Unesite pasword:";
    getline(cin,pasword[j]);
}
void login(string *lusername,string *lpasword,int i){
	cout<<"Username:";
    getline(cin,lusername[i]);
    cout<<"Pasword:";
    getline(cin,lpasword[i]);
}

bool reg(string *regU,string *regP,string *luser,string *lpas,int i,int j){
	int k=0;
	for(int n=0;n<j;n++){
		if (strcmp(luser[i-1].c_str(),regU[n].c_str()) == 0 && strcmp(lpas[i-1].c_str(),regP[n].c_str())== 0){	
				k++;
			}	}
		if(k==0) return false;
		else	return true;
		
}



bool adm(string *luser,string *lpas,int i,Admin *novi ){
	int k=0;
	for(int n=0;n<4;n++){
		if (strcmp(luser[i-1].c_str(),novi[n].username.c_str()) == 0 && strcmp(lpas[i-1].c_str(),novi[n].sifra.c_str())== 0){	
				k++;
			}	}
		if(k==0) return false;
		else	return true;
}


void korisnickiMenu(){
	system("cls");
	cout<<"-----------------------KORISNICKI MENU!---------------------------------"<<endl;
}


mobitel unosMobitela(){
    ofstream ispis("bazaMobitela.txt");
    if(ispis.fail()){
        cout<<"ERROR";
    }else{
        int izbor;
        do{
            cout<<"----------------------"<<endl;
            cout<<"\t1-Samsung"<<endl;
            cout<<"\t2-iPhone"<<endl;
            cout<<"\t3-Huawei"<<endl;
            cout<<"\t4-Xiaomi"<<endl;
            cout<<"----------------------"<<endl;
            cout << "Unesite redni broj proizvodjaca mobitela: ";
            do{
                cin>>izbor;
                ispis<<(nazivMobitela)izbor<<" ";
            }while(izbor<1 || izbor>4);

            system("cls");
        }while(1);
        ispis.close();
    }

}
int adminMeni(){
   	system("cls");
	int izbor;
	do{
		cout << "1. Dodati novi artikal(mobitel): " << endl;
		cout << "2. Provjera stanja artikala: " << endl;
		cout << "3. Prodaj artikal: " << endl;
		cout << "Unesite izbor: ";
		cin >> izbor;
		cin.ignore();
	}while(izbor<1 || izbor>3); 

    switch(izbor){
        case 1:
        system("cls");
        unosMobitela();
    }
}

void loginMeni(){
	system("cls");
        cout<<"\t\tDobrodosli u Mobi-SHOP"<<endl;
		cout <<"\n:::LOGIN / REGISTER:::"<<endl;
		cout << "1. Registracija usera " << endl;
		cout << "2. Login " << endl;
		cout << "3. Napustiti sistem " << endl;
}
int main (){
	int izbor,a=0,b=0,br=0;
	string username[20],pasword[20],lusername[20],lpasword[20];
		Admin *novi=new Admin[4];
	ifstream ob("admini.txt");
			if(ob.is_open()){
				while(!ob.eof()){
					ob>>novi[br].username;
					ob>>novi[br].sifra;
					br++;
				}
			ob.close();
		}else{
			cout<<"Neuspjesno otvaranje datoteke!\n";
		}
do{
	do{
		loginMeni();
		cout << "Izbor: ";
		cin >> izbor;
		cin.ignore();
	switch(izbor){
		case 1:
			registracija(username,pasword,a);
			a++;
			break;	
		case 2:
			login(lusername,lpasword,b);
			b++;
			if(adm(lusername,lpasword,b,novi)){
			adminMeni();
				system("pause");
			}
			if(reg(username,pasword,lusername,lpasword,b,a)){
				korisnickiMenu();
				system("pause");
			}else{
				cout<<"Nema registrovanog \n";
				system("pause");
			}
		case 3:
				break;		
		}
	}while(izbor != 5);
	}while(izbor<1 || izbor>5);
return 0;
}
