#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "tools.h"

#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

#define MAXC 30
#define ARCHIVOUSUARIO "archivoUsuario.dat"
#define ARCHIVOCLIENTEXABOGADO "clienteXAbogado.dat"
//----------------------------------//
//ESTRUCTURAS DE USUARIO
//----------------------------------//
//1. ESTRUCTURA NOMBRE
//2. ESTRUCTURA PERSONA
//3. ESTRUCTURA DIRECCION
//4. ESTRUCTURA PRINCIPAL DE USUARIO
//5. ESTRUCTURA ABOGADOXCLIENTE
typedef struct
{
    char nombre[MAXC];
    char apellido[MAXC];
}stName;

typedef struct
{
    stName name;
    char dni[MAXC];
    char telefono[MAXC];
    char genero;
    int edad;
} stPersona;

typedef struct
{
    char calle[MAXC];
    char numero[MAXC];
    char piso[MAXC];
    char departamento[MAXC];
    char ciudad[MAXC];
} stDireccion;

typedef struct
{
    int id;
    int tipo;
    int baja;
    char contrasenia[MAXC];
    stDireccion direccion;
    stPersona persona;
    int idUsuarios[100];// 2-9-8-6
} stUsuario;

typedef struct
{
    int idAbogado;
    int idCliente;
} stClienteXAbogado;
//----------------------------------//
//FUNCIONES DE USUARIO
//----------------------------------//
//FUNCIONES EXTRA:
//1. GENERAR ID
//2. CONTAR CANTIDAD DE REGISTROS
int generarId();
int contarRegistrosEnArchivo();
//----------------------------------//
//1. FUNCIONES BASICAS DE USUARIO:
//-----------------------------------//
//1. CARGAR CONTRASENIA
//2. CARGAR USUARIO PARA REGISTRO
//3. MOSTRAR USUARIO
//4. PASAR ARCHIVOS A ARREGLO DE STRUCT
//5. MOSTRAR ARREGLO DE STRUCT
//6. INSERTAR DATO ORDENADAMENTE(STRING)
//7. ORDENAMIENTO POR INSERCION ALFABETICO CON ARREGLO DE PALABRAS
//8. ORDENAMIENTO POR INSERCION ALFABETICO CON ARREGLO DE PALABRAS
stUsuario cargarContraseniaRegistro(stUsuario usuario);
stUsuario cargarUsuarioRegistro(int tipoUsuario, char dni[]);
void mostrarUsuario(stUsuario usuario);
int pasarArchivoAArregloUsuario(stUsuario A[], int dimension, int tipo);
void mostrarArregloUsuario(stUsuario aOrdenado[], int validos);
void insertarUsuarioParaOrdenamiento(stUsuario a[], int  i, stUsuario A);
void ordenarPorInsercionSegunApellidoUsuario(stUsuario a[], int validos);
void mostrarListadoNombreCompletoUsuario(stUsuario aOrdenado[], int validos);

//----------------------------------//
//2. FUNCIONES DE ARCHIVOS DE USUARIO:
//----------------------------------//
//1. CARGAR ARCHIVO DE USUARIOS
//2. MOSTRAR USUARIOS CARGADOS EN ARCHIVOS
//3. MOSTRAR USUARIOS CARGADOS SEGUN TIPO DE USUARIO
//4. MOSTRAR BAJAS SEGUN TIPO DE USUARIO
//5. DAR DE ALTA / DAR DE BAJA A UN USUARIO
//6. BUSCAR USUARIO LOGIN (DNI Y CONTRASENIA)
//7. BUSCAR USUARIO POR APELLIDO
//8. BUSCAR USUARIO POR DNI
//9. BUSCAR USUARIO POR ID
//10. MODIFICAR USUARIO EN ARCHIVO
void arCargarUsuario(stUsuario usuario);
void arMostrarUsuariosCargados();
void arMostrarUsuariosCargadosSegunTipo(int tipo);
void arMostrarBajasSegunTipo(int tipo);
stUsuario arBajaAltaLogica(char apellido[], int opcion);
stUsuario arBuscarUsuarioLogin(char dni[], char contrasenia[]);
stUsuario arBuscarUsuarioApellido(char apellido[]);
stUsuario arBuscarUsuarioDni(char dni[]);
stUsuario arBuscarUsuarioId(int id);
void arModificarUsuario(char nombre[], char apellido[]);
//----------------------------------//
//3. FUNCIONES CLIENTEXABOGADO
//----------------------------------//
//1. CARGAR ESTRUCTURA
//2. CARGAR ARCHIVO
//3. MOSTRAR CLIENTES ASIGNADOS A ABOGADO
//4. SABER SI UN CLIENTE PERTENECE A UN ABOGADO
stClienteXAbogado cargarClienteXAbogado(int idAbogado, int idCliente);
void arCargarClienteXAbogado(int idAbogado, int idCliente);
void mostrarClientesDeAbogado(int idAbogado);
stUsuario esClienteDeAbogado(int idAbogado, int idCliente);
#endif // USUARIO_H_INCLUDED
