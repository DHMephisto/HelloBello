//game 2048 by ZQY
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>

int a[4][4] = {0};
int empty;


void init();
void draw();
void draw_digit(int y, int x);
void play();
void newone();
void judge();
int gameover();


int main()
{
    init();
    play();
    endwin();

    return 0;
}



void init()
{
    int x,y;

    initscr();
    cbreak();
    noecho();
    curs_set(0);

    empty = 15;
    srand(time(0));
    x = rand() % 4;
    y = rand() % 4;
    a[x][y] = 2;
    draw(); 
}



void draw()
{
    int i,j,x,y;
    char str[] = "* Press 'w' 's' 'a' 'd' or UP DOWN LEFT RIGHT to control, 'q' or 'Q' to quit.********************";

//mention: if u don't clear , how can it draw a new one correct.
    clear();

    for(i=1; i<9; i+=2)
        for(j=0; j<25; j+=6)
        {
            move(i,j);
            addch('|');
            refresh();
        }

    for(i=0; i<9; i+=2)
        for(j=0; j<24; j++)
        {
             move(i,j);
             addch('-');
             refresh();
        }

    for(j=0; j<24; j++)
        {
             move(9,j);
             addch('*');

             move(14,j);
             addch('*');

             move(10,j);
             addch(str[j]);
             move(11,j);
             addch(str[j+24]);
             move(12,j);
             addch(str[j+48]);
             move(13,j);
             addch(str[j+72]);

             refresh();
        }


    for(x=0; x<4; x++)
        for(y=0; y<4; y++)
        {
            draw_digit(x, y);
        }
}



void draw_digit(int x, int y)
{
    int i,j,m,k;
    char c[5] = {0x00};
    i = a[x][y];
    m = 0;

    while(i != 0)
    {
         j = i % 10;
         c[m++] = j + '0';
         i = i / 10;
    }
    m = 0;
    k = 6*y+5;
    while(c[m] != 0x00)
    {
        move(2*x+1,k);
        addch(c[m++]);
        k--;
    }
     
}
/*void draw()
{
    int n,m,x,y;
    clear();
    for(n=0; n < 9; n +=2)
        for(m=0; m<21; m++)
        {
            move(n,m);
            addch('-');
            refresh();
        }

    for(m=0; m<22; m+=5)
        for(n=1; n<8; n++)
        {
            move(n,m);
            addch('|');
            refresh();
        }

    for(x=0; x<4; x++)
        for(y=0; y<4; y++)
        {
            draw_digit(x,y);
        }
}

void draw_digit(int x, int y)
{
    int i,m,k,j;
    char c[5] = {0x00};
    i = a[x][y];
    m = 0;
    while(i > 0)
    {
        j = i % 10;
        c[m++] = j + '0';
        i = i/10;
    }
    m = 0;
    k = (y+1)*5-1;
    while(c[m] != 0x00)
    {
        move(2*x+1,k);
        addch(c[m++]);
        k--;
    }
}*/


