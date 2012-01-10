// Author: Mario S. Könz <mskoenz@gmx.net>
// Date:   10.01.2012 17:42:00 CET
// File:   find_if.hpp

#ifndef FIND_IF_HEADER
#define FIND_IF_HEADER

#include "vector.hpp"
#include "move_on_vector.hpp"

#ifndef SHORTCUTS
#define SHORTCUTS

#define td typedef
#define tn typename
#define tdn typedef typename
#define tpl template
#define tp ::type

#endif

tpl<tn pair_vec, tn pos, tpl<tn> class i_op, tpl<tn> class o_op, tn found> //general find_if (never used)
struct m_find_if_impl;

tpl<tn pair_vec, tn pos, tpl<tn> class i_op, tpl<tn> class o_op>        //if not yet found
struct m_find_if_impl<pair_vec, pos, i_op, o_op, m_false>
{
    tdn m_advance<pair_vec>tp new_vec;
    tdn m_find_if_impl<  new_vec
                    , pos
                    , i_op
                    , o_op
                    , tn m_equal<tn i_op<tn new_vec::item>tp, pos>tp
                    >tp type;
};

tpl<tn pair_vec, tn pos, tpl<tn> class i_op, tpl<tn> class o_op>        //if  found
struct m_find_if_impl<pair_vec, pos, i_op, o_op, m_true>
{
    tdn o_op<tn pair_vec::item>tp type;
};
//======================================================================
tpl<tn pair_vec, tn pos, tpl<tn> class i_op, tpl<tn> class o_op> // nicer interface
struct m_find_if
{
    tdn m_find_if_impl< pair_vec
                    , pos
                    , i_op
                    , o_op
                    , tn m_equal<tn i_op<tn pair_vec::item>tp, pos>tp
                    >tp type;
};

#undef SHORTCUTS
#undef td
#undef tn
#undef tdn
#undef tpl
#undef tp

#endif //FIND_IF_HEADER
