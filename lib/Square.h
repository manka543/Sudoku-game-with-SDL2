//
// Created by manka543 on 5/20/24.
//

#ifndef SQUARE_H
#define SQUARE_H


struct Square
{
    enum Type
    {
        None, User, UserFault, Program, ProgramFault
    };

    Square(): type(None), value(0){};
    Square(Type type, int value): type(type), value(value){};

    Type type;
    int value;
};



#endif //SQUARE_H
