#include <map>
#include <SFML/Graphics.hpp>

using std::string;

#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

class TextureManager
{
private:
    typedef std::map<char, sf::Texture> TextureMap;
    TextureMap data;

public:
    TextureManager();
    sf::Texture retrieve(char key);
    bool load(const string& path, char key);
    void loadAll();
    ~TextureManager();
};

#endif //TEXTURE_MANAGER_H
