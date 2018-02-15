#pragma once
#include "Player.h"
class Cuadrado :
	public Player
{
	bool Tiled = false;
	double Vo;
	double angulo;
public:
	Cuadrado();
	Cuadrado(float px, float py, float pl);
	~Cuadrado();

	//Metodos Get
	double GetVo();
	double Getangulo();
	bool GetTiled();

	//Metodos Set
	void SetVo(double Vo);
	void Setangulo(double angulo);
	void SetTiled(bool Tile);

	void Mover();
	void Transformar();
	bool Colision(Figura*a);
	void Salto(double tiempo);
	void Impulso(double tiempo);
	void CheckColision(Figura* a, double *T);
	void Mostrar(Graphics ^G, Bitmap ^ img);

};

