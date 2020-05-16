#include <math.h>
#include "../linkedlist.h"
#include "test.h"
#include "test_code.h"

Element create_int_element(int value)
{
  Element element = malloc(sizeof(int));
  *(int *)element = value;
  return element;
}

Status assert_array(List_ptr actual_array, Array expected_array)
{

  Status status = Success;
  Node_ptr p_walk = actual_array->first;

  for (int i = 0; i < fmax(actual_array->length, expected_array.length); i++)
  {
    if (expected_array.values[i] != *(int *)p_walk->element)
      status = Failure;
    p_walk = p_walk->next;
  }
  return status;
}

void test_add_to_list(Result *result)
{
  printf("\nadd_to_list\n");
  List_ptr list = create_list();
  add_to_list(list, create_int_element(3));
  int firest_test[] = {3};
  Array first_expected = {firest_test, 1};
  Status status = assert_array(list, first_expected);
  print_result("Should add at first when list is empty", status, result);

  add_to_list(list, create_int_element(4));
  int second_test[] = {3, 4};
  Array second_expected = {second_test, 2};
  status = assert_array(list, second_expected);
  print_result("Should add the element at the end when list is not empty", status, result);
}

void test_add_to_start(Result *result)
{
  printf("\nadd_to_start\n");

  List_ptr list = create_list();
  add_to_start(list, create_int_element(4));
  int firest_test[] = {4};
  Array first_expected = {firest_test, 1};
  Status status = assert_array(list, first_expected);
  print_result("Should add at first when list is empty", status, result);

  add_to_start(list, create_int_element(3));
  int second_test[] = {3, 4};
  Array second_expected = {second_test, 2};
  status = assert_array(list, second_expected);
  print_result("Should add the element at the start when list is not empty", status, result);
}

void test_insert_at(Result *result)
{
  printf("\ninsert_at\n");

  List_ptr list = create_list();
  insert_at(list, create_int_element(4), 0);
  int firest_test[] = {4};
  Array first_expected = {firest_test, 1};
  Status status = assert_array(list, first_expected);
  print_result("Should add at first when list is empty and possition is 0", status, result);

  insert_at(list, create_int_element(3), 1);
  int second_test[] = {4, 3};
  Array second_expected = {second_test, 2};
  status = assert_array(list, second_expected);
  print_result("Should add the element at the end and possition is length of array", status, result);

  insert_at(list, create_int_element(2), 1);
  int third_test[] = {4, 2, 3};
  Array third_expected = {third_test, 2};
  status = assert_array(list, third_expected);
  print_result("Should add the element at the middle when possition is given in middle", status, result);
}
