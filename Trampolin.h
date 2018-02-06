#pragma once
#include "Figura.h"
class Trampolin :
	public Figura
{
public:
	void Mostrar(Graphics^G);
	Trampolin();
	Trampolin(float px, float py, float pl);
	~Trampolin();
};

