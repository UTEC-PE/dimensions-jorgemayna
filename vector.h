#ifndef VECTOR_H
#define VECTOR_H
#include<iostream>
using namespace std;
template <typename Tr>
class Vector {
    public:
        typedef typename Tr::T T;
        typedef typename Tr::Operation Operation;

    private:
        T* data;
        int dataSize;
        Operation op;

        int dimensions;
        int* dimensionSizes;

    public:
        Vector() : data(nullptr) {};

        Vector(int dimensions, int* dimensionSizes) : dimensions(dimensions), dimensionSizes(dimensionSizes) {
            // TODO

            int p=1;
            for(int i=0;i<dimensions;i++)
            {
                p=p*dimensionSizes[i];
            }


            data=new T[p];

        }

        void set(T datum, int* coordinates)
        {
            data[op(coordinates,dimensionSizes,dimensions)]=datum;
        }; // TODO

        T get(int* coordinates)
        {

            return data[op(coordinates,dimensionSizes,dimensions)];

        }; // TODO
};

#endif
