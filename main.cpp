#include "Sculptor.h"

int main()
{
    Sculptor silverhand(100, 100, 100);


    silverhand.setColor(0.2, 0.2, 0.2, 1.0);  //pernas do oculos
    silverhand.putBox(20, 20, 50, 50, 2, 10);
    silverhand.putBox(20, 20, 49, 49, 0, 4);
    silverhand.putBox(66, 66, 50, 50, 2, 10);
    silverhand.putBox(66, 66, 49, 49, 0, 4);


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

    silverhand.setColor(0.8, 0.3, 0.0, 0.7); // oculos
    silverhand.putEllipsoid(30, 50, 30, 9, 8, 1);
    silverhand.putEllipsoid(56, 50, 30, 9, 8, 1);
    silverhand.putEllipsoid(30, 50, 29, 9, 8, 1);
    silverhand.putEllipsoid(56, 50, 29, 9, 8, 1);

    silverhand.cutVoxel(30, 50, 31);
    silverhand.cutVoxel(56, 50, 31);
    silverhand.cutVoxel(30, 50, 28);
    silverhand.cutVoxel(56, 50, 28);

    silverhand.writeOFF("silverhand.off");

    return 0;
}
