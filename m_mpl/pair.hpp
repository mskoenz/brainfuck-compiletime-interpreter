// Author: Mario S. Könz <mskoenz@gmx.net>
// Date:   10.01.2012 14:42:50 CET
// File:   pair.hpp


#ifndef PAIR_HEADER
#define PAIR_HEADER

#ifndef SHORTCUTS
#define SHORTCUTS

#define td typedef
#define tn typename
#define tdn typedef typename
#define tpl template
#define tp ::type

#endif

tpl<tn _1, tn _2> // the pairlet
struct m_pair
{
    td _1 first;
    td _2 second;
};
//======================================================================
tpl<tn pair, tn _1> //change 1. argument
struct m_pair_chng_first
{
    td m_pair<_1, tn pair::second> type;
};

tpl<tn pair, tn _2> //change 2. argument
struct m_pair_chng_second
{
    td m_pair<tn pair::first, _2> type;
};
//======================================================================
tpl<tn pair>        //extract first
struct m_get_first
{
    tdn pair::first type;
};

tpl<tn pair>        //extract second
struct m_get_second
{
    tdn pair::second type;
};
//======================================================================
//only for debuging

#include <iostream>
#include <typeinfo>

using namespace std;

tpl <tn pair>
void m_print_pair()
{
    cout << "first : " << typeid(tn pair::first).name() << endl;
    cout << "second: " << typeid(tn pair::second).name() << endl;
}

#undef SHORTCUTS
#undef td
#undef tn
#undef tdn
#undef tpl
#undef tp

#endif //PAIR_HEADER
