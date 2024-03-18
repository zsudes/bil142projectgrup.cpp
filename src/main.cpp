#include <iostream>
#include "../inc/event.h"
#include "../inc/ship.h"
#include <memory>
int main()
{
    std::unique_ptr<IShip> ship;
    ship->startGame(ship);
    return 0;
}
