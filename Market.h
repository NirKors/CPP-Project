#ifndef MARKET_H
#define MARKET_H
#include "Farm.h"
#include <vector>
#include <exception>


// TODO add const to every function in every file.
// TODO figure out about printing other farms "Type farm(ID)".
class Market
{
    int year;
    int passed;
    std::vector<Farm*> farms;
public:
    Market();
    ~Market();
    void addFarms();
    void printMarketFarms() const;
    int getYear() const;
    void nextYear(int fastforward=0);
    void fastForwardYears();
};















#endif