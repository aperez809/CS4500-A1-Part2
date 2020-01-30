//lang::CwC


#pragma once


/**
 * Object: represents the superclass from which all objects will extend from.
 * authors: zhan.d@husky.neu.edu, cao.yuan1@husky.neu.edu
 */
class Object {
  public:

    /**
     * Default constructor.
     * Sets its own type to 'Object'
     */
    Object() {}

    /**
     * Default desctructor.
     */
    virtual ~Object() {}

    /**
     * Computes the hash value of this object.
     */
    virtual size_t hash() {}

    /**
     * Determines if this Object is equal to the given Object o.
     */
    virtual bool equals(Object* o) {}
};
