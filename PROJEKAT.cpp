#include<iostream>
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

enum nazivMobitela {Samsung=1, iPhone, Huawei, Xiaomi,};

struct mobitel{
    nazivMobitela naziv;
    string modelMobitela;
    int godinaProizvodnje;
    int RAM;
    int ROM;

};
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

int loginMeni(){
	system("cls");
	int izbor;
	do{
        cout<<"\t\tDobrodosli u Mobi-SHOP"<<endl;
		cout <<"\n:::LOGIN / REGISTER:::"<<endl;
		cout << "1. Login " << endl;
		cout << "2. Registracija usera " << endl;
		cout << "3. Napustiti sistem " << endl;
		cout << "Unesite izbor: ";
		cin >> izbor;
		cin.ignore();
	}while(izbor<1 || izbor>3);

    if (izbor==1) adminMeni();
}
int main (){
loginMeni();



return 0;
}