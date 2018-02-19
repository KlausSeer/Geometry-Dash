#include "Figura.h"


void Figura::Gravity()
{
	GravMod *= -1;
}

float Figura::Getx()
{
	return x;
}

float Figura::Gety()
{
	return y;
}

float Figura::Getl()
{
	return l;
}

short Figura::GetTag()
{
	return Tag;
}

bool Figura::GetColide()
{
	return Colible;
}

void Figura::Colide(bool B)
{
	Colible = B;
}

void Figura::SetTag(short T)
{
	Tag = T;
}

void Figura::Sety(float y)
{
	this->y = y;
}

void Figura::Setx(float x)
{
	this->x = x;
}

void Figura::Mover()
{
	x -= 3;
}

Figura::Figura()
{
}


Figura::~Figura()
{
}