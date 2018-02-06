#pragma once
#include "Figura.h"
class Portal :
	public Figura
{
public:
	void Mostrar(Graphics^G);
	Portal();
	Portal(float px, float py, float pl);
	~Portal();
};

