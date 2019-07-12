#include "main.h"

//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
	//*************************************************************************
	// Chame aqui as funções do mygl.h
	//*************************************************************************
	srand(time(NULL));
	std::vector<Pixel> pixels;      //Vetor de pixels
	for(int i = 0; i < 500; i++){
	Pixel p = {i, i, rand() % 255, rand() % 255 , rand() % 255, 0}; //Cada pixel tem cores aleatorias
	pixels.push_back(p);
	}
	for(int i; i < pixels.size(); i++){                             //desenha uma linha com cores aleatórias
	putPixel(pixels[i]);
	}

}

//-----------------------------------------------------------------------------
int main(int argc, char **argv)
{
	// Inicializações.
	InitOpenGL(&argc, argv);
	InitCallBacks();
	InitDataStructures();

	// Ajusta a função que chama as funções do mygl.h
	DrawFunc = MyGlDraw;	

	// Framebuffer scan loop.
	glutMainLoop();

	return 0;
}

