// Author: Mario S. Könz <mskoenz@gmx.net>
// Date:   10.01.2012 11:36:51 CET
// File:   vector.hpp


#ifndef VECTOR_HEADER
#define VECTOR_HEADER

#include "int.hpp"

#ifndef SHORTCUTS
#define SHORTCUTS

#define td typedef
#define tn typename
#define tdn typedef typename
#define tpl template
#define tp ::type

#endif

struct m_vector_end{}; //marks the end of the vector

tpl<tn pre, tn what, tn id, tn nex> //the vector
struct m_vector
{
    td pre prev;
    td nex next;
    td what item;
    td id index;
};

tpl <tn item>   //get the first vector-element
struct m_init_vector
{
    td m_vector<m_vector_end, item, m_int<0>, m_vector_end> type;
};


//======================================================================
tpl <tn pre, tn vec, tn item, tn pos>   //the impl of push_back
struct m_push_back_impl
{
    td m_vector<  tn vec::prev
                , tn vec::item
                , tn vec::index
                , tn m_push_back_impl<vec, tn vec::next, item, tn vec::index>::type
                > type;
};

tpl <tn pre, tn item, tn pos>           //recursion-break
struct m_push_back_impl<pre, m_vector_end, item, pos>
{
    td m_vector<pre
                , item
                , tn m_plus<pos, m_int<1> >::type
                , m_vector_end
                > type;
};

tpl <tn vec, tn item> //nice push_back interface
struct m_push_back
{
    td m_vector<  tn vec::prev
                , tn vec::item
                , tn vec::index
                , tn m_push_back_impl<vec, tn vec::next, item, tn vec::index>::type
                > type;
};

tpl <tn item> //for an empty vector
struct m_push_back<m_vector_end, item>
{
    tdn m_init_vector<item>tp type;
};

//======================================================================
tpl<tn pre, tn vec> //       for stack use: top
struct m_top_impl
{
    tdn m_top_impl<vec, tn vec::next>tp type;
};
tpl<tn pre>
struct m_top_impl<pre, m_vector_end> //recursion-end
{
    tdn pre::item type;
};

tpl<tn vec> //nicer interface
struct m_top
{
    tdn m_top_impl<tn vec::prev, vec>tp type;
};
//======================================================================
tpl<tn pre, tn vec, tn nex> //       for stack use: pop
struct m_pop_impl
{
    tdn m_pop_impl<   vec
                    , nex
                    , tn nex::next
                    >tp type;
};
tpl<tn a, tn b>
struct m_goto;

tpl<tn pre, tn vec>
struct m_pop_impl<pre, vec, m_vector_end> //recursion-end
{
    tdn m_goto< m_vector< tn pre::prev
                , tn pre::item
                , tn pre::index
                , m_vector_end> , m_int<0> >tp type;
};
tpl<tn vec>
struct m_pop_impl<m_vector_end, vec, m_vector_end>
{
    td m_vector_end type;
};


tpl<tn vec> //nicer interface
struct m_pop
{
    tdn m_pop_impl<   tn vec::prev
                    , vec
                    , tn vec::next
                    >tp type;
};
//======================================================================
tpl <tn vec> //increase tpl for applying quartett apply_to_...
struct m_increase
{
    td m_vector<tn vec::prev, tn m_plus<tn vec::item, m_int<1> >tp, tn vec::index, tn vec::next> type;
};
tpl <tn vec> //decreases
struct m_decrease
{
    td m_vector<tn vec::prev, tn m_minus<tn vec::item, m_int<1> >tp, tn vec::index, tn vec::next> type;
};
//======================================================================
tpl <tn vec>        //remove void
struct m_remove_void
{
    td m_vector<  tn vec::prev
                , tn vec::item
                , tn vec::index
                , tn m_remove_void<tn vec::next>tp
                > type;
};
tpl<tn pre, tn id, tn nex> //void spez
struct m_remove_void<m_vector<pre, void, id, nex> >
{
    tdn m_remove_void<nex>tp type;
};
tpl<>       //recursion-break
struct m_remove_void<m_vector_end>
{
    td m_vector_end type;
};
//======================================================================
tpl<  int _0 = 0
    , int _1 = 0
    , int _2 = 0
    , int _3 = 0
    , int _4 = 0
    , int _5 = 0
    , int _6 = 0
    , int _7 = 0
    , int _8 = 0
    , int _9 = 0
    >
struct m_fast_int_init
{
    tdn m_push_back<
    tn m_push_back<
    tn m_push_back<
    tn m_push_back<
    tn m_push_back<
    tn m_push_back<
    tn m_push_back<
    tn m_push_back<
    tn m_push_back<
    tn m_init_vector<m_int<_0> >tp
    , m_int<_1> >tp
    , m_int<_2> >tp
    , m_int<_3> >tp
    , m_int<_4> >tp
    , m_int<_5> >tp
    , m_int<_6> >tp
    , m_int<_7> >tp
    , m_int<_8> >tp
    , m_int<_9> >tp type;
};
//======================================================================
//only for debug

#include <iostream>
#include <typeinfo>

template <typename vec> //print fwd
void m_print_vector_fwd()
{
    std::cout << "index: " << typeid(tn vec::index).name() << "   type: " << typeid(tn vec::item).name() << std::endl;
    m_print_vector_fwd<tn vec::next>();
}
template<>
void m_print_vector_fwd<m_vector_end>()
{
    std::cout << "type: " << typeid(m_vector_end).name() << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
}

template <typename vec> //print backwards
void m_print_vector_rev()
{
    std::cout << "index: " << typeid(tn vec::index).name() << "   type: " << typeid(tn vec::item).name() << std::endl;
    m_print_vector_rev<tn vec::prev>();
}
template<>
void m_print_vector_rev<m_vector_end>()
{
    std::cout << "type: " << typeid(m_vector_end).name() << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
}

#undef SHORTCUTS
#undef td
#undef tn
#undef tdn
#undef tpl
#undef tp

#endif //VECTOR_HEADER
