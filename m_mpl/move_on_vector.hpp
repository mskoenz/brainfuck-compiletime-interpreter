// Author: Mario S. Könz <mskoenz@gmx.net>
// Date:   10.01.2012 12:18:22 CET
// File:   move_on_vector.hpp


#ifndef MOVE_ON_VECTOR_HEADER
#define MOVE_ON_VECTOR_HEADER

#include "if.hpp"

#include "vector.hpp"

#ifndef SHORTCUTS
#define SHORTCUTS

#define td typedef
#define tn typename
#define tdn typedef typename
#define tpl template
#define tp ::type

#endif

tpl<tn vec>     //advance
struct m_advance
{
    td m_vector<  vec
                , tn vec::next::item
                , tn vec::next::index
                , tn vec::next::next
                > type;
};
tpl<tn pre, tn item, tn index>
struct m_advance<m_vector<pre, item, index, m_vector_end> >
{
    td m_vector_end type;
};
//======================================================================
tpl<tn vec> //for a save advance
struct m_is_end
{
    td m_false type;
};
tpl<>   // is_the _end
struct m_is_end<m_vector_end>
{
    td m_true type;
};

tpl<tn vec> //chooses between advance and pushback/advance
struct m_save_advance
{
    tdn m_if< tn m_is_end<tn vec::next>tp
            , tn m_advance<tn m_push_back<vec, m_int<0> >tp >tp
            , tn m_advance<vec>tp
            >tp type;
};
tpl<>   //for the empty vector
struct m_save_advance<m_vector_end>
{
    tdn m_init_vector<m_int<0> >tp type;
};
//======================================================================
tpl<tn vec>     //back
struct m_back
{
    td m_vector<  tn vec::prev::prev
                , tn vec::prev::item
                , tn vec::prev::index
                , vec
                > type;
};

//======================================================================
tpl<tn vec, tn pos, tn bigger, tn smaller> //general goto impl (never used)
struct m_goto_impl;

tpl<tn vec, tn pos>                         //spez for vec::index > pos
struct m_goto_impl<vec, pos, m_true, m_false>
{
    tdn m_back<vec>tp new_vec;
    tdn m_goto_impl<  new_vec
                    , pos
                    , tn m_bigger<tn new_vec::index, pos>tp
                    , tn m_smaller<tn new_vec::index, pos>tp
                    >tp type;
};

tpl<tn vec, tn pos>                         //spez for vec::index < pos
struct m_goto_impl<vec, pos, m_false, m_true>
{
    tdn m_advance<vec>tp new_vec;
    tdn m_goto_impl<  new_vec
                    , pos
                    , tn m_bigger<tn new_vec::index, pos>tp
                    , tn m_smaller<tn new_vec::index, pos>tp
                    >tp type;
};

tpl<tn vec, tn pos>                         //spez for vec::index == pos
struct m_goto_impl<vec, pos, m_false, m_false>
{
    td vec type;
};
//======================================================================
tpl<tn vec, tn pos> //nice interface
struct m_goto
{
    tdn m_goto_impl<  vec
                    , pos
                    , tn m_bigger<tn vec::index, pos>tp
                    , tn m_smaller<tn vec::index, pos>tp
                    >tp type;
};

#undef SHORTCUTS
#undef td
#undef tn
#undef tdn
#undef tpl
#undef tp

#endif //MOVE_ON_VECTOR_HEADER
