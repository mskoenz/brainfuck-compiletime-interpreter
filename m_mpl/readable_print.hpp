// Author: Mario S. Könz <mskoenz@gmx.net>
// Date:   10.01.2012 23:28:11 CET
// File:   readable_print.hpp

#ifndef READABLE_PRINT_HEADER
#define READABLE_PRINT_HEADER

#include "vector.hpp"

#ifndef SHORTCUTS
#define SHORTCUTS

#define td typedef
#define tn typename
#define tdn typedef typename
#define tpl template
#define tp ::type

#endif


#include <iostream>
#include <typeinfo>

tpl<tn vec>         //print with char-representation
void readable_runtime_print_char()
{
    std::cout << char(vec::item::value);
    readable_runtime_print_char<tn vec::next>();
};
tpl<>
void readable_runtime_print_char<m_vector_end>()
{
    std::cout << std::endl << "-----------------" << std::endl;
};
//======================================================================
tpl<tn vec>         //print with int-representation
void readable_runtime_print_int()
{
    std::cout << vec::item::value << std::endl;
    readable_runtime_print_int<tn vec::next>();
};
tpl<>
void readable_runtime_print_int<m_vector_end>()
{
    std::cout << "-----------------" << std::endl;
};

//======================================================================
tpl<tn elem> //print the type of an element
void m_print_type()
{
    std::cout << "single type: " << typeid(elem).name() << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
}

#undef SHORTCUTS
#undef td
#undef tn
#undef tdn
#undef tpl
#undef tp

#endif //READABLE_PRINT_HEADER
