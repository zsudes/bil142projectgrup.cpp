//
// Created by Zeynep Sude Sezgin on 5.03.2024.
//

#include <iostream>
#include "../inc/event.h"
#include "../inc/ship.h"
#include <memory>
#include <cstdlib>
void IShip::startGame(std::unique_ptr<IShip> &ship)
{
    std::srand(std::time(nullptr));
    std::cout<<"Welcome to Cosmic Voyager! Please enter your ship type to start.\n";
    int shipType{0};
    std::cout<<"Enter 1 for regular ship, 2 for fast ship and 3 for strong ship.Remember fast ships are more agile and strong ships have more power\n";
    std::cin>>shipType;
    ship->ChoseShip(shipType,ship);
    std::cout<<"The initial status of your ship is:\n";
    ship->fuelDisplay();
    ship->moneyDisplay();
    ship->healthDisplay();
    std::unique_ptr<Ievent> event(new Ievent());
    if ((event->eventCounter < 5) || ship->getFuel()) {
        for (event->eventCounter = 0; event->eventCounter < 5; event->eventCounter++) {
            event->RandEvent(ship);
            std::this_thread::sleep_for(std::chrono::seconds(1));
            if (event->eventCounter == 4) {
                event->EndGame(ship);
            }
            if (ship->getFuel() <= 1)
            {
                event->EndGame(ship);
                break;
            }
        }
    }
    else
    {
        event->EndGame(ship);
    }
}

void IShip::earnGold(int extraGold)
{
    this->money=money+extraGold;

}
void IShip::giveGold(int minusGold) {
    this->money=money-minusGold;
}

void IShip::fuelUse(double _fuelchange) {
    this->fuel=static_cast<double>(fuel)-_fuelchange;
}

void IShip::ChoseShip(int shipType,std::unique_ptr<IShip> &ptr) {
    if (shipType == 1)
    {
        ptr = std::make_unique<regularShip>();
    } else if (shipType == 2)
    {
        ptr = std::make_unique<fastShip>();
    }
    else if (shipType == 3)
    {
        ptr = std::make_unique<strongShip>();
    }
    else
    {
        while(shipType>3||shipType<1)
        {
            std::cout<<"Invalid type! Please enter again \n ";
            std::cin>>shipType;
        }
    }
}

void IShip::fuelDisplay() const
{
    std::cout<<"Fuel: "<<this->fuel<<"\n";
}
void IShip::moneyDisplay() const
{
    std::cout<<"Money: "<<this->money<<"\n";
}
void IShip::healthDisplay() const
{
    std::cout<<"Health: "<<this->health<<"\n";
}
regularShip::regularShip() {
    std::cout<<"You have chosen the regular ship."<<std::endl;
}
int regularShip::runAwayChance()
 {
     int randNum{0};
     randNum= rand()%2;
     if(randNum==0)
     {
         std::cout<<"Congratulations!! You ran away\n";
         return 1;
     }
     else
     {
         std::cout<<"Unfortunately, your ship was not able to escape.\n";
         return 0;
     }
}
double regularShip::getDamage(int damagechange)
    {
        this->health=health-damagechange;
        return this->health;
    }
fastShip::fastShip() {

    std::cout<<"You have chosen the fast ship."<<std::endl;
}
int fastShip::runAwayChance() {
    int randNum{0};
    randNum = std::rand() % 4;
    if(randNum!=0)
    {
        std::cout<<"Congratulations!! You ran away\n";
        return 1;
    }
    else
    {
        std::cout<<"Unfortunately, your ship was not able to escape.\n";
        return 0;
    }
}
double fastShip::getDamage(int damagechange)
{
    this->health=health-(1.5)*damagechange;
    return this->health;
}
strongShip::strongShip() {
    std::cout<<"you have chosen the strong ship"<<std::endl;
}
int strongShip::runAwayChance() {
    int randNum{0};
    randNum = std::rand() % 4;
    if(randNum==0)
    {
        std::cout<<"Congratulations!! You ran away\n";
        return 1;
    }
    else
    {
        std::cout<<"Unfortunately, your ship was not able to escape.\n";
        return 0;
    }
}
double strongShip::getDamage(int damagechange) {
    this->health=health-(0.5)*damagechange;
    return this->health;
}



