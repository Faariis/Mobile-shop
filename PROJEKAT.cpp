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
<<<<<<< Updated upstream
=======

using namespace std;
>>>>>>> Stashed changes

using namespace std;

enum nazivMobitela {Samsung=1, iPhone, Huawei, Xiaomi,};
struct Admin{
	string username;
	string sifra;
};
struct kupac{
    string imePrezime;
    string adresa;
    int brTel;
};
struct mobitel{
    nazivMobitela naziv;
    string modelMobitela;
    int godinaProizvodnje;
    int RAM;
    int ROM;
    int kolicina;
    float cijena;

	string vratiMob(){
        switch (naziv){
            case 1:
            return "Samsung";
            case 2:
            return "iPhone";
            case 3: 
            return "Huawei";
            case 4:
            return "Xiaomi";
	    }
    }
    	string vratiROM(int izbor){
        switch (izbor){
            case 1:
            return "8";
            case 2:
            return "16";
            case 3: 
            return "32";
            case 4:
            return "64";
            case 5:
            return "128";
            case 6:
            return "256";
            case 7:
            return "512";
            case 8:
            return "1024";

	    }
    }
    //Login Menu-otvara ga na pocetku programa
    void loginMeni(){
	system("cls");
        cout<<"\t\tDobrodosli u Mobi-SHOP"<<endl;
		cout <<"\n:::LOGIN / REGISTER:::"<<endl;
		cout << "1. Registracija usera " << endl;
		cout << "2. Login " << endl;
		cout << "0. Napustiti sistem " << endl;
    }
<<<<<<< Updated upstream
    //Admin menu-otvara ga nakon Å¡to se prijavimo kao admini
=======
    //Admin menu-otvara ga nakon što se prijavimo kao admini
>>>>>>> Stashed changes
    void adminMeni(){
   	system("cls");
	int izbor;
	do{
		cout << "1. Dodati novi artikal(mobitel): " << endl;
		cout << "2. Provjera stanja artikala: " << endl;
        cout << "3. Provjeri narudzbe: " << endl;
		cout << "4. Prodaj artikal: " << endl;
        cout <<"0. Kraj: "<<endl;
		cout << "Unesite izbor: ";
		cin >> izbor;
		cin.ignore();
	}while(izbor<0 || izbor>4); 

    switch(izbor){
        case 1:
        system("cls");
        unosMobitela();
        case 2:
        system("cls");
        ProvjeraStanjaMeni();
        case 3:
        system("cls");
        case 0:
        loginMeni();

<<<<<<< Updated upstream
=======
    }
}
    //funkcija za unos mobitela u sklopu Admin menua
    void unosMobitela(){
    ifstream some("skladiste.txt");
    string temp;
    some>>temp;
    if(some.eof()){
        some.close();
        ofstream open("skladiste.txt");
        open<<"--------------------------------------------------------------------------------------------------------"<<endl;
<<<<<<< HEAD
        open<<left<<setw(14)<<"Proizvodjac:"<<setw(10)<<"Model:"<<setw(21)<<"Godina proizvodnje:"<<setw(10)<<"RAM(GB):"<<setw(10)<<"ROM(GB):"<<setw(12)<<"Kolièina:"<<setw(13)<<"Cijena(KM):"<<endl;
        open<<"--------------------------------------------------------------------------------------------------------"<<endl;
        open.close();
    }else some.close();
    
    ofstream unos("skladiste.txt", ios::app);
    if(unos.fail()){
        cout<<"Nemoguce pristupiti bazi podataka!!!";
    }else{
        int izbor;
            cout<<"----------------------"<<endl;
            cout<<"\t1-Samsung"<<endl;
            cout<<"\t2-iPhone"<<endl;
            cout<<"\t3-Huawei"<<endl;
            cout<<"\t4-Xiaomi"<<endl;
            cout<<"----------------------"<<endl;
                do{
                    cout << "Unesite redni broj proizvodjaca mobitela: ";
                    cin>>izbor;
                }while(izbor<1 || izbor>4);
            naziv=(nazivMobitela)izbor;
                unos<<left<<setw(14)<<vratiMob();
                cin.ignore();
            cout<<"Unesite model mobitela: ";
                getline(cin, modelMobitela);
                unos<<setw(10)<<modelMobitela;
            cout<<"Unesite godinu proizvodnje: ";
                cin>>godinaProizvodnje;
                unos<<setw(21)<<godinaProizvodnje;
            cout<<"Unesite kolicinu RAM memorije (GB): ";
                cin>>RAM;
                unos<<setw(10)<<RAM;
                int izbor2;
                do{
                    cout<<"Unesite kolicinu ROM memorije (GB): "<<endl;
                    cout<<"(1)-8 GB, (2)-16 GB, (3)-32 GB, (4)-64 GB, (5)-128 GB, (6)-264 GB, (7)-512 GB, (8)-1024 GB"<<endl;
                    cin>>izbor2;
                }while(izbor2<1 || izbor2 >8);    
                unos<<setw(10)<<vratiROM(izbor2);
            cout<<"Unesite kolicinu:";
                cin>>kolicina;
                unos<<setw(12)<<kolicina;
            cout<<"Unesite cijenu:";
                cin>>cijena;
                unos<<setw(13)<<cijena;
                unos<<endl;
                unos.close();
                int x;
                do{
                    cout<<"\nZelite li unijeti jos jedan mobitel: (0-NE, 1-DA)";
                    cin>>x;
                }while(x<0 || x>1);
                switch(x){
                    case 0:
                    adminMeni();
                    case 1:
                    system("cls");
                    unosMobitela();
                }
            }
            //unos.close();
        }
        //menu koji izbacuje nakon što odaberemo provjera stanja u admin menu
        void ProvjeraStanjaMeni(){
            system("cls");
            int izbor;
            do{
                cout << "1. Ispisi sve artikle (sortirano): " << endl;
                cout << "2. Provjeri mobitel u skladistu : " << endl;
                cout << "0. Nazad: " << endl;
                cout << "Unesite izbor: ";
                cin >> izbor;
                cin.ignore();
            }while(izbor<0 || izbor>2);
            switch (izbor){
                case 1:
                system("cls");
                IspisiSortirano();
                case 0:
                adminMeni();
            } 
        
        }
        //menu koji izbacuje nakon sto izaberemo ispis svih sortiranih artikala
        void IspisiSortirano(){
        system("cls");
        int izbor;
        do{
            cout << "1. Sortirano po RAM-u: " << endl;
            cout << "2. Sortirano po ROM-u: " << endl;
            cout << "3. Sortirano po cijeni: " << endl;
            cout << "0. Nazad: " << endl;
            cout << "Unesite izbor: ";
            cin >> izbor;
            cin.ignore();
        }while(izbor<0 || izbor>3);

        switch (izbor){
            case 0:
            ProvjeraStanjaMeni();
        } 
    
>>>>>>> Stashed changes
    }

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
    //funkcija za unos mobitela u sklopu Admin menua
    void unosMobitela(){
    ifstream some("skladiste.txt");
    string temp;
    some>>temp;
    if(some.eof()){
        some.close();
        ofstream open("skladiste.txt");
        open<<"--------------------------------------------------------------------------------------------------------"<<endl;
        open<<left<<setw(14)<<"Proizvodjac:"<<setw(10)<<"Model:"<<setw(21)<<"Godina proizvodnje:"<<setw(10)<<"RAM(GB):"<<setw(10)<<"ROM(GB):"<<setw(12)<<"KoliÄina:"<<setw(13)<<"Cijena(KM):"<<endl;
=======
        open<<left<<setw(14)<<"Proizvodjac:"<<setw(10)<<"Model:"<<setw(21)<<"Godina proizvodnje:"<<setw(10)<<"RAM(GB):"<<setw(10)<<"ROM(GB):"<<setw(12)<<"Kolicina:"<<setw(13)<<"Cijena(KM):"<<endl;
>>>>>>> e9c432068cca3943d6828930170590a67cee38ba
        open<<"--------------------------------------------------------------------------------------------------------"<<endl;
        open.close();
    }else some.close();
    
    ofstream unos("skladiste.txt", ios::app);
    if(unos.fail()){
        cout<<"Nemoguce pristupiti bazi podataka!!!";
    }else{
        int izbor;
            cout<<"----------------------"<<endl;
            cout<<"\t1-Samsung"<<endl;
            cout<<"\t2-iPhone"<<endl;
            cout<<"\t3-Huawei"<<endl;
            cout<<"\t4-Xiaomi"<<endl;
            cout<<"----------------------"<<endl;
                do{
                    cout << "Unesite redni broj proizvodjaca mobitela: ";
                    cin>>izbor;
                }while(izbor<1 || izbor>4);
            naziv=(nazivMobitela)izbor;
                unos<<left<<setw(14)<<vratiMob();
                cin.ignore();
            cout<<"Unesite model mobitela: ";
                getline(cin, modelMobitela);
                unos<<setw(10)<<modelMobitela;
            cout<<"Unesite godinu proizvodnje: ";
                cin>>godinaProizvodnje;
                unos<<setw(21)<<godinaProizvodnje;
            cout<<"Unesite kolicinu RAM memorije (GB): ";
                cin>>RAM;
                unos<<setw(10)<<RAM;
                int izbor2;
                do{
                    cout<<"Unesite kolicinu ROM memorije (GB): "<<endl;
                    cout<<"(1)-8 GB, (2)-16 GB, (3)-32 GB, (4)-64 GB, (5)-128 GB, (6)-264 GB, (7)-512 GB, (8)-1024 GB"<<endl;
                    cin>>izbor2;
                }while(izbor2<1 || izbor2 >8);    
                unos<<setw(10)<<vratiROM(izbor2);
            cout<<"Unesite kolicinu:";
                cin>>kolicina;
                unos<<setw(12)<<kolicina;
            cout<<"Unesite cijenu:";
                cin>>cijena;
                unos<<setw(13)<<cijena;
                unos<<endl;
                unos.close();
                int x;
                do{
                    cout<<"\nZelite li unijeti jos jedan mobitel: (0-NE, 1-DA)";
                    cin>>x;
                }while(x<0 || x>1);
                switch(x){
                    case 0:
                    adminMeni();
                    case 1:
                    system("cls");
                    unosMobitela();
                }
            }
            unos.close();
        }
        //menu koji izbacuje nakon sto odaberemo provjera stanja u admin menu
        void ProvjeraStanjaMeni(){
            system("cls");
            int izbor;
            do{
                cout << "1. Ispisi sve artikle (sortirano): " << endl;
                cout << "2. Provjeri mobitel u skladistu : " << endl;
                cout << "0. Nazad: " << endl;
                cout << "Unesite izbor: ";
                cin >> izbor;
                cin.ignore();
            }while(izbor<0 || izbor>2);
            switch (izbor){
                case 1:
                system("cls");
                IspisiSortirano();
                case 0:
                adminMeni();
            } 
        
        }
        //menu koji izbacuje nakon sto izaberemo ispis svih sortiranih artikala
        void IspisiSortirano(){
        system("cls");
        int izbor;
        do{
            cout << "1. Sortirano po RAM-u: " << endl;
            cout << "2. Sortirano po ROM-u: " << endl;
            cout << "3. Sortirano po cijeni: " << endl;
            cout << "0. Nazad: " << endl;
            cout << "Unesite izbor: ";
            cin >> izbor;
            cin.ignore();
        }while(izbor<0 || izbor>3);

<<<<<<< Updated upstream
        switch (izbor){
            case 1:
            sortirajRAM();
            case 0:
            ProvjeraStanjaMeni();
        } 
    
    }
    //sortiranje po RAM-u 
    void sortirajRAM (){
        ifstream skladiste("skladiste.txt");
        vector<string> telefoni;
        vector<int> ram;
        int a;
        string temp;
        if(skladiste.fail()){
            cout<<"Nemoguce pristupiti bazi podataka!!!";
        }else{

        cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
        cout<<left<<setw(14)<<"Proizvodjac:"<<setw(10)<<"Model:"<<setw(21)<<"Godina proizvodnje:"<<setw(10)<<"RAM(GB):"<<setw(10)<<"ROM(GB):"<<setw(12)<<"Kolicina:"<<setw(13)<<"Cijena(KM):"<<endl;
        cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
        getline(skladiste, temp);
        getline(skladiste, temp);
        getline(skladiste, temp);
        while(true){
            getline(skladiste, temp);
            if(skladiste.eof()) break;
            telefoni.push_back(temp);
            a=temp[45]-'0';
            ram.push_back(a);
        }
        for(int i=0; i<telefoni.size(); i++){
            for(int j=i; j<telefoni.size(); j++){
                if(ram[i]>ram[j]) {
                    swap(ram[i], ram[j]);
                    swap(telefoni[i], telefoni[j]);
                }
            }
        }        
        for(int i=0; i<telefoni.size(); i++){
            cout<<telefoni[i]<<endl;
        }
        skladiste.close();
        system("PAUSE");
        }
    }

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
=======


bool adm(string *luser,string *lpas,int i,Admin *novi ){
	int k=0;
	for(int n=0;n<4;n++){
		if (strcmp(luser[i-1].c_str(),novi[n].username.c_str()) == 0 && strcmp(lpas[i-1].c_str(),novi[n].sifra.c_str())== 0){	
>>>>>>> Stashed changes
				k++;
			}	}
		if(k==0) return false;
		else	return true;
<<<<<<< Updated upstream
		
=======
>>>>>>> Stashed changes
}


void korisnickiMenu(){
	system("cls");
	cout<<"-----------------------KORISNICKI MENU!---------------------------------"<<endl;
}
/*--------------------------------------------------MAIN FUNKCIJA--------------------------------------------------*/
int main (){
    
    mobitel user;
    
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
		user.loginMeni();
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
			user.adminMeni();
				system("pause");
			}
			if(reg(username,pasword,lusername,lpasword,b,a)){
				korisnickiMenu();
				system("pause");
			}else{
				cout<<"Pogresan username ili password \n";
				system("pause");
			}
		case 0:
                system("cls");
				break;		
		}
	}while(izbor != 5);
	}while(izbor<1 || izbor>5);

<<<<<<< Updated upstream
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
/*--------------------------------------------------MAIN FUNKCIJA--------------------------------------------------*/
int main (){
    
    mobitel user;
    /*
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
		user.loginMeni();
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
			user.adminMeni();
				system("pause");
			}
			if(reg(username,pasword,lusername,lpasword,b,a)){
				korisnickiMenu();
				system("pause");
			}else{
				cout<<"Pogresan username ili password \n";
				system("pause");
			}
		case 0:
                system("cls");
				break;		
		}
	}while(izbor != 5);
	}while(izbor<1 || izbor>5);
*/
=======
>>>>>>> Stashed changes
user.adminMeni();
return 0;
}
