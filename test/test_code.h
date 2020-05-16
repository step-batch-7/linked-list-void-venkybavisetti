#ifndef __TEST_CODE__H
#define __TEST_CODE__H

typedef struct
{
  int *values;
  int length;

} Array;

typedef Array *Array_ptr;

void test_add_to_list(Result *result);

#endif