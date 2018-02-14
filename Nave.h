#pragma once
#include "Player.h"
class Nave :
	public Player
{
	//Para animacion
	int i = 0;
	int j = 0;
public:
	Nave();
	Nave(float px, float py, float pl);
	~Nave();

	void Tranformar();
	void Mover();
	void Salto(double tiempo);
	void Mostrar(Graphics^ G, Bitmap^ img);
};

