#include "Sculptor.h"

int main()
{
    Sculptor silverhand(100, 100, 100);


    silverhand.setColor(0.2, 0.2, 0.2, 1.0);
    silverhand.putBox(20, 20, 50, 50, 2, 30);
    silverhand.putBox(20, 20, 49, 49, 0, 4);
    silverhand.putBox(66, 66, 50, 50, 2, 30);
    silverhand.putBox(66, 66, 49, 49, 0, 4);


    silverhand.setColor(0.4, 0.4, 0.4, 1.0);
    silverhand.putEllipsoid(30, 50, 30, 10, 9, 1);
    silverhand.putEllipsoid(56, 50, 30, 10, 9, 1);

    silverhand.setColor(0.9, 0.4, 0.0, 0.7);
    silverhand.putEllipsoid(30, 50, 30, 9, 8, 1);
    silverhand.putEllipsoid(56, 50, 30, 9, 8, 1);

    silverhand.cutVoxel(30, 50, 31);
    silverhand.cutVoxel(56, 50, 31);
    silverhand.cutVoxel(30, 50, 29);
    silverhand.cutVoxel(56, 50, 29);


    silverhand.setColor(0.4, 0.4, 0.4, 1.0);
    silverhand.putVoxel(40, 50, 30);
    silverhand.putVoxel(46, 50, 30);
    silverhand.putBox(41, 45, 51, 51, 30, 30);
    silverhand.putBox(30, 56, 59, 59, 30, 30);



    silverhand.writeOFF("silverhand.off");

    return 0;
}
