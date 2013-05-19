#include "matrizesparza.h"

MatrizEsparza::MatrizEsparza()
{
    for(register num i=0;i<100;++i)
        row.push_back(0);
    for(register num i=0;i<100;++i)
        colum.push_back(0);
}

MatrizEsparza::MatrizEsparza(const int x,const int y)
{
    for(register num i=0;i<x;++i)
        row.push_back(0);
    for(register num i=0;i<y;++i)
        colum.push_back(0);
}

void MatrizEsparza::insert_X(NodeE *Node_new,NodeE *&N_father)
{
    if(!N_father || Node_new->coord_x < N_father->coord_x)
    {
        Node_new->nextRight=N_father;
        N_father=Node_new;
        return;
    }
    insert_X(Node_new,N_father->nextRight);
}

void MatrizEsparza::insert_Y(NodeE *&Node_new, NodeE *&N_Father)
{
    if(!Node_new || N_Father->coord_y > Node_new->coord_y)
    {
        Node_new->nextRight=N_Father;
        N_Father=Node_new;
        return;
    }
    insert_Y(Node_new,N_Father->nextRight);
}

void MatrizEsparza::insertCell(Expression *Dato, num x_coord, num y_coord)
{
}
