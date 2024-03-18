//
// Created by Zeynep Sude Sezgin on 5.03.2024.
//

#ifndef UNTITLED9_EVENT_H
#define UNTITLED9_EVENT_H
#include "../inc/ship.h"
#include <memory>
class Ievent {
public:
    Ievent()=default;
    static void RandEvent(std::unique_ptr<IShip> &pIShip );
    void EndGame(std::unique_ptr<IShip> &ptr);
    static double CountScore(std::unique_ptr<IShip> &ship);
    int eventCounter{0};
    ~Ievent()=default;
};
class asteroidZone: public Ievent
{
private:
protected:
public:
    asteroidZone();
    int damageKontrol (std::unique_ptr<IShip> &Ship);
    int asteroidCounter{0};
    ~asteroidZone()=default;
};
class abandonedPlanet:public Ievent
{
private:
protected:
public:
    abandonedPlanet();
    static int GetMoneyOrNot (std::unique_ptr<IShip> &ptr);
    ~abandonedPlanet()=default;
};
class spacePirates: public Ievent{
private:
protected:
public:
    spacePirates();
    static void ChosenRunBattleOrBargain(std::unique_ptr<IShip> &ship);
    static void RunSenario(std::unique_ptr<IShip> &ship);
    void BattleScenario(std::unique_ptr<IShip> &ship);
    void BargainScenario(std::unique_ptr<IShip> &ship);
    ~spacePirates()=default;
};

#endif //UNTITLED9_EVENT_H
