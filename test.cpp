//lang::CwC


/**
 * Test File for Part 2
 *
 * Authors: cao.yuan1@husky.neu.edu and zhan.d@husky.neu.edu
 */


#include <cstring>
#include <cstdio>
#include <cstdlib>


#include "object.h"
#include "string.h"
#include "array.h"


// Function Forward Declaration
void equality_test();
void get_fields_test();
void memory_access_test();
void t_true( bool );
void t_false( bool);

// Create names used in tests

// Helpers
const char* c1 = "String";
char* c2 = const_cast<char*>(c1);

// Objects
Object* o1 = new Object();
Object* o2 = new Object();

// Strings
String* s1 = new String();
String* s2 = new String(c1);
String* s3 = new String(c2);
String* s4 = new String(s1);
String* s5 = new String(s2);

// Arrays
Array* ao1 = new Array("Object", 1);

Array* ao2 = new Array("Object", 2);

Array* as1 = new Array("String", 4);

Array* as2 = new Array("String", 8);

Array* aa1 = new Array("Array", 3);

Array* aa2;

Array* al1;


int main(int argc, char** argv) {

	// Tests
	equality_test();
	get_fields_test();
	memory_access_test();

	printf("All test have passed!\n");
	return 0;
}

void setup() {
	c1 = "String";
	c2 = const_cast<char*>(c1);

	// Objects
	o1 = new Object();
	o2 = new Object();

	// Strings
	s1 = new String();
	s2 = new String(c1);
	s3 = new String(c2);
	s4 = new String(s1);
	s5 = new String(s2);

	// Arrays
	ao1 = new Array("Object");

	ao2 = new Array("Object");

	as1 = new Array("String");

	as2 = new Array("String");

	aa1 = new Array("Array");

	aa2 new Array(aa1);

	//setUp and testing set
	ao1->set(o1, 0);

	ao2->set(o1, 0);
	ao2->set(o2, 1);

	as1->set(s1, 0);
	as1->set(s2, 1);
	as1->set(s3, 2);
	as1->set(s4, 3);

	as2->set(s1, 1);
	as2->set(s2, 2);
	as2->set(s3, 3);
	as2->set(s4, 4);
	as2->set(s5, 5);
	as2->set(s1, 6);
	as2->set(s2, 7);
	as2->set(s3, 0);

	aa1->set(as1, 1);
	aa1->set(as1, 2);
	aa1->set(as2, 3);

	al1 = new Array("String");
}

void teardown() {
	// tearDown + Destructor Testing
	delete o1;
	delete o2;
	delete s1;
	delete s2;
	delete s3;
	delete s4;
	delete s5;
	delete ao1;
	delete ao2;
	delete as1;
	delete as2;
	delete aa1;
	delete aa2;
	delete al1;
}

// Helper Functions
void fail() { exit(1); }
void OK() { }
void t_true(bool p) { if (!p) fail(); }
void t_false(bool p) { if (p) fail(); }

// Test Implementation
void equality_test () {
	setup();
	printf("Started equality testing... ");

	// Object
	printf("for objects... ");
	t_true(o1->equals(o1));
	t_false(o1->equals(o2));

	// String
	printf("for strings... ");
	t_true(s1->equals(s1));
	t_true(s1->equals(s4));
	t_true(s2->equals(s3));
	t_true(s2->equals(s5));
	t_false(s2->equals(s4));
	t_false(s2->equals(s1));

	// Array
	printf("for arrays... ");
	t_true(ao1->equals(ao1));
	t_true(aa1->equals(aa2));
	teardown();
	printf("Passed.\n");
}

void get_fields_test () {
	setup();
	printf("Started get field testing... ");

	// Object
	printf("for objects... ");
	t_true(strcmp(o1->get_type(), "Object") == 0);
	t_true(strcmp(o2->get_type(), "Object") == 0);

	// String
	printf("for strings... ");
	t_true(strcmp(s1->get_type(), "String") == 0);
	t_true(strcmp(s2->get_type(), "String") == 0);
	t_true(strcmp(s3->get_type(), "String") == 0);
	t_true(strcmp(s4->get_type(), "String") == 0);
	t_true(strcmp(s5->get_type(), "String") == 0);

	t_true(s1->get_len() == 0);
	t_true(s1->get_len() == 6);
	t_true(s1->get_len() == 6);
	t_true(s1->get_len() == 6);
	t_true(s1->get_len() == 6);

	// Array
	printf("for arrays... ");
	t_true(strcmp(ao1->get_type(), "Array") == 0);
	t_true(strcmp(ao2->get_type(), "Array") == 0);
	t_true(strcmp(as1->get_type(), "Array") == 0);
	t_true(strcmp(as2->get_type(), "Array") == 0);
	t_true(strcmp(aa2->get_type(), "Array") == 0);

	t_true(ao1->get_len() == 1);
	t_true(ao2->get_len() == 2);
	t_true(as2->get_len() == 4);
	t_true(as2->get_len() == 8);
	t_true(aa2->get_len() == 3);

	t_true(ao1->get(0)->equals(o1));
	t_true(aa1->get(0)->equals(aa2->get(0)));
	t_true(aa1->get(1)->equals(aa2->get(1)));
	t_true(aa1->get(2)->equals(aa2->get(2)));
	t_true(as2->equals(aa2->get(2)));

	t_true(strcmp(ao1->get_content_type(), "Object") == 0);
	t_true(strcmp(as1->get_content_type(), "String") == 0);
	t_true(strcmp(aa1->get_content_type(), "Array") == 0);

	teardown();
	printf("Passed.\n");
}

void memory_access_test () {
	setup();
	printf("Started memory access testing... ");

	// Object
	// No test needed
	printf("for objects... ");

	// String
	printf("for strings... ");
	t_true(s1->char_at(0) == 0);
	t_true(s1->char_at(1) == 0);
	t_true(s2->char_at(0) == 'S');
	t_true(s2->char_at(1) == 't');
	t_true(s2->char_at(2) == 'r');
	t_true(s2->char_at(3) == 'i');
	t_true(s2->char_at(4) == 'n');
	t_true(s2->char_at(5) == 'g');
	t_true(s2->char_at(6) != 'S');
	t_true(s2->char_at(6) == 0);
	t_true(s2->char_at(-1) == 0);

	// Array
	printf("for arrays... ");
	t_true(ao1->get(0)->equals(o1));
	t_true(o1->equals(ao1->get(0)));
	t_false(ao1->get(10));
	t_false(ao1->set(o1, 1));

	teardown();
	printf("Passed.\n");
}

void get_length_test() {
	setup();
	t_true(al1.get_len() == 0);
	al1.add(s1);
	t_true(al1.get_len() == 1);
	al1.add(s2);
	t_true(al2.get_len() == 2);
	teardown();
}

void insert_test() {
	al1.insert(s1, 0);
	t_true(ali.get(0) == s1);
	ali.insert(s2, 1);
	t_true(ali.get(0) == s2);
	t_true(ali.get(1) == s1);
}

void add() {
	ali.add(s1);
	t_true(ali.get(0) == s1);
	ali.add(s2);
	t_true(ali.get(1) == s2);
}
