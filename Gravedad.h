#pragma once
#include "Figura.h"
class Gravedad :
	public Figura
{
	bool Primero;
public:
	void Mostrar(Graphics^ G, Bitmap^ img);
	Gravedad();
	Gravedad(float px, float py, float pl, bool b);
	~Gravedad();
};

