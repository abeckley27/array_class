#ifndef ARRAY_H
#define ARRAY_H

#include <cstddef> // For size_t
#include <xkeycheck.h>

template <typename T>
class array {
public:
    // Default Constructor: Initializes data to a null pointer. Useful only for reassignment
    array();

    //Other constructors
    array(int n, T);            //Initialize by setting the entire array to a certain value
    array(const array<T>&);     //copy constructor
    array(T*, int len_);        //Initialize using data is a raw array

    // Destructor
    ~array() { this->clear(); }

    // Accessor methods:
    size_t size() const; // Returns the size of the array
    size_t data_size() const;   // Returns the size of the elements, T
    
    void print();
    T& operator[](int i); // Access element at the specified index

    //Arithmetic methods
    void operator+=(const array<T>& a1);
    void operator-=(const array<T>& a1);

    void add_arrays(const array<T>& a2, const array<T>& a3);
    void subtract_arrays(const array<T>& a2, const array<T> a3);

    T operator*(const array<T>& a1);   //dot product
    

    //comparison
    bool operator==(const array<T>& a1);
    

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


template<typename T>
inline array<T>::array(int N, T value)
{
    n_alloc = N;
    T_size = sizeof(T);
    data = new T[N];
    for (int i = 0; i < N; i++) { data[i] = value; }
}

//copy constructor
template<typename T>
inline array<T>::array(const array<T>& a1)
{
    T_size = a1.T_size;
    n_alloc = a1.n_alloc;
    data = new T[n_alloc];
    for (int i = 0; i < n_alloc; i++) { data[i] = a1.data[i]; }
}

template<typename T>
inline array<T>::array(T* a1, int len_)
{
    T_size = sizeof(*a1);
    n_alloc = len_;
    data = new T[len_];

    for (int i = 0; i < len_; i++) { data[i] = a1[i]; }
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

template<typename T>
inline void array<T>::operator+=(const array& a1)
{
    if (n_alloc != a1.n_alloc)
    {
        //I dunno, don't add them I guess.
    }
    else {
        for (int i = 0; i < n_alloc; i++) { data[i] = data[i] + a1.data[i]; }
    }
}

template<typename T>
inline void array<T>::operator-=(const array& a1)
{
    if (n_alloc != a1.n_alloc)
    {
        //
    }
    else {
        for (int i = 0; i < n_alloc; i++) { data[i] = data[i] - a1.data[i]; }
    }
}


template<typename T>
inline void array<T>::add_arrays(const array<T>& a2, const array<T>& a3)
{
    if (this->data != NULL)
    {
        for (int i = 0; i < this->n_alloc; i++) { this->data[i] = a2.data[i] + a3.data[i]; }
    }
    else {
        this->n_alloc = a2.n_alloc;
        if (a3.n_alloc > a2.n_alloc) { this->n_alloc = a3.n_alloc; }

        this->T_size = sizeof(T);
        this->data = new T[n_alloc];

        // THIS IS SUPER UNSAFE MEMORY ACCESS IF a2 AND a3 HAVE DIFFERENT LENGTHS
        for (int i = 0; i < this->n_alloc; i++) { this->data[i] = a2.data[i] + a3.data[i]; }
    }
}

template<typename T>
inline void array<T>::subtract_arrays(const array<T>& a2, const array<T> a3)
{
    if (this->data != NULL)
    {
        for (int i = 0; i < this->n_alloc; i++) { this->data[i] = a2.data[i] - a3.data[i]; }
    }
    else {
        this->n_alloc = a2.n_alloc;
        if (a3.n_alloc > a2.n_alloc) { this->n_alloc = a3.n_alloc; }

        this->T_size = sizeof(T);
        this->data = new T[n_alloc];

        // THIS IS SUPER UNSAFE MEMORY ACCESS IF a2 AND a3 HAVE DIFFERENT LENGTHS
        for (int i = 0; i < this->n_alloc; i++) { this->data[i] = a2.data[i] - a3.data[i]; }
    }
}

template<typename T>
inline T array<T>::operator*(const array& a1)
{
    T output = T(1);
    for (int i = 0; i < n_alloc; i++) { output *= (data[i] * a1.data[i]); }

    return output;
}

template<typename T>
inline bool array<T>::operator==(const array<T>& a1)
{
    bool output = true;
    for (int i = 0; i < n_alloc; i++) {
        if (data[i] != a1.data[i]) {
            output = false;
            break;
        }
    }
    return output;
}


template <typename T>
size_t array<T>::size() const {
    return n_alloc;
}

template<typename T>
inline size_t array<T>::data_size() const
{
    return T_size;
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










