#include <cstdlib>
#include <iostream>

#include "vector.h"

using namespace std;

template <typename T>
struct Dimensions {
    int operator()(int* coordinates, int* sizes, int dimensions) {
        // TODO
        int pos=0;
        for(int i=0;i<dimensions;i++)
        {
            int po=1;
            for(int j=i+1;j<dimensions;j++)
            {
                po=po*sizes[j];
            }
            po=po*coordinates[i];
            pos=pos+po;
        }


        return pos;
    }
};

struct Integer {
       typedef int T;
       typedef Dimensions<T> Operation;
};

int main(int argc, char *argv[]) {

    //Cree una matriz 2x3 para corroborar el funsionamiento.
    int *cor;
    int *dim;
    cor=new int[2];
    dim=new int[2];
    dim[0]=2;
    dim[1]=3;
    cor[0]=0;
    cor[1]=0;

    int tt=1;
    Vector<Integer> vector(2,dim);
    for(int i=0;i<2;i++)
    {

        for(int j=0;j<3;j++)
        {
            cor[0]=i;
            cor[1]=j;
            vector.set(tt,cor);
            tt++;
        }
    }



    for(int i=0;i<2;i++)
    {

        for(int j=0;j<3;j++)
        {
            cor[0]=i;
            cor[1]=j;
            cout <<vector.get(cor)<<" ";

        }
        cout<<endl;
    }

    system("pause");
    return EXIT_SUCCESS;
}
