#include "Tile.h"



void Tile::Mostrar(Graphics ^ G, Bitmap ^ img)
{
	G->DrawImage(img, x, y, l - 5, l - 5);
}

Tile::Tile()
{
}

Tile::Tile(float px, float py, float pl)
{
	lado = 4;
	Tag = 4;
	x = px;
	y = py;
	l = pl;
}


Tile::~Tile()
{
}
