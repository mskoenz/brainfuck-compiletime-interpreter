#ifndef INT_HEADER
#define INT_HEADER

#include "bool.hpp"

#ifndef SHORTCUTS
#define SHORTCUTS

#define td typedef
#define tn typename
#define tdn typedef typename
#define tpl template
#define tp ::type

#endif

tpl <int N> //int-def
struct m_int
{
    enum{value = N};
};
//======================================================================
tpl <tn a, tn b>   //operator +
struct m_plus
{
    td m_int<a::value + b::value> type;
};
//======================================================================
tpl <tn a, tn b>   //operator -
struct m_minus
{
    td m_int<a::value - b::value> type;
};
//======================================================================
tpl<tn a, tn b>    //operator ==
struct m_equal
{
    tdn m_bool<(int(a::value) == int(b::value))>tp type;
};
//======================================================================
tpl<tn a, tn b>    //operator >
struct m_bigger
{
    tdn m_bool<(int(a::value) > int(b::value))>tp type;
};
//======================================================================
tpl<tn a, tn b>    //operator <
struct m_smaller
{
    tdn m_bool<(int(a::value) < int(b::value))>tp type;
};

#undef SHORTCUTS
#undef td
#undef tn
#undef tdn
#undef tpl
#undef tp

#endif //INT_HEADER
