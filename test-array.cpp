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

// Objects
Object* o1;
Object* o2;
Object* o3;

// Strings
String* s1;

// Arrays
Array* ao1;
Array* ao2;
Array* ao3;
Array* as1;
Array* as2;
Array* as3;


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
	o3 = new Object();

	// Strings
	s1 = new String();
	s2 = new String(c1);
	s3 = new String(c2);
}

void teardown() {
	// tearDown + Destructor Testing
	delete o1;
	delete o2;
	delete o3;
	delete s1;
	delete ao1;
	delete ao2;
	delete ao3;
	delete as2;
	delete as1;
	delete as3;
}

// Helper Functions
void fail() { exit(1); }
void OK() { }
void t_true(bool p) { if (!p) fail(); }
void t_false(bool p) { if (p) fail(); }

// Test Implementation
void equality_test () {
	printf("Started equality testing... ");

	// Array with objects
	printf("for arrays... ");
	ao1 = new Array();
	ao2 = new Array(ao1);
	t_true(ao1->equals(ao1));
	t_true(ao1->equals(ao2));
	ao1->add(o1);
	ao3 = new Array(ao1);
	t_true(ao1->equals(ao3));


	// Array with strings
	printf("for arrays... ");
	as1 = new Array();
	as2 = new Array(as1);
	t_true(as1->equals(as1));
	t_true(as1->equals(as2));
	as1->add(s1);
	as3 = new Array(as1);
	t_true(as1->equals(as3));

	teardown();
	printf("Passed.\n");
}

void get_fields_test () {
	setup();
	printf("Started get field testing... ");

	// get length object
	printf("for arrays... ");
	ao1 = new Array();
	t_true(ao1->get_len() == 0);
	ao1.add(o1);
	t_true(ao1->get_len() == 1);
	ao1.insert(o2, 0);
	t_true(ao1->get_len() == 2);
	ao1.set(o3, 0);
	t_true(ao1->get_len() == 2);

	// get length strings
	as1 = new Array();
	t_true(as1->get_len() == 0);
	as1.add(s1);
	t_true(as1->get_len() == 1);
	as1.insert(s2, 0);
	t_true(as1->get_len() == 2);
	as1.set(s3, 0);
	t_true(as1->get_len() == 2);

	// get value objects
	ao2 = new Array();
	t_true(ao2->get(0) == nullptr);
	ao2.add(o1);
	t_true(ao2->get(0)->equals(o1));
	ao2.add(o2);
	t_true(ao2->get(1)->equals(o2));
	t_true(ao2->get(2) == nullptr);

	teardown();
	printf("Passed.\n");
}

void set_test() {
	setup();
	printf("Started set testing... ");

	// Array
	printf("for arrays... ");
	ao1 = new Array();
	t_true(ao1->get(0) == nullptr);
	t_true(ao1->set(o1, 0) == nullptr);
	ao1.add(o1, 0);
	t_true(ao1->set(o2, 0)->equals(o1));
	t_true(ao1->get(0)->equals(o2));
	t_true(ao1->set(o3, 1) == nullptr);

	teardown();
	printf("Passed.\n");
}

void insert_test() {
	setup();
	printf("Started insert testing... ");

	printf("for arrays... ");
	as1.insert(s1, 0);
	t_true(as1->get(0) == s1);
	as1.insert(s2, 1);
	t_true(as1->get(0) == s2);
	t_true(as1->get(1) == s1);
	as1.insert(s1, 5);
	t_true(as1->get_len() == 2);

	teardown();
	printf("Passed.\n");
}

void add() {
	setup();
	printf("Started add testing... ");

	printf("for arrays... ");
	as1.add(s1);
	t_true(as1->get(0) == s1);
	as1.add(s2);
	t_true(as1->get(1) == s2);
	t_true(as1->get_len() == 2);

	teardown();
	printf("Passed.\n");
}
