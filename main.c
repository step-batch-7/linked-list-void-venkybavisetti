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

void add_one(Element value)
{
  ++*(int *)value;
}

Status isequal_nums(Element element_a, Element element_b)
{
  return *(int *)element_a == *(int *)element_b;
}

int main()
{
  List_ptr list = create_list();
  add_to_list(list, create_int_element(2));
  add_to_list(list, create_int_element(3));
  add_to_list(list, create_int_element(4));
  add_to_list(list, create_int_element(5));
  add_to_list(list, create_int_element(6));
  add_to_list(list, create_int_element(7));

  printf("list             : ");
  display_list(list, &display_integers);

  printf("\nadd_to_list 5    : ");
  add_to_list(list, create_int_element(5));
  display_list(list, &display_integers);

  printf("\nadd_to_start 3   : ");
  add_to_start(list, create_int_element(3));
  display_list(list, &display_integers);

  printf("\ninsert_at 3 at 1 : ");
  insert_at(list, create_int_element(3), 1);
  display_list(list, &display_integers);

  printf("\n\nlist             : ");
  display_list(list, &display_integers);
  List_ptr reversed_list = reverse(list);
  printf("\nreverse          : ");
  display_list(reversed_list, &display_integers);

  printf("\n\nlist             : ");
  display_list(list, &display_integers);
  List_ptr mapped_list = map(list, &square);
  printf("\nmap squares      : ");
  display_list(mapped_list, &display_integers);

  printf("\n\nlist             : ");
  display_list(list, &display_integers);
  List_ptr filtered_list = filter(list, &is_even);
  printf("\nfilter evens     : ");
  display_list(filtered_list, &display_integers);

  printf("\n\nlist             : ");
  display_list(list, &display_integers);
  Element initial_context, sum_of_all_nums;
  int context = 0;
  sum_of_all_nums = reduce(list, &context, &sum);
  printf("\nreduce sum       : ");
  display_integers(sum_of_all_nums);

  printf("\n\nlist             : ");
  display_list(list, &display_integers);
  forEach(list, &add_one);
  printf("\nforeach add 1    : ");
  display_list(list, &display_integers);

  printf("\n\nlist             : ");
  display_list(list, &display_integers);
  Element rm_ele_str = remove_from_start(list);
  printf("\nremove_from_start: ");
  display_integers(rm_ele_str);

  printf("\n\nlist             : ");
  display_list(list, &display_integers);
  Element rm_ele_end = remove_from_end(list);
  printf("\nremove_from_end  : ");
  display_integers(rm_ele_end);

  printf("\n\nlist             : ");
  display_list(list, &display_integers);
  Element rm_ele_at = remove_at(list, 1);
  printf("\nremove_from_at   : ");
  display_integers(rm_ele_at);

  printf("\n\nlist             : ");
  display_list(list, &display_integers);
  Element rm_ele_fir = remove_first_occurrence(list, create_int_element(4), &isequal_nums);
  printf("\nremove_first_occurrence: ");
  display_integers(rm_ele_fir);

  printf("\n");

  return 0;
}
