#ifndef __ITERATOR_HPP__
#define __ITERATOR_HPP__

#include <iterator>

template <class T>
class MyIterator : public std::iterator<std::forward_iterator_tag, T>//Custom iterators with an iterator type of forward_iterator_tag
{
private:
    T* _ptr; //The actual content pointer through which the container is connected
public:
    MyIterator(T* p)
    {
        _ptr = p;
    }
    
    MyIterator& operator=(const MyIterator& iter)
    {
        _ptr = iter._ptr;
    }
   
    bool operator!=(const MyIterator& iter)
    {
        return _ptr != iter._ptr;
    }
   
    bool operator==(const MyIterator& iter)
    {
        return _ptr == iter._ptr;
    }
   
    MyIterator& operator++()
    {
        _ptr++;
        return *this;
    }
    
    MyIterator operator++(int)
    {
        MyIterator tmp = *this;
        _ptr++;
        return tmp;
    }
    
    T& operator*()
    {
        return *_ptr;
    }
};

#endif