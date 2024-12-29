#include "calendario.h"

void menuCalendario(stUsuario A)
{
    int M[6][7];
    char Dias[1][7];

    if (A.persona.genero=='m')
    {
        printf("--------------------------------------------------------------------------------------------------\n");
        printf("Calendario del DR. %s %s \n", A.persona.name.nombre, A.persona.name.apellido);
        printf("--------------------------------------------------------------------------------------------------\n");

    }
    else
    {
        printf("--------------------------------------------------------------------------------------------------\n");
        printf("Calendario de la DRA. %s %s \n", A.persona.name.nombre, A.persona.name.apellido);
        printf("--------------------------------------------------------------------------------------------------\n");

    }

    mostrarCalendario(M, Dias);
}

void mostrarCalendario(int M[][7], char Dias[1][7])
{
    int iDia=1;
    int c=0;
    Dias[0][0]= 'D';
    Dias[0][1]= 'L';
    Dias[0][2]= 'M';
    Dias[0][3]= 'M';
    Dias[0][4]= 'J';
    Dias[0][5]= 'V';
    Dias[0][6]= 'S';

    color(9);
    printf("----------------------------------------------------\n");
    printf("ENERO 2023 \n");
    color(15);

    for(int c=0; c<7; c++)
    {
        printf("%c \t", Dias[0][c]);
    }
    printf("\n");

    for(int f=0; f<5; f++)
    {
        c=0;
        while (c<7 && iDia<=31)
        {

            printf("%d \t", iDia);
            iDia++;
            c++;
        }
        printf("\n");
    }

    iDia =1;

    color(9);
    printf("----------------------------------------------------\n");
    printf("FEBRERO 2023 \n");
    color(15);

    for(int c=0; c<7; c++)
    {
        printf("%c \t", Dias[0][c]);
    }
    printf("\n");
    printf("\t\t\t");

    for(int f=0; f<5; f++)
    {
        while (c<7 && iDia<=28)
        {
            printf("%d \t", iDia);
            iDia++;
            c++;
        }

        if (f != 4)
        {
            c=0;
        }
        printf("\n");
    }

    color(9);
    printf("----------------------------------------------------\n");
    printf("MARZO 2023 \n");
    color(15);

    for(int c=0; c<7; c++)
    {
        printf("%c \t", Dias[0][c]);
    }
    printf("\n");
    printf("\t\t\t");
    iDia = 1;

    for(int f=0; f<5; f++)
    {
        while (c<7 && iDia<=31)
        {
            printf("%d \t", iDia);
            iDia++;
            c++;
        }
        c=0;
        printf("\n");
    }

    color(9);
    printf("----------------------------------------------------\n");
    printf("ABRIL 2023 \n");
    color(15);

    for(int c=0; c<7; c++)
    {
        printf("%c \t", Dias[0][c]);
    }
    printf("\n");
    printf("\t\t\t\t\t\t");
    iDia = 1;

    c=6;
    for(int f=0; f<6; f++)
    {
        while (c<7 && iDia<=30)
        {
            printf("%d \t", iDia);
            iDia++;
            c++;
        }
        c=0;

        printf("\n");
    }

    color(9);
    printf("----------------------------------------------------\n");
    printf("MAYO 2023 \n");
    color(15);

    for(int c=0; c<7; c++)
    {
        printf("%c \t", Dias[0][c]);
    }
    printf("\n");
    printf("\t");
    iDia = 1;

    c=1;
    for(int f=0; f<6; f++)
    {
        while (c<7 && iDia<=31)
        {
            printf("%d \t", iDia);
            iDia++;
            c++;
        }
        c=0;

        printf("\n");
    }

    color(9);
    printf("----------------------------------------------------\n");
    printf("JUNIO 2023 \n");
    color(15);

    for(int c=0; c<7; c++)
    {
        printf("%c \t", Dias[0][c]);
    }
    printf("\n");
    printf("\t\t\t\t");
    iDia = 1;

    c=4;
    for(int f=0; f<6; f++)
    {
        while (c<7 && iDia<=30)
        {
            printf("%d \t", iDia);
            iDia++;
            c++;
        }
        c=0;

        printf("\n");
    }

    color(9);
    printf("----------------------------------------------------\n");
    printf("JULIO 2023 \n");
    color(15);

    for(int c=0; c<7; c++)
    {
        printf("%c \t", Dias[0][c]);
    }
    printf("\n");
    printf("\t\t\t\t\t\t");
    iDia = 1;

    c=6;
    for(int f=0; f<6; f++)
    {
        while (c<7 && iDia<=31)
        {
            printf("%d \t", iDia);
            iDia++;
            c++;
        }
        c=0;

        printf("\n");
    }

    color(9);
    printf("----------------------------------------------------\n");
    printf("AGOSTO 2023 \n");
    color(15);

    for(int c=0; c<7; c++)
    {
        printf("%c \t", Dias[0][c]);
    }
    printf("\n");
    printf("\t\t");
    iDia = 1;

    c=2;
    for(int f=0; f<6; f++)
    {
        while (c<7 && iDia<=31)
        {
            printf("%d \t", iDia);
            iDia++;
            c++;
        }
        c=0;

        printf("\n");
    }

    color(9);
    printf("----------------------------------------------------\n");
    printf("SEPTIEMBRE 2023 \n");
    color(15);

    for(int c=0; c<7; c++)
    {
        printf("%c \t", Dias[0][c]);
    }
    printf("\n");
    printf("\t\t\t\t\t");
    iDia = 1;

    c=5;
    for(int f=0; f<6; f++)
    {
        while (c<7 && iDia<=30)
        {
            printf("%d \t", iDia);
            iDia++;
            c++;
        }
        c=0;

        printf("\n");
    }

    color(9);
    printf("----------------------------------------------------\n");
    printf("OCTUBRE 2023 \n");
    color(15);

    for(int c=0; c<7; c++)
    {
        printf("%c \t", Dias[0][c]);
    }
    printf("\n");
    iDia = 1;

    c=0;
    for(int f=0; f<6; f++)
    {
        while (c<7 && iDia<=31)
        {
            printf("%d \t", iDia);
            iDia++;
            c++;
        }
        c=0;

        printf("\n");
    }

    color(9);
    printf("----------------------------------------------------\n");
    printf("NOVIEMBRE 2023 \n");
    color(15);

    for(int c=0; c<7; c++)
    {
        printf("%c \t", Dias[0][c]);
    }
    printf("\n");
    printf("\t\t\t");
    iDia = 1;

    c=3;
    for(int f=0; f<6; f++)
    {
        while (c<7 && iDia<=30)
        {
            printf("%d \t", iDia);
            iDia++;
            c++;
        }
        c=0;

        printf("\n");
    }

    color(9);
    printf("----------------------------------------------------\n");
    printf("DICIEMBRE 2023 \n");
    color(15);

    for(int c=0; c<7; c++)
    {
        printf("%c \t", Dias[0][c]);
    }
    printf("\n");
    printf("\t\t\t\t\t");
    iDia = 1;

    c=5;
    for(int f=0; f<6; f++)
    {
        while (c<7 && iDia<=31)
        {
            printf("%d \t", iDia);
            iDia++;
            c++;
        }
        c=0;

        printf("\n");
    }
    color(9);
    printf("----------------------------------------------------\n");
    color(15);
}
