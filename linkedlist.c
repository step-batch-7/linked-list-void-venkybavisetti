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

List_ptr reverse(List_ptr list)
{
  List_ptr new_list = create_list();
  if (list == NULL)
  {
    return new_list;
  }
  Node_ptr p_walk = list->first;
  while (p_walk != NULL)
  {
    add_to_start(new_list, p_walk->element);
    p_walk = p_walk->next;
  }
  return new_list;
}

List_ptr map(List_ptr list, Mapper mapper)
{
  List_ptr new_list = create_list();
  Element mapped_value;
  Node_ptr p_walk = list->first;

  while (p_walk != NULL)
  {
    mapped_value = (*mapper)(p_walk->element);
    add_to_list(new_list, mapped_value);
    p_walk = p_walk->next;
  }
  return new_list;
}

List_ptr filter(List_ptr list, Predicate predicate)
{
  List_ptr new_list = create_list();
  Node_ptr p_walk = list->first;
  while (p_walk != NULL)
  {
    if ((*predicate)(p_walk->element))
    {
      add_to_list(new_list, p_walk->element);
    }
    p_walk = p_walk->next;
  }
  return new_list;
}

Element reduce(List_ptr list, Element init, Reducer reducer)
{
  Node_ptr p_walk = list->first;
  while (p_walk != NULL)
  {
    (*reducer)(init, p_walk->element);
    p_walk = p_walk->next;
  }
  return init;
}

void forEach(List_ptr list, ElementProcessor processor)
{
  Node_ptr p_walk = list->first;

  while (p_walk != NULL)
  {
    (*processor)(p_walk->element);
    p_walk = p_walk->next;
  }
}

Element remove_from_start(List_ptr list)
{
  if (list->length == 0)
    return NULL;

  Node_ptr node_to_free = list->first;
  Element element = node_to_free->element;
  list->first = list->first->next;
  list->length--;
  free(node_to_free);
  return element;
}

Element remove_from_end(List_ptr list)
{
  if (list->length == 0)
    return NULL;
  Element element = list->last->element;
  Node_ptr node_to_free = list->last;
  if (list->length == 1)
  {
    node_to_free = list->first;
    list->first = NULL;
    list->last = NULL;
    list->length--;
    free(node_to_free);
    return element;
  }
  Node_ptr p_walk = list->first;
  for (int i = list->length; i > 1; i--)
  {
    if (i == 2)
    {
      p_walk->next = NULL;
      list->last = p_walk;
      list->length--;
      free(node_to_free);
    }
    p_walk = p_walk->next;
  }
  return element;
}

Element remove_at(List_ptr list, int position)
{
  if (position == 0)
    return remove_from_start(list);

  if (position >= list->length || position < 0)
    return NULL;

  if (position == (list->length) - 1)
    return remove_from_end(list);

  Node_ptr prev = NULL;

  Node_ptr p_walk = list->first;
  for (int index = 0; index < position; index++)
  {
    prev = p_walk;
    p_walk = p_walk->next;
  }

  Node_ptr node_to_free = p_walk;
  Element element = node_to_free->element;

  prev->next = p_walk->next;
  list->length--;
  free(p_walk);

  return element;
}
