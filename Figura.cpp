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

Figura::Figura()
{
}


Figura::~Figura()
{
}
