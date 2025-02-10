#include<vector>
#include<String>
using namespace std;
class Menu {
public:
	void main_menu();
	void wczytanie_konfiguracji();

	//zmienne konfiguracyjne
	static vector<int> rozmiary_macierzy;
	static int powtorzenia, liczba_instancji, progres, tryb, algTyp, pop1, pop2, pop3;
	static double czas1, czas2,czas3, tempWspL1, tempWspG1, tempWspL2, tempWspG2 , tempWspL3, tempWspG3;
	static string dane_wejsciowe1,dane_wejsciowe2,dane_wejsciowe3;
};
