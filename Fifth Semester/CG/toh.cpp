#include <stdio.h>

void TOH(int, char, char, char);
int main() 
{
  int no_of_discs;
  //User input
  scanf("%d", & no_of_discs);
  TOH(no_of_discs, 'X', 'Y', 'Z');
  return 0;
}

// Tower of Hanoi recursive program in C
void TOH(int n, char towerX, char towerY, char towerZ) 
{
  if (n == 1) 
  {
    printf("\n Move the topmost disc from %c to %c", towerX, towerZ);
    return;
  } 
  
  else 
  {
    TOH(n - 1, towerX, towerZ, towerY);
    printf("\n Move the topmost disc from %c to %c", towerX, towerZ);
    TOH(n - 1, towerY, towerX, towerZ);
  }
}


