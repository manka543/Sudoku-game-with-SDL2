//
// Created by manka on 20/06/2024.
//

#include "Paintable.h"


Paintable::Paintable(const std::shared_ptr<SDL_Renderer>& pRenderer, const std::shared_ptr<TTF_Font>& pFont) : pRenderer(pRenderer), pFont(pFont)
{
}