#pragma once
#include "Figura.h"
class Trampolin :
	public Figura
{
public:
	void Mostrar(Graphics^ G, Bitmap^ img);
	Trampolin();
	Trampolin(float px, float py, float pl);
	~Trampolin();
};

