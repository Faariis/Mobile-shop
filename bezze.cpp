#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>

using namespace std;
char * crt = "\n========================================\n";
	/*
	Napraviti enumeracije
	godinaStudija, nacinStudiranja, Odgovori
	*/
enum godinaStudija {prva=1,druga,treca,cetvrta};
enum nacinStudiranja {redovan, vanredni};
enum Odgovori {NETACNO,TACNO};

enum korisnickaUloga {student, administrator};

const int maxPitanja = 100;
const int maxStudenata = 100;

int brojPitanja = 0;
int brojStudenata = 0;



struct Osoba{
	char imePrezime[50];
	char username[30];
	char password[30];
};

struct Administrator{
	Osoba administrator;
	int ID;
	korisnickaUloga uloga;	
};

struct Student
{
	Osoba student;
	int brIndeksa;
	korisnickaUloga uloga;
	bool radioTest;
	nacinStudiranja nacin;
	godinaStudija godina;
	Odgovori odgovori[maxPitanja];
};

struct Pitanje{
	char tekstPitanja[100];
	Odgovori odgovorNaPitanje;
};
Pitanje pitanjaDB[maxPitanja];
Student studentiDB[maxStudenata];
Administrator admin;

void Dodaj(char *tekstPitanja, Odgovori tacanOdgovor){
	Pitanje nekoPitanje;
	strcpy(nekoPitanje.tekstPitanja, tekstPitanja);
	nekoPitanje.odgovorNaPitanje = tacanOdgovor;
	pitanjaDB[brojPitanja] = nekoPitanje;
	brojPitanja++;
}

void dodajDefaultPitanja(){
	Dodaj("Enumeracije i unije su sinonimi?",NETACNO);
	Dodaj("Moguce je kreirati anonimnu uniju?",TACNO);
	Dodaj("Svi clanovi unije koriste istu memorijsku lokaciju?",TACNO);
	Dodaj("Unija moze biti deklarisana unutar strukture?",NETACNO);
	Dodaj("Unija moze biti deklarisana unutar strukture?",TACNO);
}

void prikaziPitanje(int rbPitanja) {
	cout << "\n\t" << pitanjaDB[rbPitanja].tekstPitanja << endl;
}
Odgovori dajTacanOdgovor(int rbPitanja) {
	return pitanjaDB[rbPitanja].odgovorNaPitanje;
}

