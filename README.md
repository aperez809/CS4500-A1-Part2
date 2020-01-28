# README

## Specs implementers

zhan.d@husky.neu.edu
cao.yuan1@husky.neu.edu

## Content

object.h
string.h
array.h
test.cpp

## Design Choices

Array is a typed resizable array.

We tried to create an Array that can hold any object type. However, we wanted to
distinguish between different subclasses of Object. So, each object get a type
that is a string of its class name.

When an Array is initialized, it is passed a content_type value that is the
string of the name of a class. The type of each new object that gets set into
the array must be a string of the same value as the content_type.

In the case of an array of an array, we interpret that as creating an Array of
Array pointers. It follows from our design that each member of the Array has the
same type (Array), but we do not guarantee that each member of Array of Arrays
has the same content type or same length. The common technique of accessing each
member of the array using double for loops cannot be guaranteed to be successful
here.

## API

A new array can be created in two different ways. The constructor can be given
a content type, after which the constructor will create an Array
object that can hold a number of pointer to the specified object type.
All value are initialized to the nullptr. Alternatively, the
constructor can be given another Array, after which the constructor will create
another copy of the array with the same content type and values.
The values of the new Array must be owned by the new Array.

Array a = new Array("String");  
Array b = new Array(a);  

The length of the array can be queried.

a.get_len();  

The content type of the array can be queried.

a.get_content_type();  

Array support safe access. One of the common errors in C++ is that we can ask
for any number of bytes into an array, and may touch regions we are not allowed
to touch. This implementation prevents that. If you ask for a region that you
are not allowed access, it will return a nullptr instead of a pointer to the
object.

a.get(SIZE_MAX); # -> nullptr  
a.get(2); # -> The third object if it exists, otherwise nullptr

Array supporting setting a new object that is of the same type as the content
type of the Array in an array position that the user is allowed to access.

a.set(String("test"), 0); # -> true  
b.set(Object(), 0); # -> false  

An Array can be compared with another Array. In order for two Arrays to be
equal, they must be extensionally equal. Otherwise, they are not equal.

a.equals(b); # -> false, because there is something in a, but not b.  
b.set(String("test2"), 0);  
a.equals(b); # -> false, because the thing in a[0] and b[0] are not equal
