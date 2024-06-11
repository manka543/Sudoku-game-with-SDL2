//
// Created by manka543 on 5/20/24.
//

#ifndef SQUARE_H
#define SQUARE_H



struct Square
{
    enum Type
    {
        none, user, userFault, program, programFault
    };

    Square(): type(none), value(0){};
    Square(Type type, int value): type(type), value(value){};

    Type type;
    int value;
};



#endif //SQUARE_H