int dajBrojTacnih(Student & s) {
	int brTacnih = 0;
	for(int i=0;i<brojPitanja;i++){
		if(s.odgovori[i] == dajTacanOdgovor(i)){
			brTacnih++;
		}
	}
	return brTacnih;
}
//Funkcija za unos podataka: imePrezime, username, password, nacinStudiranja, godinaStudija
//Vrijednosti korisnickaUloga i radio test su po defaultu student i false
//Ova funkcija treba da provjerava sve username od studenata i brojeve indeksa, ne mogu se ponavljati
//Niti jedan student ne smije imati username admin, a username admin-a je: edin
void unosPodatakaStudenta(){
	system("cls");
	if(brojStudenata==0){
		cout << crt << "\t::Registracija studenta::" << crt;
		cout << "Registracija za prvog studenta:\n";
		cout << "Unesite ime i prezime: ";
		cin.getline(studentiDB[brojStudenata].student.imePrezime, 50);
		do{
			cout << "\tUnesite username: ";
			cin.getline(studentiDB[brojStudenata].student.username,30);
			if(!strcmp(studentiDB[brojStudenata].student.username, admin.administrator.username)){
				cout << "\tGreska: Uneseni username je od admina!\n";
			}else{
				break;
			}
		}while(1);
		cout << "\tUnesite password: ";
		cin.getline(studentiDB[brojStudenata].student.password,30);
		do{
			cout << "\tUnesite broj indeksa: ";
			cin >> studentiDB[brojStudenata].brIndeksa;
			if(!cin){
				cin.clear();
				cout << "\tGreska: Uneseni indeks mora biti broj!\n";
				cin.ignore(10000,'\n');
			}else{
				break;
			}
		}while(1);
		int x;
		do{
			cout << "\tNacin studiranja (0 - redovan, 1 - vanredan): ";
			cin >> x;
		}while(x<0 || x>1);
		studentiDB[brojStudenata].nacin = (nacinStudiranja)x;
		do{
			cout << "\tUnesite godinu studija (1,2,3 ili 4): ";
			cin >> x;
		}while(x<1 || x>4);
		studentiDB[brojStudenata].godina = (godinaStudija)x;
		studentiDB[brojStudenata].radioTest = false;
		studentiDB[brojStudenata].uloga = student;
		brojStudenata++;
	}else{
		cout << crt << "\t::Registracija studenta::" << crt;
		cout << "Registracija za prvog studenta:\n";
		cout << "Unesite ime i prezime: ";
		cin.getline(studentiDB[brojStudenata].student.imePrezime, 50);
		bool postoji = false;
		do{
			cout << "\tUnesite username: ";
			cin.getline(studentiDB[brojStudenata].student.username,30);
			for(int i=0;i<brojStudenata;i++){
				if(!strcmp(studentiDB[brojStudenata].student.username,admin.administrator.username) || 
				   !strcmp(studentiDB[brojStudenata].student.username,studentiDB[i].student.username)){
					cout << "\tGreska: Uneseni username postoji!\n";
					postoji = true;
				}
			}
		}while(postoji);
		cout << "\tUnesite password: ";
		cin.getline(studentiDB[brojStudenata].student.password,30);
		do{
			cout << "\tUnesite broj indeksa: ";
			cin >> studentiDB[brojStudenata].brIndeksa;
			bool postoji = false;
			if(!cin){
				cin.clear();
				cout << "\tGreska: Uneseni indeks mora biti broj!\n";
				cin.ignore(10000,'\n');
			}else{
				for(int i=0;i<brojStudenata;i++){
					if(studentiDB[brojStudenata].brIndeksa == studentiDB[i].brIndeksa){
						postoji = true;
						cout << "\tGreska: Uneseni indeks vec postoji!\n";
					}
				}
				if(!postoji){
					break;	
				}
			}
		}while(1);
		int x;
		do{
			cout << "\tNacin studiranja (0 - redovan, 1 - vanredan): ";
			cin >> x;
		}while(x<0 || x>1);
		studentiDB[brojStudenata].nacin = (nacinStudiranja)x;
		do{
			cout << "\tUnesite godinu studija (1,2,3 ili 4): ";
			cin >> x;
		}while(x<1 || x>4);
		studentiDB[brojStudenata].godina = (godinaStudija)x;
		studentiDB[brojStudenata].radioTest = false;
		studentiDB[brojStudenata].uloga = student;
		brojStudenata++;
	}
}


void pokreniTest(Student & s) {
	for(int i=0;i<brojPitanja;i++){
		cout << i+1 << ". pitanje: ";
		prikaziPitanje(i);
		int x;
		do{
			cout << "\t0 - Netacno\n\t1 - Tacno\n\tOdgovor: ";
			cin >> x;
		}while(x<0 || x>1);
		s.odgovori[i] = (Odgovori)x;
	}
	s.radioTest = true;
}

int adminMeni() {
	int izbor;
	system("cls");
	do
	{
		cout << crt << "\t::ADMIN::" << crt;
		cout << "1. Unos pitanja" << endl;
		cout << "2. Unos novog studenta" << endl;
		cout << "3. Prikazi rezultate testova" << endl;
		cout << "4. Pretraga" << endl;
		cout << "5. Resetuj test za studenta" << endl;		
		cout << "6. Prikazi sve studente" << endl;
		cout << "7. Priakzi sva pitanja sa testa" << endl;
		cout << "8. Kraj rada" << crt;
		cout << "Unesite izbor: ";
		cin >> izbor;
	} while (izbor<1 || izbor>8);
	return izbor;
}

int studentMeni() {
	int izbor;
	system("cls");
	do
	{
		cout << crt << "\t::Student::" << crt;
		cout << "1. Pokreni test" << endl;
		cout << "2. Prikazi rezultate" << endl;
		cout << "3. Kraj rada" << crt;
		cout << "Unesite izbor: ";
		cin >> izbor;
	} while (izbor<1 || izbor>3);
	return izbor;
}

int prikaziStudente()
{
	int rb;
	cout << setw(5) << " Rb. " << setw(30) << left << "Ime i prezime" << setw(10) << "Broj indeksa\n";
	cout << "-----------------------------------------------\n";
	for(int i = 0;i<brojStudenata;i++){
		cout << setw(3) << right << i+1 << setw(2) << ". "<< setw(30) << left << studentiDB[i].student.imePrezime 
		     << setw(12) << right << studentiDB[i].brIndeksa << endl;
	}
	cout << "-----------------------------------------------\n";
	do{
		cout << "Unesite redni broj studenta: ";
		cin >> rb;
	}while(rb<1 || rb>brojStudenata);
	return rb-1;
}

