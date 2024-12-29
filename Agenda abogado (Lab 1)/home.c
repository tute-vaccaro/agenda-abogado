#include "home.h"

//----------------------------------//
//LIBRERIA HOME
//----------------------------------//
//1. INICIO DE SESION
stUsuario iniciarSesion()
{
    stUsuario usuario;
    char dni[MAXC];
    char contrasenia[MAXC];

    printf("Ingrese DNI \n");
    fflush(stdin);
    gets(dni);
    printf("Ingrese contrasenia \n");
    fflush(stdin);
    gets(contrasenia);
    usuario = arBuscarUsuarioLogin(dni, contrasenia);
    return usuario;
}
//2. REGISTRO DE USUARIO
void registrarUsuario(int tipo)
{
    char dni[MAXC];
    stUsuario usuario;
    stUsuario abogado;

    printf("Ingrese su DNI:  \n");
    fflush(stdin);
    gets(dni);
    usuario = arBuscarUsuarioDni(dni);

    if(usuario.tipo == -1)
    {
        usuario = cargarUsuarioRegistro(tipo, dni);
        arCargarUsuario(usuario);
        if(usuario.tipo == 3){
            printf("Ingrese el dni del abogado del cliente \n");
            fflush(stdin);
            gets(dni);
            abogado = arBuscarUsuarioDni(dni);
            if(abogado.tipo != -1){
             arCargarClienteXAbogado(abogado.id, usuario.id);
            }else{
            printf("Lo sentimos. No se ha encontrado al abogado \n");
            }
        }
        printf("Usuario registrado exitosamente! \n");
    }
    else
    {
        printf("El usuario ya existe \n");
    }
}
