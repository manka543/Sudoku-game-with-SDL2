//
// Created by manka on 18/04/2024.
//

#ifndef PROJECT_NAME_ERRORMESSAGES_H
#define PROJECT_NAME_ERRORMESSAGES_H

#include <iostream>
#include <string_view>

class ErrorMessages{
public:
    static constexpr std::string_view SDL_INIT_ERROR{"Initializing SDL2 caused an Error!!!\n"};
    static constexpr std::string_view WINDOW_INIT_ERROR{"Could not create window!!!\n"};



};


#endif //PROJECT_NAME_ERRORMESSAGES_H
