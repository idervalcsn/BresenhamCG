#include "main.h"

//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
	//*************************************************************************
	// Chame aqui as funções do mygl.h
	//*************************************************************************
	std::vector<int> cor = {255, 0, 255,1};
	std::vector<int> cor2 = {0, 255, 255,1};
	for(int i = 0; i < IMAGE_WIDTH/2; i++){
	putPixel(i,0,cor);
	}
	for(int i = IMAGE_WIDTH/2; i < IMAGE_WIDTH; i++){
	putPixel(i,0,cor2);
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

