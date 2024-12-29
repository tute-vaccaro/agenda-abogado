#include "menu.h"
#include "usuario.h"
#include "causas.h"
#include "citas.h"
#include "calendario.h"

//----------------------------------//
//MENU PRINCIPAL
//----------------------------------//
void home()
{
    stUsuario usuario;
    stUsuario admin;
    int option, tipo;
    char dni[MAXC];

    admin = arBuscarUsuarioId(ADMINID);
    if(admin.tipo == -1)
    {
        printf("Creando admin 1: \n");
        printf("DNI: \n");
        fflush(stdin);
        gets(dni);
        admin = cargarUsuarioRegistro(1, dni);
        admin.id = ADMINID;
        arCargarUsuario(admin);
        printf("Admin creado exitosamente! \n");
        system("pause");
        system("cls");
    }

    do
    {
        printf("1. Iniciar Sesion \n");
        printf("2. Registrarse \n");
        printf("0. Salir \n");
        scanf("%i",&option);
        system("cls");
        switch(option)
        {
        case 1:
            usuario = iniciarSesion();
            system("cls");
            if(usuario.tipo == 1)
            {
                if(usuario.persona.genero == 'f')
                {
                    printf("Bienvenida Admin %s \n", usuario.persona.name.nombre);
                }
                else
                {
                    printf("Bienvenido Admin %s \n", usuario.persona.name.nombre);
                }
                system("pause");
                system("cls");
                menuAdmin(usuario);
            }
            else if(usuario.tipo == 2)
            {
                if(usuario.persona.genero == 'f')
                {
                    printf("Bienvenida Abogada %s \n", usuario.persona.name.nombre);
                }
                else
                {
                    printf("Bienvenido Abogado %s \n", usuario.persona.name.nombre);
                }
                system("pause");
                system("cls");
                menuAbogado(usuario);
            }
            else if(usuario.tipo == 3)
            {
                if(usuario.persona.genero == 'f')
                {
                    printf("Bienvenida %s \n", usuario.persona.name.nombre);
                }
                else
                {
                    printf("Bienvenido %s \n", usuario.persona.name.nombre);
                }
                system("pause");
                system("cls");
                menuCliente(usuario);
            }
            else
            {
                printf("Usuario o contrasenia incorrecta \n");
            }
            system("pause");
            system("cls");
            break;
        case 2:
            printf("Ingrese tipo de usuario: 2.Abogado 3.Usuario \n");
            scanf("%i", &tipo);
            if(tipo == 2 || tipo == 3)
            {
                registrarUsuario(tipo);
            }
            else
            {
                printf("Tipo no valido. \n");
            }
            system("pause");
            system("cls");
            break;
        case 0:
            printf("Saliendo del sistema...\n");
            system("pause");
            system("cls");
            break;
        default:
            printf("Opcion Incorrecta \n");
            system("pause");
            system("cls");
            break;
        }
    }
    while(option != 0);
}
//----------------------------------//
//FUNCIONES COMPARTIDAS
//----------------------------------//
void modificarPerfil(stUsuario usuario)
{
    arModificarUsuario(usuario.persona.name.nombre, usuario.persona.name.apellido);
}
//----------------------------------//
//1.MENU ADMIN Y FUNCIONES:
//----------------------------------//
//1. MENU ADMIN PRINCIPAL
void menuAdmin(stUsuario admin)
{
    int option;

    do
    {
        printf("1. ABM \n");
        printf("2. Registro \n");
        printf("3. Modificar Perfil \n");
        printf("0. Volver al menu anterior \n");
        scanf("%i",&option);
        system("cls");
        switch(option)
        {
        case 1:
            adMenuABM();
            system("pause");
            system("cls");
            break;
        case 2:
            adMenuRegistro();
            system("pause");
            system("cls");
            break;
        case 3:
            modificarPerfil(admin);
            system("pause");
            system("cls");
            break;
        case 0:
            system("cls");
            break;
        default:
            printf("Opcion Incorrecta \n");
            system("pause");
            system("cls");
            break;
        }

    }
    while(option!=0);

}
//2. MENU ABM (ABOGADOS, CLIENTES, CAUSAS)
void adMenuABM()
{
    int option;
    int dimension = 100;
    int validos;
    stCita citas[dimension];
    char lugar[MAXC];
    int lugarCita = 0;

    do
    {
        printf("1. Abogados\n");
        printf("2. Clientes\n");
        printf("3. Causas \n");
        printf("4. Ver citas segun lugar \n");
        printf("0. Volver al menu anterior \n");
        scanf("%i",&option);
        system("cls");
        switch(option)
        {
        case 1:
            adMenuAbogados();
            system("pause");
            system("cls");
            break;
        case 2:
            adMenuClientes();
            system("pause");
            system("cls");
            break;
        case 3:
            adMenuCausas();
            system("pause");
            system("cls");
            break;
        case 4:
            validos = pasarArchivoAArregloCita(citas, dimension);
            ordenarPorSeleccionCita(citas, validos);
            printf("En que lugar es la cita?\n");
            printf("1. Tribunal Familiar, 2. Tribunal criminal, 3. Juzgado Civil y comercial 4. Estudio Juridico\n");
            scanf("%i", &lugarCita);
            switch(lugarCita)
            {
            case 1:
                strcpy(lugar, "TRIBUNAL FAMILIAR");
                break;
            case 2:
                strcpy(lugar, "TRIBUNAL CRIMINAL");
                break;
            case 3:
                strcpy(lugar, "JUZGADO CIVIL Y COMERCIAL");
                break;
            case 4:
                strcpy(lugar, "ESTUDIO JURIDICO");
                break;
            default:
                lugarCita = 0;
                printf("Opcion incorrecta \n");
                break;
            }
            if(lugarCita!=0){
            mostrarCitaSegunLugar(citas, validos, lugar);
            }
            system("pause");
            system("cls");
            break;
        case 0:
            system("cls");
            break;
        default:
            printf("Opcion Incorrecta \n");
            system("pause");
            system("cls");
            break;
        }

    }
    while(option!=0);
}
//3. MENU ABM PARA ABOGADOS
void adMenuAbogados()
{
    int option;
    stUsuario abogado;
    int dimension = 100;
    int validos;
    stUsuario abogados[dimension];
    char dni[MAXC];
    char nombre[MAXC];
    char apellido[MAXC];
    do
    {
        printf("1. Listado de Abogados por Apellido y nombre \n");
        printf("2. Listado de Abogados Alta / Baja \n");
        printf("3. Buscar Abogado por su dni \n");
        printf("4. Dar de Baja/Alta a un abogado \n");
        printf("5. Modificar datos de Abogado \n");
        printf("0. Volver al menu anterior \n");
        scanf("%i",&option);
        system("cls");
        switch(option)
        {
        case 1:
            validos = pasarArchivoAArregloUsuario(abogados, dimension, 2);
            ordenarPorInsercionSegunApellidoUsuario(abogados, validos);
            printf("Listado de Abogados: \n");
            mostrarListadoNombreCompletoUsuario(abogados, validos);
            system("pause");
            system("cls");
            break;
        case 2:
            printf("Seleccione una opcion: \n");
            printf("1. Listado de Abogados \n");
            printf("2. Listado de Bajas \n");
            scanf("%i", &option);
            system("cls");
            if(option == 1)
            {
                validos = pasarArchivoAArregloUsuario(abogados, dimension, 2);
                ordenarPorInsercionSegunApellidoUsuario(abogados, validos);
                printf("Listado de Abogados: \n");
                mostrarArregloUsuario(abogados, validos);
            }
            else if(option == 2)
            {
                printf("Listado de Abogados en baja: \n");
                arMostrarBajasSegunTipo(2);
            }
            system("pause");
            system("cls");
            break;
        case 3:
            printf("Ingrese el dni del Abogado: \n");
            fflush(stdin);
            gets(dni);
            abogado = arBuscarUsuarioDni(dni);
            if(abogado.tipo == 2)
            {
                mostrarUsuario(abogado);
            }
            else
            {
                printf("Abogado no encontrado en el registro \n");
            }
            system("pause");
            system("cls");
            break;
        case 4:
            printf("Ingrese una opcion: \n");
            printf("1. Dar de baja a un Abogado \n");
            printf("2. Dar de alta a un Abogado \n");
            scanf("%i", &option);
            system("cls");
            while(option != 1 && option != 2)
            {
                printf("Error \n");
                printf("Ingrese una opcion: \n");
                printf("1. Dar de baja a un Abogado \n");
                printf("2. Dar de alta a un Abogado \n");
                scanf("%i", &option);
            }
            printf("Ingrese el apellido del Abogado \n");
            fflush(stdin);
            gets(apellido);
            abogado = arBajaAltaLogica(apellido, option);
            if(abogado.tipo != -1)
            {
                if(abogado.baja == 1)
                {
                    printf("El usuario ha sido dado de baja \n");
                }
                else
                {
                    printf("El usuario ha sido dado de alta \n");
                }
            }
            else
            {
                printf("Abogado no encontrado en el registro \n");
            }
            system("pause");
            system("cls");

        case 5:
            printf("Ingrese el nombre del abogado: \n");
            fflush(stdin);
            gets(nombre);
            printf("Ingrese el apellido del abogado: \n");
            fflush(stdin);
            gets(apellido);
            arModificarUsuario(nombre, apellido);
            system("pause");
            system("cls");
            break;

        case 0:
            system("cls");
            break;

        default:
            printf("Opcion Incorrecta \n");
            system("pause");
            system("cls");
            break;
        }
    }
    while(option!=0);
}
//4. MENU ABM PARA CLIENTES
void adMenuClientes()
{
    int option;
    stUsuario cliente;
    int dimension = 500;
    int validos;
    stUsuario clientes[dimension];
    char dni[MAXC];
    char nombre[MAXC];
    char apellido[MAXC];

    do
    {
        printf("1. Listado de Clientes por Apellido y nombre \n");
        printf("2. Listado de Clientes \n");
        printf("3. Buscar un cliente por su dni \n");
        printf("4. Dar de Baja/Alta a un Cliente \n");
        printf("5. Modificar datos de un cliente \n");
        printf("0. Volver al menu anterior \n");
        scanf("%i",&option);
        system("cls");
        switch(option)
        {
        case 1:
            validos = pasarArchivoAArregloUsuario(clientes, dimension, 3);
            ordenarPorInsercionSegunApellidoUsuario(clientes, validos);
            printf("Listado de Clientes: \n");
            mostrarListadoNombreCompletoUsuario(clientes, validos);
            system("pause");
            system("cls");
            break;
        case 2:
            printf("Seleccione una opcion: \n");
            printf("1. Listado de Clientes \n");
            printf("2. Listado de Bajas \n");
            scanf("%i", &option);
            system("cls");
            if(option == 1)
            {
                validos = pasarArchivoAArregloUsuario(clientes, dimension, 3);
                ordenarPorInsercionSegunApellidoUsuario(clientes, validos);
                printf("Listado de Clientes: \n");
                mostrarArregloUsuario(clientes, validos);
            }
            else if(option == 2)
            {
                printf("Listado de Clientes en baja: \n");
                arMostrarBajasSegunTipo(3);
            }
            system("pause");
            system("cls");
            break;
        case 3:
            printf("Ingrese el dni del Cliente: \n");
            fflush(stdin);
            gets(dni);
            cliente = arBuscarUsuarioDni(dni);
            if(cliente.tipo == 3)
            {
                mostrarUsuario(cliente);
            }
            else
            {
                printf("Cliente no encontrado en el registro \n");
            }
            system("pause");
            system("cls");
            break;
        case 4:
            printf("Ingrese una opcion: \n");
            printf("1. Dar de baja a un Cliente \n");
            printf("2. Dar de alta a un Cliente \n");
            scanf("%i", &option);
            while(option != 1 && option !=2)
            {
                printf("Error \n");
                printf("Ingrese una opcion: \n");
                printf("1. Dar de baja a un Cliente \n");
                printf("2. Dar de alta a un Cliente \n");
                scanf("%i", &option);
            }
            printf("Ingrese el apellido del Cliente \n");
            fflush(stdin);
            gets(apellido);
            cliente = arBajaAltaLogica(apellido, option);
            if(cliente.tipo != -1)
            {
                if(cliente.baja == 1)
                {
                    printf("El usuario ha sido dado de baja \n");
                }
                else
                {
                    printf("El usuario ha sido dado de alta \n");
                }
            }
            else
            {
                printf("Cliente no encontrado en el registro \n");
            }
            system("pause");
            system("cls");
            break;
        case 5:
            printf("Ingrese el nombre del cliente: \n");
            fflush(stdin);
            gets(nombre);
            printf("Ingrese el apellido del cliente: \n");
            fflush(stdin);
            gets(apellido);
            arModificarUsuario(nombre, apellido);
            system("pause");
            system("cls");
            break;
        case 0:
            system("cls");
            break;
        default:
            printf("Opcion Incorrecta \n");
            system("pause");
            system("cls");
            break;
        }
    }
    while(option!=0);
}
//5. MENU ABM PARA CAUSAS
void adMenuCausas()
{
    int option, numCausa;
    stUsuario usuario;
    stCausa causa;
    int dimension = 500;
    int validos;
    stCausa causas[dimension];
    char dni[MAXC];
    Pila pilaNum;
    inicpila(&pilaNum);
    do
    {
        printf("1. Listado de causas \n");
        printf("2. Cargar causa \n");
        printf("3. Buscar causa \n");
        printf("4. Dar de Baja/Alta a una causa \n");
        printf("5. Modificar datos de una causa \n");
        printf("6. Ver ultimas causas cargadas \n");
        printf("0. Volver al menu anterior \n");
        scanf("%i",&option);
        system("cls");
        switch(option)
        {
        case 1:
            printf("1. Listado de causas Activas \n");
            printf("2. Listado de causas Inctivas \n");
            scanf("%i", &option);
            system("cls");
            if(option == 1)
            {
                validos = pasarArchivoAArregloCausas(causas, dimension);
                ordenarPorSeleccionCausa(causas, validos);
                printf("Causas Activas: \n");
                mostrarArregloCausasActivas(causas, validos);
            }
            else if(option == 2)
            {
                printf("Causas Inactivas: \n");
                arMostrarArchivoCausas(1);
            }
            else
            {
                printf("Error. Opcion invalida \n");
            }
            system("pause");
            system("cls");
            break;
        case 2:
            printf("Ingrese el dni del Cliente o del abogado \n");
            fflush(stdin);
            gets(dni);
            usuario = arBuscarUsuarioDni(dni);
            if(usuario.tipo != -1)
            {
                arCargarCausa(dni, &pilaNum);
                printf("Causa cargada exitosamente! \n");
            }
            else
            {
                printf("Usuario no encontrado, primero registrelo en el sistema. \n");
            }
            system("pause");
            system("cls");
            break;
        case 3:
            adBuscarCausa();
            system("pause");
            system("cls");
            break;
        case 4:
            printf("Ingrese el numero de la causa: \n");
            scanf("%i", &numCausa);
            causa = arBuscarCausaSegunNumDeCausa(numCausa);
            if(causa.estado != -1)
            {
                printf("Ingrese 1: Para dar de Baja la causa, 2: Para dar de alta la causa \n");
                scanf("%i", &option);
                if(option == 1 || option == 2)
                {
                    arBajaAltaLogicaCausa(numCausa, option);
                    printf("Ha sido modificado el estado de la causa \n");
                }
                else
                {
                    printf("Opcion incorrecta \n");
                }
            }
            else
            {
                printf("Causa no encontrada \n");
            }
            system("pause");
            system("cls");
            break;
        case 5:
            printf("Ingrese el numero de la causa: \n");
            scanf("%i", &numCausa);
            arModficarDatoCausa(numCausa);
            system("pause");
            system("cls");
            break;
        case 6:
            printf("Ultimas causas cargadas: \n");
            mostrar(&pilaNum);
            printf("\n");
            system("pause");
            system("cls");
            break;

        case 0:
            printf("Saliendo del sistema...\n");
            system("pause");
            system("cls");
            break;
        default:
            printf("Opcion Incorrecta \n");
            system("pause");
            system("cls");
            break;
        }
    }
    while(option != 0);
}
//6. MENU ABM PARA BUSCAR CAUSAS SEGUN TIPO DE DATO
void adBuscarCausa()
{
    int option, numCausa;
    char dni[MAXC];
    char juezBuscado[MAXC];
    stCausa causa;
    do
    {
        printf("1. Buscar causa por DNI\n");
        printf("2. Buscar causa por Numero de causa\n");
        printf("3. Buscar causa por Juez \n");
        printf("0. Volver al menu anterior \n");
        scanf("%i",&option);
        system("cls");

        switch(option)
        {
        case 1:
            printf("Ingrese el dni del usuario \n");
            fflush(stdin);
            gets(dni);
            causa = arBuscarCausaSegunDni(dni);
            if(causa.estado == 0)
            {
                mostrarCausa(causa);
            }
            else if(causa.estado == 1)
            {
                printf("La causa esta inactiva \n");
                mostrarCausa(causa);
            }
            else
            {
                printf("No se ha encontrado la causa \n");
            }
            system("pause");
            system("cls");
            break;
        case 2:
            printf("Ingrese el numero de la causa: \n");
            scanf("%i", &numCausa);
            causa = arBuscarCausaSegunNumDeCausa(numCausa);
            if(causa.estado == 0)
            {
                mostrarCausa(causa);
            }
            else if(causa.estado == 1)
            {
                printf("La causa esta inactiva \n");
                mostrarCausa(causa);
            }
            else
            {
                printf("No se ha encontrado la causa \n");
            }
            system("pause");
            system("cls");
            break;
        case 3:
            printf("Ingrese el nombre del juez \n");
            fflush(stdin);
            gets(juezBuscado);
            causa = arBuscarCausaSegunJuez(juezBuscado);
            if(causa.estado == 0)
            {
                mostrarCausa(causa);
            }
            else if(causa.estado == 1)
            {
                printf("La causa esta inactiva \n");
                mostrarCausa(causa);
            }
            else
            {
                printf("No se ha encontrado la causa \n");
            }
            system("pause");
            system("cls");
            break;
        case 0:
            printf("Saliendo del sistema...\n");
            system("pause");
            system("cls");
            break;
        default:
            printf("Opcion Incorrecta \n");
            system("pause");
            system("cls");
            break;
        }
    }
    while(option != 0);
}
//7. MENU REGISTRO(SE UTILIZA PARA AGREGAR UN ADMIN)
void adMenuRegistro()
{
    int option;
    do
    {
        stUsuario admin;
        printf("1. Agregar Admins \n");
        printf("0. Volver al menu anterior \n");
        scanf("%i",&option);
        system("cls");
        switch(option)
        {
        case 1:
            admin = agregarAdmin();
            arCargarUsuario(admin);
            system("cls");
            printf("Admin creado exitosamente \n");
            mostrarUsuario(admin);
            system("pause");
            system("cls");
            break;
        case 0:
            system("cls");
            break;
        default:
            printf("Opcion Incorrecta \n");
            system("pause");
            system("cls");
            break;
        }
    }
    while(option!=0);

}
//8. FUNCION AGREGAR ADMIN
stUsuario agregarAdmin()
{
    stUsuario admin;
    char dni[MAXC];
    printf("Ingrese DNI del nuevo admin: \n");
    fflush(stdin);
    gets(dni);
    admin = cargarUsuarioRegistro(1, dni);
    arCargarUsuario(admin);
    return admin;
}
//----------------------------------//
//2. MENU ABOGADO:
//----------------------------------//
//1. MENU ABOGADO PRINCIPAL - (PERFIL, AGENDA, CLIENTES, CAUSAS)
void menuAbogado(stUsuario abogado)
{
    int option;
    do
    {
        printf("1. Perfil \n");
        printf("2. Agenda \n");
        printf("3. Clientes \n");
        printf("4. Causas \n");
        printf("0. Volver al menu anterior \n");
        scanf("%i",&option);
        system("cls");
        switch(option)
        {
        case 1:
            abMenuPerfil(abogado);
            system("pause");
            system("cls");
            break;
        case 2:
            abMenuAgenda(abogado);
            system("pause");
            system("cls");
            break;
        case 3:
            abMenuClientes(abogado);
            system("pause");
            system("cls");
            break;
        case 4:
            abMenuCausas(abogado);
            system("pause");
            system("cls");
            break;
        case 0:
            system("pause");
            system("cls");
            break;
        default:
            printf("Opcion Incorrecta \n");
            system("pause");
            system("cls");
            break;
        }

    }
    while(option!=0);
}
//2. MENU ABOGADO PERFIL - (MODIFICAR DATOS PERSONALES)
void abMenuPerfil(stUsuario abogado)
{
    int option;
    printf("Hola %s \n", abogado.persona.name.nombre);
    printf("Tus datos actuales son: \n");
    mostrarUsuario(abogado);
    printf("Desea modificar su perfil? \n");
    printf("1. Si, 0: No. \n");
    scanf("%i",&option);
    system("cls");
    if(option == 1)
    {
        modificarPerfil(abogado);
    }
    system("cls");
}
//3. MENU ABOGADO AGENDA - (AGREGAR, VER, MODIFICAR CITAS)
void abMenuAgenda(stUsuario abogado)
{
    int option;
    char dni[MAXC];
    stCita cita;
    do
    {
        printf("1. Agregar cita \n");
        printf("2. Ver citas \n");
        printf("3. Modificar cita \n");
        printf("4. Ver Calendario \n");
        printf("0. Volver al menu anterior \n");
        scanf("%i",&option);
        system("cls");
        switch(option)
        {
        case 1:
            abMenuAgregarCita(abogado);
            system("pause");
            system("cls");
            break;
        case 2:
            abMenuVerCitas(abogado);
            system("pause");
            system("cls");
            break;
        case 3:
            printf("Ingrese el dni de su cliente \n");
            fflush(stdin);
            gets(dni);
            cita = buscarCitaPorDni(dni);
            if(cita.estado != -1)
            {
                abMenuModificarCita(cita);
            }
            else
            {
                printf("No se ha encontrado una cita con ese cliente \n");
            }
            system("pause");
            system("cls");
            break;
        case 4:
            menuCalendario(abogado);
            system("pause");
            system("cls");
            break;
        case 0:
            system("pause");
            system("cls");
            break;
        default:
            printf("Opcion Incorrecta \n");
            system("pause");
            system("cls");
            break;
        }

    }
    while(option!=0);
}
//4. MENU ABOGADO AGENDA - AGREGAR CITA
void abMenuAgregarCita(stUsuario abogado)
{
    stUsuario cliente;
    char dniCliente[MAXC];

    printf("Ingrese el dni del cliente\n");
    fflush(stdin);
    gets(dniCliente);
    cliente = arBuscarUsuarioDni(dniCliente);
    if(cliente.tipo != -1)
    {
        cargarCitaArchivo(abogado.persona.dni, cliente.persona.dni);
        printf("Cita cargada exitosamente \n");
    }
    else
    {
        printf("Cliente no encontrado. Registre al cliente \n");
    }
}
//5. MENU ABOGADO AGENDA - VER CITAS
void abMenuVerCitas(stUsuario abogado)
{
    int dimension = 100;
    int validos;
    stCita citas[dimension];
    stCita cita;
    cita = buscarCitaPorDni(abogado.persona.dni);
    if(cita.estado != -1)
    {
        validos = pasarArchivoAArregloCita(citas, dimension);
        ordenamientoPorInsercionDelArregloPorFecha(citas,validos);
        printf("Mis proximas citas: \n");
        verCitasUsuario(abogado.persona.dni, citas, validos);
    }
    else
    {
        printf("Usted no tiene citas pendientes \n");
    }
}
//6. MENU ABOGADO AGENDA - MODIFICAR CITA, CANCELAR CITA
void abMenuModificarCita(stCita cita)
{
    int option;
    do
    {
        printf("1. Modificar dato de la cita \n");
        printf("2. Cancelar cita \n");
        printf("0. Volver al menu anterior \n");
        scanf("%i", &option);
        switch(option)
        {
        case 1:
            if(cita.estado != -1)
            {
                arModificarCita(cita.dniCliente);
            }
            else
            {
                printf("No se ha encontrado la cita \n");
            }
            system("pause");
            system("cls");
            break;
        case 2:
            cita = arBajaLogicaCita(cita.dniCliente);
            if(cita.estado == 1)
            {
                printf("Su Cita ha sido cancelada \n");
            }
            else
            {
                printf("No se encontro la cita \n");
            }
            system("pause");
            system("cls");
            break;
        case 0:
            system("cls");
        default:
            printf("Opcion incorrecta \n");
            system("pause");
            system("cls");
            break;
        }
    }
    while(option != 0);
}
//7. MENU ABOGADO CLIENTES
void abMenuClientes(stUsuario abogado)
{
    int option;
    stUsuario cliente;
    stCausa causa;
    char dni[MAXC];

    printf("1. Buscar cliente \n");
    printf("2. Listado de mis clientes \n");
    printf("3. Agregar un cliente \n");
    printf("4. Ver causas de un cliente \n");
    printf("0. Volver al menu anterior \n");
    scanf("%i",&option);
    system("cls");

    switch(option)
    {
    case 1:
        printf("Ingrese el dni del cliente \n");
        fflush(stdin);
        gets(dni);
        cliente = arBuscarUsuarioDni(dni);
        if(cliente.tipo == 3)
        {
            cliente = esClienteDeAbogado(abogado.id, cliente.id);
            if(cliente.tipo != -1)
            {
                printf("Cliente encontrado! \n");
                mostrarUsuario(cliente);
                causa = arBuscarCausaSegunDni(cliente.persona.dni);
                if(causa.estado != -1)
                {
                    printf("La causa del cliente es: \n");
                    mostrarCausasDeUsuario(cliente.id);
                }
                else
                {
                    printf("El cliente no tiene una causa \n");
                }
            }
            else
            {
                printf("Cliente no encontrado \n");
            }
        }
        else
        {
            printf("Cliente no encontrado \n");
        }
        system("pause");
        system("cls");
        break;
    case 2:
        mostrarClientesDeAbogado(abogado.id);
        system("pause");
        system("cls");
        break;
    case 3:
        printf("Ingrese el DNI del cliente \n");
        fflush(stdin);
        gets(dni);
        cliente = arBuscarUsuarioDni(dni);
        if(cliente.tipo == 3)
        {
            arCargarClienteXAbogado(abogado.id, cliente.id);
            printf("Cliente cargado con exito \n");
        }
        else
        {
            printf("Cliente no encontrado en el registro \n");
        }
        system("pause");
        system("cls");
        break;
    case 4:
        printf("Ingrese el DNI del cliente \n");
        fflush(stdin);
        gets(dni);
        cliente = arBuscarUsuarioDni(dni);
        if(cliente.tipo == 3)
        {
            mostrarCausasDeUsuario(cliente.id);
        }
        else
        {
            printf("Cliente no encontrado en el registro \n");
        }

        system("pause");
        system("cls");
        break;
    case 0:
        system("pause");
        system("cls");
        break;
    default:
        printf("Opcion Incorrecta \n");
        system("pause");
        system("cls");
        break;
    }
}
//8. MENU ABOGADO CAUSAS - (AGREGAR UNA CAUSA, VER CAUSAS DEL ABOGADO)
void abMenuCausas(stUsuario abogado)
{
    int option;
    char dni[MAXC];
    stUsuario cliente;
    stCausa causa;
    Pila pilaNum;
    inicpila(&pilaNum);

    printf("1. Agregar causa \n");
    printf("2. Ver mis causas \n");
    printf("0. Volver al menu anterior \n");
    scanf("%i",&option);
    system("cls");
    switch(option)
    {
    case 1:
        printf("Ingrese el DNI del cliente \n");
        fflush(stdin);
        gets(dni);
        cliente = arBuscarUsuarioDni(dni);
        if(cliente.tipo != -1)
        {
            arCargarCausa(dni, &pilaNum);
            causa = arBuscarCausaSegunDni(dni);
            arCargarCausaXClyAb(causa.numDeCausa, cliente.id, abogado.id);
            printf("Causa cargada exitosamente! \n");
        }
        else
        {
            printf("Cliente no encontrado. Registre al cliente \n");
        }
        system("pause");
        system("cls");
        break;
    case 2:
        mostrarCausasDeUsuario(abogado.id);
        system("pause");
        system("cls");
        break;
    case 0:
        system("pause");
        system("cls");
        break;
    default:
        printf("Opcion Incorrecta \n");
        system("pause");
        system("cls");
        break;
    }
}
//----------------------------------//
//3. MENU CLIENTES:
//----------------------------------//
//1. MENU PRINCIPAL CLIENTES
void menuCliente(stUsuario cliente)
{
    int option;
    do
    {
        printf("1. Causas\n");
        printf("2. Citas\n");
        printf("3. Perfil \n");
        printf("0. Volver al menu anterior \n");
        scanf("%i",&option);
        system("cls");
        switch(option)
        {
        case 1:
            clMenuVerCausa(cliente);
            system("pause");
            system("cls");
            break;
        case 2:
            clMenuCita(cliente);
            system("pause");
            system("cls");
            break;
        case 3:
            modificarPerfil(cliente);
            system("pause");
            system("cls");
            break;
        case 0:
            system("cls");
            break;
        default:
            printf("Opcion Incorrecta \n");
            system("pause");
            system("cls");
            break;
        }

    }
    while(option!=0);
}
//2. MENU VER CAUSAS - (VER CAUSAS DEL CLIENTE)
void clMenuVerCausa(stUsuario cliente)
{
    stCausa causa;
    causa = arBuscarCausaSegunDni(cliente.persona.dni);
    if(causa.estado == 0)
    {
        mostrarCausa(causa);
    }
    else if(causa.estado == 1)
    {
        printf("Su causa se encuentra inactiva \n");
        mostrarCausa(causa);
    }
    else
    {
        printf("No se ha encontrado ninguna causa con sus datos \n");
    }
}
//3. MENU VER CITAS - (VER CITAS DEL CLIENTE)
void clMenuCita(stUsuario cliente)
{
    int option;
    int dimension = 100;
    int validos;
    stCita citas[dimension];
    stCita cita;

    do
    {
        printf("1. Ver mis citas\n");
        printf("2. Cancelar una cita\n");
        printf("0. Volver al menu anterior \n");
        scanf("%i",&option);
        system("cls");
        switch(option)
        {
        case 1:
            cita = buscarCitaPorDni(cliente.persona.dni);
            if(cita.estado != -1)
            {
                validos = pasarArchivoAArregloCita(citas, dimension);
                ordenamientoPorInsercionDelArregloPorFecha(citas, validos);
                verCitasUsuario(cliente.persona.dni, citas, validos);
            }
            else
            {
                printf("Usted no tiene citas pendientes\n");
            }
            system("pause");
            system("cls");
            break;
        case 2:
            cita = buscarCitaPorDni(cliente.persona.dni);
            if(cita.estado != -1)
            {
                cita =  arBajaLogicaCita(cliente.persona.dni);
                if(cita.estado != -1)
                {
                    printf("Cita cancelada con exito \n");
                }
                else
                {
                    printf("Cita no encontrada \n");
                }

            }
            else
            {
                printf("Cita no encontrada \n");
            }
            system("pause");
            system("cls");
            break;
        case 0:
            system("cls");
            break;
        default:
            printf("Opcion Incorrecta \n");
            system("pause");
            system("cls");
            break;
        }
    }
    while(option!=0);
}