void play()
{
    int x,y,i,j;
    int old_empty;
    int move;
    char ch;
    
    while(1)
    {
        old_empty = empty;
        move = 0;
        ch = getch();
        switch(ch){
                    case 97: //key 'a'
                    case 68: //key left
                       for(x=0; x<4; x++)
                            for(y=0; y<4; y++)
                            {
                                if(a[x][y] == 0)
                                    {
                                        continue;
                                    }
                                else{
                                        for(i=y+1;i<4;i++)
                                            {
                                                if(a[x][i] == a[x][y])
                                                    {
                                                        a[x][y] += a[x][i];
                                                        a[x][i] = 0;
                                                        empty++;
                                                        break;
                                                    }
                                                if(a[x][i] == 0)
                                                    {
                                                        continue;
                                                    }
                                                else{
                                                        break;
                                                    }
                                            }
                                    }
                            }

                        for(x=0; x<4; x++)
                            for(y=1; y<4;y++)
                                {
                                    if(a[x][y] == 0)
                                       {
                                           continue;
                                       }
                                    else{
                                           for(j=0; j<y; j++)
                                              {
                                                  if(a[x][j] == 0)
                                                     {
                                                         a[x][j] = a[x][y];
                                                         a[x][y] = 0;
                                                         move = 1;
                                                         break;
                                                     }
                                              }
                                        } 
                                }
                        /*for(x = 0; x < 4; x++)
                            for(y=0;y<4;y++)
                                {
                                    if(a[x][y] == 0)
                                        {
                                            continue;
                                        }
                                    else{
                                            for(i = y; (i>0) && (a[x][i-1] ==0);i--)
                                                {
                                                    a[x][i-1] = a[x][i];
                                                    a[x][i] = 0;
                                                }
                                        }
                                }*/
                         
                        break;

                    case 100: //key 'd'
                    case 67:  //key right
                        for(x=0;x<4;x++)
                            for(y=3;y>=0;y--)
                                {
                                    if(a[x][y] == 0)
                                    {
                                        continue;
                                    }
                                    else{
                                        for(i=y-1; i>=0; i--)
                                        {
                                            if(a[x][i] == 0)
                                            {
                                                continue;
                                            }
                                            else if(a[x][i] == a[x][y])
                                            {
                                                    a[x][y] += a[x][i];
                                                    a[x][i] = 0;
                                                    empty++;
                                                    break;
                                            }
                                            else{
                                                break;
                                            }
                                        }
                                    }
                                }
                                
                                for(x=0; x<4; x++)
                                    for(y=2; y>=0; y--)
                                    {
                                        if(a[x][y] == 0)
                                        {
                                            continue;
                                        }
                                        else{
                                            for(j=3; j>y; j--)
                                            {
                                                if(a[x][j] == 0)
                                                {
                                                    a[x][j] = a[x][y];
                                                    a[x][y] = 0;
                                                    move = 1;
                                                    break;
                                                }
                                            }
                                        }
                                    }
                        break;

                    case 119: //w
                    case 65:  //up
                        for(y=0;y<4;y++)
                           for(x=0; x<4; x++)
                            {
                                if(a[x][y] == 0)
                                    {
                                        continue;
                                    }
                                else{
                                        for(i=x+1;i<4;i++)
                                            {
                                                if(a[i][y] == a[x][y])
                                                    {
                                                        a[x][y] += a[i][y];
                                                        a[i][y] = 0;
                                                        empty++;
                                                        break;
                                                    }
                                                if(a[i][y] == 0)
                                                    {
                                                        continue;
                                                    }
                                                else{
                                                        break;
                                                    }
                                            }
                                    }
                            }

                        for(y=0; y<4; y++)
                            for(x=1; x<4;x++)
                                {
                                    if(a[x][y] == 0)
                                       {
                                           continue;
                                       }
                                    else{
                                           for(j=0; j<x; j++)
                                              {
                                                  if(a[j][y] == 0)
                                                     {
                                                         a[j][y] = a[x][y];
                                                         a[x][y] = 0;
                                                         move = 1;
                                                         break;
                                                     }
                                              }
                                        } 
                                }
                        break;

                    case 115: //s
                    case 66: //down
                        for(y=0;y<4;y++)
                            for(x=3;x>=0;x--)
                                {
                                    if(a[x][y] == 0)
                                    {
                                        continue;
                                    }
                                    else{
                                        for(i=x-1; i>=0; i--)
                                        {
                                            if(a[i][y] == 0)
                                            {
                                                continue;
                                            }
                                            else if(a[i][y] == a[x][y])
                                            {
                                                a[x][y] += a[i][y];
                                                a[i][y] = 0;
                                                empty++;
                                                break;
                                            }
                                            else{
                                                break;
                                            }
                                        }
                                    }
                                }
                                
                                for(y=0; y<4; y++)
                                    for(x=2; x>=0; x--)
                                    {
                                        if(a[x][y] == 0)
                                        {
                                            continue;
                                        }
                                        else{
                                            for(j=3; j>x; j--)
                                            {
                                                if(a[j][y] == 0)
                                                {
                                                    a[j][y] = a[x][y];
                                                    a[x][y] = 0;
                                                    move = 1;
                                                    break;
                                                }
                                            }
                                        }
                                    }
                        break;

                    case 'Q':
                    case 'q':
                        game_over();
                        break;  
                    default:
                           continue;
                           break;
                  }
                  
                  judge();
                  if(empty != old_empty || move != 0)
                  {
                      newone();
                  }
                  draw();
                  
    }
}

void newone()
{
    int x,y;
    do
    {
        x = rand() % 4;
        y = rand() % 4;
    }while(a[x][y] != 0);

    a[x][y] = 2*(rand()%2)+2;
    empty--;
}


void judge()
{
    /*int x,y;
    for(x=0;x<4;x++)
       for(y=0;y<4;y++)
          {
              if(a[x][y] == 2048)
              {
                   break;
                 //To be continue.
              }
          }*/
    if(empty <= 0)
    {
        game_over();
    }
}

int game_over()
{
    sleep(1);
    endwin();
    exit(0);
}
