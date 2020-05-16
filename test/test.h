#ifndef __TEST__H
#define __TEST__H

// ✔ = \u2714  HEAVY CHECK MARK
// ✘ = \u2718  HEAVY BALLOT X

#define RESET "\033[0m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define PASS GREEN "\u2714 " RESET
#define FAIL RED "\u2718 " RESET

typedef struct
{
  int passing;
  int failing;
} Result;

void print_result(char *msg, Status status, Result *result);
void final_result(Result *result);

#endif