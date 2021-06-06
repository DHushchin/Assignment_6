#include "Light.h"

Light::Light() {}

Light::Light(const Point &point) : base(point) {}

Point Light::getBase()
{
    return this->base;
}