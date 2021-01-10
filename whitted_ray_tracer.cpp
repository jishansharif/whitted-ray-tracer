#include <iostream>
using namespace std;

int main() {
    /*
        This is a pseudo implementation of the whitted ray tracer algorithm.
        Propagation of light in nature is simply a countless number of rays 
        emitted from light sources that reflect or refract until they hit the surface of our eye.
        Ray-tracing is elegant in the way that it is based on what happens around us. 
        It follows the path of light from the reverse order (From our eyes to the light source), hence 
        it is the perfect nature simulator.
    */

   for (int height = 0; height < imageHeight; ++i) {
       for (int width = 0; width < imageWidth; ++ j) {
           Ray primaryRay;
           calculatePrimaryRay(height, width, primaryRay)
           // Need to compute the primary Ray direction
           /*
              For each pixel of the image, it shoots a primary ray into the scene.
              The direction of the primary ray is obtained by tracing a line from 
              the eye to the center of that pixel. 
           */
           Point pHit;
           Normal nHit;
           float minimumDistance = INFINITY;
           Object object = NULL;
           /*
               Once we have the direction of the primary ray, we check every object of
               the scene to see if it intersects with any of them. Intersection may happen 
               more than once. In this case, we select the object who's intersection point
               is closest to the eye.
           */ 
           for (int i = 0; i < objects.size(); ++k) {
               if (intersect(object[k], primaryRay, pHit, nHit)) {
                   float distance = findDistance(eyePosition, pHit);
                   if (distance < minDistance) {
                       object = objects[k];
                       minDistance = distance

                   }
               }
           }

           /*
               We will then shoot a shadow ray from the intersection point to the light source.
               If it does intersect with another object, that object will be in shadow.
               If it does not intersect, the object is illuminated
           */

           if (object != NULL) {
               Ray shadowRay;
               shadowRay.direction = lightPosition - pHit;
               bool shadow = false;
               for (int i = 0; i < objects.size(); ++i ) {
                   if (intersect(objects[i], shadow)) {
                       inShadow = true;
                       break;
                   }
               }
            
            if (!isInShadow){
                pixels[i][j] = object -> color * loight.brightness;
            } else {
                pixels[i][j] = 0;
            }

           }

       }
   }

   /*
       This operation is repeated for every pizel, we obtain a two dimensional
       representation of our three dimensional scene. 
   */
} 