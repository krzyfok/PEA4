#include<iostream>
#include"Menu.h"
#include"Gen1.h"
#include"Gen2.h"
#include<fstream>
#include<string>
#include<vector>
using namespace std;

vector<int> Menu::rozmiary_macierzy;
int Menu::powtorzenia;
int Menu::liczba_instancji;
int Menu::progres;
int Menu::tryb;
int Menu:: algTyp;
double Menu :: czas1;
double Menu :: czas2;
double Menu :: czas3;
int Menu:: pop1;
int Menu :: pop2;
int Menu::pop3;
string Menu::dane_wejsciowe1;
string Menu :: dane_wejsciowe2;
string Menu :: dane_wejsciowe3;


void Menu::wczytanie_konfiguracji()
{	//wczytywanie danych z pliku konfiguraycjnego
	string nazwa_pliku = "config.txt";
	ifstream plik(nazwa_pliku);

	if (plik.is_open()) {

		string nazwa;
		int dane;

		cout << "KONFIGURACJA: " << endl;
		//tryb
		plik >> nazwa;
		plik >> tryb;
		cout << nazwa << " " << tryb << endl;

	//rodzaj algorytmu jezeli tryb pojedynczego pliku
		plik >> nazwa;
		plik >> algTyp;
		cout << nazwa << " " << algTyp << endl;
		
//pliki
		plik >> nazwa;
		plik >> dane_wejsciowe1;
		cout << nazwa << " " << dane_wejsciowe1 << endl;

		
		plik >> nazwa;
		plik >> dane_wejsciowe2;
		cout << nazwa << " " << dane_wejsciowe2 << endl;

		
		plik >> nazwa;
		plik >> dane_wejsciowe3;
		cout << nazwa << " " << dane_wejsciowe3 << endl;


		plik >>nazwa;
		plik>>czas1;
		cout << nazwa << " " << czas1 << endl;

		plik >>nazwa;
		plik>>czas2;
		cout << nazwa << " " << czas2 << endl;

		plik >>nazwa;
		plik>>czas3;
		cout << nazwa << " " << czas3 << endl;

		plik >>nazwa;
		plik>>pop1;
		cout << nazwa << " " << pop1 << endl;

		plik >>nazwa;
		plik>>pop2;
		cout << nazwa << " " << pop2 << endl;

		plik >>nazwa;
		plik>>pop3;
		cout << nazwa << " " << pop3 << endl;

		plik.close();

	}
	else {
		cout << "BRAK PLIKU KONFIGURACYJNEGO\n";
		exit(0);
	}
}
void Menu::main_menu() {
	wczytanie_konfiguracji();

	if (tryb == 0)
	{
		int liczba_powtorzen=10;
	
		Gen1 a1;
		Gen2 a2;
		
		
		AlgAbstr::wczytywanie(dane_wejsciowe1);
		

			cout<<"PLIK 1"<<endl;
		for(int i =0;i<liczba_powtorzen;i++)
		{
		
		cout<<a1.start(czas1,pop1)<<" milisekund "<<endl;
		 }
		for(int i =0;i<liczba_powtorzen;i++)
			{
		cout<<a1.start(czas1,pop2)<<" milisekund "<<endl;
		 }
		for(int i =0;i<liczba_powtorzen;i++)
		{
		cout<<a1.start(czas1,pop3)<<" milisekund "<<endl;
		 }
		 
		for(int i =0;i<liczba_powtorzen;i++)
		{
		
		cout<<a2.start(czas1,pop1)<<" milisekund "<<endl;
		 }
		for(int i =0;i<liczba_powtorzen;i++)
			{
		cout<<a2.start(czas1,pop2)<<" milisekund "<<endl;
		 }
		for(int i =0;i<liczba_powtorzen;i++)
		{
		cout<<a2.start(czas1,pop3)<<" milisekund "<<endl;
		 }
		 cout<<"PLIK 2"<<endl;

		 AlgAbstr::wczytywanie(dane_wejsciowe2);
		for(int i =0;i<liczba_powtorzen;i++)
		{
		
		cout<<a1.start(czas2,pop1)<<" milisekund "<<endl;
		 }
		for(int i =0;i<liczba_powtorzen;i++)
			{
		cout<<a1.start(czas2,pop2)<<" milisekund "<<endl;
		 }
		for(int i =0;i<liczba_powtorzen;i++)
		{
		cout<<a1.start(czas2,pop3)<<" milisekund "<<endl;
		 }
		 
		 for(int i =0;i<liczba_powtorzen;i++)
		{
		
		cout<<a2.start(czas2,pop1)<<" milisekund "<<endl;
		 }
		for(int i =0;i<liczba_powtorzen;i++)
			{
		cout<<a2.start(czas2,pop2)<<" milisekund "<<endl;
		 }
		for(int i =0;i<liczba_powtorzen;i++)
		{
		cout<<a2.start(czas2,pop3)<<" milisekund "<<endl;
		 }
		
AlgAbstr::wczytywanie(dane_wejsciowe3);
		cout<<"PLIK 3"<<endl;
	for(int i =0;i<liczba_powtorzen;i++)
		{
		
		cout<<a1.start(czas3,pop1)<<" milisekund "<<endl;
		 }
		for(int i =0;i<liczba_powtorzen;i++)
			{
		cout<<a1.start(czas3,pop2)<<" milisekund "<<endl;
		 }
		for(int i =0;i<liczba_powtorzen;i++)
		{
		cout<<a1.start(czas3,pop3)<<" milisekund "<<endl;
		 }
	 	 for(int i =0;i<liczba_powtorzen;i++)
	 	{
		
		cout<<a2.start(czas3,pop1)<<" milisekund "<<endl;
		 }
		for(int i =0;i<liczba_powtorzen;i++)
			{
		cout<<a2.start(czas3,pop2)<<" milisekund "<<endl;
		 }
		for(int i =0;i<liczba_powtorzen;i++)
		{
		cout<<a2.start(czas3,pop3)<<" milisekund "<<endl;
		 }
		
		
		
	
		
	
		
	}
	else
	{
		AlgAbstr::wczytywanie(dane_wejsciowe1);
		switch (algTyp)
		{
		case 1:
			{
			cout<<"Mutacja: Reciprocal Exchange "<<endl;
			Gen1 a1;
			a1.start(czas1,pop1);
			a1.wynik();
			}
			break;
		case 2:
			{
				cout<<"Mutacja: Insert"<<endl;
				Gen2 a2;
			cout<<a2.start(czas1,pop1);
			a2.wynik();
			}
			break;
		
		
		
		}
	}

	cout << "NACISNIJ DOWOLNY PRZYCISK BY ZAKONCZYC";
	getchar();

}

