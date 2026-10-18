#pragma once

#include <stdfloat>

#include "cum/Core.hpp"

namespace cum
{
    void cum(DEVICE device = DEVICE::AUTO);
    void recum(DEVICE device = DEVICE::AUTO);
    void decum();
}