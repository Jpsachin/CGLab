#include<stdio.h>
#include<graphics.h>

int abs (int n)
{
    return ( (n>0) ? n : ( n * (-1)));
}

void DDA(int X1, int Y1, int X2, int Y2)
{
    int dx = X2 - X1;
    int dy = Y2 - Y1;
 
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
 
    float Xinc = dx / (float) steps;
    float Yinc = dy / (float) steps;

    float X = X1;
    float Y = Y1;
    for (int i = 0; i <= steps; i++)
    {
        putpixel (X,Y,RED);  
        X += Xinc;          
        Y += Yinc;         
        delay(100);                           
    }
    getch();
}

int main()
{
    int gd = DETECT, gm;

    initgraph (&gd, &gm, NULL);   
 
    DDA(2, 2, 100, 100);
    return 0;
} 
