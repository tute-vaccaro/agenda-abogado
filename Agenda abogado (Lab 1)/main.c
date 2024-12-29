#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "usuario.h"
#include "menu.h"
#include "home.h"
#include "causas.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "usuario.h"
#include "menu.h"
#include "home.h"
#include "causas.h"

int main()
{
    stUsuario A[50];
    int validos=0;

    printf("\n");
    printf("\n");

    printf("-----  -----  -----  -   -  ----    -  -----          -  -   -  -----   -  ----    -  -----  ----- \n");
    printf("-      -        -    -   -  -    -  -  -   -          -  -   -  -    -  -  -    -  -  -      -   -\n");
    printf("---    -----    -    -   -  -    -  -  -   -          -  -   -  -   -   -  -    -  -  -      -   -\n");
    printf("-          -    -    -   -  -    -  -  -   -     -    -  -   -  -  -    -  -    -  -  -      -   -\n");
    printf("-----  -----    -    -----  ----    -  -----     -----   -----  -    -  -  ----    -  -----  -----\n");

    printf("\n");
    printf("\n");

    printf("--------------------------------------------------------------------------------------------------\n");
    validos=pasarArchivoAArregloUsuario(A,50, 2);
    printf("Dr. Abogados: \n");
    mostrarListadoNombreCompletoUsuario(A, validos);
    printf("--------------------------------------------------------------------------------------------------\n");

    home();
    return 0;
}
