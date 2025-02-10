#include"AlgAbstr.h"
#include<iostream>
#include<vector>
#include<fstream>
#include <sstream>
#include<Algorithm>
#include<random>
#include <algorithm>
using namespace std;
vector<vector<int>> AlgAbstr::macierz;
 

vector<int> AlgAbstr::kolejnosc_przejscia;
vector<int> AlgAbstr::kolejnosc_przejscia_nastepnego;
vector<int> AlgAbstr :: rozwiazanie;
LicznikCzasu licznik;


void AlgAbstr:: wczytywanie(string nazwa)
{
macierz.clear();
	
	int rozmiar;
	int linia = 4;
	int wyraz=2;
	int liniaObecna=0;
	int wyrazObecny=0;
	string liniaTekst;
	string wynik_oczekiwany;

	ifstream plik(nazwa);  

	if (plik.is_open()) {

		while(getline(plik,liniaTekst))	
	{	
		liniaObecna++;
		if(liniaObecna==linia)
		{
			istringstream stream(liniaTekst);
			string slowo;
			while(stream>>slowo)
			{
				wyrazObecny++;
				if(wyrazObecny==wyraz)
				{
					rozmiar=stoi(slowo);
					cout<<"rozmiar "<<rozmiar<<endl;
				}
			}
		}
		else if(liniaObecna==7)
		{
		macierz.resize(rozmiar, vector<int>(rozmiar));
		
		for (int i = 0; i < rozmiar; i++) {
			for (int j = 0; j < rozmiar; j++) {
			plik >> macierz[i][j]; 
			}
		}
		}
	}
		
		
	
		plik.close();  
	}
	else {
		cout << "BRAK PLIKU,"<<" NACISNIJ DOWOLNY PRZYCISK BY ZAKONCZYC";
		getchar();
		exit(0);
	}
}

void AlgAbstr::wyswietlanie()
{
    for (int i = 0; i < macierz.size(); i++)
	{
		for (int k = 0; k < macierz[i].size(); k++)
		{
			cout << macierz[i][k] << " ";
		}
		cout << endl;
	}
}



void AlgAbstr::wynik()
{
	

cout<<"  trasa: ";
   for(int i=0;i<kolejnosc_przejscia.size();i++)
   {
    cout<<kolejnosc_przejscia[i]<<" ";
   }
   cout<<endl;
}


int AlgAbstr::oblicz_koszt(vector<int> miasta)
{
	int koszt=0;
	
	for(int i=0;i<miasta.size()-1;i++)
	{
			koszt+=macierz[miasta[i]][miasta[i+1]];
	}
	koszt+=macierz[miasta.back()][miasta[0]];

	return koszt;
}

void AlgAbstr :: losowe_rozwiazanie()
{
	random_device rd;
	mt19937 gen(rd());
	kolejnosc_przejscia.clear();
		for(int i =0;i< macierz.size();i++)
   {
      kolejnosc_przejscia.push_back(i);
   }
	shuffle(kolejnosc_przejscia.begin(),kolejnosc_przejscia.end(),rd);

}

void AlgAbstr :: losowe_rozwiazanieLC(int startW)
{
	int start = startW;
	int aktualny = start;
	vector<int> odwiedzone(macierz.size(), 0);
	odwiedzone[aktualny] = 1;
	//szukanie minimum połączonego
	int laczone_minimum = INT_MAX;
	int nowy = -1;
	kolejnosc_przejscia.clear();
	kolejnosc_przejscia.push_back(aktualny);
	for (int k = 0; k < macierz.size() - 1; k++) {
		laczone_minimum = INT_MAX;
		nowy = -1;
		for (int i = 0; i < macierz.size(); i++)
		{
			
			if (odwiedzone[i] == 0 && laczone_minimum > macierz[aktualny][i] && aktualny!=i)
			{
				laczone_minimum = macierz[aktualny][i];
				nowy = i;

			}

		}
		if (nowy != -1) {
			aktualny = nowy;
			kolejnosc_przejscia.push_back(aktualny);
			odwiedzone[aktualny] = 1;
		}
	}
}

	

