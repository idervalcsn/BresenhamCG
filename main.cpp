#include "main.h"

//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
	//*************************************************************************
	// Chame aqui as funções do mygl.h
	//*************************************************************************
    Pixel pxl1 = {100, 300, 255, 0, 0, 0};
    Pixel pxl2 = {200, 150, 0, 0, 255, 0};

    Pixel pxl3 = {400, 300, 0, 255, 0, 0};
    Pixel pxl4 = {300, 150, 0, 0, 255, 0};

    Pixel pxl5 = {150, 450, 255, 0, 0, 0};
    Pixel pxl6 = {350, 450, 0, 255, 0, 0};

    Pixel pxl7 = {100, 300, 255, 0, 0, 1};
    Pixel pxl8 = {300, 400, 0, 255, 0, 1};
    Pixel pxl9 = {400, 350, 0, 0, 255, 1};




    drawLine(pxl1,pxl2);
    drawLine(pxl3,pxl4);
    drawLine(pxl5,pxl6);

    drawTriangle(pxl7,pxl8,pxl9);

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

