//
// Created by Zeynep Sude Sezgin on 5.03.2024.
//

#ifndef UNTITLED9_SHIP_H
#define UNTITLED9_SHIP_H
#include <iostream>
#include <string>
#include <ctime>
#include <memory>
#include <thread>
class IShip {
public:
    static void startGame(std::unique_ptr<IShip> &ship);
    void ChoseShip(int shipType,std::unique_ptr<IShip> &ship);
    virtual int runAwayChance()=0;
    virtual double getDamage(int damagechange)=0;
     void earnGold(int extraGold);
     void giveGold(int minusGold);
    void fuelUse(double fuelchange);
    void fuelDisplay() const;
    void healthDisplay() const;
    void moneyDisplay() const;
    double damagechange{0};
    double fuelchange{33};
    inline int getFuel()
    {
        return this->fuel;
    }
    inline int getMoney()
    {
        return this->money;
    }
    inline int getHealth()
    {
        return this->health;
    }
    ~IShip()=default;

protected:
    int fuel{100};
    int health{100};
    int money{0};
};
class regularShip: public IShip {
public:
    regularShip();
    int runAwayChance() override;
    double getDamage(int damagechange) override;
};
class fastShip:public IShip
{
public:
    fastShip();
    int runAwayChance() override;
    double getDamage(int damagechange) override;

};
class strongShip:public IShip
{
public:
    strongShip();
    int runAwayChance() override;
    double getDamage(int damagechange) override;
};
#endif //UNTITLED9_SHIP_H
