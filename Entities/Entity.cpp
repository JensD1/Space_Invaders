//
// Created by Jens on 2/03/2020.
//

#include "Entity.h"
#include <iostream>

//
// Constructors---------------------------------------------------------------------------------------------------------
//
SI::Entity::Entity()
{
    std::cout << "Entity created." << std::endl;
    SI::Entity::xPos = 0;
    SI::Entity::yPos = 0;
    SI::Entity::width = 0;
    SI::Entity::height = 0;
    SI::Entity::dx = 0;
    SI::Entity::dy = 0;
}

SI::Entity::Entity(float xPos, float yPos, float width, float height, float dx, float dy)
{
    std::cout << "Entity created." << std::endl;
    SI::Entity::xPos = xPos;
    SI::Entity::yPos = yPos;
    SI::Entity::width = width;
    SI::Entity::height = height;
    SI::Entity::dx = dx;
    SI::Entity::dy = dy;
}

SI::Entity::~Entity()
{
    std::cout << "Entity destroyed." << std::endl;
}

SI::Entity::Entity(const SI::Entity& other)
{
    SI::Entity::xPos = other.xPos;
    SI::Entity::yPos = other.yPos;
    SI::Entity::width = other.width;
    SI::Entity::height = other.height;
    SI::Entity::dx = other.dx;
    SI::Entity::dy = other.dy;
}

//
// Methods--------------------------------------------------------------------------------------------------------------
//

bool SI::Entity::detectCollision(SI::Entity* other)
{
    bool returnValue = true;

    float A_upperEdge = SI::Entity::getYPos();
    float A_lowerEdge = SI::Entity::getYPos() + SI::Entity::getHeight();
    float A_leftEdge = SI::Entity::getXPos();
    float A_rightEdge = SI::Entity::getXPos() + SI::Entity::getWidth();

    float B_upperEdge = other->getYPos();
    float B_lowerEdge = other->getYPos() + other->getHeight();
    float B_leftEdge = other->getXPos();
    float B_rightEdge = other->getXPos() + other->getWidth();

    if(A_upperEdge > B_lowerEdge){
        returnValue = false;
    }
    if(A_lowerEdge < B_upperEdge){
        returnValue = false;
    }
    if(A_leftEdge > B_rightEdge){
        returnValue = false;
    }
    if(A_rightEdge < B_leftEdge){
        returnValue = false;
    }
    return returnValue;
}

//
// Operators------------------------------------------------------------------------------------------------------------
//
SI::Entity& SI::Entity::operator=(const SI::Entity& other)
{
    if(this != &other){
        SI::Entity::xPos = other.xPos;
        SI::Entity::yPos = other.yPos;
        SI::Entity::width = other.width;
        SI::Entity::height = other.height;
        SI::Entity::dx = other.dx;
        SI::Entity::dy = other.dy;
    }
    std::cout << "Game assigned." << std::endl;
    return *this;
}

//
// Getters--------------------------------------------------------------------------------------------------------------
//
float SI::Entity::getXPos() const
{
    return xPos;
}

float SI::Entity::getYPos() const
{
    return yPos;
}

float SI::Entity::getWidth() const
{
    return width;
}

float SI::Entity::getHeight() const
{
    return height;
}

float SI::Entity::getDx() const
{
    return dx;
}

float SI::Entity::getDy() const
{
    return dy;
}

//
// Setters--------------------------------------------------------------------------------------------------------------
//
void SI::Entity::setXPos(float xPos)
{
    SI::Entity::xPos = xPos;
}

void SI::Entity::setYPos(float yPos)
{
    SI::Entity::yPos = yPos;
}

void SI::Entity::setWidth(float width)
{
    SI::Entity::width = width;
}

void SI::Entity::setHeight(float height)
{
    SI::Entity::height = height;
}

void SI::Entity::setDx(float dx)
{
    SI::Entity::dx = dx;
}

void SI::Entity::setDy(float dy)
{
    SI::Entity::dy = dy;
}