#include "Sculptor.h"
#include <math.h>
#include <fstream>
#include <string>
#include <cstdlib>


Sculptor::Sculptor(int _nx, int _ny, int _nz){

    nx = _nx;
    ny = _ny;
    nz = _nz;
    r = 0;
    g = 0;
    b = 0;
    a = 1;
    v = new Voxel**[nx];
    v[0] = new Voxel*[nx*ny];
    v[0][0] = new Voxel[nx*ny*nz];

    for(int i = 1; i<nx; i++){
        v[i] = v[i-1] + ny;
    }
    for (int i = 0; i<nx; i++){
        for(int j = 0; j<ny; j++){
            v[i][j] = v[0][0] + (i*ny + j) * nz;
        }
    }

    for(int i = 0; i<nx; i++){
        for(int j = 0; j<ny; j++){
            for(int k = 0; k<nz; k++){
                v[i][j][k].r = 1;
                v[i][j][k].g = 1;
                v[i][j][k].b = 1;
                v[i][j][k].a = 1;
                v[i][j][k].show = false;
            }
        }
    }
    }

Sculptor::~Sculptor(){
    delete[] v[0][0];
    delete[] v[0];
    delete[] v;
}

void Sculptor::setColor(float r, float g, float b, float alpha){
    Sculptor::r = r;
    Sculptor::g = g;
    Sculptor::b = b;
    a = alpha;
}

void Sculptor::putVoxel(int x, int y, int z){
    if(x >= 0 && x < nx && y >= 0 && y < ny && z >= 0 && z < nz){
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
    v[x][y][z].show = true;
}
}

void Sculptor::cutVoxel(int x, int y, int z){
    if(x >= 0 && x < nx && y >= 0 && y < ny && z >= 0 && z < nz){
    v[x][y][z].show = false;
}
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
    int _x0 = std::max(0, x0);
    int _x1 = std::min(nx - 1, x1);
    int _y0 = std::max(0, y0);
    int _y1 = std::min(ny - 1, y1);
    int _z0 = std::max(0, z0);
    int _z1 = std::min(nz - 1, z1);
    for (int i=_x0; i<=_x1; i++){
        for (int j=_y0; j<=_y1; j++){
            for (int k=_z0; k<=_z1; k++){
                v[i][j][k].r = Sculptor::r;
                v[i][j][k].g = Sculptor::g;
                v[i][j][k].b = Sculptor::b;
                v[i][j][k].a = Sculptor::a;
                v[i][j][k].show = true;
            }
        }
    }
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    int _x0 = std::max(0, x0);
    int _x1 = std::min(nx - 1, x1);
    int _y0 = std::max(0, y0);
    int _y1 = std::min(ny - 1, y1);
    int _z0 = std::max(0, z0);
    int _z1 = std::min(nz - 1, z1);
    for (int i=_x0; i<=_x1; i++){
        for (int j=_y0; j<=_y1; j++){
            for (int k=_z0; k<=_z1; k++){
                v[i][j][k].show = false;
            }
        }
    }

}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
    int x0 = std::max(0,     xcenter - radius);
    int x1 = std::min(nx - 1, xcenter + radius);
    int y0 = std::max(0,     ycenter - radius);
    int y1 = std::min(ny - 1, ycenter + radius);
    int z0 = std::max(0,     zcenter - radius);
    int z1 = std::min(nz - 1, zcenter + radius);

    for(int i=x0; i<=x1; i++){
        for (int j=y0; j<=y1; j++){
            for (int k=z0; k<=z1; k++){
                if (sqrt(pow(i-xcenter, 2) + pow(j-ycenter, 2) + pow(k-zcenter, 2)) <= radius){
                    v[i][j][k].r = Sculptor::r;
                    v[i][j][k].g = Sculptor::g;
                    v[i][j][k].b = Sculptor::b;
                    v[i][j][k].a = Sculptor::a;
                    v[i][j][k].show = true;
                }
            }
        }
    }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    int x0 = std::max(0,     xcenter - radius);
    int x1 = std::min(nx - 1, xcenter + radius);
    int y0 = std::max(0,     ycenter - radius);
    int y1 = std::min(ny - 1, ycenter + radius);
    int z0 = std::max(0,     zcenter - radius);
    int z1 = std::min(nz - 1, zcenter + radius);

    for(int i=x0; i<=x1; i++){
        for (int j=y0; j<=y1; j++){
            for (int k=z0; k<=z1; k++){
                if (sqrt(pow(i-xcenter, 2) + pow(j-ycenter, 2) + pow(k-zcenter, 2)) <= radius){
                    v[i][j][k].show = false;
                }
            }
        }
    }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    int x0 = std::max(0,     xcenter - rx);
    int x1 = std::min(nx - 1, xcenter + rx);
    int y0 = std::max(0,     ycenter - ry);
    int y1 = std::min(ny - 1, ycenter + ry);
    int z0 = std::max(0,     zcenter - rz);
    int z1 = std::min(nz - 1, zcenter + rz);

    for(int i=x0; i<=x1; i++){
        for (int j=y0; j<=y1; j++){
            for (int k=z0; k<=z1; k++){
                if ((pow(i-xcenter,2)/pow(rx,2) + pow(j-ycenter,2)/pow(ry,2) + pow(k-zcenter,2)/pow(rz,2)) <= 1){
                    v[i][j][k].r = Sculptor::r;
                    v[i][j][k].g = Sculptor::g;
                    v[i][j][k].b = Sculptor::b;
                    v[i][j][k].a = Sculptor::a;
                    v[i][j][k].show = true;
                }
            }
        }
    }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    int x0 = std::max(0,     xcenter - rx);
    int x1 = std::min(nx - 1, xcenter + rx);
    int y0 = std::max(0,     ycenter - ry);
    int y1 = std::min(ny - 1, ycenter + ry);
    int z0 = std::max(0,     zcenter - rz);
    int z1 = std::min(nz - 1, zcenter + rz);

    for(int i=x0; i<=x1; i++){
        for (int j=y0; j<=y1; j++){
            for (int k=z0; k<=z1; k++){
                if ((pow(i-xcenter,2)/pow(rx,2) + pow(j-ycenter,2)/pow(ry,2) + pow(k-zcenter,2)/pow(rz,2)) <= 1){
                    v[i][j][k].show = false;
                }
            }
        }
    }
}

