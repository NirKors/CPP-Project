#include "SheepFarm.h"
#include "Sheep.h"
#include <iostream>

SheepFarm::SheepFarm()
{
    addAnimal(3);
}


SheepFarm::~SheepFarm()
{}

void SheepFarm::addAnimal(int amount)
{
    int i;
    for (i = 0; i < amount; i++)
        try
            {animals.push_back(new Sheep());}
        catch (bad_alloc)
            {exit;}
}


void SheepFarm::yield()
{
    int i;
    for (i = 0; i < animals.size(); i++)
    {
        products[1] += animals[i]->getAge();
    }
}


void SheepFarm::buyAnimals()
{
    int amount = (int)(money/Sheep::price);
    if (amount > 0)
    {
        money -= amount * Sheep::price;
        addAnimal(amount);
        cout << "Sheep farm(" << ID << ") bought " << amount << " sheeps for " << amount*Sheep::price << " dollars" << endl;
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

void SheepFarm::printinfo() const
{
    cout << "Farm Id: " << ID << ", type: Sheep farm, Money: " << money << ", Animals: " << animals.size() << " sheep, Products: " 
                                            << "Milk[" << products[0] << "], Wool[" << products[1] << "], Eggs[" << products[2] << "]" << endl;
}

int SheepFarm::purchaseProducts(int selling_amount)
{
    // Buying milk for 3$
    if (money < 3)
        return 0;
    int buying_amount = 1;
    while (money >= (buying_amount + 1) * 3 && (buying_amount + 1) <= selling_amount)
        buying_amount++;
    int pay = buying_amount * 3;
    money -= pay;
    products[0] += buying_amount;
    cout << "Sheep farm(" << ID << ") bought " << buying_amount << " milk for " << pay << " dollars from ";
    return buying_amount;
}


void SheepFarm::sellProducts()
{
    int i = 0;
    while (i < clients.size() && products[1] > 0)
    {
        int sold = clients[i]->purchaseProducts(products[1]);
        i++;
        if (sold == 0)
            continue;
        products[1] -= sold;
        money += sold * 2;
        cout << "Sheep farm(" << ID << ")" << endl;
    }
}




/**
 * cow wants chicken
 * sheep wants cow
 * chicken wants sheep 
 * */
void SheepFarm::handleCowFarm(Farm *f)
{
    if (f->inClients(this))
        return;
    cout << "Cow farm(" << f->ID << ") Added Sheep farm(" << ID << ") to his client list" << endl;
    f->subscribe(this);
}

void SheepFarm::handleSheepFarm(Farm *f){}

void SheepFarm::handleChickenFarm(Farm *f)
{
    addClient(f);
}

void SheepFarm::addClient(Farm *check)
{
    check->handleSheepFarm(this);
}