#pragma once
#include "Figura.h"
class Player :
	public Figura
{
protected:
	double dx, dy;
	double Rotation;
	int Lim;
	double t;
	bool Transformado;
	bool EnPortal = false;

	bool Tiled = false;
	bool EnAire = false;
	bool OnColision = false;

	bool Saltando = false;
	bool Impulsando = false;
private:
	double Vo;
	double angulo;
public:
	//Contrusctores
	Player();
	~Player();
	Player(float px, float py, float pl);
	
	//Movimiento
	virtual void Salto(double tiempo);
	void Impulso(double tiempo);
	void Mostrar(Graphics ^ G, Bitmap^ img);
	virtual void Mover();

	//Colision
	void CheckColision(Figura*a, double *t);
	bool Colision(Figura* a);
	void Tiling(Figura* a);

	//Metodos Get
	int GetLim();
	double GetDx();
	double GetDy();
	double GetVo();
	double Getangulo();
	bool GetTransformado();
	bool GetSaltando();
	bool GetImpulsando();
	bool GetEnAire();
	double Gett();
	double GetRotation();
	bool GetEnPortal();
	bool GetTiled();
	bool GetOnColision();

	//Metodos Set
	void SetDx(double Dx);
	void SetDy(double Dy);
	void SetVo(double Vo);
	void Setangulo(double angulo);
	void SetSaltando(bool Saltando);
	void SetImpulsando(bool Impulsando);
	void Sett(double t);
	void SetRotation(double Rotation);
	void SetOnAire(bool Aire);
	void SetEnPortal(bool Portal);
	void SetTiled(bool Tile);

	virtual void Tranformar();
};

