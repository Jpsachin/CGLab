#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

void bresenham(int x1, int y1, int x2, int y2)
{
   int m_new = 2 * (y2 - y1);
   int slope_error_new = m_new - (x2 - x1);
   for (int x = x1, y = y1; x <= x2; x++)
   {
      putpixel (x,y,RED);
      delay(100);
      
      slope_error_new += m_new;

      if (slope_error_new >= 0)
      {
         y++;
         slope_error_new  -= 2 * (x2 - x1);
      }
   }
   getch();
}

int main()
{
  int gd = DETECT, gm;
  initgraph (&gd, &gm, NULL); 
  bresenham (2, 2, 150, 150);
  return 0;
}

