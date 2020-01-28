//lang::CwC


#pragma once


/**
 * Object: represents the superclass from which all objects will extend from.
 *
 * All classes that extend this Object class must set their type to be the name
 * of the class itself in their constructors with the first letter being
 * uppercase and all subsequent letters lowercase.
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
     * Returns the type of this Object.
     */
    virtual char* get_type() {}

    /**
     * Determines if this Object is equal to the given Object o.
     */
    virtual bool equals(Object* o) {}
};
