#pragma once

extern "C"
{
#include <sbi.h>
#include <r_stdio.h>
}

namespace eio
{
    class Cout {
    public:
        const Cout& operator<<(const int integer) const;
        const Cout& operator<<(const char *s) const;
    };

    [[maybe_unused]] static Cout cout;
}