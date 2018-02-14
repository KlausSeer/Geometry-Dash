#pragma once
#include "Figura.h"
class Portal :
	public Figura
{
	bool Primero;
public:
	void Mostrar(Graphics^ G, Bitmap^ img);
	Portal();
	Portal(float px, float py, float pl, bool b);
	~Portal();
};

