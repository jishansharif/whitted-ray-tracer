# whitted-ray-tracer

Built a whitted-ray-tracer based off the chapters from scratchpixels.com: https://www.scratchapixel.com/lessons/3d-basic-rendering/ray-tracing-overview/light-transport-ray-tracing-whitted

# How the Algorithm works
The ray is cast into the scene and the closest visible surface is calculated. There are three main cases to consider depending on the type of material this object is made of:

    - If the object is transparent, we cast a reflection and a refraction ray. The resulting colors are mixed using the result of the Fresnel equation.
    - If the object is only reflective (like a mirror) we only need to cast a reflection ray.
    - If the object is diffuse and/or glossy we evaluate the Phong illumination model. Shadow rays are cast towards each light in the scene to find if the point is in shadow.

If the recursion depth is greater than the maximum allowed depth, then the function simply returns the background color and no additional secondary rays are cast.
