#ifndef __TEST_CODE__H
#define __TEST_CODE__H

typedef struct
{
  int *values;
  int length;

} Array;

typedef Array *Array_ptr;

void test_add_to_list(Result *result);
void test_add_to_start(Result *);
void test_insert_at(Result *);
void test_reverse(Result *result);
void test_map(Result *result);

#endif