void prikazStudenata(){
	if(brojStudenata == 0){
		cout << "Trenutno nema registrovanih studenata!\n";
		system("pause");
		system("cls");
	}else{
		cout << setw(5) << " Rb. " << setw(30) << left << "Ime i prezime" << endl;
		cout << "-----------------------------------------------\n";
		for(int i = 0;i<brojStudenata;i++){
			cout << setw(3) << right << i+1 << setw(2) << ". "<< setw(30) 
			     << left << studentiDB[i].student.imePrezime << endl;
		}
		cout << "-----------------------------------------------\n";
	}
}

void prikaziPitanja(){
	cout << setw(3) << "\nPitanja za test:\n";
	for(int i=0;i<brojPitanja;i++){
		cout << setw(3) << i+1 << ". " << pitanjaDB[i].tekstPitanja << endl;
	}
}

void unosPitanja(){
	cin.ignore();
	int x;
	cout << "Unesite tekst pitanja: ";
	cin.getline(pitanjaDB[brojPitanja].tekstPitanja,100);
	do{
		cout << "Unesite odgovor na pitanje 0 - Netacno, 1 - Tacno\n";
		cout << "Odabir: ";
		cin >> x;	
	}while(x<0 || x>1);
	pitanjaDB[brojPitanja].odgovorNaPitanje = (Odgovori)x;
	brojPitanja++;
}

string vratiGodinu(int x){
	switch(x){
		case 1:
			return "prvoj";
		case 2:
			return "drugoj";
		case 3:
			return "trecoj";
		case 4:
			return "cetvrtoj";
	}
}

string vratiNacin(int x){
	switch(x){
		case 0:
			return "redovnih";
		case 1:
			return "vanrednih";
	}
}

void pretraga(){
	system("cls");
	int izbor;
	do{
		cout << crt << "\t::Pretraga meni::" << crt;
		cout << "1. Po godini studija " << endl;
		cout << "2. Po nacinu studiranja " << endl;
		cout << "3. Po rezultatima testa " << endl;
		cout << "4. Izlaz iz pretrage!" << endl;
		cout << "Unesite izbor: ";
		cin >> izbor;
	}while(izbor<1 || izbor>4);
	if(izbor==4){
	}
	int x;
	if(izbor==1){
		do{
			cout << "Unesite godinu studija za ispis studenata: ";
			cin >> x;	
		}while(x<1 || x>4);
		int br = 1;
		cout << setw(5) << " Rb. " << setw(30) << left << "Ime i prezime" << setw(10) << "Broj indeksa\n";
		cout << "-----------------------------------------------\n";
		for(int i = 0;i<brojStudenata;i++){
			if(studentiDB[i].godina == (godinaStudija)x){
				cout << setw(3) << right << br++ << setw(2) << ". "
				     << setw(30) << left << studentiDB[i].student.imePrezime 
		     		 << setw(12) << right << studentiDB[i].brIndeksa << endl;
			}	
		}
		if(br==1){
			cout << "Nema studenata na " << vratiGodinu(x) << " godini!\n";
		}
		cout << "-----------------------------------------------\n";	
	}else if(izbor==2){
		do{
			cout << "Unesite nacin studiranja za ispis studenata: \n0-redovan, 1-vanredan\n";
			cin >> x;	
		}while(x<0 || x>1);
		int br = 1;
		cout << setw(5) << " Rb. " << setw(30) << left << "Ime i prezime" << setw(10) << "Broj indeksa\n";
		cout << "-----------------------------------------------\n";
		for(int i = 0;i<brojStudenata;i++){
			if(studentiDB[i].nacin == (nacinStudiranja)x){
				cout << setw(3) << right << br++ << setw(2) << ". "
				     << setw(30) << left << studentiDB[i].student.imePrezime 
		     		 << setw(12) << right << studentiDB[i].brIndeksa << endl;
			}	
		}
		if(br==1){
			cout << "Nema " << vratiNacin(x) << " studenata!\n";
		}
		cout << "-----------------------------------------------\n";
	}else if(izbor==3){
		int minP,maxP;
		do{
			cout << "Unesite minimalni postotak: ";
			cin >> minP;
		}while(minP<0 || minP>100);
		do{
			cout << "Unesite maksimalni postotak: ";
			cin >> maxP;
		}while((maxP<0 || maxP>100) && maxP<minP);
		int br = 1;
		cout << setw(5) << " Rb. " << setw(30) << left << "Ime i prezime" << setw(10) << "Broj indeksa\n";
		cout << "-----------------------------------------------\n";
		for(int i = 0;i<brojStudenata;i++){
			int t = dajBrojTacnih(studentiDB[i]);
			int p = 100.*t/brojPitanja;
			if(p>minP && p<maxP){
				cout << setw(3) << right << br++ << setw(2) << ". "
				     << setw(30) << left << studentiDB[i].student.imePrezime 
		     		 << setw(12) << right << studentiDB[i].brIndeksa << endl;
			}	
		}
		if(br==1){
			cout << "Nema studenata sa procentom iz intervala [" 
				 << minP << "," << maxP << "]!\n";
		}
		cout << "-----------------------------------------------\n";
	}
}

