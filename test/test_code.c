#include "../linkedlist.h"
#include "test.h"

Element create_int_element(int value)
{
  Element element = malloc(sizeof(int));
  *(int *)element = value;
  return element;
}

int assert_integers(int actual, int expected)
{

  return actual == expected;
}

void test_add_to_list(Result *result)
{
  List_ptr list = create_list();
  Status actual = add_to_list(list, create_int_element(3));
  Status status = assert_integers(actual, Success);
  status = status && assert_integers(list->length, 1);
  print_result("Should add at first when list is empty", status, result);

  actual = add_to_list(list, create_int_element(4));
  status = assert_integers(actual, Success);
  status = status && assert_integers(list->length, 2);
  print_result("Should add the element at the end when list is not empty", status, result);
}
