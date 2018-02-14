#pragma once
#include "Figura.h"
class Tile :
	public Figura
{
public:
	void Mostrar(Graphics^ G, Bitmap^ img);
	Tile();
	Tile(float px, float py, float pl);
	~Tile();
};

