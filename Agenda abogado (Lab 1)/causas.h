#ifndef CAUSAS_H_INCLUDED
#define CAUSAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gotoxy.h"
#include "tools.h"
#include "pila.h"

#define ARCHIVOCAUSAS "archivoCausas.dat"
#define ARCHIVOCAUSAXCLIENTEYABOGADO "archivoCausasAbyCl.dat"
#define MAXC 30

//----------------------------------//
//ESTRUCTURAS
//----------------------------------//
//1. FECHA (DIA, MES Y ANIO)
//2. ESTRUCTURA PRINCIPAL DE CAUSA
//3. ESTRUCTURA CAUSA X CLIENTE Y ABOGADO (RELACIONA UNA CAUSA CON UN CLIENTE Y UN ABOGADO PARTICULAR)
typedef struct
{
    int dia;
    int mes;
    int anio;
}stFechaCausa;

typedef struct
{
    char dni[MAXC];
    int numDeCausa;
    char juez[MAXC];
    char tribunal[MAXC];
    char caso[MAXC];
    stFechaCausa fecha;
    int estado;
} stCausa;

typedef struct
{
    int numCausa;
    int idCliente;
    int idAbogado;
} stCausaXClienteYAbogado;

//----------------------------------//
//1. FUNCIONES BASICAS CAUSA:
//----------------------------------//
//1. CARGAR CAUSA
//2. MOSTRAR CAUSA
//3. MOSTRAR ARREGLO DE CAUSAS ACTIVAS
//4. ENCONTRAR MENOR NUMERO DE CAUSA
//5. ORDENAMIENTO POR SELECCION POR NUMERO DE CAUSA
//6. INSERTAR
//7. ORDENAMIENTO POR INSERCION - ALFABETICAMENTE
//8. CARGAR PILA CON NUMERO DE CAUSAS
//9. HISTORIAL NUMEROS DE CAUSAS CARGADAS
stCausa cargarCausa(char dni []);
void mostrarCausa(stCausa causa);
void mostrarArregloCausasActivas(stCausa A[], int validos);
int encontrarMenorNumeroDeCausa(stCausa causas[], int pos, int validos);
void ordenarPorSeleccionCausa(stCausa causas[], int validos);
void insertarDatoJuez(stCausa A[], int i, stCausa B);
void ordenamientoPorInsercionDelArregloPorJuez(stCausa A[], int validos);
void cargarNumDeCausaEnPila(Pila * A, stCausa B);
void historialNumDeCausas(Pila * A);
//----------------------------------//
//2. FUNCIONES DE ARCHIVOS DE CAUSA
//----------------------------------//
//1. CARGAR CAUSA
//2. MOSTRAR ARCHIVO DE CAUSAS
//3. BUSCAR CAUSA POR DNI
//4. BUSCAR CAUSA POR NUMERO DE CAUSA
//5. BUSCAR CAUSA POR JUEZ
//6. MODIFICAR UN DATO DE LA CAUSA EN EL ARCHIVO
//7. DAR DE BAJA /  DAR DE ALTA UNA CAUSA
//8. PASAR EL ARCHIVO A UN ARRAY
void arCargarCausa(char dni[], Pila *A);
void arMostrarArchivoCausas(int estado);
stCausa arBuscarCausaSegunDni(char dniBuscado[]);
stCausa arBuscarCausaSegunNumDeCausa (int causaBuscada);
stCausa arBuscarCausaSegunJuez (char juezBuscado[]);
void arModficarDatoCausa(int causaBuscada);
void arBajaAltaLogicaCausa(int causaBuscada, int opcion);
int pasarArchivoAArregloCausas(stCausa A[], int dimension);
//----------------------------------//
//3. FUNCIONES CAUSAXCLIENTEYABOGADO
//----------------------------------//
//1. CARGAR ESTRUCTURA CAUSA
//2. CARGAR ARCHIVO ESTRUCTURA
//3. MOSTRAR CAUSAS DE CLIENTE
//4. SABER SI UNA CAUSA PERTENECE A UN USUARIO
stCausaXClienteYAbogado cargarCausaXClyAb(int numCausa, int idCliente, int idAbogado);
void arCargarCausaXClyAb(int numCausa, int idCliente, int idAbogado);
void mostrarCausasDeUsuario(int idUsuario);
stCausa esCausaDeUsuario(int numCausa, int idUsuario);

#endif // CAUSAS_H_INCLUDED
