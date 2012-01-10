// Author: Mario S. Könz <mskoenz@gmx.net>
// Date:   10.01.2012 20:39:52 CET
// File:   quartett.hpp

#ifndef QUARTETT_HEADER
#define QUARTETT_HEADER

#ifndef SHORTCUTS
#define SHORTCUTS

#define td typedef
#define tn typename
#define tdn typedef typename
#define tpl template
#define tp ::type

#endif

tpl<tn _1, tn _2, tn _3, tn _4> // the quartett
struct m_quartett
{
    td _1 first;
    td _2 second;
    td _3 third;
    td _4 fourth;
};
//======================================================================
tpl<tn qrt, tn _1> //change 1. argument
struct m_qrt_chng_first
{
    td m_quartett<_1
                , tn qrt::second
                , tn qrt::third
                , tn qrt::fourth
                > type;
};

tpl<tn qrt, tn _2> //change 2. argument
struct m_qrt_chng_second
{
    td m_quartett<tn qrt::first
                , _2
                , tn qrt::third
                , tn qrt::fourth
                > type;
};

tpl<tn qrt, tn _3> //change 3. argument
struct m_qrt_chng_third
{
    td m_quartett<tn qrt::first
                , tn qrt::second
                , _3
                , tn qrt::fourth
                > type;
};

tpl<tn qrt, tn _4> //change 4. argument
struct m_qrt_chng_fourth
{
    td m_quartett<tn qrt::first
                , tn qrt::second
                , tn qrt::third
                , _4
                > type;
};
//======================================================================
tpl<tn qrt, tpl<tn> class op> //apply op to the 1. argument
struct m_qrt_apply_first
{
    td m_quartett<tn op<tn qrt::first>tp
                , tn qrt::second
                , tn qrt::third
                , tn qrt::fourth
                > type;
};
tpl<tn qrt, tpl<tn> class op> //apply op to the 2. argument
struct m_qrt_apply_second
{
    td m_quartett<tn qrt::first
                , tn op<tn qrt::second>tp
                , tn qrt::third
                , tn qrt::fourth
                > type;
};
tpl<tn qrt, tpl<tn> class op> //apply op to the 3. argument
struct m_qrt_apply_third
{
    td m_quartett<tn qrt::first
                , tn qrt::second
                , tn op<tn qrt::third>tp
                , tn qrt::fourth
                > type;
};
tpl<tn qrt, tpl<tn> class op> //apply op to the 4. argument
struct m_qrt_apply_fourth
{
    td m_quartett<tn qrt::first
                , tn qrt::second
                , tn qrt::third
                , tn op<tn qrt::fourth>tp
                > type;
};
//======================================================================
//only for debuging

#include <iostream>
#include <typeinfo>

using namespace std;

tpl <tn qrt>
void m_print_quart()
{
    cout << "first : " << typeid(tn qrt::first).name() << endl;
    cout << "second: " << typeid(tn qrt::second).name() << endl;
    cout << "third : " << typeid(tn qrt::third).name() << endl;
    cout << "fourth: " << typeid(tn qrt::fourth).name() << endl;
}

#undef SHORTCUTS
#undef td
#undef tn
#undef tdn
#undef tpl
#undef tp

#endif //QUARTETT_HEADER
