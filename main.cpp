#include "sculptor.h"

int main()
{
    Sculptor silverhand(100, 100, 100); // o objetivo do desenho é retratar os óculos de sol e o revolver de Johnny Silverhand, do jogo Cyberpunk
    // 2077, conhecido pelo seu ator, Keanu Reeves. Consegui aplicar todas as funções da classe ao longo do código.

    // PARTE 1: OCULOS DE JOHNNY SILVERHAND
    //---------------------------------------------------------//

    silverhand.setColor(0.2, 0.2, 0.2, 1.0);  //pernas do oculos

    silverhand.putBox(20, 20, 50, 50, 6, 15);
    silverhand.putBox(20, 20, 49, 49, 5, 6);
    silverhand.putBox(20, 20, 48, 48, 4, 5);
    silverhand.putBox(20, 20, 47, 47, 3, 4);
    silverhand.putBox(20, 20, 46, 46, 2, 3);
    silverhand.putBox(20, 20, 45, 45, 1, 2);


    silverhand.putBox(66, 66, 50, 50, 6, 15);
    silverhand.putBox(66, 66, 49, 49, 5, 6);
    silverhand.putBox(66, 66, 48, 48, 4, 5);
    silverhand.putBox(66, 66, 47, 47, 3, 4);
    silverhand.putBox(66, 66, 46, 46, 2, 3);
    silverhand.putBox(66, 66, 45, 45, 1, 2);


    silverhand.setColor(0.7, 0.7, 0.7, 1.0); // apoios do oculos

    silverhand.putEllipsoid(30, 50, 30, 10, 9, 1);
    silverhand.putEllipsoid(30, 50, 29, 10, 9, 1);
    silverhand.putEllipsoid(56, 50, 30, 10, 9, 1);
    silverhand.putEllipsoid(56, 50, 29, 10, 9, 1);

    silverhand.putVoxel(40, 53, 30);
    silverhand.putVoxel(46, 53, 30);
    silverhand.putVoxel(40, 53, 29);
    silverhand.putVoxel(46, 53, 29);

    silverhand.putBox(41, 45, 54, 54, 29, 30);

    silverhand.putBox(35, 51, 58, 58, 29, 30);

    silverhand.putBox(66, 66, 50, 50, 11, 30);
    silverhand.putBox(20, 20, 50, 50, 11, 30);

    silverhand.setColor(0.8, 0.3, 0.0, 0.7); // lentes

    silverhand.putEllipsoid(30, 50, 30, 9, 8, 1);
    silverhand.putEllipsoid(56, 50, 30, 9, 8, 1);
    silverhand.putEllipsoid(30, 50, 29, 9, 8, 1);
    silverhand.putEllipsoid(56, 50, 29, 9, 8, 1);

    silverhand.cutVoxel(30, 50, 31);
    silverhand.cutVoxel(56, 50, 31);
    silverhand.cutVoxel(30, 50, 28);
    silverhand.cutVoxel(56, 50, 28);

    // PARTE 2: REVOLVER DE JOHNNY SILVERHAND
    //---------------------------------------------------------//

    silverhand.setColor(0.5, 0, 0, 1); // base vermelha

    silverhand.putBox(79, 84, 51, 55, 51, 58);
    silverhand.putBox(80, 83, 46, 50, 51, 58);
    silverhand.putBox(80, 83, 42, 45, 50, 57);
    silverhand.putBox(80, 83, 38, 41, 49, 56);

    silverhand.cutEllipsoid(81, 44, 54, 4, 4, 2); // janela do cabo

    silverhand.setColor(1, 0.8, 0.1, 1); // detalhes amarelos

    silverhand.putSphere(79, 54, 56, 1);
    silverhand.putSphere(84, 54, 56, 1);

    silverhand.putBox(81, 82, 52, 52, 78, 81);

    silverhand.setColor(0.7, 0.7, 0.7, 1); // quadro, ferrolho e bloco

    silverhand.putBox(80, 83, 53, 55, 59, 90);
    silverhand.putBox(80, 83, 52, 52, 83, 90);
    silverhand.putBox(81, 82, 49, 49, 59, 62);
    silverhand.putBox(79, 84, 49, 55, 63, 72);

    silverhand.putBox(79, 84, 56, 62, 64, 90);
    silverhand.putBox(79, 84, 56, 60, 52, 63);

    silverhand.cutBox(79, 79, 62, 62, 64, 90); // chanfro do ferrolho
    silverhand.cutBox(84, 84, 62, 62, 64, 90);

    silverhand.cutBox(79, 79, 56, 60, 53, 53); // serrilha
    silverhand.cutBox(79, 79, 56, 60, 55, 55);
    silverhand.cutBox(79, 79, 56, 60, 57, 57);
    silverhand.cutBox(79, 79, 56, 60, 59, 59);
    silverhand.cutBox(84, 84, 56, 60, 53, 53);
    silverhand.cutBox(84, 84, 56, 60, 55, 55);
    silverhand.cutBox(84, 84, 56, 60, 57, 57);
    silverhand.cutBox(84, 84, 56, 60, 59, 59);

    silverhand.setColor(0.35, 0.35, 0.35, 1); // gatilho e base do bloco

    silverhand.putBox(81, 82, 51, 52, 60, 60);
    silverhand.putBox(80, 83, 48, 48, 63, 72);

    silverhand.setColor(0.25, 0.25, 0.28, 1); // faixa lateral

    silverhand.putBox(79, 79, 59, 60, 70, 88);
    silverhand.putBox(84, 84, 59, 60, 70, 88);

    silverhand.setColor(0.1, 0.1, 0.1, 1); // miras

    silverhand.putBox(80, 80, 63, 63, 64, 65);
    silverhand.putBox(83, 83, 63, 63, 64, 65);
    silverhand.putBox(81, 82, 63, 63, 84, 85);

    silverhand.setColor(0, 0, 0, 1); // buracos para saida

    silverhand.putBox(80, 83, 57, 61, 86, 89);

    silverhand.cutBox(81, 82, 61, 61, 87, 90);
    silverhand.cutBox(80, 83, 59, 60, 87, 90);
    silverhand.cutBox(81, 82, 58, 58, 87, 90);

    silverhand.putBox(81, 82, 53, 54, 87, 87);

    silverhand.cutBox(81, 82, 53, 54, 88, 90);

    silverhand.setColor(0.6, 0.6, 0.6, 0.5); // fumaca

    silverhand.putSphere(81, 60, 94, 2);
    silverhand.putSphere(82, 63, 96, 2);
    silverhand.putSphere(81, 66, 98, 1);

    silverhand.cutSphere(83, 62, 95, 1);
    silverhand.cutSphere(80, 64, 97, 1);


    silverhand.writeOFF("silverhand.off");

    return 0;
}