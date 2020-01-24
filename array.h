//lang::CwC


#pragma once


#include "object.h"


/**
 * Array: represents a fixed length array of objects of the same type 
 * as the content_type.
 * The content_type of the array is chosen at the construction and only
 * elements that matches the content_type can be stored.
 * In the case that the content_type is Array, then the only guarantee 
 * is that the elemenet stored are of type Array.
 */ 
class Array : public Object {
  
  public:
    const char* content_type; // the content type
    size_t len_; // the array length
    Object** vals_; // the stored objects

    /**
     * Constructs a new Array with the given type and length.
     * The initial values of this Array are initialized to nullptr.
     */  
    Array(const char* content_type, size_t len) {}

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
     * If the given i is < 0 or >= than the length, return false to indcate
     * failure.
     * Else, the function will return true to indicate success.
     */  
    virtual bool set(Object *o, size_t i) {}

    /**
     * Determines if this Array is equal to a given Object o.
     */ 
    virtual bool equals(Object* o) {}
};
