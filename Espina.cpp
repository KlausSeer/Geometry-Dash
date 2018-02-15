#include "Espina.h"



void Espina::Mostrar(Graphics ^ G, Bitmap ^ img)
{
	int x1 = x;
	int y1 = y;

	Rectangle Cut(i*(img->Width / 4), 0, img->Width / 4, img->Height);

	G->DrawImage(img, x1, y1, Cut, GraphicsUnit::Pixel);

	i++;
	if (i > 3)
		i = 0;

}

Espina::Espina()
{
}

Espina::Espina(float px, float py, float pl)
{
	lado = 3;
	Tag = 1;
	x = px;
	y = py;
	l = pl;
}


Espina::~Espina()
{
}
