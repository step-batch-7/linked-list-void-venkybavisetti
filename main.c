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

int main()
{
  List_ptr list = create_list();

  add_to_list(list, create_int_element(3));
  add_to_start(list, create_int_element(2));
  display_list(list, &display_integers);

  return 0;
}
