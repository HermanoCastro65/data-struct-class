#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

struct full_name
{
  char name[20];
  char last[20];
};

struct node
{
  full_name person;
  node *next;
};

void allocate10(node *root)
{
  for (int i = 1; i <= 10; i++)
  {
    cout << "Initial Root " << i << " = " << root;
    node *new_node = new (node);
    strcpy(new_node->person.name, "Jonh");
    strcpy(new_node->person.last, "Wick");
    new_node->next = root;
    root = new_node;
    cout << " --- Final Root " << i << " = " << root << "\n";
  }
}

void removeAll(node *root)
{
  while (root != NULL)
  {
    node *current = root;
    root = root->next;
    delete (current);
  }
}

int main(int argc, char **argv)
{

  node *root = NULL;
  allocate10(root);
  removeAll(root);

  return 0;
}