#ifndef CPP_ANTSCOLONY_SQUAREBOX_H
#define CPP_ANTSCOLONY_SQUAREBOX_H

#include <SFML/Graphics.hpp>


class SquareBox{

protected:
    int posX;
    int posY;
    sf::Texture texture;
    std::string imagePath = "../assets/ground.jpg";
public:
    SquareBox(const int &posX, const int &posY);

    virtual ~SquareBox() = default;

    [[nodiscard]] int getPosX() const;

    [[nodiscard]] int getPosY() const;

    sf::Texture getTexture();

    bool operator==(const SquareBox &squareBox) const;

    bool operator!=(const SquareBox &squareBox) const;

};


#endif //CPP_ANTSCOLONY_SQUAREBOX_H
