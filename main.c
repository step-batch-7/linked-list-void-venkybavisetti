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

int main()
{
  List_ptr list = create_list();

  add_to_list(list, create_int_element(4));
  add_to_start(list, create_int_element(2));
  insert_at(list, create_int_element(3), 1);
  List_ptr reversed_list = reverse(list);
  List_ptr mapped_list = map(list, &square);
  List_ptr filtered_list = filter(list, &is_even);

  printf("list    :");
  display_list(list, &display_integers);
  printf("\nreverse :");
  display_list(reversed_list, &display_integers);
  printf("\nmap     :");
  display_list(mapped_list, &display_integers);
  printf("\nfilter     :");
  display_list(filtered_list, &display_integers);
  printf("\n");

  return 0;
}