void Sculptor::writeOFF(const char* filename){

    int voxels = 0;
    int va = 0;
    std::ofstream fout;
    std::string nome = std::string(filename);
    fout.open(nome);

    if(!fout.is_open()){
        exit(1);
    }

    fout << "OFF \n";
    for (int i=0; i<nx; i++){
        for (int j=0; j<ny; j++){
            for (int k=0; k<nz; k++){
                if(v[i][j][k].show == 1){
                   voxels++;
                }
            }
        }
    }
    fout << voxels*8 << " " << voxels*6 << " 0 \n";

    for (int i=0; i<nx; i++){
        for (int j=0; j<ny; j++){
            for (int k=0; k<nz; k++){
                if(v[i][j][k].show == 1){
                   fout << i-0.5 << " " << j+0.5 << " " << k-0.5 << "\n";
                   fout << i-0.5 << " " << j-0.5 << " " << k-0.5 << "\n";
                   fout << i+0.5 << " " << j-0.5 << " " << k-0.5 << "\n";
                   fout << i+0.5 << " " << j+0.5 << " " << k-0.5 << "\n";
                   fout << i-0.5 << " " << j+0.5 << " " << k+0.5 << "\n";
                   fout << i-0.5 << " " << j-0.5 << " " << k+0.5 << "\n";
                   fout << i+0.5 << " " << j-0.5 << " " << k+0.5 << "\n";
                   fout << i+0.5 << " " << j+0.5 << " " << k+0.5 << "\n";
                }
            }
        }
    }

    for (int i=0; i<nx; i++){
        for (int j=0; j<ny; j++){
            for (int k=0; k<nz; k++){
                if(v[i][j][k].show == 1){
                    fout << "4 " << 0+(8*va) << " " << 3+(8*va) << " " << 2+(8*va) << " " << 1+(8*va) << " "
                    << v[i][j][k].r << ".0" << " " << v[i][j][k].g << ".0" << " " << v[i][j][k].b << ".0" << " " << v[i][j][k].a << ".0" << "\n";
                    fout << "4 " << 4+(8*va) << " " << 5+(8*va) << " " << 6+(8*va) << " " << 7+(8*va) << " "
                    << v[i][j][k].r << ".0" << " " << v[i][j][k].g << ".0" << " " << v[i][j][k].b << ".0" << " " << v[i][j][k].a << ".0" << "\n";
                    fout << "4 " << 0+(8*va) << " " << 1+(8*va) << " " << 5+(8*va) << " " << 4+(8*va) << " "
                    << v[i][j][k].r << ".0" << " " << v[i][j][k].g << ".0" << " " << v[i][j][k].b << ".0" << " " << v[i][j][k].a << ".0" << "\n";
                    fout << "4 " << 0+(8*va) << " " << 4+(8*va) << " " << 7+(8*va) << " " << 3+(8*va) << " "
                    << v[i][j][k].r << ".0" << " " << v[i][j][k].g << ".0" << " " << v[i][j][k].b << ".0" << " " << v[i][j][k].a << ".0" << "\n";
                    fout << "4 " << 3+(8*va) << " " << 7+(8*va) << " " << 6+(8*va) << " " << 2+(8*va) << " "
                    << v[i][j][k].r << ".0" << " " << v[i][j][k].g << ".0" << " " << v[i][j][k].b << ".0" << " " << v[i][j][k].a << ".0" << "\n";
                    fout << "4 " << 1+(8*va) << " " << 2+(8*va) << " " << 6+(8*va) << " " << 5+(8*va) << " "
                    << v[i][j][k].r << ".0" << " " << v[i][j][k].g << ".0" << " " << v[i][j][k].b << ".0" << " " << v[i][j][k].a << ".0" << "\n";
                   va++;
                }
            }
        }
    }
}
