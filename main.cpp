#define SDL_MAIN_HANDLED

#include "Utilities.h"

int main(int argc, char* argv[])
{
    if(Utilities::initLibraries()){
        Utilities::runGame();
    }
    Utilities::quitLibraries();
    return 0;
}
