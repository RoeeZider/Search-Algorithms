//
// Created by harelfeldman on 1/14/20.
//

#ifndef ADVANCEDPROG2_POINT_H
#define ADVANCEDPROG2_POINT_H


class Point {
    int i;
    int j;

public:
    Point(int i, int j);

    Point();

    int getI();

    int getJ();

    bool operator==(Point other);
    bool Equals(Point Other);

};


#endif //ADVANCEDPROG2_POINT_H
