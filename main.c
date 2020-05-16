#include "linkedlist.h"

void display_integers(Element value)
{
  printf("%d ", *(int *)value);
}

void display_list(List_ptr list, DisplayData displayer)
{
  Node_ptr p_walk = list->first;
  while (p_walk != NULL)
  {
    (*displayer)(p_walk->element);
    p_walk = p_walk->next;
  }
}

Element create_int_element(int value)
{
  Element element = malloc(sizeof(int));
  *(int *)element = value;
  return element;
}

Element square(Element value)
{
  Element integer = malloc(sizeof(Element));
  *(int *)integer = (*(int *)value) * (*(int *)value);
  return integer;
}

Status is_even(Element value)
{
  return *(int *)value % 2 == 0;
}

Element sum(Element total, Element value)
{
  *(int *)total = (*(int *)total) + (*(int *)value);
  return total;
}

int main()
{
  List_ptr list = create_list();
  add_to_list(list, create_int_element(4));

  printf("list            : ");
  display_list(list, &display_integers);

  printf("\nadd_to_list 5   : ");
  add_to_list(list, create_int_element(5));
  display_list(list, &display_integers);

  printf("\nadd_to_start 3  : ");
  add_to_start(list, create_int_element(3));
  display_list(list, &display_integers);

  printf("\ninsert_at 3 at 1: ");
  insert_at(list, create_int_element(3), 1);
  display_list(list, &display_integers);

  printf("\n\nlist            : ");
  display_list(list, &display_integers);
  List_ptr reversed_list = reverse(list);
  printf("\nreverse         : ");
  display_list(reversed_list, &display_integers);

  printf("\n\nlist            : ");
  display_list(list, &display_integers);
  List_ptr mapped_list = map(list, &square);
  printf("\nmap squares     : ");
  display_list(mapped_list, &display_integers);

  printf("\n\nlist            : ");
  display_list(list, &display_integers);
  List_ptr filtered_list = filter(list, &is_even);
  printf("\nfilter evens    : ");
  display_list(filtered_list, &display_integers);

  printf("\n\nlist            : ");
  display_list(list, &display_integers);
  Element initial_context, sum_of_all_nums;
  int context = 0;
  sum_of_all_nums = reduce(list, &context, &sum);
  printf("\nreduce sum      : ");
  display_integers(sum_of_all_nums);

  printf("\n");

  return 0;
}
