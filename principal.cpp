#include "iostream"
#include "principal.h"
#include "fstream"
#include "vector"
#include "sstream"

using namespace NGLLEL001;
using namespace std;
principal::principal():junuary(vector<double>()),july(vector<double>()){
    string name;
    ifstream file("data.csv");
    file >> name;
    while (getline(file,name))
    {
        string temp;
        stringstream ss(name);
        
        for(string line;getline(ss,line,','); ){
            string line2;
            getline(ss,line2,',');
            double temp1 = stod(line);
            double temp2 = stod(line2);
            junuary.push_back(temp1);
            july.push_back(temp2);
        }
       
    }
    
    file.close();
}

double principal::calculateMean(vector<double> oriVector){
    double sum = 0;
    for(auto i = oriVector.begin(); i != oriVector.end();i++){
       sum += *i;
    }
    return sum / oriVector.size();
}

void principal::adjestData(){
    double meanForJunuary = principal::calculateMean(junuary);
    double meanForJuly = principal::calculateMean(july);
    for(auto i = junuary.begin(); i != junuary.end(); i++){
         adujustedJunuary.push_back(*i - meanForJunuary);
    }

    for (auto i = july.begin(); i != july.end(); i++){
         adujustedJuly.push_back(*i - meanForJuly);
    }
}

double principal::calculateCovernce(vector<double> junu,vector<double> jul){
    double sum = 0;
    for (int i = 0; i < junu.size(); i++){
        double temp = junu[i] * jul[i];
        sum += temp;
    }
    return sum / (junu.size() - 2);
}

void principal::matrix(){
    double meanForJunuary = principal::calculateMean(junuary);
    double meanForJuly = principal::calculateMean(july);
    for(int i = 0; i < junuary.size() ; i++){
        adujustedJunuary.push_back(junuary[i] - meanForJunuary);
        adujustedJuly.push_back(july[i] - meanForJuly);
    }
    double janJan = principal::calculateCovernce(adujustedJunuary,adujustedJunuary);
    double janJul =  principal::calculateCovernce(adujustedJunuary,adujustedJuly);
    double julyJuly = principal::calculateCovernce(adujustedJuly,adujustedJuly);
    double cov[2][2];

    cov[1][2] = janJul;
    cov[2][1] = janJul;

  //  cout << cov[2][1] << endl;
}
void principal::testMatrix(){
     /*  int height[] = {9,15,25,14,10,18,0,16,5,19,16,20};
    int mark[] =   {39,56,93,61,50,75,32,85,42,70,66,80};
    
    vector<int> testArrJan, testArrJul,adjustedArrJan, adujustedArrJul;
    for (int i = 0; i < 12; i++){
        testArrJan.push_back(height[i]);
        testArrJul.push_back(mark[i]);
    }
    double meanForJunuary = principal::calculateMean(testArrJan);
    double meanForJuly = principal::calculateMean(testArrJul);

    for(int i = 0; i < 12 ; i++){
        adjustedArrJan.push_back(testArrJan[i] - meanForJunuary);
        adujustedArrJul.push_back(testArrJul[i] - meanForJuly);
    }

    double mama =  principal::calculateCovernce(adjustedArrJan,adujustedArrJul);
    
    cout << mama << endl;*/
}

principal::~principal(){
    
}
