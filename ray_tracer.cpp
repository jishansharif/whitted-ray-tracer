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

        /*
            Since Vectors have a magnitude and a direction, A shape in the scene will be 
            able to move forward, backwards, up and down. They can also be enlarged and 
            diminished in size. We deal with those conditions here.
        */
        newVec<T> operator * (const T &f) const { return newVec<T>(x * f, y * f, z * f); } 
        newVec<T> operator * (const newVec<T> &v) const { return newVec<T>(x * v.x, y * v.y, z * v.z); }
        // Enlarging an object, We take a constant scale and we multiply each cordinate with that scale
        T dot(const newVec<T> &v) const { return x * v.x + y * v.y + z * v.z; } 
        newVec<T> operator - (const newVec<T> &v) const { return newVec<T>(x - v.x, y - v.y, z - v.z); } 
        newVec<T> operator + (const newVec<T> &v) const { return newVec<T>(x + v.x, y + v.y, z + v.z); } 
        // We now deal with moving an object in the forward direction
        // We also deal with diminishing an object.
        newVec<T>& operator += (const newVec<T> &v) { x += v.x, y += v.y, z += v.z; return *this; } 
        newVec<T>& operator *= (const newVec<T> &v) { x *= v.x, y *= v.y, z *= v.z; return *this; } 
        newVec<T> operator - () const { return newVec<T>(-x, -y, -z); } 
        // length2 and length is the implementation of the Pythagoraus theorem
        // a ** 2 + b ** 2 = c ** 2
        // Using this theorem we know the length of a segment will be
        // sqrt (a ** 2 + b ** 2 + c ** 2) 
        T length2() const { return x * x + y * y + z * z; } 
        T length() const { return sqrt(length2()); }
        // We now return the cordinates such that it is easy to understand.
        friend std::ostream & operator << (std::ostream &os, const newVec<T> &v) 
        { 
            os << "[" << v.x << " " << v.y << " " << v.z << "]"; 
            return os; 
        } 
};

typedef newVec<float> newVecf;

class Sphere
{
    public:
        // We will now initialize aobjects in scene. A sphere will have a midpoint
        // Since it's a 3-D shape, we will need the shape's volume.
        newVecf midPoint;
        float radius, radiusSquared;
        newVecf shapeColor, emissionColor;
        float transparency, reflection;

        // We're going to have to use Snell's equation to determine the angle of reflection
        // and transmission. Hence it is important to declare emissionColor as well as
        // reflection values.
        Sphere (
            const newVecf &midPoint,
            const float &radius,
            const float &radiusSquared,
            const newVecf &shapeColor,
            const newVecf &emissionColor,
            const float &transparency = 0,
            const float &reflection = 0,
        )

        bool intersect(const newVecf &rayOrigin, const Vec3f &rayDirection, float &t0, float &t1) const {
            /*
                One of the most important methods for our ray tracher, once we cast a ray into the scene,
                We need to see whether the ray hits an object or not, this will be computed here.
            */
            newVecf contact = midPoint - rayOrigin;
            float tca = contact.dot(rayDirection);
            if (tca < 0) {
                return false;
            }
            float d2 = contact.dot(contact) - (tca * tca);
            if (d2 < 0) {
                return false;
            }
            float thc = sqrt(radiusSquared - d2);
            t0 = tca - thc;
            t1 = tca + thc;
            return true;
        }
};

#define MAX_RAY_DEPTH 5 
// using MAX_RAY_DEPTH we can ow control the maximum recursion depth
float mix(const float &a, const float &b, const float &mix) 
{ 
    return b * mix + a * (1 - mix); 
} 
 

