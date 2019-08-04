#ifndef _principal
#define _principal
#include "iostream"
#include "vector"
namespace NGLLEL001{
    class principal
    {
    private:
        std::vector<double> junuary;
        std::vector<double>  july;
        std::vector<double> adujustedJunuary;
        std::vector<double>  adujustedJuly;
    public:
        principal();
        double calculateMean(std::vector<double> oriVector);
        void adjestData();
        double calculateCovernce(std::vector<double> junu, std::vector<double> jul);
        void matrix();
        void testMatrix();
        void readData();
        ~principal();
    };
}


#endif