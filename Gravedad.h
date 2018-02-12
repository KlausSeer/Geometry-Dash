#pragma once
#include "Figura.h"
class Gravedad :
	public Figura
{
public:
	void Mostrar(Graphics^ G);
	Gravedad();
	Gravedad(float px, float py, float pl);
	~Gravedad();
};

