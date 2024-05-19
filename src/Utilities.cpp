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
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << ErrorMessages::SDL_INIT_ERROR << SDL_GetError() << std::endl;
        return false;
    }
    if (TTF_Init() == -1)
    {
        std::cerr << ErrorMessages::TTF_INIT_ERROR << TTF_GetError() << std::endl;
        return false;
    }
    return true;
}

int Utilities::decodeKey(const SDL_Keycode& key)
{
    switch (key)
    {
    case SDLK_0:
    case SDLK_KP_0:
    case SDLK_DELETE:
    case SDLK_BACKSPACE:
        {
            return 0;
        }
    case SDLK_1:
    case SDLK_KP_1:
        {
            return 1;
        }
    case SDLK_2:
    case SDLK_KP_2:
        {
            return 2;
        }
    case SDLK_3:
    case SDLK_KP_3:
        {
            return 3;
        }
    case SDLK_4:
    case SDLK_KP_4:
        {
            return 4;
        }
    case SDLK_5:
    case SDLK_KP_5:
        {
            return 5;
        }
    case SDLK_6:
    case SDLK_KP_6:
        {
            return 6;
        }
    case SDLK_7:
    case SDLK_KP_7:
        {
            return 7;
        }
    case SDLK_8:
    case SDLK_KP_8:
        {
            return 8;
        }
    case SDLK_9:
    case SDLK_KP_9:
        {
            return 9;
        }
    default:
        {
            return -1;
        }
    }
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
    if (SDL_WasInit(SDL_INIT_VIDEO))
    {
        SDL_Quit();
    }
}

Utilities::NumberTexture::NumberTexture(const int& number, const std::shared_ptr<TTF_Font>& pFont,
                                        const std::shared_ptr<TTF_Font>& pBoldFont,
                                        const std::shared_ptr<SDL_Renderer>& pRenderer)
{
    pUserTexture = generateTextTexture(std::to_string(number), Constants::GAME_NUMBER_COLOR, pFont,
                                                  pRenderer);
    pUserFaultTexture = generateTextTexture(std::to_string(number), Constants::GAME_NUMBER_ERROR_COLOR,
                                                       pFont, pRenderer);
    pProgramTexture = generateTextTexture(std::to_string(number), Constants::GAME_NUMBER_COLOR, pBoldFont,
                                                     pRenderer);
    pProgramFaultTexture = generateTextTexture(std::to_string(number), Constants::GAME_NUMBER_ERROR_COLOR,
                                                          pBoldFont, pRenderer);
}

Utilities::TextureUniPtr& Utilities::NumberTexture::operator[](const NumberTextureVersion& version)
{
    switch (version)
    {
    case NumberTextureVersion::User:
        {
            return pUserTexture;
        }
    case NumberTextureVersion::UserFault:
        {
            return pUserFaultTexture;
        }
    case NumberTextureVersion::Program:
        {
            return pProgramTexture;
        }
    case NumberTextureVersion::ProgramFault:
        {
            return pProgramFaultTexture;
        }
    }
    return pUserTexture;
}
