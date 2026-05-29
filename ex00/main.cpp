#include "Zombie.hpp"

int main()
{
    //Heap
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    delete heapZombie;

    //Stack
    randomChump("StackZombie");

    return 0;
}