#include "Tile.h"



void Tile::Mostrar(Graphics ^ G)
{
	Pen^ P = gcnew Pen(Color::PaleVioletRed);
	G->DrawRectangle(P, x, y, l2, l1);
	Brush^ B = gcnew SolidBrush(Color::PaleVioletRed);
	G->FillRectangle(B, x, y, l2, l1 );
}

Tile::Tile()
{
}

Tile::Tile(float px, float py, float pl)
{
	Tag = 5;
	x = px;
	y = py;
	l1 = pl;
	l2 = l1 + 90;
}

float Tile::GetL1()
{
	return l1;
}

float Tile::GetL2()
{
	return l2;
}


Tile::~Tile()
{
}
