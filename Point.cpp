//
// Created by harelfeldman on 1/14/20.
//

#include "Point.h"

Point::Point(int i, int j) {
    this->i = i;
    this->j = j;
}

Point::Point() {
    this->i = 0;
    this->j = 0;
}
/*
 * this method return the i index at the point
 */
int Point::getI() {
    return this->i;
}

int Point::getJ() {
    return this->j;
}

bool Point::operator==(Point other) {
    return (this->getI() == other.getI() && this->getJ() == other.getJ());
}