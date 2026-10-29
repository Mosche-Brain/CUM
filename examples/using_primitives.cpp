/*
 * @author: jaro
 * @name:   using_primitives
 * @file:   examples/using_primitives.cpp
 * @date:   29 October 2026 20:15:41
 */

#include <cum/cum.hpp>

#include <cum/neural_primitives/Primitive.hpp>
#include <cum/neural_primitives/Memory.hpp>

namespace cum::dnn
{
    using namespace cum::neural_primitives;
}

int main()
{
    cum::cum(cum::DEVICE::GPU);

    cum::dnn::Memory::Descriptor md({6, 7}, cum::datatype::U8, cum::layout::AB);

    cum::dnn::Primitive::Descriptor pd = cum::dnn::Primitive::Descriptor::Binary(
        cum::dnn::Algo::binary_mul, md, md, md
    );

    cum::dnn::Primitive primitive(pd);
    
    primitive.compile();

    cum::dnn::Memory A(md);
    cum::dnn::Memory B(md);
    cum::dnn::Memory C(md);

    primitive.execute(C, A, B);

    return 0;
}