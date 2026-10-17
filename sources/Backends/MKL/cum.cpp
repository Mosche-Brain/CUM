#include "cum/cum.hpp"

#include "../../../include/cum/detail/vendor/oneapi/context.hpp"

void cum::cum(DEVICE device)
{
    cum::internal::context(device);
}

void cum::recum(DEVICE device)
{
    cum::internal::context(device);
}

void cum::decum()
{

}