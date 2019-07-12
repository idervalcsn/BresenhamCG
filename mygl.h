#ifndef _MYGL_H_
#define _MYGL_H_

#include "definitions.h"
#include <vector>

typedef struct Pixel {
	int x;
	int y;
	
	int red;
	int green;
	int blue;
	int alpha;
	} Pixel;
		


//*****************************************************************************
// Defina aqui as suas funções gráficas
//*****************************************************************************

//Desenha um pixel na tela. Seus atributos são definidos no struct passado. 
void putPixel(Pixel p) {
	
	int endereco = p.x*4 + p.y*4*IMAGE_WIDTH;
	FBptr[endereco] = p.red;
	FBptr[endereco + 1] = p.green;
	FBptr[endereco + 2] = p.blue;
	FBptr[endereco + 3] = p.alpha;
}


#endif // _MYGL_H_

