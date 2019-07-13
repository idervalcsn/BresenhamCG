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

void drawLine(Pixel inicial, Pixel final){
    int xi = inicial.x;
    int xf = final.x;
    int yi = inicial.y;
    int yf = final.y;
    int dx = abs(xf - xi);
    int dy = abs(yf - yi);
    int controle = 0;   //Controla se a direção menor vai crescer ou nao;
    int incX = 0;
    int incY = 0;

    //Define se Y e X estão indo nas direções positivas ou negativas
    if(xf > xi) incX = 1;
    else incX = -1;

    if(yf > yi) incY = 1;
    else incY = -1;


    putPixel(inicial);
    Pixel linha = {inicial.x, inicial.y, inicial.red, inicial.green, inicial.blue, inicial.alpha};  //Esse pixel é o que se moverá e pintará a linha
    if(dx == 0){
        if(yf > yi){    //linha pra baixo
            while(linha.y != yf)
            {

                linha.y++;
                putPixel(linha);

            }
        }
        else{           //linha pra cima
            while(linha.y != yf)
            {

                linha.y--;
                putPixel(linha);

            }
        }

    }
    else if(dy == 0){
        if(xf > xi){    //linha pra baixo
            while(linha.x != xf)
            {

                linha.x++;
                putPixel(linha);

            }
        }
        else{           //linha pra cima
            while(linha.x != xf)
            {

                linha.x--;
                putPixel(linha);

            }
        }
    }
    else {
        if (dx >= dy) {

            controle = dx / 2;
            putPixel(inicial);
            while (linha.x != xf) {
                linha.x += incX;
                controle = controle - dy;
                if (controle < 0) {
                    linha.y += incY;
                    controle += dx;
                }

                putPixel(linha);
            }

        } else {
            controle = dy / 2;
            putPixel(inicial);
            while (linha.y != yf) {
                linha.y += incY;
                controle = controle - dx;
                if (controle < 0) {
                    linha.x += incX;
                    controle += dy;
                }

                putPixel(linha);
            }

        }
    }


}

void drawTriangle(Pixel p1, Pixel p2, Pixel p3){
    drawLine(p1,p2);
    drawLine(p2,p3);
    drawLine(p3,p1);
}


#endif // _MYGL_H_

