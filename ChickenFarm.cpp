#include "ChickenFarm.h"
#include "Chicken.h"
#include <iostream>

ChickenFarm::ChickenFarm()
{
    addAnimal(3);
}


ChickenFarm::~ChickenFarm()
{}

void ChickenFarm::addAnimal(int amount)
{
    int i;
    for (i = 0; i < amount; i++)
        try
            {animals.push_back(new Chicken());}
        catch (bad_alloc)
            {exit;}
}


void ChickenFarm::yield()
{
    int i;
    for (i = 0; i < animals.size(); i++)
    {
        products[2] += animals[i]->getAge();
    }
}


void ChickenFarm::buyAnimals()
{
    int i = 0;
    int amount = (int)(money/Chicken::price);
    if (amount > 0)
    {
        money -= amount * Chicken::price;
        addAnimal(amount);
        cout << "Chicken farm(" << ID << ") bought " << amount << " chickens for " << amount*Chicken::price << " dollars" << endl;
    }
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

void ChickenFarm::printinfo() const
{
    cout << "Farm Id: " << ID << ", type: Chicken Farm, Money: " << money << ", Animals: " << animals.size() << " chickens, Products: " 
                                            << "Milk[" << products[0] << "], Wool[" << products[1] << "], Eggs[" << products[2] << "]" << endl;
}

int ChickenFarm::purchaseProducts(int selling_amount)
{
    // Buying wool for 2$
    if (money < 2)
        return 0;
    int buying_amount = 1;
    while (money >= (buying_amount + 1) * 2 && (buying_amount + 1) <= selling_amount)
        buying_amount++;
    int pay = buying_amount * 2;
    money -= pay;
    products[1] += buying_amount;
    cout << "Chicken farm(" << ID << ") bought " << buying_amount << " wool for " << pay << " dollars from ";
    return buying_amount;
}


void ChickenFarm::sellProducts()
{
    int i = 0;
    while (i < clients.size() && products[2] > 0)
    {
        int sold = clients[i]->purchaseProducts(products[2]);
        i++;
        if (sold == 0)
            continue;
        products[2] -= sold;
        money += sold;
        cout << "Chicken farm(" << ID << ")" << endl;
    }
}


/**
 * cow wants chicken
 * sheep wants cow
 * chicken wants sheep 
 * */
void ChickenFarm::handleCowFarm(Farm *f)
{
    addClient(f);
}

void ChickenFarm::handleSheepFarm(Farm *f)
{
    if (f->inClients(this))
        return;
    cout << "Sheep farm(" << f->ID << ") Added Chicken farm(" << ID << ") to his client list" << endl;
    f->subscribe(this);
}

void ChickenFarm::handleChickenFarm(Farm *f){}

void ChickenFarm::addClient(Farm *check)
{
    check->handleChickenFarm(this);
}

