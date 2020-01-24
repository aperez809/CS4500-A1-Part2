//lang::CwC


#pragma once


#include "object.h"


/**
 * String: represents an immutable string object.
 */ 
class String : public Object {
  public:
    const char* value_; // the stored value
    size_t len_; // the length of the value
    
    /**
     * Constructs a new empty String object.
     */ 
    String() : Object() {}
    
    /**
     * Constructs a new String object from the given value s.
     */ 
    String(const char* s) {}

    /**
     * Constructs a new String object from the given value s.
     */
    String(char* s) {}

    /**
     * Constructs a new String object from another String object.
     */ 
    String(String* s) {}

    /**
     * Destructor for this String object.
     */ 
    ~String() {}

    /**
     * Returns the value stored in this string.
     */ 
    virtual const char* get_value() {}

    /**
     * Returns the length of this string.
     */
    virtual size_t get_len() {}
    
    /**
     * Gets the character at the given index.
     * If idx < 0 or >= the length of the value, the null character is returned.
     */
    virtual char char_at(size_t idx) {}

    /**
     * Compares in a lexicographical order the value stored 
     * in this String object with the value in s. 
     * Returns a negative number, 0, or positive number if 
     * the value of this String is respectively  smaller, 
     * equal, or greater than the value in s.
     */ 
    virtual int compares(String* s) {}
    
    /**
     * Determines if this String is equal to a given Object o.
     *
     * In order for the two object to be equal, they must share the same type
     * and the same values.
     */ 
    virtual bool equals(Object* o) {}
};
