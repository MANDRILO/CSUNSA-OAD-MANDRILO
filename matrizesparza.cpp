#include "matrizesparza.h"

/* CONSTRUCTOR POR DEFECTO INICIALIZA A LA MATRIZ 100 X 100
 */
MatrizEsparza::MatrizEsparza()
{
    for(register num i=0;i<100;++i)
        row.push_back(0);
    for(register num i=0;i<100;++i)
        colum.push_back(0);
}
/*CONSTRUCTOR CON PARAMETROS
 */
MatrizEsparza::MatrizEsparza(const int x,const int y)
{
    for(register num i=0;i<x;++i)
        row.push_back(0);
    for(register num i=0;i<y;++i)
        colum.push_back(0);
}
/*INSERTA UN NODO EN LA MATRIZ ESPARZA
 */
void MatrizEsparza::insertCell(Expression *Dato, num x_coord, num y_coord)
{
    NodeE New_Node(Dato,x_coord-1,y_coord-1);
    NodeE *&temp_row=row[x_coord-1];
    NodeE *&temp_colum=colum[y_coord-1];
    insert_X(&New_Node,temp_colum);
    insert_Y(&New_Node,temp_row);
}
/*INSERTA EL NODO EN EL EJE Y CON UN X ESTATICO
 */
void MatrizEsparza::insert_Y(NodeE *Node_new,NodeE *&N_father)
{
    if(!N_father || Node_new->coord_y < N_father->coord_y)
    {
        Node_new->nextRight=N_father;
        N_father=Node_new;
        return;
    }
    insert_X(Node_new,N_father->nextRight);
}
/*INSERTA EL NODO EN EL EJE X CON UN  Y ESTATICO
 */
void MatrizEsparza::insert_X(NodeE *Node_new,NodeE *&N_Father)
{
    if(!Node_new || N_Father->coord_x > Node_new->coord_x)
    {
        Node_new->nextDown=N_Father;
        N_Father=Node_new;
        return;
    }
    insert_Y(Node_new,N_Father->nextRight);
}
/*ELIMNA UN NODO TAN SOLO RECIBE LAS COORDENAS DE DICHO NODO
 */
bool MatrizEsparza::deleteCell(num axis_x, num axis_y)
{
    NodeE *&temp_row=row[axis_x-1];
    NodeE *&temp_colum=colum[axis_y-1];
    if(delete_X(temp_colum,axis_x) && delete_Y(temp_row,axis_y))
        return 1;
    return 0;
}

/*ELMININA EL NODO APARTIR DE LA COORDENADA X
 */
bool MatrizEsparza::delete_X(NodeE *&N_Father,num x)
{
    NodeE *&xtemp=N_Father->nextRight;
    if(!N_Father && N_Father->coord_x == x)
    {
            xtemp=xtemp->nextRight;
            N_Father->nextRight=xtemp;
            return 1;
    }
    delete_X(N_Father->nextRight,x);
    return 0;
}

/* ELIMINA EL NODO APARTI DE LA COORDENADA Y
 */
bool MatrizEsparza::delete_Y(NodeE *&N_Father,num y)
{
    NodeE *&ytemp=N_Father->nextDown;
    if(!N_Father && N_Father->coord_y == y)
    {
        ytemp=ytemp->nextDown;
        N_Father->nextDown=ytemp;
        return 1;
    }
    delete_Y(N_Father->nextDown,y);
    return 0;
}
