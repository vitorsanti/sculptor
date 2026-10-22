#include "Sculptor.h"

int main()
{
    // cria um escultor cuja matriz tem 10x10x10 voxels
    Sculptor trono(30,30,30);
    // para mudar a cor do voxel
    trono.setColor(0,0,1.0,1.0); // azul
    // ativa os voxels na faixa de [x,y,z] pertencendo a [0-9]
    trono.putBox(0,9,0,9,0,9);
    // desativa os voxels na faixa de [x,y,z] pertencendo a [0-9]
    trono.cutBox(1,8,1,9,1,9);
    trono.setColor(1.0,0.5,0,1.0);
    trono.putEllipsoid(20, 3, 21, 4, 3, 5);
    trono.setColor(0,1.0,0.4,1.0);
    trono.putSphere(15, 15, 10, 4);
    // grava a escultura digital no arquivo "trono.off"
    trono.writeOFF("trono.off");
}
