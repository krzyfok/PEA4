#include"AlgAbstr.h"
class Gen1: public AlgAbstr{
    public:
 double start(double czas,int pop) override;
void crossing(vector<int> &parent1,vector<int> &parent2);
bool pathCheck(int i,int start,int end, vector<int> &sciezka);
 
};