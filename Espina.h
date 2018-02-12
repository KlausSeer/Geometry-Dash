#pragma once
#include "Figura.h"
class Espina :
	public Figura
{
public:
	void Mostrar(Graphics^ G);
	Espina();
	Espina(float px, float py, float pl);
	~Espina();
};

