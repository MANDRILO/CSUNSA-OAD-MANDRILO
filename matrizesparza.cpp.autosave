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
    NodeE *&temp_row=row[x_coord];
    NodeE *&temp_colum=colum[y_coord];
    insert_X(&New_Node,temp_row);
    insert_Y(&New_Node,temp_colum);
}
/*INSERTA EL NODO EN EL EJE Y CON UN X ESTATICO
 */
void MatrizEsparza::insert_X(NodeE *Node_new,NodeE *&N_father)
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
void MatrizEsparza::insert_Y(NodeE *Node_new,NodeE *&N_Father)
{
    if(!Node_new || N_Father->coord_x > Node_new->coord_x)
    {
        Node_new->nextDown=N_Father;
        N_Father=Node_new;
        return;
    }
    insert_Y(Node_new,N_Father->nextRight);
}


