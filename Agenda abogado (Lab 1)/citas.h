#ifndef CITAS_H_INCLUDED
#define CITAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "tools.h"
#include <time.h>
#include "tools.h"

#define ARCHIVOCITA "archivoCita.dat"
#define MAXC 30

//------------------------------------//
//ESTRUCTURAS DE CITA
//------------------------------------//
//1. ESTRUCTURA FECHA
//2. ESTRUCTURA PRINCIPAL CITA
typedef struct
{
    int dia;
    char hora[MAXC];
    int mes;
} stFecha;

typedef struct
{
    char dniAbogado[MAXC];
    char dniCliente[MAXC];
    char lugar[MAXC];
    int estado;
    stFecha fecha;
} stCita;

//------------------------------------//
//FUNCIONES BASICAS DE CITA
//------------------------------------//
//1. CARGAR CITA
//2. MOSTRAR CITA
//3. INSERTAR CITA SEGUN FECHA
//4. ORDENAMIENTO CITA SEGUN FECHA
//4. ORDENAMIENTO CITA SEGUN FECHA
//5. ENCONTRAR MENOR LUGAR
//7. ORDENAMIENTO POR SELECCION POR LUGAR
//8. MOSTRAR CITAS SEGUN LUGAR
stCita cargarCita(char dniAbogado[], char dniCliente[]);
void verCita(stCita cita);
void insertarCitaSegunFecha(stCita A[], int i, stCita B);
void ordenamientoPorInsercionDelArregloPorFecha(stCita A[], int validos);
int encontrarMenorLugar(stCita citas[], int pos, int validos);
void ordenarPorSeleccionCita(stCita citas[], int validos);
void mostrarCitaSegunLugar(stCita citas[], int validos, char lugar[MAXC]);

//------------------------------------//
//FUNCIONES DE ARCHIVO DE CITA
//------------------------------------//
//1. CARGAR ARCHIVO CON CITA
//2. MOSTRAR ARCHIVO DE CITAS SEGUN ALTA O BAJA
//3. DAR DE ALTA O BAJA UNA CITA
//4. MODIFICAR CITA EXISTENTE
//5. PASAR ARCHIVO A ARREGLO
//6. VER CITAS DE UN USUARIO
//7. BUSCAR CITA POR DNI
void cargarCitaArchivo(char dniAbogado[], char dniCliente[]);
void arVerCitas();
stCita arBajaLogicaCita(char dniCliente[]);
void arModificarCita (char DNIBuscado[]);
int pasarArchivoAArregloCita(stCita A[], int dimension);
void verCitasUsuario(char dniUsuario[], stCita citas[], int validos);
stCita buscarCitaPorDni(char dniUsuario[]);
#endif // CITAS_H_INCLUDED
