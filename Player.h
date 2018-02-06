#pragma once
#include "Figura.h"
#include "Tile.h"
class Player :
	public Figura
{
	int Lim;
	double a, b;
	double dx, dy;
	double Vo;
	double angulo;
	double t;
	double TiempoReal = 0;
	bool OnImpulse = false;
	bool Salto = false;
	bool Tiled = false;
public:
	Player();
	~Player();
	Player(float px, float py, float pl);

	bool JumpState();
	bool ImpulseState();
	bool Colision(Figura* a);
	bool Dentro(Figura* a);

	void MoverP(double tiempo);
	void Mover();
	void Mostrar(Graphics ^ G);
	
	void CheckColision(Figura*a, double *t);
	void Impulso(double tiempo);
	void SetDx(double pdx);
	void SetDy(double pdy);
	void Saltar(bool B);
	void Tiling(Figura* a);
	double GetTiempo();
	int GetLim();
	double GetTiempoReal();
	void SetTiempo(double t);
	void Impulsar(bool b);
};

