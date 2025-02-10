#ifndef ALGABSTR_H
#define ALGABSTR_H

#include <vector>
#include <string>
#include<Algorithm>
#include<queue>
#include"LicznikCzasu.h"
using namespace std;
class AlgAbstr {
public:



    virtual double start(double czas, int pop)=0;
    static void wynik();
    
    static void wczytywanie(string nazwa);
    static void wyswietlanie();
    static int oblicz_koszt(vector<int> miasta);
    static void losowe_rozwiazanie();
    static void losowe_rozwiazanieLC(int startW);
    static vector<vector<int>> macierz;
   static vector<int> kolejnosc_przejscia;
    static vector<int> kolejnosc_przejscia_nastepnego;
    static vector<int> rozwiazanie;
   
};

#endif // ALGABSTR_H
