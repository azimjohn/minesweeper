#include <exception>


struct GameOver : public std::exception {
    const char *what() const throw() {
        return "Game Is Over";
    }
};