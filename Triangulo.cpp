#include "Triangulo.h"



void Triangulo::Mostrar(Graphics^G)
{
	Pen^ P = gcnew Pen(Color::Green);
	G->DrawEllipse(P, x, y, l, l);
	Brush^ B = gcnew SolidBrush(Color::Green);
	G->FillEllipse(B, x, y, l, l);
}

Triangulo::Triangulo()
{
}

Triangulo::Triangulo(float px, float py, float pl)
{
	Tag = 1;
	x = px;
	y = py;
	l = pl;
}


Triangulo::~Triangulo()
{
}
