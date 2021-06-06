#include "texture_manager.h"

TextureManager::TextureManager() = default;

sf::Texture TextureManager::retrieve(const char key)
{
    if (data.find(key) != data.end())
    {
        return data[key];
    }
    return sf::Texture();
}

bool TextureManager::load(const string& path, const char key)
{
    if (data.find(key) != data.end())
        return true;
    else
    {
        sf::Texture texture;
        if (texture.loadFromFile(path))
        {
            data[key] = texture;
            return true;
        }
        return false;
    }
}

void TextureManager::loadAll()
{
    load("../res/0.png", '0');
    load("../res/1.png", '1');
    load("../res/2.png", '2');
    load("../res/3.png", '3');
    load("../res/4.png", '4');
    load("../res/5.png", '5');
    load("../res/6.png", '6');
    load("../res/7.png", '7');
    load("../res/8.png", '8');
    load("../res/b.png", 'b');
    load("../res/0.png", 'f');
    load("../res/0.png", 'n');
}

TextureManager::~TextureManager() = default;
