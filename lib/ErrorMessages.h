//
// Created by manka on 18/04/2024.
//

#ifndef PROJECT_NAME_ERRORMESSAGES_H
#define PROJECT_NAME_ERRORMESSAGES_H

#include <iostream>
#include <string_view>

class ErrorMessages{
public:
    static constexpr std::string_view SDL_INIT_ERROR{"Initializing SDL2 caused an Error!!!"};
    static constexpr std::string_view WINDOW_INIT_ERROR{"Could not create pWindow!!!"};
    static constexpr std::string_view RENDERER_CREATE_ERROR{"Could not create pRenderer!!!"};
    static constexpr std::string_view TEXT_RENDERING_ERROR{"Could not render text!!!"};
    static constexpr std::string_view SURFACE_TO_TEXTURE_ERROR{"Could not create texture from surface!!!"};
    static constexpr std::string_view TTF_INIT_ERROR{"SDL_ttf could not initialize!"};
    static constexpr std::string_view FONT_OPENING_ERROR{"Failed to load font!"};



};


#endif //PROJECT_NAME_ERRORMESSAGES_H
