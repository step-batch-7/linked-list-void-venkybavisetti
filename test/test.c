#include "../linkedlist.h"
#include "test.h"
#include "test_code.h"

void final_result(Result *result)
{
  printf(GREEN "\n%d passing\n" RESET, result->passing);
  printf(RED "%d failing\n" RESET, result->failing);
}

void print_result(char *msg, Status status, Result *result)
{
  if (status)
  {
    printf(PASS "%s\n", msg);
    result->passing++;
    return;
  }
  printf(FAIL "%s\n", msg);
  result->failing++;
}

int main(void)
{
  Result result = {0, 0};
  test_add_to_list(&result);
  test_add_to_start(&result);
  test_insert_at(&result);
  final_result(&result);
  return 0;
}
