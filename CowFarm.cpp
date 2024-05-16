#include "CowFarm.h"
#include "Cow.h"
#include <iostream>

CowFarm::CowFarm()
{
    addAnimal(3);
}


CowFarm::~CowFarm()
{}

void CowFarm::addAnimal(int amount)
{
    int i;
    for (i = 0; i < amount; i++)
        try
            {animals.push_back(new Cow());}
        catch (bad_alloc)
            {exit;} 
}


void CowFarm::yield()
{
    int i;
    for (i = 0; i < animals.size(); i++)
    {
        products[0] += animals[i]->getAge();
    }
}


void CowFarm::buyAnimals()
{
    int amount = (int)(money/Cow::price);
    if (amount > 0)
    {
        money -= amount * Cow::price;
        addAnimal(amount);
        cout << "Cow farm(" << ID << ") bought " << amount << " cows for " << amount*Cow::price << " dollars" << endl;
    }
    int i = 0;
    while(i < animals.size())
    {
        if (animals[i]->age())
        {
            delete(animals[i]);
            animals.erase(animals.begin() + i);
            i--;
        }
        i++;
    }
    money += 10;
}

void CowFarm::printinfo() const
{
    cout << "Farm Id: " << ID << ", type: Cow farm, Money: " << money << ", Animals: " << animals.size() << " cows, Products: " 
                                            << "Milk[" << products[0] << "], Wool[" << products[1] << "], Eggs[" << products[2] << "]" << endl;
}

int CowFarm::purchaseProducts(int selling_amount)
{
    // Buying eggs for 1$
    if (money < 1)
        return 0;
    int buying_amount = 1;
    while (money >= (buying_amount + 1) && (buying_amount + 1) <= selling_amount)
        buying_amount++;
    money -= buying_amount;
    products[2] += buying_amount;
    cout << "Cow farm(" << ID << ") bought " << buying_amount << " eggs for " << buying_amount << " dollars from ";
    return buying_amount;
}

void CowFarm::sellProducts()
{
    int i = 0;
    while (i < clients.size() && products[0] > 0)
    {
        int sold = clients[i]->purchaseProducts(products[0]);
        i++;
        if (sold == 0)
            continue;
        products[0] -= sold;
        money += sold * 3;
        cout << "Cow farm(" << ID << ")" << endl;
    }
}


/**
 * cow wants chicken
 * sheep wants cow
 * chicken wants sheep 
 * */
void CowFarm::handleCowFarm(Farm *f){}

void CowFarm::handleSheepFarm(Farm *f)
{
    addClient(f);
}

void CowFarm::handleChickenFarm(Farm *f)
{
    if (f->inClients(this))
        return;
    cout << "Chicken farm(" << f->ID << ") Added Cow farm(" << ID << ") to his client list" << endl;
    f->subscribe(this);
}

void CowFarm::addClient(Farm *check)
{
    check->handleCowFarm(this);
}
