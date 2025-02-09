#include "food.h"
#include <bits/stdc++.h>



Food::Food()
    : size(5),
    color{RED},
    position{}
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, 1080);
    std::uniform_int_distribution<std::mt19937::result_type> distY(0, 720);


    position.x = dist(rng);
    position.y = distY(rng);


}

void Food::setPosition()
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, 1080);
    std::uniform_int_distribution<std::mt19937::result_type> distY(0, 720);


    position.x = dist(rng);
    position.y = distY(rng);
}
