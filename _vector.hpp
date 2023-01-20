#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

#include <iostream>
#include <cstring>
#include "_iterator.hpp"

namespace my_vector
{
#define __rate (2)
    template <class T>
    class _vector
    {
    private:
        size_t len;         //Used to record the maximum free space
        size_t tail;        //Used to record the space that is currently in use
        T* arr;             //Used to maintain dynamic arrays

    public:                                 //Iterator dependent
        typedef MyIterator<T> iterator;     //Custom iterators
        //Common iterator operations

        iterator begin() //Overload begin()
        {
            return iterator(arr);
        }
        iterator end() //Overload end()
        {
            return iterator(arr + tail);
        }

    public: //Vector dependent

        _vector(size_t _size = 1) : tail(0), len(_size)        //The call constructor displayed(_size is the allocated space size)
        {
            arr = new T[len];                                  //Allocated space
        }
        _vector(std::initializer_list<T> data)                 //Use the constructor of the brace initializer
        {
            tail = 0;                               
            len = data.size();                                  //len is the number of arguments
            arr = new T[len];                                   //Allocated space

            for (auto it : data)
            {
                this->push_back(it);                        //Inserting data
            }
        }
        _vector(const _vector<T>& copy)                         //Copy constructor
        {
            len = copy.len;
            tail = copy.tail;
            arr = new T[len];
            memcpy(arr, copy.arr, tail * sizeof(T));
        }

        _vector<T>& operator=(const _vector<T>& copy)           //Overload '='
        {
            len = copy.len;
            tail = copy.tail;
            arr = new T[len];
            memcpy(arr, copy.arr, tail * sizeof(T));
        }

        ~_vector()           //destructor                                   
        {
            delete[] arr;
        }

        size_t size()       //function size() returns the number of spaces currently in use
        {
            return tail;
        }

        size_t max_size()   //function max_size() returns the maximum number of free spaces
        {
            return len;
        }

        bool empty()        //Determine whether the vector is empty(is empty return true if not return false)
        {
            return tail ? true : false;
        }

        friend std::ostream& operator<<(std::ostream& out, _vector<T>& info)       //Overload "<<" be used output vector information
        {
            out << "size = " << info.tail << " max_size = " << info.len << std::endl;
            for (int i = 0; i < info.size(); i++)
            {
                out << info.arr[i] << " ";
            }
            return out;
        }

        T& operator[](size_t n)         //Overload "[]" is used to for subscript access 
        {
            if (n >= tail)              //If n > tail throw error 
                throw std::out_of_range("out of range");
            return arr[n];
        }

        T& at(size_t n)             //Used to access data via n
        {
            if (n >= tail)          
                throw std::out_of_range("out of range");
            return arr[n];
        }

        void push_back(const T& info)       //Used to insert data into the tail
        {
            if (tail + 1 > len)             //Augment when the current space is exhausted and data is inserted
            {
                size_t new_len = int(len * (__rate)) == len ? len + 1 : int(len * (__rate));    //When space needs to be expanded, double the current allocation to reduce the time overhead of frequently allocating space and avoid memory fragmentation
                T* new_arr = new T[new_len];
                memcpy(new_arr, arr, len * sizeof(T));
                delete[] arr;
                len = new_len;
                arr = new_arr;
            }
            arr[tail++] = info;
        }

        void pop_back()
        {
            tail = tail - 1 > 0 ? tail - 1 : throw std::out_of_range("out of range");
        }
    };

    template <typename Ty>//Derivation guidelines for brace initializers
    _vector(std::initializer_list<Ty>) -> _vector<Ty>;
}

#endif