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
#include "windows.h" //potrebno za funkciju sleep
using namespace std;

char* crt = "--------------------------------------------------------------------------------\n";
char* crt2 ="================================================================================\n";
char* crt3 ="________________________________________________________________________________\n";

enum nazivMobitela {Samsung=1, iPhone, Huawei, Xiaomi,};
struct Admin{
	string username;
	string sifra;
};
struct kupac{
    string imePrezime;
    string adresa;
    string brTel;
};
struct mobitel{
    int id;
    nazivMobitela naziv;
    string modelMobitela;
    int godinaProizvodnje;
    int RAM;
    int ROM;
    int kolicina;
    float cijena;
    string nazivv;//koristimo samo za niz 
    kupac kupac; //potrebno jer se funkcija kupiArtikal() nalazi unutar mobitel structa

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
    string vratiPostu(int izbor){
        switch(izbor){
            case 1:
            return "EuroExpress";
            case 2:
            return "BH-PostExpress";
            case 3:
            return "A2B-Express";
            case 4:
            return "X-Express";
        }
    }
    /*-------------------LOGIN MENU (otvara ga na pocetku programa)-----------------*/
   void loginMeni(){
	system("cls");
		//==========================================================================
		cout<<crt2;
		cout << "\t\t\t ";for(int i=1;i<=25;i++){cout << "_";};cout << endl;
		cout << "\t\t\t |                       |" << endl;
        cout << "\t\t\t |Dobrodosli u Mobi-SHOP!|" << endl;
        cout << "\t\t\t |_______________________|\n\n";
        cout<<crt2;
        //==========================================================================
        cout<<crt3;
		cout <<"\n\t\t\t  :::::LOGIN / REGISTER:::::"<<endl;
		cout<<crt3;
        cout << "\t\t\t ________________________" << endl;
        cout << "\t\t\t/  __________o__________ \\ " << endl;
        cout << "\t\t\t| |__________________==| |" << endl;
        cout << "\t\t\t| |                    | |" << endl;
        cout << "\t\t\t| |                    | |" << endl;
        cout << "\t\t\t| |  1. Registracija   | |" << endl;
        cout << "\t\t\t| |  2. Login          | |" << endl;
        cout << "\t\t\t| |  0. Dovidjenja     | |" << endl;
        cout << "\t\t\t| |                    | |" << endl;
        cout << "\t\t\t| |                    | |" << endl;
        cout << "\t\t\t| |                    | |" << endl;
        cout << "\t\t\t| |                    | |" << endl;
        cout << "\t\t\t| |                    | |" << endl;
        cout << "\t\t\t| |                    | |" << endl;
        cout << "\t\t\t| |                    | |" << endl;
        cout << "\t\t\t| |                    | |" << endl;
        cout << "\t\t\t| |                    | |" << endl;
        cout << "\t\t\t| |                    | |" << endl;
        cout << "\t\t\t| |____________________| |" << endl;
        cout << "\t\t\t| |____________________| |" << endl;
        cout << "\t\t\t|    <       o       >   |" << endl;
        cout << "\t\t\t\\________________________/" << endl;
    }
    
/*-------------------ADMIN MENU (otvara ga nakon što se prijavimo kao admini)-----------------*/ 
  void adminMeni(string rec){	  
    system("cls");
	//===================================================================================================================
	cout<<crt2;
	cout << "\t\t\t  _______________________" << endl;
	cout << "\t\t\t  |                     |" << endl;
	cout << "\t\t\t  | Dobrodosao, admine! |" << endl; 
	cout << "\t\t\t  |_____________________|\n" << endl;
	cout<<crt2;
	//===================================================================================================================
	int izbor;
	do{
		cout << "\n\t\t  ____________________________________" << endl;
		cout << "\t\t    |                                  |" << endl;
		cout << "\t\t    | 1. Dodati novi artikal(mobitel): |" << endl;
		cout << "\t\t    | 2. Provjera stanja artikala:     |" << endl;
        cout << "\t\t    | 3. Provjeri narudzbe:            |" << endl;
		cout << "\t\t    | 4. Prodaj artikal:               |" << endl;
		cout << "\t\t    | 5. Broj artikala:                |" << endl;
        cout << "\t\t    | 0. Kraj:                         |" << endl;
        cout << "\t\t    |__________________________________|\n" << endl;
        cout<<crt2;
		cout << "Unesite izbor: ";
		cin >> izbor;
		cin.ignore();
	}while(izbor<0 || izbor>5); 

    switch(izbor){
        case 1:
        system("cls");
        unosMobitela();
        case 2:
        system("cls");
        ProvjeraStanjaMeni("admin");
        case 3:
        system("cls");
        provjeriNarudzbe();
        case 4:
        system("cls");
        IspisMobitela();
        prodajArtikal();
        case 0:
        system("cls");
        loginMeni();
        break;
         case 5:
        	int b=0;
        	system("cls");
            cout<<crt;
        	cout<<"\t\tU vasem skladistu se nalazi "<<izrArtikal(b)<<" razlicitih modela mobitela."<<endl;
            cout<<crt;
        	system("pause");
        	adminMeni("admin");

    }
}
//Rekurzivnom funkcijom racunamo ukupan broj mobitela u skladistu
int izrArtikal(int n){
 ifstream unos("skladiste.txt");
            int br1=0;
            string tenp;
            if(unos.is_open()){
            	while(!unos.eof()){
            		getline(unos,tenp);
            		br1++;
				}
                unos.close();
			}
                if(n==br1-4){
					return n;
				}else{
					return izrArtikal(n+1);
				}	
			}
     /*-------------------FUNKCIJA ZA UNOS MOBITELA U SKLOPU ADMIN MENUA-----------------*/
    void unosMobitela(){
        ifstream some("skladiste.txt");
        string temp;
        int ID=-3;//stavljamo brojac ID na -3 jer preskacemo prve 3 linije iz datoteke
        some>>temp;
        if(some.eof()){
            some.close();
            ofstream open("skladiste.txt");
            open<<"--------------------------------------------------------------------------------------------------------"<<endl;
            open<<left<<setw(6)<<"ID:"<<setw(14)<<"Proizvodjac:"<<setw(10)<<"Model:"<<setw(21)<<"Godina proizvodnje:"<<setw(10)<<"RAM(GB):"<<setw(10)<<"ROM(GB):"<<setw(12)<<"Kolicina:"<<setw(13)<<"Cijena(KM):"<<endl;
            open<<"--------------------------------------------------------------------------------------------------------"<<endl;
            open.close();
        }else some.close();
        //-------------------------------
        ifstream unosID("skladiste.txt");
            string mobi;              
            do{
            getline(unosID, mobi);           //ovim omogucujemo da se ID uvijek povecava za 1 prilikom unosenja novog mobitela
            ID++; 
            }while(!unosID.eof());
        unosID.close();
        //---------------------------------
        ofstream unos("skladiste.txt", ios::app);
            if(unos.fail()){
                cout<<"Nemoguce pristupiti bazi podataka!!!";
            }else{
                unos<<left<<setw(6)<<ID;
                ID++;
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
                            adminMeni("admin");
                            system("PAUSE");
                            case 1:
                            system("cls");
                            unosMobitela();
                            
                        }
                    }
                unos.close();
        }
            /*-------------------PROVJERAVA DA LI SE MOBITEL NALAZI U SKLADISTU (IMA LI GA NA STANJU)-----------------*/
    void provjeriMob(string rec){
        ifstream unosV("skladiste.txt");
            string linija;
            int br=0;
            if (unosV.fail()){
                cout<<"fail";
            }else{
                while(!unosV.eof()){
                    getline(unosV, linija); //unosi liniju po liniju
                    br++;                   //jer nam je potreban brojac
                }
            }
        unosV.close();

        unosV.open("skladiste.txt", ios::in);
            mobitel nizMobitela[br-4]; //pravimo niz jer nam treba da provjerimo da li se mobitel nalazi na stanju
                string temp;
                    getline(unosV, temp);   //
                    getline(unosV, temp);   //preskacemo prve 3 linije
                    getline(unosV, temp);   //
                    for(int i=0; i<br-4; i++){ //unos iz datoteke u niz
                        unosV>>nizMobitela[i].id>>nizMobitela[i].nazivv>>nizMobitela[i].modelMobitela>>nizMobitela[i].godinaProizvodnje>>nizMobitela[i].RAM>>
                        nizMobitela[i].ROM>>nizMobitela[i].kolicina>>nizMobitela[i].cijena;
                    }
            unosV.close();
            string proizv;   //
            string mod;     //potrebni stringovi za poredjenje sa nizom
            cout << "Unesite proizvodjaca mobitela (npr. iPhone): ";
                cin>>proizv;
            cout<<crt;
            cout << "Unesite model mobitela (npr. 12-pro): ";
                cin>>mod;
            cout<<crt;
            int br1=0;
            for(int i=0;i<br-4;i++){
                if(strcmp(proizv.c_str(),nizMobitela[i].nazivv.c_str())==0 && strcmp(mod.c_str(),nizMobitela[i].modelMobitela.c_str())==0 && nizMobitela[i].kolicina>0){ //provjerava je li mobitel dostupan u datoteci
                	br1++;
                    cout<<"\n\t\t\tTrazeni artikal je dostupan.\n"<<endl;
                    cout<<crt;
                    cout<<left<<setw(13)<<"ID: "<<nizMobitela[i].id<<endl;
                    cout<<left<<setw(13)<<"Proizvodjac: "<<nizMobitela[i].nazivv<<endl;
                    cout<<left<<setw(13)<<"Model: "<<nizMobitela[i].modelMobitela<<endl;
                    cout<<left<<setw(13)<<"Godina: "<<nizMobitela[i].godinaProizvodnje<<endl;
                    cout<<left<<setw(13)<<"RAM: "<<nizMobitela[i].RAM<<endl;
                    cout<<left<<setw(13)<<"ROM: "<<nizMobitela[i].ROM<<endl;
                        if(rec=="admin") cout<<setw(13)<<"Kolicina"<<nizMobitela[i].kolicina<<endl;//ako se otvara preko admin menua treba da ispise i kolicinu 
                    cout<<left<<setw(13)<<"Cijena: "<<nizMobitela[i].cijena<<endl;
                    int izbor;
                        if(rec=="korisnik"){
                            cout << "\n\t\t\t  ___________________" << endl;
                            cout << "\t\t\t  |                 |" << endl;
                            cout << "\t\t\t  | 1. Kupi artikal |" << endl;
                            cout << "\t\t\t  | 0. Nazad        |" << endl;
                            cout << "\t\t\t  |_________________|\n" << endl;
                        do{
                            cout<<"\nIzbor: ";
                            cin>>izbor;
                        }while(izbor<0 || izbor>1);
                        switch(izbor){
                            case 1:
                            KupiArtikal();
                            case 0:
                            korisnickiMenu("korisnik");
                        }

                    }
                    if(rec=="admin"){
                        system("PAUSE");
                        adminMeni("admin");
                    } 
                }              
            }
            
            if(br1==0){ //ako se nisu zadovoljili uslovi znaci da tog mobitela nema u datoteci
                    if(rec=="admin"){
					 cout<<"Nema vise na stanju, kontaktirajte dobavljaca!"<<endl;
					 system("pause");
					 adminMeni("admin");
                    }   
                    if(rec=="korisnik") {
                        cout<<"Nema vise na stanju, molimo pogledajte neki drugi mobitel iz nase ponude! "<<endl;
                        for(int i=1;i<=80;i++){if(i<80){cout << "-";}else if(i==80){cout << endl;}}
                        system("PAUSE");
                        korisnickiMenu("korisnik");
                    }
                }
        }
        /*-------------------PROVJERAVA IMA LI NARUDZBI U DATOTECI narudzbe.txt i prihvata te narudzbe(brise iz datoteke)-----------------*/
        void provjeriNarudzbe(){
            cout<<"------------------------------------------------------------------------------------------------------------------------\n";
            cout<<"                             LISTA NARUDZBI\n";
            cout<<"------------------------------------------------------------------------------------------------------------------------\n";
            cout<<left<<setw(15)<<"Ime:"<<setw(20)<<"Prezime: "<<setw(30)<<"Adresa: "<<setw(20)<<"Br.telefona: "<<setw(20)<<"ID mobitela: "<<"Posta: "<<endl;
            cout<<"------------------------------------------------------------------------------------------------------------------------\n";
            ifstream narudzbe ("narudzbe.txt");
            string temp;
            int br=0;
            if(narudzbe.fail()) cout<<"Nemoguce pristupiti bazi podataka!!!";
            else{
                while(!narudzbe.eof()){
                    getline(narudzbe, temp);
                    narudzbe>>temp;
                    cout<<left<<setw(15)<<temp<<" ";
                    narudzbe>>temp;
                    cout<<setw(20)<<temp;
                    narudzbe>>temp;
                    cout<<setw(30)<<temp;
                    narudzbe>>temp;
                    cout<<setw(26)<<temp;
                    narudzbe>>temp;
                    cout<<setw(14)<<temp;
                    narudzbe>>temp;
                    cout<<temp<<endl;
                    narudzbe>>temp;   
                    br++;    
                }
                narudzbe.close();

            }
            cout<<"\n------------------------------------------------------";
            cout<<"\n\tUkupan broj narudzbi: "<<br<<endl; 
            cout<<"------------------------------------------------------\n\n";

            cout<<"1. Prodaj artikal: "<<endl;
            cout<<"0. Nazad: "<<endl;
            int izbor;
            do{
                cout<<"\nIzbor: ";
                cin>>izbor;
            }while(izbor < 0 || izbor > 1);
            switch(izbor){
                case 1:
                cout<<endl;
                prodajArtikal();
                system("PAUSE");

                case 0:
                adminMeni("admin");
            }
        }
         /*-------------------PROVJERA STANJA MENU(nalazi se u sklopu admin menua)-----------------*/
        void ProvjeraStanjaMeni(string rec){//rec ce biti jednako "admin" ili "korisnik" te u zavisnosti od toga ce se pozivati 
            system("cls");
            int izbor;
            do{
                if(rec=="admin"){
                cout<<crt2;
            cout << "\t\t\t_________________________________________" << endl;
            cout << "\t\t\t|                                        |" << endl;
            cout << "\t\t\t| 1. Ispisi sve artikle (sortirano):     |" << endl;
            cout << "\t\t\t| 2. Provjeri mobitel u skladistu:       |" << endl;
            cout << "\t\t\t| 0. Nazad:                              |" << endl;
            cout << "\t\t\t|________________________________________|\n" << endl;
                cout<<crt2;
                }if(rec=="korisnik"){
                cout<<crt2;
        	cout << "\t\t\t_________________________________________" << endl;
        	cout << "\t\t\t|                              		    |" << endl;
            cout << "\t\t\t| 1. Ispisi sve artikle (sortirano): 	|" << endl;
            cout << "\t\t\t| 2. Pretrazi mobitel:			        |" << endl;
            cout << "\t\t\t| 0. Nazad:                     			|" << endl;
            cout << "\t\t\t|________________________________________|\n" << endl;
                cout<<crt2;
        }
                cout << "Unesite izbor: ";
                cin >> izbor;
                cin.ignore();
            }while(izbor<0 || izbor>2);
            switch (izbor){
                case 1:
                system("cls");
                if(rec=="admin") IspisiSortirano("admin");
                if(rec=="korisnik") IspisiSortirano("korisnik");

                case 2:
                if(rec=="admin") provjeriMob("admin");
                if(rec=="korisnik") provjeriMob("korisnik");
                break;

                case 0:
				if(rec=="admin"){
			    	adminMeni("admin");
			    	break;
            	}if(rec=="korisnik"){
            		korisnickiMenu("korsinik");
					break;
			    }
		    }
        }
     
         /*-------------------ISPISI SORTIRANO MENU (otvara ga nakon sto odaberemo Ispisi sve artikle (sortirano) u ADMIN menu)-----------------*/
       void IspisiSortirano(string rec){
        system("cls");
        int izbor;
        do{
        	cout<<crt2;
        	cout << "\t\t\t_________________________________" << endl;
        	cout << "\t\t\t|                               |" << endl;
            cout << "\t\t\t| 1. Sortirano po proizvodjacu: |" << endl;
            cout << "\t\t\t| 2. Sortirano po RAM-u:        |" << endl;
            cout << "\t\t\t| 3. Sortirano po ROM-u:        |" << endl;
            cout << "\t\t\t| 4. Sortirano po cijeni:       |" << endl;
            cout << "\t\t\t| 0. Nazad:                     |" << endl;
            cout << "\t\t\t|_______________________________|\n" << endl;
            cout<<crt2;
            cout << "Unesite izbor: ";
            cin >> izbor;
            cin.ignore();
        }while(izbor<0 || izbor>4);

        switch (izbor){
            case 1:
                sortirajPROIZVODJAC();
                system("cls");
                if(rec=="korisnik") IspisiSortirano("korisnik");
                if(rec=="admin") IspisiSortirano("admin");

            case 2:
                sortirajRAM();
                system("cls");
                if(rec=="korisnik") IspisiSortirano("korisnik");
                if(rec=="admin") IspisiSortirano("admin");

            case 3:
                sortirajROM();
                system("cls");
                if(rec=="korisnik") IspisiSortirano("korisnik");
                if(rec=="admin") IspisiSortirano("admin");

            case 4:
                sortirajCIJENU();
                system("cls");
                if(rec=="korisnik") IspisiSortirano("korisnik");
                if(rec=="admin") IspisiSortirano("admin");

            case 0:
            	if(rec=="admin"){
                    ProvjeraStanjaMeni("admin");
                }	
                if(rec=="korisnik"){
                    korisnickiMenu("korisnik");
                }
            } 
        }
    

    /*-------------------ISPIS mobitela onim redom kako su uneseni u datoteku(bez sortiranja)-----------------*/ 
    void IspisMobitela(){
        ifstream skladiste("skladiste.txt");
            vector<string> telefoni;
            int a;
            string temp;
            if(skladiste.fail()){
                    cout<<"Nemoguce pristupiti bazi podataka!!!";
            }else{
            cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
            cout<<left<<setw(6)<<"ID:"<<setw(14)<<"Proizvodjac:"<<setw(10)<<"Model:"<<setw(21)<<"Godina proizvodnje:"<<setw(10)<<"RAM(GB):"<<setw(10)<<"ROM(GB):"<<setw(12)<<"Kolicina:"<<setw(13)<<"Cijena(KM):"<<endl;
            cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
            getline(skladiste, temp);
            getline(skladiste, temp);
            getline(skladiste, temp);

            while(true){
                getline(skladiste, temp);
                if(skladiste.eof()) break;
                telefoni.push_back(temp);
            }        
            for(int i=0; i<telefoni.size(); i++){
                cout<<telefoni[i]<<endl;
            }
        skladiste.close();
        system("PAUSE");
        }
    }
     /*-------------------SORTIRANJE PO PROIZVODJACU-----------------*/
    void sortirajPROIZVODJAC(){
        ifstream skladiste("skladiste.txt");
            vector<string> telefoni;
            vector<string> mob;
            string temp,a;
            if(skladiste.fail()){
                cout<<"Nemoguce pristupiti bazi podataka!!!";
            }else{

            cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
            cout<<left<<setw(6)<<"ID:"<<setw(14)<<"Proizvodjac:"<<setw(10)<<"Model:"<<setw(21)<<"Godina proizvodnje:"<<setw(10)<<"RAM(GB):"<<setw(10)<<"ROM(GB):"<<setw(12)<<"Kolicina:"<<setw(13)<<"Cijena(KM):"<<endl;
            cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
            //preskacem prve tri linije i idem do proizvoda
            getline(skladiste, temp);
            getline(skladiste, temp);
            getline(skladiste, temp);
            //uzimam liniju po liniju i smjestam u vektor telefoni
            do{
                getline(skladiste, temp);
                telefoni.push_back(temp);
            }while(!skladiste.eof());
        skladiste.close();

    skladiste .open("skladiste.txt");
        getline(skladiste, temp);
        getline(skladiste, temp);
        getline(skladiste, temp);
        //uzimam samo drugu rijec (proizvodjac) i smjestam u vektor mob
        do{
            skladiste>>a;
            skladiste>>a;
            mob.push_back(a);
            skladiste>>a;
            skladiste>>a;
            skladiste>>a;
            skladiste>>a;
            skladiste>>a;
            skladiste>>a;
        }while(!skladiste.eof());
    skladiste.close();
        //sortiranje
        for(int i=0; i<telefoni.size(); i++){
            for(int j=i; j<telefoni.size(); j++){
                if(mob[i]>mob[j]) {
                    swap(mob[i], mob[j]);
                    swap(telefoni[i], telefoni[j]);
                }
            }
        }    
        //ispis    
        for(int i=0; i<telefoni.size(); i++){
            cout<<telefoni[i]<<endl;
            }
        system("PAUSE");
        }
    }
    /*-------------------SORTIRANJE PO RAMU-----------------*/ 
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
            cout<<left<<setw(6)<<"ID:"<<setw(14)<<"Proizvodjac:"<<setw(10)<<"Model:"<<setw(21)<<"Godina proizvodnje:"<<setw(10)<<"RAM(GB):"<<setw(10)<<"ROM(GB):"<<setw(12)<<"Kolicina:"<<setw(13)<<"Cijena(KM):"<<endl;
            cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
            getline(skladiste, temp);
            getline(skladiste, temp);
            getline(skladiste, temp);
            while(true){
                getline(skladiste, temp);
                if(skladiste.eof()) break;
                telefoni.push_back(temp);
                a=temp[51];
                ram.push_back(a);
            }
            for(int i=0; i<telefoni.size(); i++){
                for(int j=i; j<telefoni.size(); j++){
                    if(ram[i]<ram[j]) {
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
    /*-------------------SORTIRANJE PO ROMU-----------------*/
    void sortirajROM (){
        ifstream skladiste("skladiste.txt");
            vector<string> telefoni;
            vector<int> rom;
            int a,b,c,d,x;
            string temp;
                if(skladiste.fail()){
                    cout<<"Nemoguce pristupiti bazi podataka!!!";
                }else{
            cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
            cout<<left<<setw(6)<<"ID:"<<setw(14)<<"Proizvodjac:"<<setw(10)<<"Model:"<<setw(21)<<"Godina proizvodnje:"<<setw(10)<<"RAM(GB):"<<setw(10)<<"ROM(GB):"<<setw(12)<<"Kolicina:"<<setw(13)<<"Cijena(KM):"<<endl;
            cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
            getline(skladiste, temp);
            getline(skladiste, temp);
            getline(skladiste, temp);
            while(true){
                getline(skladiste, temp);
                if(skladiste.eof()) break;
                telefoni.push_back(temp);
                //pretvara string u int
                a=temp[61]-'0';
                b=temp[62]-'0';
                c=temp[63]-'0';
                d=temp[64]-'0';
                //sortiranje iz datoteke jer ROM moze imati 1,2,3 ili 4 cifre
                if( a>-1 && b>-1 && c>-1 && d>-1) x=a*1000+b*100+c+10+d;
                else if( a>-1 && b>-1 && c>-1 && d<-1) x=a*100+b*10+c;
                else if( a>-1 && b>-1 && c<-1 && d<-1) x=a*10+b;
                else if( a>-1 && b<-1 && c<-1 && d<-1) x=a;
                rom.push_back(x);
            }
            for(int i=0; i<telefoni.size(); i++){
                for(int j=i; j<telefoni.size(); j++){
                    if(rom[i]<rom[j]) {
                        swap(rom[i], rom[j]);
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
    /*-------------------SORTIRANJE PO CIJENI-----------------*/
    void sortirajCIJENU (){
        ifstream skladiste("skladiste.txt");
            vector<string> telefoni;
            vector<int> cijena;
            int a,b,c,d,x;
            string temp;
            if(skladiste.fail()){
                cout<<"Nemoguce pristupiti bazi podataka!!!";
            }else{

            cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
            cout<<left<<setw(6)<<"ID:"<<setw(14)<<"Proizvodjac:"<<setw(10)<<"Model:"<<setw(21)<<"Godina proizvodnje:"<<setw(10)<<"RAM(GB):"<<setw(10)<<"ROM(GB):"<<setw(12)<<"Kolicina:"<<setw(13)<<"Cijena(KM):"<<endl;
            cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
            getline(skladiste, temp);
            getline(skladiste, temp);
            getline(skladiste, temp);
            while(true){
                getline(skladiste, temp);
                if(skladiste.eof()) break;
                telefoni.push_back(temp);
                //pretvara string u int
                a=temp[83]-'0';
                b=temp[84]-'0';
                c=temp[85]-'0';
                d=temp[86]-'0';
                //sortiranje iz datoteke jer cijena moze imati 1,2,3 ili 4 cifre
                if( a>-1 && b>-1 && c>-1 && d>-1) x=a*1000+b*100+c+10+d;
                else if( a>-1 && b>-1 && c>-1 && d<-1) x=a*100+b*10+c;
                else if( a>-1 && b>-1 && c<-1 && d<-1) x=a*10+b;
                else if( a>-1 && b<-1 && c<-1 && d<-1) x=a;
                cijena.push_back(x);
            }
            for(int i=0; i<telefoni.size(); i++){
                for(int j=i; j<telefoni.size(); j++){
                    if(cijena[i]>cijena[j]) {
                        swap(cijena[i], cijena[j]);
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
    
void korisnickiMenu(string rec){//rec =="korisnik" ,pogledati u int mainu
	system("cls");
	//===================================================================================================================
	        cout<<crt2;
	cout << "\t\t\t\t________________" << endl;
	cout << "\t\t\t\t|              |" << endl;
	cout << "\t\t\t\t| Dobro dosli! |" << endl;
	cout << "\t\t\t\t|______________|\n";
	        cout<<endl<<crt2;
	//===================================================================================================================
	int izbor;
	do{
		cout << "\n\t\t   ";for(int i=1;i<=39;i++){cout << "_";};cout << endl;
		cout << "\t\t   |                                     |" << endl;
		cout << "\t\t   | 1. Pogledajte nasu ponudu mobitela: |" << endl;
		cout << "\t\t   | 2. Provjera stanja artikala:        |" << endl;
        cout << "\t\t   | 0. Kraj:                            |" << endl;
        cout << "\t\t   |_____________________________________|\n" << endl;
		cout << "Unesite izbor: ";
		cin >> izbor;
		cin.ignore();

        switch(izbor){
            case 1:
                system("cls");
	            IspisMobitela();
	            cout << "\n\t\t\t";for(int i=1;i<=32;i++){cout << "_";};cout << endl;
	            cout << "\t\t\t|                              |" << endl;
                cout << "\t\t\t| 1. Kupi artikal:             |" << endl;
                cout << "\t\t\t| 2. Ispisi sortirano artikle: |" << endl;
                cout << "\t\t\t| 0. Kraj:                     |" << endl;
				cout << "\t\t\t|______________________________|\n" << endl; 
                do{
                    cout << "Unesite izbor: ";
		            cin >> izbor;
                }while(izbor<0 || izbor>2);
                if(izbor==1) KupiArtikal();
                else if(izbor==2) IspisiSortirano("korisnik");//ide u ispisiSortirano namjenjena korsiniku odnosno ondje gdje ima if(rec=="korisnik")u navedenoj funkciji
            case 2:
                system("cls");
                provjeriMob("korisnik");   
            case 0:
                system("cls");
                loginMeni();    
        }
	  
	}while(izbor<0 || izbor>2); 
}
  /*-------------------POTVRDI PRODAJU ARTIKLA (funkciju koju ima samo admin)---------------------*/
void prodajArtikal(){
    //brisanje narudzbe iz datoteke narudzbe.txt
    cin.ignore();
    string line, name;
    string tem;
        do{
            cout << "Unesite ime i prezime osobe koja je narucila mobitel: ";
            getline(cin, name);
        }while(name.length()<1);    //ne moze se unijet prazan string
    ifstream narudzbe("narudzbe.txt", ios::in);
    ofstream ispiss ("tempp.txt");
        while (getline(narudzbe, line))
        {
        if (line.substr(0, name.size()) != name) { //sve dok je razlicito od imena i prezimena koje smo unijeli
            ispiss << line << endl;                //ispisuje liniju u datoteku 
            }
        else if (line.substr(0, name.size()) == name) { //ako se poklopi ime i prezime sa necim u datoteci
            getline(narudzbe, tem);                     //preskace sljedecu liniju (ispod svake narudzbe u datoteci imaju linije zbog izgleda, ali je i njih potrebno izbrisati zajedno sa narudzbom)
            }
        }
    narudzbe.close();
    ispiss.close();
    remove("narudzbe.txt");                 //brise narudzbe.txt
    rename("tempp.txt", "narudzbe.txt");  //mijenja naziv temp.txt u skladiste.txt
    string tenp;   
    ifstream unos("skladiste.txt");
            int br1=0;
            if(unos.is_open()){
            	while(!unos.eof()){
            		getline(unos,tenp);
            		br1++;
				}
                unos.close();
			}
  
    //smanjivanje količine za 1 iz datoteke skladiste.txt
    unos.open("skladiste.txt", ios::in);
    ofstream ispis("temp.txt");
        string temp;
        int ID;
        do{
            cout<<"\nUnesite ID mobitela: ";
            cin>>ID;
        }while(ID<0 || ID>br1-4); //ne moze se unositi ID veci od onih u datoteci
        int broj;
        if(unos.fail()) cout<<"Nemoguce otvoriti datoteku!"<<endl;
        else{
            getline(unos, temp);
            ispis<<temp<<endl;
            getline(unos, temp);
            ispis<<temp<<endl;
            getline(unos, temp);
            ispis<<temp<<endl;
            while(true){
                unos>>broj;
                if(unos.eof()) break;
                if(broj==ID){
                    ispis<<left<<setw(6)<<broj;
                    unos>>temp;
                    ispis<<setw(14)<<temp;
                    unos>>temp;
                    ispis<<setw(10)<<temp;
                    unos>>temp;
                    ispis<<setw(21)<<temp;
                    unos>>temp;
                    ispis<<setw(10)<<temp;
                    unos>>temp;
                    ispis<<setw(10)<<temp;
                    unos>>broj;
                    ispis<<setw(12)<<broj-1; // smanjujemo kolicinu iz datoteke za 1
                    unos>>temp;
                    ispis<<setw(13)<<temp<<endl;
                }
                else{
                    ispis<<broj;
                    getline(unos, temp);
                    ispis<<temp<<endl;
                }
            }
        }
    unos.close();
    ispis.close();
    remove("skladiste.txt");                     //brise skladiste.txt
    rename("temp.txt", "skladiste.txt");        //mijenja naziv temp.txt u skladiste.txt
        system("cls");
        cout<<crt2;
        cout<<"\n\t\t\t\t  Loading...\n" << endl;
        cout<<crt2;
        Sleep(2000);//ubaceno da bi se program malo zaustavio (loading) prije nego sto se ispise sljedeca poruka
        system("cls");
        cout<<crt2;
        cout << "\t      _____________________________________________________" << endl;
        cout << "\t      |                                                   |" << endl;
        cout << "\t      |            Artikal je uspjeno prodan!             |" << endl; 
        cout << "\t      | Brza posta je obavijestena za preuzimanje paketa. |" << endl;
        cout << "\t      |___________________________________________________|\n" << endl;
        cout<<crt2;
    system("PAUSE");
    cin.ignore();
    system("cls");
    provjeriNarudzbe();
}    
/*-------------------FUNKCIJA KOJU IZBACUJE KAD KUPAC ODABERE OPCIJU -Kupi artikal- ---------------------*/
    void KupiArtikal(){
        string tenp;   
        ifstream unos("skladiste.txt");
            int br1=0;
            if(unos.is_open()){
            	while(!unos.eof()){
            		getline(unos,tenp);
            		br1++;
				    }
                unos.close();
			    }
            int izbor;
        ofstream narudzba("narudzbe.txt", ios::app); //smjesta u posebnu datoteku narudzbe.txt koja je dostupna adminu
            narudzba<<"--------------------------------------------------------\n";
                cout<<crt;
                do{
            cout<<"Unesite vase ime i prezime: ";
            cin.ignore();
            getline(cin, kupac.imePrezime);
            narudzba<<kupac.imePrezime<<" ";
            }while(kupac.imePrezime.length()<1);
                cout<<crt;
                do{
            cout<<"Unesite vasu adresu (npr. Zelenih-beretki-22-Sarajevo): ";
            getline(cin, kupac.adresa);
            narudzba<<kupac.adresa<<" ";
            }while(kupac.adresa.length()<1);
                cout<<crt;
                do{
            cout<<"Unesite broj telefona: ";
            getline(cin, kupac.brTel);
            narudzba<<kupac.brTel<<" ";
            }while(kupac.brTel.length()<1);
                cout<<crt;
            do{
            cout<<"Unesite ID mobitela koji zelite kupiti: ";
            cin>>id;
            }while(id<0|| id>br1-4);
            narudzba<<id<<" ";
                cout<<crt;
            cout<<"Odaberite brzu postu: " << endl;
                cout<<crt;
                cout << "\t\t";for(int i=1;i<=53;i++){cout << "_";};cout << endl;
                cout << "\t\t|                                                   |" << endl;
                cout << "\t\t| 1-EuroExpress (10 KM - isporuka u toku 24h)       |" << endl;
                cout << "\t\t| 2-BH PostExpress (8 KM - isporuka u toku 24h-48h) |" << endl;
                cout << "\t\t| 3-A2B Express (12 KM - isporuka u toku 24h)       |" << endl;
                cout << "\t\t| 4-X Express (13 KM - isporuka u toku 24h)         |" << endl;
                cout << "\t\t|___________________________________________________|\n" << endl;
                cout<<crt;
            do{
                cout<<"\t\tIzbor: ";
                cin>>izbor;
            }while(izbor<1 || izbor>4);
            narudzba<<vratiPostu(izbor);
            narudzba<<"\n--------------------------------------------------------";
        narudzba.close();
            system("cls");
                cout<<crt2;
            cout<<"\n\t\t\t\t  Loading...\n" << endl;
                cout<<crt2;
            Sleep(2000);//ubaceno da bi se program malo zaustavio (loading) prije nego sto se ispise sljedeca poruka
            system("cls");
                cout<<crt2;
            cout << "\t\t  ";for(int i=1;i<=45;i++){cout << "_";};cout << endl;
            cout << "\t\t  |                                           |" << endl;
            cout << "\t\t  | Cestitamo, uspjesno ste narucili mobitel. |" << endl;
            cout << "\t\t  | Paket ocekujte u roku od 48 sati.         |" << endl;
            cout << "\t\t  | Vas MOBI-Shop, uvijek tu za vas!          |" << endl;
            cout << "\t\t  |___________________________________________|\n" << endl;
                cout<<crt2;
            system("PAUSE");
            cin.ignore();
            korisnickiMenu("korisnik");
    }
};
//unos username i pasworda za registraciju
void registracija(string *username,string *pasword,int j){
	cout<<setw(49)<<"Unesite username:";
    getline(cin,username[j]);
    cout<<setw(48)<<"Unesite pasword:";
    getline(cin,pasword[j]);
}
//unos username i pasworda  i smjestanje u niz za login
void login(string *lusername,string *lpasword,int i){
	cout<<setw(41)<<"Username:";
    getline(cin,lusername[i]);
    cout<<setw(40)<<"Pasword:";
    getline(cin,lpasword[i]);
}
//porede se uneseni pasword i username za login,sa do tad unesenim pasword i username u registracijama te vraca true ako postoji username i pasword u registracijama
bool reg(string *regU,string *regP,string *luser,string *lpas,int i,int j){
	int k=0;
	for(int n=0;n<j;n++){
		if (strcmp(luser[i-1].c_str(),regU[n].c_str()) == 0 && strcmp(lpas[i-1].c_str(),regP[n].c_str())== 0){	
				k++;
			}	}
		if(k==0) return false;
		else	return true;
		
}

//porede se uneseni pasword i username za login,sa paswordima i username u datoteci admini.txt u kojoj smo smjestili ove varijable,te vraca true ako postoji username i pasword u datoteci admini.txt
bool adm(string *luser,string *lpas,int i,Admin *novi){
	int k=0;
	for(int n=0;n<4;n++){
		if (strcmp(luser[i-1].c_str(),novi[n].username.c_str()) == 0 && strcmp(lpas[i-1].c_str(),novi[n].sifra.c_str())== 0){	
				k++;
			}	}
		if(k==0) return false;
		else	return true;
}

/*************************************** MAIN FUNKCIJA *********************************************/
int main (){
    system("Color 1F");
		std::cout << "\n\n\n\n\t\t  D";
		Sleep(200);
		std::cout << "\t  O" ;
		Sleep(200);
		std::cout << "\t  B" ;
		Sleep(200);
		std::cout << "\t  R" ;
		Sleep(200);
		std::cout << "\t  O\t";
		Sleep(200);
        std::cout << "\t  D";
		Sleep(200);
		std::cout << "\t  O" ;
		Sleep(200);
		std::cout << "\t  S" ;
		Sleep(200);
		std::cout << "\t  L" ;
		Sleep(200);
		std::cout << "\t  I\n\n"<<endl;
		Sleep(200);
		std::cout << "\t\t\t\t\t\t\t  U\n\n\n" ;
		Sleep(200);
		std::cout << "\t\t\t  M" ;
		Sleep(200);
		std::cout << "\t  O" ;
		Sleep(200);
		std::cout << "\t  B" ;
		Sleep(200);
		std::cout << "\t  I\t";
		Sleep(200);
		std::cout << "\t  S" ;
        Sleep(200);
        std::cout << "\t  H" ;
		Sleep(200);
		std::cout << "\t  O" ;
		Sleep(200);
		std::cout << "\t  P" ;
        Sleep(1500);
        system("Color F0");
    
    mobitel user;
	int izbor,a=0,b=0,br=0,o=0;
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
		cout << "\n\t\t\t\tIzbor: "; 
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
			user.adminMeni("admin");
				system("pause");
			}
			if(reg(username,pasword,lusername,lpasword,b,a)){
				user.korisnickiMenu("korisnik");
				system("pause");
			}else{
				cout<<"Pogresan username ili password \n";
				system("pause");
                break;
			}
		case 0:
                system("cls");
				return 0;		
		}
	}while(izbor != 0);
	}while(izbor<1 || izbor>3);

delete [] novi;
   
return 0;
}
