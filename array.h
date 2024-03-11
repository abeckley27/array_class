#ifndef ARRAY_H
#define ARRAY_H

#include <cstddef> // For size_t
#include <xkeycheck.h>

template <typename T>
class array {
public:
    // Default Constructor: Initializes all elements to a default value (e.g., 0 for int, nullptr for pointers).
    array();

    //Other constructors
    array(int n);               //Initialize to length n, using the default constructor for T
    array(int n, T);           //Initialize by setting the entire array to a certain value
    array(const array<T>&);      //copy constructor

    // Destructor
    ~array() { this->clear(); }

    // Accessor methods:
    size_t size() const; // Returns the size of the array
    T& operator[](int i); // Access element at the specified index
    void print();
    

    //Modifier methods
    
    


private:

    void clear();

    T* data; // The actual array storage
    size_t T_size;
    size_t n_alloc;
};

// Constructor implementation

template <typename T>
array<T>::array() {
    data = NULL;
    T_size = sizeof(T);
    n_alloc = 0;
}

template <typename T>
array<T>::array(int N) {

    T_size = sizeof(T);
    n_alloc = N;
    T* data = new T[N];
    for (size_t i = 0; i < n_alloc; ++i) {
        data[i] = T();  // Default constructor for type T
    }
}

//copy constructor
template<typename T>
inline array<T>::array(int N, T value)
{
    n_alloc = N;
    T_size = sizeof(T);
    data = new T[N];
    for (int i = 0; i < N; i++) { data[i] = value; }
}

template<typename T>
inline array<T>::array(const array<T>& a1)
{
    T_size = a1.T_size;
    n_alloc = a1.n_alloc;
    data = new T[n_alloc];
    for (int i = 0; i < n_alloc; i++) { data[i] = a1.data[i]; }
}

template<typename T>
inline void array<T>::clear()
{
    // Clean up any resources (if applicable)
    if (n_alloc > 0) { delete[] data; }
    n_alloc = 0;
}



//Other method implementations
template<typename T>
T& array<T>::operator[](int i)
{
    return data[i];
}


template <typename T>
size_t array<T>::size() const {
    return n_alloc;
}

template<typename T>
void array<T>::print()
{
    for (int i = 0; i < n_alloc - 1; i++)
    {
        std::cout << data[i] << ", ";
    }
    std::cout << data[n_alloc - 1] << std::endl;
}



#endif // ARRAY_H










