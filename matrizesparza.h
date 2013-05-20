#ifndef MATRIZESPARZA_H
#define MATRIZESPARZA_H
#include "expression.h"
#include"types.h"
#include <new>


class MatrizEsparza
{
    struct NodeE
    {
        Expression *type_dato;
        num coord_x,coord_y;
        NodeE *nextRight,*nextDown;
        vector<NodeE*>depend_list;
        NodeE(Expression *dato,const num x,const num y):type_dato(dato),coord_x(x),coord_y(y){};
    };
    vector<NodeE*>row;
    vector<NodeE*>colum;
public:
    MatrizEsparza();
    MatrizEsparza(const num x,const num y);
    void insert_X(NodeE *Node_new,NodeE *&N_Father);
    void insert_Y(NodeE *Node_new,NodeE *&N_Father);
    void insertCell(Expression *Dato,num x_coord,num y_coord);
    bool delete_X(NodeE *&N_Father,num x);
    bool delete_Y(NodeE *&N_Father, num y);
    bool deleteCell(num axis_x,num axis_y);
    void set_value(dato_cadena,num axis_x,num axis_y);

};

#endif // MATRIZESPARZA_H
