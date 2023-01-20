#define _SILENCE_CXX17_ITERATOR_BASE_CLASS_DEPRECATION_WARNING 1                        //Used to dismiss warnings

#include <iostream>
#include "_vector.hpp"

struct T       //Used to test
{
    int number;
    T(int data)
    {
        number = data;
    }
    T()
    {
        number = 0;
    }
};
int main() //Test program
{
    T test[10];
    for (int i = 1; i < 10; i++)
    {
        test[i].number = i;
    }

    my_vector::_vector Test_Vec_Custom{test[0],test[1],test[2] ,test[3] ,test[4] ,test[5] ,test[6] ,test[7] ,test[8] ,test[9] };

    std::cout << "Custom type access: ";
    for (auto it: Test_Vec_Custom)
    {
        std::cout << it.number<<" ";
    }
    std::cout << "\n"<<"Base type access: ";

    my_vector::_vector Test_Vec_Base{ 1,2,3,4,5,6,7,8,9,10 };
    for (auto it : Test_Vec_Base)
    {
        std::cout << it << " ";
    }
   
}

