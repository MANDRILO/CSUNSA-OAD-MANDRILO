#ifndef OPERADOR_H
#define OPERADOR_H
#include<stack>
#include <math.h>
#include<vector>
#include<string>

using namespace std;
namespace OP{
  
	enum operators {el='^',mu='x',di='/',su='+',re='-'};
	
	//OPERADORES 
	typedef char C;
	typedef double D;
	
	D suma(D num1,D num2){return num1+num2;}
	D resta(D num1,D num2){return num1-num2;}
	D division(D num1,D num2){return num1/num2;}
	D multiplicacion(D num1,D num2){return num1*num2;}
	D elevado(D num1,D num2){return pow(num1,num2);}
	
	
	stack< D,vector<D> >operandos;
	stack< C,vector<C> >operador;
	
	
	D compilador(string &operacion)
	{
		while(!operacion.empty())
		{
			
		}
	}
}
#endif
