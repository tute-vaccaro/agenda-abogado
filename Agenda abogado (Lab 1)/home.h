#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "usuario.h"

#ifndef HOME_H_INCLUDED
#define HOME_H_INCLUDED

//----------------------------------//
//LIBRERIA HOME
//----------------------------------//
//1. INICIO DE SESION
//2. REGISTRO DE USUARIO
stUsuario iniciarSesion();
void registrarUsuario(int tipo);

#endif // HOME_H_INCLUDED
