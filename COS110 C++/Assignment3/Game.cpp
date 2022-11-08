#include "Game.h"

using namespace std;

Game::Game(int w, int h, string chars)
{
    map = new Map(w, h);
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (chars[i * w + j] == '#')
                map->add(new Wall(j, i));
            else if (chars[i * w + j] == '.')
                map->add(new Floor(j, i));
            else if (chars[i * w + j] == '&')
            {
                Floor* floor = new Floor(j, i);
                map->add(floor);
                player = new Player(j,i);
                floor->above = player;
                player->below = floor;
            }
        }
    }
}
Game::~Game()
{
    delete map;
    delete player;
}
string Game::display()
{
    return map->print();
}
void Game::update(char c)
{
    switch (c)
    {
        case '1':
            player->move(-1, 1);
            break;
        case '2':
            player->move(0, 1);
            break;
        case '3':
            player->move(1, 1);
            break;
        case '4':
            player->move(-1, 0);
            break;
        case '6':
            player->move(1, 0);
            break;
        case '7':
            player->move(-1, -1);
            break;
        case '8':
            player->move(0, -1);
            break;
        case '9':
            player->move(1, -1);
            break;
    }
}