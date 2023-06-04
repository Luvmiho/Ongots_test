// zaza bolchhshig bolloo hha unti2 hha
//  noice
// haragdjiinoo hha emuugeeree chatlah uu
//  uu za baragshuu ho haha yu hjin ho
//  one piece iin uzeegui baisan angiudaa nuhuj baigaad hamag anhaaral ened tatatagdaad odoo bol ene iig l hiijin
//  Stand-change test
#include <stdio.h>
#include <stdlib.h>
// Board-nii hemjee 10x10
// Massive 0-ees eheldeg ba board-iig 1-ees ehluulhiin tuld SIZE=11
#define SIZE 11
// comment ustgasan haragdjinu gsh
// haragdjiinoo ustagtsan bn.
// Board-iig coordinattai ni hewleh
void printBoard(char plane[SIZE][SIZE])
{
    // Commit test hello
    int i, j;
    printf("\nBoard: \n  ");

    for (i = 1; i <= 10; i++)
    {
        printf(" %d", i);
    }
    printf("\n");
    for (i = 1; i <= 10; i++)
    {
        if (i < 10)
            printf(" ");
        printf("%d ", i);
        for (j = 1; j <= 10; j++)
        {
            printf("%c ", plane[i][j]);
        }
        printf("\n");
    }
}
// Hereglegch ongotsnii tolgoi, biynii code-iig coordinate-iig oruulah
void setPlane(char plane[SIZE][SIZE], int x, int y, int tolgoiX, int tolgoiY)
{
    plane[x][y] = 'B';
    plane[tolgoiX][tolgoiY] = 'T';
}
// Hereglegch x=0, y=0 gj oruulsan tohioldold togloomiig duusgah
void duusgah()
{
    printf("Togloom duuslaa!");
    exit(0);
}
int main()
{
    // Tx - tolgoin x tenhleg
    // Ty - tolgoin y tenhleg
    // Bx - biyiin x tenhleg
    // By - biyiin y tenhleg

    // planeNum - Hereglegchiin uusgeh ongotsnii too

    // i,j - x,y tenhlegiin davtaltiin tooluuruud
    // n,m - buudah x,y tenhleguud

    int Tcounter = 0, Tx, Ty, Bx, By, planeNum, i, j, n, m;
    char plane[SIZE][SIZE];

    // Board-aa uusgeh
    for (i = 1; i <= 10; i++)
    {
        for (j = 1; j <= 10; j++)
        {
            plane[i][j] = '.';
        }
    }
    // Eronhii durem, tanih temdeguud
    printf("\n\n---WELCOME TO PLANE-SHOOTING GAME---\n");
    printf("      ---TOGLOOMIIN DUREM---\n\n");
    printf("1. Ta uuriin ongotsnii coordinate-iig oruulna\n");
    printf("2. Ongotsnii coordinate-iig oruulj buudaj sharhduulna\n");
    printf("3. Herev togloomiig duusgahiig husvel y: 0 x: 0 gj oruulna\n\n");

    printf("T - ongotsnii tolgoi\n");
    printf("B - ongotsnii biy\n");
    printf("X - sonoson\n");
    printf("S - sharh\n\n");

    // Hereglegchees uusgeh ongotsnii shirheg-iig avah
    printf("Ta heden shirheg ongots oruulah ve?\n");

    printf("Ongotsnii too: ");
    scanf("%d", &planeNum);

    // Uusgeh ongotsnii toog 0 gj oruulval program duusna
    if (planeNum == 0)
        duusgah();
    for (int tooluur = 1; tooluur <= planeNum; tooluur++)
    {
        printf("ongots %d: \n", tooluur);
        // Ongotsnii tolgoin coordinate-uudiig avah
        printf("ongotsnii tolgoi hesgiin coordinate\ny:  ");
        scanf("%d", &Tx);
        printf("x:  ");
        scanf("%d", &Ty);
        // Ongotsnii biyiin coordinate-uudiig avah
        if (Tx == 0 && Ty == 0)
            duusgah();
        printf("ongotsnii biynii hesgiin coordinate-uud: \n");
        for (int tooluurB = 1; tooluurB <= 7; tooluurB++)
        {
            printf("y: ");
            scanf("%d", &Bx);
            printf("x: ");
            scanf("%d", &By);
            // Board-naas tom coordinate-iin tseg oruulsan tohioldold aldaa zaah nohtsol
            while (Bx > SIZE || By > SIZE || Tx > SIZE || Ty > SIZE)
            {
                printf("\nTa coordinate-iig zov oruulna uu!\n");

                printf("ongotsnii tolgoi hesgiin coordinate-iig oruulna uu\ny:  ");
                scanf("%d", &Tx);
                printf("x:  ");
                scanf("%d", &Ty);

                printf("ongotsnii biynii hesgiin coordinate-uudiig oruulna uu\n");
                printf("y: ");
                scanf("%d", &Bx);
                printf("x: ");
                scanf("%d", &By);
            }
            setPlane(plane, Bx, By, Tx, Ty);
        }
        printBoard(plane);
    }
    while (100 > 0)
    {
        // Hereglegch ongots buudah
        printf("buudah tseguud: \n");
        printf("y:");
        scanf("%d", &n);
        printf("x:");
        scanf("%d", &m);
        // x=0, y=0 gj oruulsan nohtsold program duusgah nohtsol
        if (n != 0 && m != 0)
        {
            if (n < 11 & m < 11)
            {
                // Ongots sonooson tohioldold sonoson ongotsiig tooloh, T useg tavih
                if (plane[n][m] == 'T')
                {
                    Tcounter += 1;
                    plane[n][m] = 'X';
                    if (Tcounter == planeNum)
                    {
                        printBoard(plane);
                        printf("\nTa hojloo!\nTogloom duuslaa!\n");
                        break;
                    }
                    printBoard(plane);
                }
                // Ongotsnii biyiig onoson tohioldold S useg tavih
                else if (plane[n][m] == 'B')
                {
                    plane[n][m] = 'S';

                    printBoard(plane);
                }
                else
                {
                    printBoard(plane);
                }
            }
            else
            {
                printf("Coordinate-iig zov oruulna uu");
            }
        }
        else
        {
            duusgah();
        }
    }
}
