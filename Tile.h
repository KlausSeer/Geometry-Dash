#pragma once
#include "Figura.h"
class Tile :
	public Figura
{
	float l1, l2;
public:
	void Mostrar(Graphics^G);
	Tile();
	Tile(float px, float py, float pl);
	float GetL1();
	float GetL2();
	~Tile();
};

