#include <r_iostream.hpp>

using namespace eio;

const Cout& Cout::operator<<(const int integer) const
{
    cprintf("%d", integer);
    return *this;
}
const Cout& Cout::operator<<(const char *s) const
{
    cprintf("%s", s);
    return *this;
}