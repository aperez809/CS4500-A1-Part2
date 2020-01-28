//lang::CwC


#pragma once


#include "object.h"


/**
 * Array: represents a resizable array of objects of the same type
 * as the content_type.
 * The content_type of the array is chosen at the construction and only
 * elements that matches the content_type can be stored.
 * In the case that the content_type is Array, then the only guarantee
 * is that the elemenet stored are of type Array.
 */
class Array : public Object {

  public:
    /**
     * Constructs a new Array with the given type.
     * The initial values of this Array are initialized to nullptr.
     */
    Array(const char* content_type) {}

    /**
     * Constructs a new Array with the same type, values, and length
     * as in the given Array a.
     */
    Array(Array* a) {}

    /**
     * Default destructor.
     */
    ~Array() {}

    /**
     * Returns the length of this Array.
     */
    virtual size_t get_len() {}

    /**
     * Returns the content type of this Array.
     */
    virtual const char* get_content_type() {};

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
    */
    virtual void insert(Object* o, size_t index) {}

    /**
    * Adds the given object o at the end of the array.
    */
    virtual void add(Object* o) {}
};
