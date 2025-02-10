#include<iostream>
#include"Gen2.h"
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include <iostream>
#include <fstream>
using namespace std;
 //SA
  
bool Gen2::pathCheck(int i,int start,int end, vector<int> &sciezka)
{
   for(int k = start;k<=end;k++)
   {
      if(i==sciezka[k])
      {
         return true;
      }
   }
   return false;
}


void Gen2::crossing(std::vector<int> &parent1, std::vector<int> &parent2) {
    int startR, endR;
    size_t size = parent1.size();
    
    std::vector<int> child1(size);
    std::vector<int> child2(size);
    
    do {
        startR = rand() % size;
        endR = rand() % size;
    } while (startR >= endR || endR >= size);
    
    for (int i = startR; i <= endR; i++) {
        child1[i] = parent1[i];
        child2[i] = parent2[i];
    }
    
    int idx1 = (endR + 1) % size;
    int idx2 = (endR + 1) % size;
    
    for (int i = 0; i < size; i++) {
        if (idx1 == startR) break;
        while (pathCheck(parent2[idx2], startR, endR, child1)) {
            idx2 = (idx2 + 1) % size;
        }
        child1[idx1] = parent2[idx2];
        idx1 = (idx1 + 1) % size;
        idx2 = (idx2 + 1) % size;
    }
    
    idx1 = (endR + 1) % size;
    idx2 = (endR + 1) % size;
    
    for (int i = 0; i < size; i++) {
        if (idx1 == startR) break;
        while (pathCheck(parent1[idx2], startR, endR, child2)) {
            idx2 = (idx2 + 1) % size;
        }
        child2[idx1] = parent1[idx2];
        idx1 = (idx1 + 1) % size;
        idx2 = (idx2 + 1) % size;
    }
    
    parent1 = child1;
    parent2 = child2;
}

double Gen2::start(double czas,int pop)
 {
   vector<int> fitnnesFunction;
   vector<vector<int>> population;
   vector<vector<int>> nextPopulation;
   clock_t start;
   double cR=0.8;
   int najlepszeGlob=INT_MAX;
   double mR=0.01;
   double stop=czas;
   int tSize=4;
   double czas_znalezienia;
   double czas_zakonczenia=0;
   double czas_ostatniego_zapisu = 0; 
   double czasZ;
    int koszt=0;
   losowe_rozwiazanie();
   
   int popSize=pop;
   for(int i=0;i<macierz.size();i++)
   {
      losowe_rozwiazanieLC(i);
      population.push_back(kolejnosc_przejscia);

   }
   for(int i=macierz.size();i<popSize;i++)
   {     losowe_rozwiazanie();
         population.push_back(kolejnosc_przejscia);
   }
   string plik_wyjsciowy = "daneWyjsciowe.csv";
   string plik_sciezki = "sciezki.csv";
   ofstream myfile;
	myfile.open(plik_wyjsciowy,ios::app);
	if (!myfile.is_open()) {
		cout << "Nie udalo sie otworzyc pliku wyjsciowego!" << endl;
		
	}
   licznik.start();
   start = clock();
   while(((clock()-start)/(CLOCKS_PER_SEC))<stop){
      fitnnesFunction.clear();
      for(int i =0;i<popSize;i++)
      {
         fitnnesFunction.push_back(oblicz_koszt(population[i]));
         if(oblicz_koszt(population[i])<najlepszeGlob)
         {
            
            najlepszeGlob=oblicz_koszt(population[i]);
             czas_znalezienia=(clock()-start)/(double)CLOCKS_PER_SEC;
             rozwiazanie=population[i];
         }
      }
      

     
      //selekcja
      //turniejowa
      for(int k=0;k<popSize*cR;k++)
      {
         
            czasZ = (clock()-start)/(double)CLOCKS_PER_SEC;
          if (czasZ - czas_ostatniego_zapisu >= 0.5) {
            myfile << najlepszeGlob << ";";
             czas_ostatniego_zapisu = czasZ; 
            }
         int tournamentBest=INT_MAX;
         for(int i=0;i<tSize;i++)
         {
            int id=rand()%popSize;
            if(fitnnesFunction[id]<tournamentBest)
            {
               tournamentBest=fitnnesFunction[id];
               kolejnosc_przejscia_nastepnego.clear();
               kolejnosc_przejscia_nastepnego=population[id];
            }
         }
         nextPopulation.push_back(kolejnosc_przejscia_nastepnego);
        
      }
     
      //krzyzowanie



      for(int i =0;i<nextPopulation.size();i+=2)
      {
         
       czasZ = (clock()-start)/(double)CLOCKS_PER_SEC;
          if (czasZ - czas_ostatniego_zapisu >= 0.5) {
            myfile << najlepszeGlob << ";";
            czas_ostatniego_zapisu = czasZ; 
            }
         crossing(nextPopulation.at(i),nextPopulation.at(i+1));
      }
      //mutacja
     for (int j = 0; j < (int)(mR * (float)nextPopulation.size()); j++) {
    int index = rand() % macierz.size();  
    int pozycja= rand() % macierz.size();  

    if (index != pozycja) {
        int value = nextPopulation.at(j)[index];  
        nextPopulation.at(j).erase(nextPopulation.at(j).begin() + index);
        nextPopulation.at(j).insert(nextPopulation.at(j).begin() + pozycja, value); 
    }
}

      int elita_size = popSize - nextPopulation.size(); 

         sort(population.begin(), population.end(), [](const vector<int>& a, const vector<int>& b) {
         return oblicz_koszt(a) < oblicz_koszt(b);
         });


      vector<vector<int>> elita(population.begin(), population.begin() + elita_size);


      population.clear();
      population = nextPopulation;


      for (const auto& osobnik : elita) {
         population.push_back(osobnik);
      }

      nextPopulation.clear();
      fitnnesFunction.clear();

      
      

      


   }

        
      czas_zakonczenia=licznik.stop();
      cout<<"wynik "<<najlepszeGlob<<" czas znalezioenia "<<czas_znalezienia<<"czas dzialania "<<czas_zakonczenia<<endl;
      myfile<<"wynik"<<";"<<najlepszeGlob<<";"<<czas_znalezienia<<";"<<czas_zakonczenia;
      myfile<<"\n";
	   myfile.close();
      myfile.open(plik_sciezki,ios::app);
	   if (!myfile.is_open()) {
		cout << "Nie udalo sie otworzyc pliku wyjsciowego!" << endl;        
	   }
      myfile<<"wynik"<<";"<<najlepszeGlob<<";";
      for(int k=0;k<rozwiazanie.size();k++)
      {
      myfile<<rozwiazanie[k]<<"-";
      }
      myfile<<"\n";
	   myfile.close();
      return czas_zakonczenia;

}


 