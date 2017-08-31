#include "avion.h"

int main(){
    Director* dir = new Director();
    dir->setBuilder(new BuilderBoeing());
    dir->construct();

    Avion* miAvion = dir->getAvion();
    std::cout << miAvion->getMarca();

    return 0;
}


