#include "Trampolin.h"



void Trampolin::Mostrar(Graphics ^ G)
{
	Pen^ P = gcnew Pen(Color::Goldenrod);
	G->DrawEllipse(P, x, y, l, l);
	Brush^ B = gcnew SolidBrush(Color::Goldenrod);
	G->FillEllipse(B, x, y, l, l);
}

Trampolin::Trampolin()
{
}

Trampolin::Trampolin(float px, float py, float pl)
{
	Tag = 3;
	x = px;
	y = py;
	l = pl;
}


Trampolin::~Trampolin()
{
}
