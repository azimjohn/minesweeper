#include <map>
#include <SFML/Graphics.hpp>

using std::string;

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
