#include <iostream>
#include <math.h>

using namespace std;

struct point
{
  int x;
  int y;
};

struct line
{
  point start;
  point end;
};

struct circle
{
  point center;
  float radius;
};

typedef line *Pline;

typedef point lineV2[2];

float distance(point *a, point *b)
{
  return sqrtf(powf(a->x - b->x, 2) + powf(a->y - b->y, 2));
}

float distance(line *l)
{
  return distance(&l->start, &l->start);
}

bool interior(circle c, point p)
{
  float d_center = distance(&c.center, &p);
  return d_center <= c.radius;
}

union example
{
  int i;
  char c;
};

int main()
{
  example e1;
  e1.i = 0x2B65;

  cout << e1.i << endl;
  cout << e1.c << endl;

  point pp;
  pp.x = 10.0;
  pp.y = 5.0;

  cout << "(x,y) = (" << pp.x << ", " << pp.y << ") \n";

  Pline l1 = (Pline)malloc(sizeof(line));
  l1->start.x = 12.0;
  l1->start.y = 5.0;
  l1->end.x = 25.0;
  l1->end.y = 3.0;

  cout << "start: (x,y) = (" << l1->start.x << ", " << l1->start.y << ") \n";
  cout << "end: (x,y) = (" << l1->end.x << ", " << l1->end.y << ") \n";

  free(l1);

  lineV2 l2;
  l2[0].x = 16.0;
  l2[0].y = 7.0;
  l2[1].x = 20.0;
  l2[1].y = 1.0;

  cout << "0: (x,y) = (" << l2[0].x << ", " << l2[0].y << ") \n";
  cout << "1: (x,y) = (" << l2[1].x << ", " << l2[1].y << ") \n";

  return 0;
}