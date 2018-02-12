#pragma once
#include "Figura.h"
class Player :
	public Figura
{
	double dx, dy;
	double Vo;
	double angulo;
	bool EnAire = false;
	bool Saltando = false;
	bool Impulsando = false;
	bool OnColision = false;
	double t;
	double Rotation;
	int Lim;
public:
	Player();
	~Player();
	Player(float px, float py, float pl);
	
	void Salto(double tiempo);
	void Impulso(double tiempo);
	void Mostrar(Graphics ^ G);

	void CheckColision(Figura*a, double *t);
	bool Colision(Figura* a);

	int GetLim();
	double GetDx();
	double GetVo();
	double Getangulo();
	bool GetSaltando();
	bool GetImpulsando();
	bool GetEnAire();
	double Gett();
	double GetRotation();

	void Mover();
	void SetDx(double Dx);
	void SetDy(double Dy);
	void SetVo(double Vo);
	void Setangulo(double angulo);
	void SetSaltando(bool Saltando);
	void SetImpulsando(bool Impulsando);
	void Sett(double t);
	void SetRotation(double Rotation);
	void SetOnAire(bool Aire);
};

