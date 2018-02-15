#include "Trampolin.h"



void Trampolin::Mostrar(Graphics ^ G, Bitmap ^ img)
{
	G->DrawImage(img, x, y, l, l);
}

Trampolin::Trampolin()
{
}

Trampolin::Trampolin(float px, float py, float pl)
{
	Tag = 7;
	x = px;
	y = py;
	l = pl;
}


Trampolin::~Trampolin()
{
}
