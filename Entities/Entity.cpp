//
// Created by Jens on 2/03/2020.
//

#include "Entity.h"
#include <iostream>

//
// ------------------------------------------------------Constructors---------------------------------------------------
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
// ----------------------------------------------------Methods----------------------------------------------------------
//
/**
 * This method will detect if there's a collision between this Entity and another one.
 * @param other is the other entity where you want to check a collision with.
 * @return true if there's a collision, false if there's not a collision.
 */
bool SI::Entity::detectCollision(SI::Entity* other)
{
    bool returnValue = true;
    // temporary variables to make it easier below.
    float A_upperEdge = SI::Entity::getYPos();
    float A_lowerEdge = SI::Entity::getYPos() + SI::Entity::getHeight();
    float A_leftEdge = SI::Entity::getXPos();
    float A_rightEdge = SI::Entity::getXPos() + SI::Entity::getWidth();

    float B_upperEdge = other->getYPos();
    float B_lowerEdge = other->getYPos() + other->getHeight();
    float B_leftEdge = other->getXPos();
    float B_rightEdge = other->getXPos() + other->getWidth();

    // Here we check if there's a collision.
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

/**
 * Updates the position of this Entity.
 */
void SI::Entity::updatePosition()
{
    SI::Entity::setXPos(SI::Entity::getXPos() + SI::Entity::getDx());
    SI::Entity::setYPos(SI::Entity::getYPos() + SI::Entity::getDy());
}


//
// ---------------------------------------------------Operators---------------------------------------------------------
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
// ------------------------------------------------------Getters--------------------------------------------------------
//
/**
 * Get the x position of this entity.
 * @return the x position.
 */
float SI::Entity::getXPos() const
{
    return xPos;
}

/**
 * Get the y position of this entity.
 * @return the y position.
 */
float SI::Entity::getYPos() const
{
    return yPos;
}

/**
 * Get the width of this entity.
 * @return the width.
 */
float SI::Entity::getWidth() const
{
    return width;
}

/**
 * Get the height of this entity.
 * @return the height.
 */
float SI::Entity::getHeight() const
{
    return height;
}

/**
 * Get the horizontal speed of this entity.
 * @return the dx of this entity.
 */
float SI::Entity::getDx() const
{
    return dx;
}

/**
 * Get the vertical speed of this entity.
 * @return the dy of this entity.
 */
float SI::Entity::getDy() const
{
    return dy;
}

//
// --------------------------------------------------------Setters------------------------------------------------------
//
/**
 * Set the x position of the entity
 * @param xPos
 */
void SI::Entity::setXPos(float xPos)
{
    SI::Entity::xPos = xPos;
}

/**
 * Set the y position of the entity
 * @param yPos
 */
void SI::Entity::setYPos(float yPos)
{
    SI::Entity::yPos = yPos;
}

/**
 * Set the width of the entity
 * @param width
 */
void SI::Entity::setWidth(float width)
{
    SI::Entity::width = width;
}

/**
 * Set the height of the entity
 * @param height
 */
void SI::Entity::setHeight(float height)
{
    SI::Entity::height = height;
}

/**
 * Set the horizontal speed of the entity
 * @param dx
 */
void SI::Entity::setDx(float dx)
{
    SI::Entity::dx = dx;
}

/**
 * Set the vertical speed of the entity
 * @param dy
 */
void SI::Entity::setDy(float dy)
{
    SI::Entity::dy = dy;
}
