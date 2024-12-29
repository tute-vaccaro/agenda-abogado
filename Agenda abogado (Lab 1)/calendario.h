#ifndef CALENDARIO_H_INCLUDED
#define CALENDARIO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "gotoxy.h"
#include <string.h>
#include "usuario.h"

void menuCalendario(stUsuario A);
void mostrarCalendario(int M[][7], char Dias[1][7]);

#endif // CALENDARIO_H_INCLUDED
