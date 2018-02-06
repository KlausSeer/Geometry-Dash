#pragma once
#include <iostream>
using namespace System::Drawing;
class Figura
{
protected:
	short GravMod = 1;
	short Tag;
	float x, y, l;
	double g = 9.81;
	bool Colible = true;
public:
	void Gravity();
	virtual void Mostrar(Graphics ^ G) = 0;
	float Getx();
	float Gety();
	float Getl();
	short GetTag();
	bool GetColide();
	void Colide(bool B);
	void SetTag(short T);
	Figura();
	~Figura();
};

