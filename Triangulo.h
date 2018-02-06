#pragma once
#include "Figura.h"
class Triangulo :
	public Figura
{
public:
	void Mostrar(Graphics^G);
	Triangulo();
	Triangulo(float px, float py, float pl);
	~Triangulo();
};

