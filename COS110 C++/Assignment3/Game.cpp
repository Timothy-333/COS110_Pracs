#include "Game.h"

using namespace std;
#include <iostream>

Game::Game(int w, int h, string chars)
{
    exit = NULL;
    player = NULL;
    map = new Map(w, h);
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (chars[i * w + j] == '#')
                map->add(new Wall(j, i));
            else if (chars[i * w + j] == '&' && player == NULL)
            {
                Floor* floor = new Floor(j, i);
                map->add(floor);
                player = new Player(j,i);
                floor->above = player;
                player->below = floor;
            }
            else if (chars[i * w + j] == '@' && exit == NULL)
            {
                exit = new Exit(j, i);
                map->add(exit);
            }
            else if(chars[i*w+j] == '=')
            {
                Door* door = new Door(j, i, true); 
                map->add(door);
            }
            else if(chars[i*w+j] == '+')
            {
                Door* door = new Door(j, i, false);
                map->add(door);
            }
            else if(chars[i*w+j] == '^')
            {
                Floor* floor = new Floor(j, i);
                map->add(floor);
                Lamp* light = new Lamp(j, i);
                map->addLight(light);
                floor->above = light;
                light->below = floor;
            }
            else
                map->add(new Floor(j, i));
            
        }
    }
    messages = new MessageQueue(4);
    map->resetEnvironment();
    map->updateEnvironment();
}
Game::~Game()
{
}
string Game::display()
{
    stringstream ss;
    ss << messages->print();
    ss << map->print();
    return ss.str();
}
void Game::update(char c)
{
    if(!player)
    {
        Message* message = new Message("Missing player");
        messages->addMessage(message);
    }
    else
    {
        switch (c)
        {
            case '1':
                {try
                {
                    player->move(-1, 1);
                }
                catch (string msg)
                {
                    Message* message = new Message(msg);
                    messages->addMessage(message);
                }
                break;}
            case '2':
                {try
                {
                    player->move(0, 1);
                }
                catch (string msg)
                {
                    Message* message = new Message(msg);
                    messages->addMessage(message);
                }
                break;}
            case '3':
                {try
                {
                    player->move(1, 1);
                }
                catch (string msg)
                {
                    Message* message = new Message(msg);
                    messages->addMessage(message);
                }
                break;}
            case '4':
                {try
                {
                    player->move(-1, 0);
                }
                catch (string msg)
                {
                    Message* message = new Message(msg);
                    messages->addMessage(message);
                }
                break;}
            case '6':
                {try
                {
                    player->move(1, 0);
                }
                catch (string msg)
                {
                    Message* message = new Message(msg);
                    messages->addMessage(message);
                }
                break;}
            case '7':
                {try
                {
                    player->move(-1, -1);
                }
                catch (string msg)
                {
                    Message* message = new Message(msg);
                    messages->addMessage(message);
                }
                break;}
            case '8':
                {try
                {
                    player->move(0, -1);
                }
                catch (string msg)
                {
                    Message* message = new Message(msg);
                    messages->addMessage(message);
                }
                break;}
            case '9':
                {try
                {
                    player->move(1, -1);
                }
                catch (string msg)
                {
                    Message* message = new Message(msg);
                    messages->addMessage(message);
                }
                break;}
            case 'e':
                {Object* temp = player;
                while (temp->below!=NULL)
                {
                    temp = temp->below;
                }
                if(temp->nextHoriz)
                    playerInteract(temp->nextHoriz);
                if(temp->prevHoriz)
                    playerInteract(temp->prevHoriz);
                if(temp->nextVert)
                    playerInteract(temp->nextVert);
                if(temp->prevVert)
                    playerInteract(temp->prevVert);
                break;}
            default:
                {break;}
        }
        if(player->below == exit)
        {
            string output = "You reached the exit!";
            throw output;
        }
    }
    map->resetEnvironment();
    map->updateEnvironment();
}
void Game::playerInteract(Object* object)
{
    if(object)
    {
        try
        {
            object->interact();
        }
        catch(string message)
        {
            Message* m = new Message(message);
            messages->addMessage(m);
        }
    }
}