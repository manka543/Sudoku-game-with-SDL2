//
// Created by manka on 26/04/2024.
//

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include "Sudoku.h"
#include "Utilities.h"
#include "ErrorMessages.h"


Utilities::TextureUniPtr Utilities::generateTextTexture(const std::string& text, const SDL_Color& color,
                                                        const std::shared_ptr<TTF_Font>& pFont,
                                                        const std::shared_ptr<SDL_Renderer>& pRenderer)
{
    SDL_Surface* pTextSurface = TTF_RenderText_Blended(pFont.get(), text.c_str(), color);
    if (pTextSurface == nullptr)
    {
        std::cerr << ErrorMessages::TEXT_RENDERING_ERROR << TTF_GetError() << std::endl;
        return TextureUniPtr{nullptr, &SDL_DestroyTexture};
    }

    std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> pTextTexture(
        SDL_CreateTextureFromSurface(pRenderer.get(), pTextSurface), &SDL_DestroyTexture);
    SDL_FreeSurface(pTextSurface);

    if (pTextTexture == nullptr)
    {
        std::cerr << ErrorMessages::SURFACE_TO_TEXTURE_ERROR << SDL_GetError() << std::endl;
    }

    return pTextTexture;
}

bool Utilities::isContaining(const SDL_Rect& rect, const int& pointX, const int& pointY)
{
    return (pointX >= rect.x && pointX <= rect.x + rect.w) && (pointY >= rect.y && pointY <= rect.y + rect.h);
}

bool Utilities::initLibraries()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cerr << ErrorMessages::SDL_INIT_ERROR << SDL_GetError() << std::endl;
        return false;
    }
    else if (TTF_Init() == -1)
    {
        std::cerr << ErrorMessages::TTF_INIT_ERROR << TTF_GetError() << std::endl;
        return false;
    }
    return true;
}

void Utilities::runGame()
{
    Sudoku sudoku{};
}

void Utilities::quitLibraries()
{
    if (TTF_WasInit())
    {
        TTF_Quit();
    }
    if (SDL_WasInit(SDL_INIT_EVERYTHING))
    {
        SDL_Quit();
    }
}

Utilities::NumberTexture::NumberTexture(const int& number, const std::shared_ptr<TTF_Font>& pFont,
                                        const std::shared_ptr<TTF_Font>& pBoldFont,
                                        const std::shared_ptr<SDL_Renderer>& pRenderer)
{
    textures.emplace(NumberTextureVersion::User,
                     Utilities::generateTextTexture(std::to_string(number), Constants::GAME_NUMBER_COLOR,
                                                    pFont, pRenderer));
    textures.emplace(NumberTextureVersion::UserFault,
                     Utilities::generateTextTexture(std::to_string(number), Constants::GAME_NUMBER_ERROR_COLOR, pFont,
                                                    pRenderer));
    textures.emplace(NumberTextureVersion::Program,
                     Utilities::generateTextTexture(std::to_string(number), Constants::GAME_NUMBER_COLOR, pBoldFont,
                                                    pRenderer));
    textures.emplace(NumberTextureVersion::ProgramFault,
                     Utilities::generateTextTexture(std::to_string(number), Constants::GAME_NUMBER_ERROR_COLOR,
                                                    pBoldFont, pRenderer));
}
