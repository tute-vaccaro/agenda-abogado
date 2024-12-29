#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED

//----------------------------------//
//LIBRERIA TOOLS
//----------------------------------//
//1. VALIDAR STRING CHAR
//2. VALIDAR STRING NUM
//3. VALIDAR LENGHT DE UNA PALABRA
//4. VALIDAR LENGHT DE LA CONTRASENIA
//5. VALIDAR CONTRASENIA
//6. VALIDAR DIA FECHA
//7. VALIDAR MES FECHA
//8. VALIDAR HORA
int validarStringNombre(char nombre[]);
int validarStringNum(char nombre[]);
int validarLenght(char prototipo[], int minChar);
int validarLenghtContrasenia(char contrasenia[]);
int validarContrasenia(char contrasenia[], char contrasenia1[]);
int validarDiaFecha(int dia);
int validarMesFecha(int dia);

#endif // TOOLS_H_INCLUDED
