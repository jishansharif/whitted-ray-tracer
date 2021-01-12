// Include all the necessary packages

#include <cstdlib> 
#include <cstdio> 
#include <cmath> 
#include <fstream> 
#include <vector> 
#include <iostream> 
#include <cassert>

# if defined __APPLE__

# else

#define M_PI 3.1415926535;

// We are declaring infinity values as well as Pi values here
#define INFINITY 1e8; 
#endif 

template <typename T>

class newVec
{
    public:
        T x, y, z;
        // We first initialize a new vector class newVec with cordinates
        // in three dimensions.

        // We have dealt with the case where the class newVec was initialized 
        // without any cordinates, with an x cordinate, and x y z cordinates.
        newVec() : x(T(0)), y(T(0)), z(T(0)) {}
        newVec(T xx) : x(xx), y(xx), z(xx) {} 
        newVec(T xx, T yy, T zz) : x(xx), y(yy), z(zz) {}
        newVec& normalize()
        /*
            normalization is a mechanism or process 
            to return something to a normal state or condition
        */
        {
            T nor2 = length2();
            if (nor2 > 0) {
                T invNor = 1 / sqrt(nor2);
                x = x * invNor;
                y = y * invNor;
                z = z * invNor;
            }
            return *this;

        }

}

