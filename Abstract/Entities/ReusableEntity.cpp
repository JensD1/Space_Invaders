//
// Created by Jens on 27/04/2020.
//

#include "ReusableEntity.h"
#include <iostream>

//
// ------------------------------------------------------Constructors---------------------------------------------------
//
SI::ReusableEntity::ReusableEntity(float xPos, float yPos, float width, float height, float dx, float dy) : SI::Entity(
        xPos, yPos, width, height, dx, dy) {
    SI::ReusableEntity::inField = false;
    std::cout << "ReusableEntity created" << std::endl;
}

SI::ReusableEntity::~ReusableEntity() {
    std::cout << "ReusableEntity destroyed" << std::endl;
}

SI::ReusableEntity::ReusableEntity(const SI::ReusableEntity& other) : SI::Entity(other) {
    SI::ReusableEntity::inField = other.inField;
    std::cout << "ReusableEntity copied" << std::endl;
}

//
// ---------------------------------------------------Operators---------------------------------------------------------
//
SI::ReusableEntity& SI::ReusableEntity::operator=(const SI::ReusableEntity& other) {
    if (this != &other) {
        SI::Entity::operator=(other);
        SI::ReusableEntity::inField = other.inField;
    }
    std::cout << "ReusableEntity assigned" << std::endl;
    return *this;
}

//
// -------------------------------------------------------Methods-------------------------------------------------------
//
/**
 * Returns the inField variable.
 * @return true when the entity is in the field, false otherwise.
 */
bool SI::ReusableEntity::getInField() {
    return SI::ReusableEntity::inField;
}

/**
 * Set the inField value to a new value.
 * @param inField
 */
void SI::ReusableEntity::setInField(bool inField) {
    SI::ReusableEntity::inField = inField;
}

/**
 * Reset the position of the entity (out of the screen) and set the speed to 0.
 * The inField variable will be set to false.
 */
void SI::ReusableEntity::resetPosition() {
    SI::ReusableEntity::setYPos(SI::OUT_OF_SCREEN);
    SI::ReusableEntity::setXPos(SI::OUT_OF_SCREEN);
    SI::ReusableEntity::setDy(0);
    SI::ReusableEntity::setDx(0);
    SI::ReusableEntity::setInField(false);
}