#include "Gravedad.h"



void Gravedad::Mostrar(Graphics ^ G, Bitmap ^ img)
{
	G->DrawImage(img, x, y, l, l + 35);
}

Gravedad::Gravedad()
{
}

Gravedad::Gravedad(float px, float py, float pl, bool b)
{
	Primero = b;
	if (Primero)
		Tag = 2;
	else
		Tag = 3;
	x = px;
	y = py;
	l = pl;
}


Gravedad::~Gravedad()
{
}
