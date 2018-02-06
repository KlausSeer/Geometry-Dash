#include "Portal.h"



void Portal::Mostrar(Graphics ^ G)
{
	Pen^ P = gcnew Pen(Color::CornflowerBlue, 3);
	G->DrawEllipse(P, x, y, l , l + 35);
}

Portal::Portal()
{

}

Portal::Portal(float px, float py, float pl)
{
	Tag = 2;
	x = px;
	y = py;
	l = pl;
}


Portal::~Portal()
{
}
