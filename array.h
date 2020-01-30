//lang::CwC


#pragma once


#include "object.h"


/**
 * Array: represents a resizable array of objects.
 */
class Array : public Object {

  public:

    /**
     * Constructs a new empty array.
     */
    Array() : Object() {}

    /**
     * Constructs a new Array with the same type, values, and length
     * as in the given Array a.
     */
    Array(Array* a) : Object() {}

    /**
     * Default destructor.
     */
    ~Array() {}

    /**
     * Returns the length of this Array.
     */
    virtual size_t get_len() {}

    /**
     * Returns the value stored at index i in this Array.
     * If the given i is < 0 or >= than the length, a nullptr is returned.
     */
    virtual Object* get(size_t i) {}

    /**
     * Sets the given Object o at index i in this Array.
     * If the given i is < 0 or >= than the length, return nullptr.
     * Else, the function will return the object that was previously at index i.
     */
    virtual Object* set(Object *o, size_t i) {}

    /**
     * Determines if this Array is equal to a given Object o.
     */
    virtual bool equals(Object* o) {}

    /**
    * Inserts the given object o at the given index.
    * If the given i is < 0 or >= than the length, nothing happens.
    */
    virtual void insert(Object* o, size_t index) {}

    /**
    * Adds the given object o at the end of the array.
    */
    virtual void add(Object* o) {}
};
