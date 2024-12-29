#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "usuario.h"
#include "home.h"
#include "citas.h"

#ifndef MAINS_H_INCLUDED
#define MAINS_H_INCLUDED

#define ADMINID 1
//----------------------------------//
//MENU PRINCIPAL
//----------------------------------//
void home();

//----------------------------------//
//FUNCIONES COMPARTIDAS
//----------------------------------//
void modificarPerfil(stUsuario usuario);

//----------------------------------//
//1.MENU ADMIN Y FUNCIONES:
//----------------------------------//
//1. MENU ADMIN PRINCIPAL
//2. MENU ABM (ABOGADOS, CLIENTES, CAUSAS)
//3. MENU ABM PARA ABOGADOS
//4. MENU ABM PARA CLIENTES
//5. MENU ABM PARA CAUSAS
//6. MENU ABM PARA BUSCAR CAUSAS SEGUN TIPO DE DATO
//7. MENU REGISTRO(SE UTILIZA PARA AGREGAR UN ADMIN)
//8. FUNCION AGREGAR ADMIN
void menuAdmin(stUsuario admin);
void adMenuABM();
void adMenuAbogados();
void adMenuClientes();
void adMenuCausas();
void adBuscarCausa();
void adMenuRegistro();
stUsuario agregarAdmin();
//----------------------------------//
//2. MENU ABOGADO:
//----------------------------------//
//1. MENU ABOGADO PRINCIPAL - (PERFIL, AGENDA, CLIENTES, CAUSAS)
//2. MENU ABOGADO PERFIL - (MODIFICAR DATOS PERSONALES)
//3. MENU ABOGADO AGENDA - (AGREGAR, VER, MODIFICAR CITAS)
//4. MENU ABOGADO AGENDA - AGREGAR CITA
//5. MENU ABOGADO AGENDA - VER CITAS
//6. MENU ABOGADO AGENDA - MODIFICAR CITA (1. MODIFICAR DATO 2.CANCELAR CITA)
//7. MENU ABOGADO CLIENTES (BUSCAR, LISTAR, AGREGAR, VER CAUSAS DE UN CLIENTE PERTENECIENTE A UN ABOGADO)
//8. MENU ABOGADO CAUSAS (AGREGAR UNA CAUSA, VER CAUSAS DEL ABOGADO)
void menuAbogado(stUsuario abogado);
void abMenuPerfil(stUsuario abogado);
void abMenuAgenda(stUsuario abogado);
void abMenuAgregarCita(stUsuario abogado);
void abMenuVerCitas(stUsuario abogado);
void abMenuModificarCita(stCita cita);
void abMenuClientes(stUsuario abogado);
void abMenuCausas(stUsuario abogado);
//----------------------------------//
//3. MENU CLIENTES:
//----------------------------------//
//1. MENU PRINCIPAL CLIENTES - (CAUSAS DEL CLIENTE, MODIFICAR PERFIL PERSONAL)
//2. MENU VER CAUSAS - (VER CAUSAS DEL CLIENTE)
//3. MENU VER CITAS - (VER CITAS DEL CLIENTE)
void menuCliente(stUsuario cliente);
void clMenuVerCausa(stUsuario cliente);
void clMenuCita(stUsuario cliente);

#endif // MAINS_H_INCLUDED
