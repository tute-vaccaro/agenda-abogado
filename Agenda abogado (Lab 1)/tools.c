#include "tools.h"

//----------------------------------//
//LIBRERIA TOOLS
//----------------------------------//
//1. VALIDAR STRING CHAR
int validarStringNombre(char nombre[])
{
    for(int i=0; i<strlen(nombre); i++)
    {
        if(!isalpha(nombre[i]) && !isspace(nombre[i]))
        {
            return 0;
        }
    }
    return 1;
}
//2. VALIDAR STRING NUM
int validarStringNum(char nombre[])
{
    for(int i=0; i<strlen(nombre); i++)
    {
        if(!isdigit(nombre[i]))
        {
            return 0;
        }
    }
    return 1;
}
//3. VALIDAR LENGHT DE UNA PALABRA
int validarLenght(char prototipo[], int minChar)
{
    if(strlen(prototipo)<minChar)
    {
        return 0;
    }
    return 1;
}
//4. VALIDAR LENGHT DE LA CONTRASENIA
int validarLenghtContrasenia(char contrasenia[])
{
    if(strlen(contrasenia)<5)
    {
        return 0;
    }
    return 1;
}
//5. VALIDAR CONTRASENIA
int validarContrasenia(char contrasenia[], char contrasenia1[])
{
    if(strcmp(contrasenia, contrasenia1)==0)
    {
        return 1;
    }
    return 0;
}
//6. VALIDAR DIA FECHA
int validarDiaFecha(int dia)
{
    if(dia<1 || dia>31)
    {
        return 0;
    }
    return 1;
}
//7. VALIDAR MES FECHA
int validarMesFecha(int mes)
{
    if(mes<1 || mes>12)
    {
        return 0;
    }
    return 1;
}
