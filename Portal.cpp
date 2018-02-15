#include "Portal.h"



void Portal::Mostrar(Graphics ^ G, Bitmap ^ img)
{
	G->DrawImage(img, x, y, l, l + 35);
}

Portal::Portal()
{
}

Portal::Portal(float px, float py, float pl, bool b)
{
	Primero = b;
	if (Primero)
		Tag = 5;
	else
		Tag = 6;
	x = px;
	y = py;
	l = pl;
}


Portal::~Portal()
{
}
