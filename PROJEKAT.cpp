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
//LOGIN MENI
	system("cls"); 
		//==========================================================================
		for(int i=1;i<=80;i++){if(i<80){cout << "=";}else if(i==80){cout << endl;}}
		cout << "\t\t\t ";for(int i=1;i<=25;i++){cout << "_";};cout << endl;
		cout << "\t\t\t |                       |" << endl;
        cout << "\t\t\t |Dobrodosli u Mobi-SHOP!|" << endl;
        cout << "\t\t\t |_______________________|\n\n";
        for(int i=1;i<=80;i++){if(i<80){cout << "=";}else if(i==80){cout << endl;}}
        //==========================================================================
for(int i=1;i<=80;i++){if(i<80){cout << "_";}else if(i==80){cout << endl;}}
		cout <<"\n\t\t\t  :::::LOGIN / REGISTER:::::"<<endl;
		for(int i=1;i<=80;i++){if(i<80){cout << "_";}else if(i==80){cout << endl;}}
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
   		cout<<"-----------------------ADMIN MENU!---------------------------------"<<endl;
	int izbor;
	do{
		cout << "1. Dodati novi artikal(mobitel): " << endl;
		cout << "2. Provjera stanja artikala: " << endl;
        cout << "3. Provjeri narudzbe: " << endl;
		cout << "4. Prodaj artikal: " << endl;
		cout<<"5. Stanje kase"<<endl;
        cout <<"0. Kraj: "<<endl;
		cout << "Unesite izbor: ";
		cin >> izbor;
		cin.ignore();
	}while(izbor<0 || izbor>5); 

    switch(izbor){
    	case 0:
        loginMeni();
        case 1:
        system("cls");
        unosMobitela();
        case 2:
        system("cls");
        ProvjeraStanjaMeni("admin");
        case 3:
        system("cls");
       	case 5:
        	system("cls");
			int budzet=50000;
			cout<<"Budzet za mjesec juni 2021: "<<budzet<<" KM."<<endl;
			cout<<"Potroseno na nabavke: "<<stanjeKase("skladiste.txt")<<" KM."<<endl;
			//ovdje dodati u budzet i pare od prodaje kad bude 
			cout<<"Ukupan rashod i prihod: "<< budzet-stanjeKase("skladiste.txt")<< " KM."<<endl;
                

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
            /*-------------------PROVJERAVA DA LI SE MOBITEL NALAZI U SKLADISTU(IMA LI GA NA STANJU)-----------------*/
    void provjeriMob(){
                ifstream unosV("skladiste.txt");
                string linija;
                int br=0;
                if (unosV.fail()){
                    cout<<"fail";
                }else{
                    while(!unosV.eof()){
                        getline(unosV, linija);
                        br++;
                    };
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
            cout<<"Unesite proizvodjaca mobitela (npr. iPhone): ";
            cin>>proizv;
            cout<<"Unesite model mobitela (npr. 12-pro): ";
            cin>>mod;
            for(int i=0;i<br-3;i++){
                if(strcmp(proizv,nizMobitela[i].nazivv)==0)
            }
    
    }

         /*-------------------PROVJERA STANJA MENU(nalazi se u sklopu admin menua)-----------------*/
        void ProvjeraStanjaMeni(string rec){//rec ce biti jednako "admin" ili "korisnik" te u zavisnosti od toga ce se pozivati 
            system("cls");
            int izbor;
            do{
                cout << "1. Ispisi sve artikle (sortirano): " << endl;
                if(rec=="admin"){
               		 cout << "2. Provjeri mobitel u skladistu : " << endl;
                }if(rec=="korisnik"){
                	cout << "2. Pretrazi mobitel: " << endl;
				}cout << "0. Nazad: " << endl;
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
                if(rec=="admin") provjeriMob();
                if(rec=="korisnik") provjeriMob();
                break;
                case 0:
				if(rec=="admin"){
			    	adminMeni("admin");
            	}if(rec=="korisnik"){
            		korisnickiMenu("korsinik");
			}
		}
        
        }
     
         /*-------------------ISPISI SORTIRANO MENU (otvara ga nakon sto odaberemo Ispisi sve artikle (sortirano) u ADMIN menu)-----------------*/
        void IspisiSortirano(string rec){
        system("cls");
        int izbor;
        do{
            cout << "1. Sortirano po proizvodjacu: " << endl;
            cout << "2. Sortirano po RAM-u: " << endl;
            cout << "3. Sortirano po ROM-u: " << endl;
            cout << "4. Sortirano po cijeni: " << endl;
            cout << "0. Nazad: " << endl;
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
        }	if(rec=="korisnik"){
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
        skladiste.close();
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
                if(rom[i]>rom[j]) {
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
     //vraca km potrosen za nabavku telefona
    int stanjeKase (string imeFajla){
        ifstream skladiste(imeFajla);
        vector<string> telefoni;
        vector<int> kasa;
        vector<int> kolicina;
        int a,b,c,d,x,e,f,y;
        string temp;
        if(skladiste.fail()){
            cout<<"Nemoguce pristupiti bazi podataka!!!";
        }else{
        getline(skladiste, temp);
        getline(skladiste, temp);
        getline(skladiste, temp);
        while(true){
            getline(skladiste, temp);
            if(skladiste.eof()) break;
            telefoni.push_back(temp);
            //-'0' pretvara string u int
            e=temp[71]-'0';
            f=temp[72]-'0';
            a=temp[83]-'0';
            b=temp[84]-'0';
            c=temp[85]-'0';
            d=temp[86]-'0';
            //sortiranje iz datoteke jer cijena moze imati 1,2,3 ili 4 cifre
            if( a>-1 && b>-1 && c>-1 && d>-1) x=a*1000+b*100+c+10+d;
            else if( a>-1 && b>-1 && c>-1 && d<-1) x=a*100+b*10+c;
            else if( a>-1 && b>-1 && c<-1 && d<-1) x=a*10+b;
            else if( a>-1 && b<-1 && c<-1 && d<-1) x=a;
            kasa.push_back(x);
            //sortiranje iz datoteke jer kolicina moze imati jednu ili 2 cifre
                if( e>-1 && f>-1) y=e*10+f;
            else if( e>-1 && f<-1) y=e;
            kolicina.push_back(y);
        }
        int u=0;
        for(int i=0; i<telefoni.size(); i++){
            u+=kasa[i]*kolicina[i];
        }
        skladiste.close();
        return u;
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
    
void korisnickiMenu(string rec){//rec =="korisnik" ,pogledaj u int mainu
	system("cls");
	cout<<"-----------------------KORISNICKI MENU!---------------------------------"<<endl;
	int izbor;
	do{
		cout << "1. Pogledajte nasu ponudu mobitela: " << endl;
		cout << "2. Provjera stanja artikala: " << endl;
        cout <<"0. Kraj: "<<endl;
		cout << "Unesite izbor: ";
		cin >> izbor;
		cin.ignore();

        switch(izbor){
            case 1:
                system("cls");
	            IspisMobitela();
                cout << "\n\n1. Kupi artikal: " << endl;
                cout << "2. Ispisi sortirano artikle: " << endl;
                cout <<"0. Kraj: "<<endl;
                do{
                    cout << "Unesite izbor: ";
		            cin >> izbor;
                }while(izbor<0 || izbor>2);
                if(izbor==1) KupiArtikal();
                else if(izbor==2) IspisiSortirano("korisnik");//ide u ispisiSortirano namjenjena korsiniku odnosno ondje gdje ima if(rec=="korisnik")u navedenoj funkciji
                else if(izbor==0) korisnickiMenu("korisnik");
    		}
	
        
	}while(izbor<0 || izbor>5); 
}
  /*-------------------POTVRDI PRODAJU ARTIKLA (funkciju koju ima samo admin)---------------------*/
void prodajArtikal(int ID){
    ifstream unos("skladiste.txt");
    ofstream ispis("temp.txt");
    string temp;
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
    remove("skladiste.txt");
    rename("temp.txt", "skladiste.txt");
}    
 /*-------------------FUNKCIJA KOJU IZBACUJE KAD KUPAC ODABERE OPCIJU -Kupi artikal- ---------------------*/
    void KupiArtikal(){
        int izbor;
        ofstream narudzba("narudzbe.txt", ios::app); //smjesta u posebnu datoteku narudzbe.txt koja je dostupna adminu
        narudzba<<"--------------------------------------------------------\n";
        cout<<"\n\tUnesite vase ime i prezime: ";
        cin.ignore();
        getline(cin, kupac.imePrezime);
        narudzba<<kupac.imePrezime<<" ";
        cout<<"\tUnesite vasu adresu (bez razmaka sa crticama izmedju- npr. Travnicka-16-Zenica): ";
        getline(cin, kupac.adresa);
        narudzba<<kupac.adresa<<" ";
        cout<<"\tUnesite broj telefona: ";
        getline(cin, kupac.brTel);
        narudzba<<kupac.brTel<<" ";
        cout<<"\tUnesite ID mobitela koji zelite kupiti: ";
        cin>>id;
        narudzba<<id<<" ";
        cout<<"\n\tOdaberite brzu postu: ";
            cout<<"\n-------------------------------------------------------------------------------"<<endl;
            cout<<"\t\t1-EuroExpress (10 KM - isporuka u toku 24h)"<<endl;
            cout<<"\t\t2-BH PostExpress (8 KM - isporuka u toku 24h-48h)"<<endl;
            cout<<"\t\t3-A2B Express (12 KM - isporuka u toku 24h)"<<endl;
            cout<<"\t\t4-X Express (13 KM - isporuka u toku 24h)"<<endl;
            cout<<"-------------------------------------------------------------------------------"<<endl;
        do{
            cout<<"\t\tIzbor: ";
            cin>>izbor;
        }while(izbor<1 || izbor>4);
        narudzba<<vratiPostu(izbor);
        narudzba<<"\n--------------------------------------------------------";
        narudzba.close();
        system("cls");
        Sleep(1500);//ubaceno da bi se program malo zaustavio (loading) prije nego sto se ispise sljedeca poruka
        cout<<"\n\n\tCestitamo uspjesno ste narucili mobitel, na vasoj adresi ce biti najduze za 48h.";
        cout<<"\n\tSvakako nam javite utiske.";
        cout<<"\n\n\tVas MOBI-Shop :)\n"<<endl;
        system("PAUSE");
        cin.ignore();
        korisnickiMenu("korisnik");
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



bool adm(string *luser,string *lpas,int i,Admin *novi ){
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
			user.adminMeni("korisnik");
				system("pause");
			}
			if(reg(username,pasword,lusername,lpasword,b,a)){
				user.korisnickiMenu("korisnik");
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
user.korisnickiMenu("korisnik");

return 0;
}