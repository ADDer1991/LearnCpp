#include <iostream>
#include "common.h"

common::common(/* args */)
{
    x = 1;
    p_data.reset(new data());
}

common::~common()
{
}

int common::get_value()
{
    return p_data->get_data();
}

void common::set_value(int input)
{
    p_data->set_data(input);
}