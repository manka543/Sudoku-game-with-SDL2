//
// Created by manka on 26/04/2024.
//

#ifndef SUDOKU_GAME_WITH_SDL2_UTILITIES_H
#define SUDOKU_GAME_WITH_SDL2_UTILITIES_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <memory>
#include <unordered_map>

namespace Utilities {
    typedef std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> TextureUniPtr;

    TextureUniPtr
    generateTextTexture(const std::string &text, const SDL_Color &color, const std::shared_ptr<TTF_Font> &pFont,
                        const std::shared_ptr<SDL_Renderer> &pRenderer);

    bool isContaining(const SDL_Rect &rect, const int &pointX, const int &pointY);

    bool initLibraries();

    void runGame();

    void quitLibraries();

    enum class NumberTextureVersion : int {
        User,
        UserFault,
        Program,
        ProgramFault,
    };

    class NumberTexture {
    public:
        NumberTexture() = default;
        NumberTexture(const int &number, const std::shared_ptr<TTF_Font> &pFont,
                      const std::shared_ptr<TTF_Font> &pBoldFont,
                      const std::shared_ptr<SDL_Renderer> &pRenderer);

        TextureUniPtr pUserTexture{nullptr, &SDL_DestroyTexture};
        TextureUniPtr pUserFaultTexture{nullptr, &SDL_DestroyTexture};
        TextureUniPtr pProgramTexture{nullptr, &SDL_DestroyTexture};
        TextureUniPtr pProgramFaultTexture{nullptr, &SDL_DestroyTexture};

        TextureUniPtr &operator[](const NumberTextureVersion &version);

        ~NumberTexture() = default;

    };

}


#endif //SUDOKU_GAME_WITH_SDL2_UTILITIES_H
