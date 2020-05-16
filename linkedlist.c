#include "linkedlist.h"

List_ptr create_list(void)
{
  List_ptr list = malloc(sizeof(LinkedList));

  list->first = NULL;
  list->last = NULL;
  list->length = 0;

  return list;
}

Node_ptr create_node(Element element)
{
  Node_ptr new_node = malloc(sizeof(Node));

  new_node->element = element;
  new_node->next = NULL;

  return new_node;
}

Status add_to_list(List_ptr list, Element element)
{
  Node_ptr new_node = create_node(element);

  Node_ptr *ptr_to_set = &list->first;
  if (list->first != NULL)
  {
    ptr_to_set = &list->last->next;
  }
  (*ptr_to_set) = new_node;
  list->last = new_node;
  list->length++;
  return Success;
}

Status add_to_start(List_ptr list, Element element)
{
  Node_ptr new_node = create_node(element);
  if (list->first == NULL)
  {
    list->last = new_node;
  }
  new_node->next = list->first;
  list->first = new_node;
  list->length++;
  return Success;
}

Status insert_at(List_ptr list, Element element, int position)
{

  if (position == 0)
    return add_to_start(list, element);

  if (position > list->length || position < 0)
    return Failure;

  if (position == list->length)
    return add_to_list(list, element);

  Node_ptr prev = NULL;
  Node_ptr new_node = create_node(element);

  Node_ptr p_walk = list->first;
  for (int index = 0; index < position; index++)
  {
    prev = p_walk;
    p_walk = p_walk->next;
  }
  new_node->next = p_walk;
  prev->next = new_node;
  list->length++;
  return Success;
}
