#include "Market.h"
#include <iostream>
#include <exception>
#include "CowFarm.h"
#include "ChickenFarm.h"
#include "SheepFarm.h"


using namespace std;


class Cowexception : public std::exception
{
public:
    const char * what () const throw () {return "Insert valid number of cow farms";}
};
class Sheepexception : public std::exception
{
public:
    const char * what () const throw () {return "Insert valid number of sheep farms";}
};
class Chickenexception : public std::exception
{
public:
    const char * what () const throw () {return "Insert valid number of chicken farms";}
};



Market::Market()
{
    year = 0;
    passed = 0;
}

Market::~Market()
{
    int i;
    for (i = 0; i < farms.size(); i++)
        if (farms[i] != NULL)
            {
                delete(farms[i]);
                farms[i] = NULL;
            }
    farms.clear();
}

void Market::addFarms()
{
    int cownum, chickennum, sheepnum;
    cout << "How many new cow farms will be added this year?" << endl;
    cin >> cownum;
    if (cownum < 0)
        throw Cowexception();
    cout << "How many new sheep farms will be added this year?" << endl;
    cin >> sheepnum;
    if (sheepnum < 0)
        throw Sheepexception();
    cout << "How many new chicken farms will be added this year?" << endl;
    cin >> chickennum;
    if (chickennum < 0)
        throw Chickenexception();

    int i;
    try
    {
        for (i = 0; i < cownum; i++)
            farms.push_back(new CowFarm());
        for (i = 0; i < sheepnum; i++)
            farms.push_back(new SheepFarm());
        for (i = 0; i < cownum; i++)
            farms.push_back(new ChickenFarm());
    }
    catch (bad_alloc)
        {exit;}

    
}

void Market::printMarketFarms() const
{
    cout << "----Market Farms----" << endl;
    int i;
    for (i = 0; i < farms.size(); i++)
        farms[i]->printinfo();
}

int Market::getYear() const
{
    return year;
}


void Market::nextYear(int fastforward)
{
    int i;
    if (fastforward == 0)
    {
        cout << "----Creating new farms----" << endl;
        while (true)
        {
            try
            {
                addFarms();
                break;
            }
            catch(Cowexception &cowex)
            {
                cout << cowex.what() << endl;
            }
            catch(Sheepexception &sheepex)
            {
                cout << sheepex.what() << endl;
            }
            catch(Chickenexception &sheepex)
            {
                cout << sheepex.what() << endl;
            }
        }



        cout << "----Adding new farms to market----" << endl;
        while (passed < farms.size())
        {
            for (i = 0; i < passed; i++)
                farms[passed]->addClient(farms[i]);
            passed++;
        }
    }
    cout << "----Begin Market----" << endl;
    for (i = 0; i < farms.size(); i++)
        farms[i]->yield();
    for (i = 0; i < farms.size(); i++)
        farms[i]->sellProducts();
    cout << "----Buy Animals----" << endl;
    for (i = 0; i < farms.size(); i++)
        farms[i]->buyAnimals();
    year++;    
}


void Market::fastForwardYears()
{
    cout << "How many years to fast forward?" << endl;
    int ff;
    cin >> ff;
    if (ff <= 0)
        return;
    while (ff > 0)
    {
        nextYear(ff);
        ff--;
    }
}


