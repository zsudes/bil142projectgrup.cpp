//
// Created by Zeynep Sude Sezgin on 5.03.2024.
//

#include <iostream>
#include "../inc/event.h"
#include <cstdlib>
#include <memory>
double Ievent::CountScore(std::unique_ptr<IShip> &ship)
{   double score{0};
    score=5*(ship->getFuel())+10*(ship->getHealth())+10*(ship->getMoney());
    return score;
}
void Ievent::RandEvent(std::unique_ptr<IShip> &pIShip) {
    int randNum{0};
    randNum = std::rand() % 3;
    if(randNum==0)
    {
        abandonedPlanet obj;
        std::cout<<"You have entered the abandoned planet! \n";
        obj.GetMoneyOrNot(pIShip);
    }
    else if(randNum==1)
    {
        spacePirates obj;
        std::cout<<"You are going to face space pirates! \n";
        obj.ChosenRunBattleOrBargain(pIShip);
    }
    else
    {
        asteroidZone obj;
        std::cout<<"You have entered the asteroid zone \n";
        obj.damageKontrol(pIShip);

    }
}
void Ievent::EndGame(std::unique_ptr<IShip> &ptr) {
    std::cout << "The game has ended.\n";
    ptr->fuelDisplay();
    ptr->healthDisplay();
    ptr->moneyDisplay();
    double endScore = CountScore(ptr);
    std::cout << "At the end, your score is " << endScore << std::endl;
}
asteroidZone::asteroidZone()=default;
int asteroidZone::damageKontrol(std::unique_ptr<IShip> &Ship) {
    for (asteroidCounter = 0; asteroidCounter < 3; asteroidCounter++) {
        int randNum{0};
        randNum = std::rand() % 2;
        if (randNum == 0) {
            int _damagechange = 10;
            std::cout << "You got damaged in asteroid zone remaining ";
            Ship->getDamage(_damagechange);
            Ship->healthDisplay();
        } else if (randNum == 1) {
            std::cout << "Congratulations!! You left the asteroid zone with no damage\n";
        }
    }
}
abandonedPlanet::abandonedPlanet()=default;
int abandonedPlanet::GetMoneyOrNot(std::unique_ptr<IShip> &ptr) {
    std::cout<<"Abandoned planet has two options: facing the space pirates or earning money. You are going to face these options by chance.\n";
    int randNum{0};
    randNum=std::rand()%2;
    if(randNum==0)
    {

        spacePirates obj;
        obj.ChosenRunBattleOrBargain(ptr);
    }
    else if (randNum==1)
    {
        std::cout<<"Congratulations! You earned money.Your new ";
        int extragold=10;
        ptr->earnGold(extragold);
        ptr->moneyDisplay();
    }
}
spacePirates::spacePirates()=default;
void spacePirates::RunSenario(std::unique_ptr<IShip> &ship)
{
    spacePirates obj;
    if(ship->getFuel()>33) {
        int b=ship->runAwayChance();
        if (b==0)
        {
            ship->fuelUse(33);
            ship->fuelDisplay();
            obj.ChosenRunBattleOrBargain(ship);
        }
        else
        {
            ship->fuelUse(33);
            ship->fuelDisplay();
        }
    }
    else
    {
        std::cout<<"You dont have enough fuel to run. Please choose battle scenario or bargain scenario. ";
        obj.ChosenRunBattleOrBargain(ship);
    }
}
void spacePirates::BattleScenario(std::unique_ptr<IShip> &ship)
{
    int randNum{0};
    randNum = std::rand() % 2;
    if(randNum==1)
    {
        int _damage=30;
        ship->getDamage(_damage);
        ship->healthDisplay();
    }
    else
    {
        std::cout<<"You won the battle against space pirates.\n";
    }
}
void spacePirates::BargainScenario(std::unique_ptr<IShip> &ship) {
    int randNum{0};
    randNum = std::rand() % 3;

    if(ship->getMoney()<=0)
    {
        std::cout << "Not enough money to give please choose the run or battle option \n";
    spacePirates obj;
    obj.ChosenRunBattleOrBargain(ship);
    }
    else
    {
        std::cout << "Remaining ";
        if (randNum == 0) {
            if (ship->getMoney() >= 0) {
                ship->giveGold(10);
                ship->moneyDisplay();
            }

        } else if (randNum == 1) {
            ship->giveGold(20);
            ship->moneyDisplay();
        } else {
            ship->giveGold(30);
            ship->moneyDisplay();
        }
    }
}
void spacePirates::ChosenRunBattleOrBargain(std::unique_ptr<IShip> &ship) {
    spacePirates obj;
    int optionChooser;
    std::cout<<"You have three options to face with space pirates:\n";
    std::cout<<"Type 1 for run option, type 2 for battle option or type 3 for bargain option:\n";
    std::cin>>optionChooser;
    if(optionChooser==1)
    {
        obj.RunSenario(ship);
    }
    else if(optionChooser==2)
    {
        obj.BattleScenario(ship);
    }
    else if(optionChooser==3)
    {
        obj.BargainScenario(ship);
    }
    else
    {
        while(optionChooser>3||optionChooser<1)
        {
            std::cout<<"Invalid number please type again\n";
            std::cin>>optionChooser;
            obj.ChosenRunBattleOrBargain(ship);
        }
    }
}



