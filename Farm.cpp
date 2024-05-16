#include "Farm.h"
#include <iostream>

int Farm::ID_count = 0;

Farm::Farm()
{
    ID_count++;
    ID = ID_count;
    money = 10;
    products.push_back(0);
    products.push_back(0);
    products.push_back(0);
}


Farm::~Farm()
{
    int i;
    for (i = 0; i < animals.size(); i++)
    {
        if (animals[i] != NULL)
        {
            delete(animals[i]);
            animals[i] = NULL;
        }
    }
    animals.clear();
}

void Farm::subscribe(Farm *f)
{
    clients.push_back(f);
}

bool Farm::inClients(const Farm *f) const
{
    int i;
    for (i = 0; i < clients.size(); i++)
        if (clients[i] == f)
            return true;
    return false;
}