int loginMeni(){
	system("cls");
	int izbor;
	do{
		cout << crt << "\t::LOGIN / REGISTER::" << crt;
		cout << "1. Login " << endl;
		cout << "2. Registracija usera " << endl;
		cout << "3. Napustiti sistem " << endl;
		cout << "Unesite izbor: ";
		cin >> izbor;
		cin.ignore();
	}while(izbor<1 || izbor>3);
}

int login(char username[30], char password[30]){
	cout << crt << "\t::Login::" << crt;
	cout << "Username: ";
	cin.getline(username,30);
	cout << "Password: ";
	cin.getline(password,30);
	if(!strcmp(username,admin.administrator.username) && !strcmp(password, admin.administrator.password)){
		return 123456;		
	}else{
		for(int i=0;i<brojStudenata;i++){
			if(!strcmp(username, studentiDB[i].student.username) && 
			   !strcmp(password, studentiDB[i].student.password)){
			   	return studentiDB[i].brIndeksa;
			   }
		}
	}
	cin.ignore();
}

int main()
{
	strcpy(admin.administrator.imePrezime, "Edin Tabak");
	strcpy(admin.administrator.username, "kobara");
	strcpy(admin.administrator.password, "abcd1234");
	admin.ID = 123456;
	admin.uloga = administrator;
	dodajDefaultPitanja();
	int izbor;
	do{
		char user[30],pass[30];
		system("cls");
		izbor = loginMeni();
		if(izbor == 3){
			break;
		}else if(izbor == 1){
			int id = login(user,pass);
			if(id = admin.ID){
				system("cls");
				do{
					izbor = adminMeni();
					if(izbor == 8){
						break;
					}
					if(izbor == 1){
						unosPitanja();
						for(int i=0;i<brojStudenata;i++){
							studentiDB[i].radioTest = false;
						}
					}else if(izbor == 2){
						cin.ignore();
						unosPodatakaStudenta();
					}else if(izbor == 3){
						Student &st = studentiDB[prikaziStudente()];
						if(st.radioTest){
							int t = dajBrojTacnih(st);
							float p = 100.*t/float(brojPitanja);
							cout << "Uspjeh je " << setprecision(4) << p << "% - (" 
				     	 	<< t << "/" << brojPitanja << ")" << endl;
						}else{
							cout << "Student " << st.student.imePrezime << " nije jos radio test!\n";
						}
					}else if(izbor==4){
						pretraga();
					}else if(izbor==5){
						Student &st = studentiDB[prikaziStudente()];
						st.radioTest = false;
					}else if(izbor==6){
						prikazStudenata();
					}else if(izbor==7){
						prikaziPitanja();
					}
					system("pause");
					system("cls");
				}while(1);
			}else{
				for(int i=0;i<brojStudenata;i++){
					if(id == studentiDB[i].brIndeksa){
						do{
							izbor = studentMeni();
							if(izbor==3){
								break;
							}else if(izbor==1){
								if(studentiDB[i].radioTest){
									cout << "Vi ste vec radili test!\n";
								}else{
									for(int j=0;j<brojPitanja;j++){
										cout << j+1 << ". pitanje: ";
										prikaziPitanje(j);
										int x;
										do{
											cout << "0 - Netacno, 1 - Tacno";
											cout << "\nOdgovor: "; 
										}while(x<0 || x>1);
										studentiDB[i].odgovori[j] = (Odgovori)x;
									}
									studentiDB[i].radioTest = true;
								}
							}else if(izbor == 2){
								if(studentiDB[i].radioTest){
									int t = dajBrojTacnih(studentiDB[i]);
									float p = 100.*t/float(brojPitanja);
									cout << "Uspjeh je " << setprecision(4) << p << "% - (" 
				     	 				 << t << "/" << brojPitanja << ")" << endl;
								}else{
									cout << "Niste jos radili test!\n";
								}
							}
							system("pause");
							system("cls");
						}while(1);
						break;
					}
				}
			}
		}else if(izbor == 2){
			unosPodatakaStudenta();
		}
	}while(1);
	return 0;
}