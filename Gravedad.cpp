#include "Gravedad.h"



void Gravedad::Mostrar(Graphics ^ G)
{
	Pen^ P = gcnew Pen(Color::CornflowerBlue, 3);
	G->DrawEllipse(P, x, y, l, l + 35);
}

Gravedad::Gravedad()
{
}

Gravedad::Gravedad(float px, float py, float pl)
{
	Tag = 2;
	x = px;
	y = py;
	l = pl;

}


Gravedad::~Gravedad()
{
}
