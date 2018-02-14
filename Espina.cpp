#include "Espina.h"



void Espina::Mostrar(Graphics ^ G, Bitmap^ img)
{
	int x1 = x;
	int y1 = y;
	/*
	array<Point>^ puntos = gcnew array<Point>(lado);
	float x1, y1;
	for (int i = 0; i < lado; i++)
	{
		float ang = 30 + (360 / lado)*i;
		x1 = x + l *System::Math::Cos(ang *System::Math::PI / 180);
		y1 = y + l *System::Math::Sin(ang *System::Math::PI / 180);
		puntos[i] = Point(x1, y1);
	}
	G->DrawImage(img, puntos);*/
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
