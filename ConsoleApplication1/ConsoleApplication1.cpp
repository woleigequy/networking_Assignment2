#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<iostream>
int main(void)
{
    char ch;
    while (ch != 27)
    {
        printf("HelloWorld\n");
        if (_kbhit())
            ch = _getch();
    }
    printf("End!\n");
    system("pause");
    return 0;
}