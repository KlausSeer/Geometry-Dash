#pragma once
#include "Player.h"
class Nave :
	public Player
{
	//Para la animacion
	int i = 0;
	int j = 0;
public:
	void Transformar();
	Nave();
	Nave(float px, float py, float pl);
	~Nave();

	void Mover();
	void Salto(double tiempo);
	void Mostrar(Graphics^ G, Bitmap^ img);
	void CheckColision(Figura*a, double *T);
};

