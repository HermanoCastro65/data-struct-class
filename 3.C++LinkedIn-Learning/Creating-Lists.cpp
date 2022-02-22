#include <iostream>
#include <list>
using namespace std;

// print the elements of the list
template <typename T>
void printl(list<T> &l)
{
  if (l.empty())
    return;
  for (T &i : l)
    cout << i << " ";
  cout << endl;
}

// print a simple message
void message(const char *s) { cout << s << endl; }
void message(const char *s, const int n) { cout << s << ": " << n << endl; }

int main()
{
  list<int> l1;
  printl(l1);
  message("size", (int)l1.size());
  message("fornt", l1.front());
  message("back", l1.back());

  message("push back 47");
  l1.push_back(47);
  printl(l1);

  // need a iterator to insert and erase
  message("insert");
  list<int>::iterator it1 = l1.begin();
  while ((*++it1 != 5) && (it1 != l1.end()))
    ;
  if (it1 != l1.end())
  {
    message("inser 112 before 5");
    l1.insert(it1, 112);
  }
  printl(l1);

  // find element value 7
  while ((*++it1 != 7) && (it1 != l1.end()))
    ;
  if (it1 != l1.end())
  {
    message("erse 7");
    l1.erase(it1);
  }
  printl(l1);

  // remove element value 8
  l1.remove(8);
  message("remove 8");
  printl(l1);

  return 0;
}