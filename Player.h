#pragma once
#include "Figura.h"
class Player :
	public Figura
{
protected:
	double dy;
	double t;
	int Rotation;
	int Lim;
	bool Impulsando = false;
	bool Saltando = false;
	bool EnAire = false;
	bool EnPortal = false;
	bool OnColision = false;
	bool Transformado;
public:
	
	//Metodos Get
	int GetLim();
	double GetDy();
	bool GetTransformado();
	bool GetSaltando();
	bool GetImpulsando();
	bool GetEnAire();
	double Gett();
	double GetRotation();
	bool GetEnPortal();
	bool GetOnColision();

	//Metodos Set
	void SetDy(double Dy);
	void SetSaltando(bool Saltando);
	void SetImpulsando(bool Impulsando);
	void Sett(double t);
	void SetRotation(double Rotation);
	void SetOnAire(bool Aire);
	void SetEnPortal(bool Portal);

	virtual bool GetTiled();
	virtual void Impulso(double tiempo);
	virtual bool Colision(Figura* a);
	virtual void Transformar() = 0;
	virtual void Salto(double tiempo) = 0;
	virtual void CheckColision(Figura* a, double *T) = 0;
	Player();
	~Player();
};

