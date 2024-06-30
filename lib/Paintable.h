//
// Created by manka on 20/06/2024.
//

#ifndef PAINTABLE_H
#define PAINTABLE_H

#include <memory>
#include <SDL.h>
#include <SDL_ttf.h>

class Paintable {

protected:
    std::shared_ptr<SDL_Renderer> pRenderer;
    std::shared_ptr<TTF_Font> pFont;


public:

    Paintable(const std::shared_ptr<SDL_Renderer>& pRenderer);
    virtual ~Paintable() = default;

    virtual void paint() = 0;
};



#endif //PAINTABLE_H
