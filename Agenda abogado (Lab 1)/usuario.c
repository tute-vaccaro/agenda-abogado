#include "usuario.h"
//------------------------------------
//FUNCIONES EXTRA
//------------------------------------
//1. GENERAR ID
int generarId()
{
    FILE* buffer = fopen(ARCHIVOUSUARIO,"rb");
    stUsuario aux;

    if(buffer)
    {
        fseek(buffer, sizeof(stUsuario)*(-1), SEEK_END);
        fread(&aux, sizeof(stUsuario), 1, buffer);
        fclose(buffer);
    }
    return aux.id+1;
}
//2. CONTAR CANTIDAD DE REGISTROS
int contarRegistrosEnArchivo()
{
    FILE* buffer = fopen(ARCHIVOUSUARIO, "rb");
    int i = 1;
    if(buffer)
    {
        fseek(buffer, 0, SEEK_END);
        i = (int) ftell(buffer) / sizeof(stUsuario);
        fclose(buffer);
    }
    return i;
}
//------------------------------------
//1. FUNCIONES BASICAS DE USUARIO:
//------------------------------------
//1. CARGAR CONTRASENIA
stUsuario cargarContraseniaRegistro(stUsuario usuario)
{
    char contrasenia[30];
    char confirmacion[30];
    printf("Ingrese su nueva contrasenia:  \n");
    fflush(stdin);
    gets(contrasenia);
    while(!validarLenghtContrasenia(contrasenia))
    {
        printf("La contrasenia es muy corta \n");
        printf("Ingrese su nueva contrasenia:  \n");
        fflush(stdin);
        gets(contrasenia);
    }
    printf("Vuelva a ingresar su contrasenia \n");
    fflush(stdin);
    gets(confirmacion);
    while(!validarContrasenia(contrasenia, confirmacion))
    {
        printf("Las contrasenias no coinciden\n");
        printf("Ingrese su nueva contrasenia:  \n");
        fflush(stdin);
        gets(contrasenia);
        printf("Vuelva a ingresar su contrasenia \n");
        fflush(stdin);
        gets(confirmacion);
    }
    strcpy(usuario.contrasenia, contrasenia);
    return usuario;
}
//2. CARGAR USUARIO PARA REGISTRO
stUsuario cargarUsuarioRegistro(int tipoUsuario, char dni[])
{
    stUsuario usuario;
    usuario.id = generarId();
    usuario.tipo = tipoUsuario;
    usuario.baja = 0;

    strcpy(usuario.persona.dni, dni);
    while(!validarStringNum(usuario.persona.dni))
    {
        printf("Error. \n");
        printf("DNI: \n");
        fflush(stdin);
        gets(usuario.persona.dni);
    }
    while(!validarLenght(usuario.persona.dni, 6))
    {
        printf("Error. Ingrese al menos 6 digitos\n");
        fflush(stdin);
        printf("DNI: \n");
        gets(usuario.persona.dni);
    }
    printf("Nombre: \n");
    fflush(stdin);
    gets(usuario.persona.name.nombre);
    while(!validarStringNombre(usuario.persona.name.nombre))
    {
        printf("Error. Nombre Invalido. \n");
        printf("Nombre: \n");
        fflush(stdin);
        gets(usuario.persona.name.nombre);
    }
    while(!validarLenght(usuario.persona.name.nombre, 2))
    {
        printf("Error. Nombre muy corto. \n");
        fflush(stdin);
        printf("Nombre: \n");
        gets(usuario.persona.name.nombre);
    }
    printf("Apellido: \n");
    fflush(stdin);
    gets(usuario.persona.name.apellido);
    while(!validarStringNombre(usuario.persona.name.apellido))
    {
        printf("Error. Apellido invalido \n");
        printf("Apellido: \n");
        fflush(stdin);
        gets(usuario.persona.name.apellido);
    }
    while(!validarLenght(usuario.persona.name.apellido, 2))
    {
        printf("Error. Apellido muy corto. \n");
        fflush(stdin);
        printf("Apellido: \n");
        gets(usuario.persona.name.apellido);
    }
    printf("TELEFONO: \n");
    fflush(stdin);
    gets(usuario.persona.telefono);
    while(!validarStringNum(usuario.persona.telefono))
    {
        printf("Error. Solo numeros aceptados\n");
        printf("TELEFONO: \n");
        fflush(stdin);
        gets(usuario.persona.telefono);
    }
    while(!validarLenght(usuario.persona.telefono, 7))
    {
        printf("Error. Numero invalido \n");
        printf("TELEFONO: \n");
        fflush(stdin);
        gets(usuario.persona.telefono);
    }

    printf("Edad: \n");
    while(!scanf("%i", &usuario.persona.edad))
    {
        printf("Error. Caracteres no permitidos \n");
        printf("Edad: \n");
        scanf("%i", &usuario.persona.edad);
    }
    printf("Genero: (Ingrese m o f) \n");
    fflush(stdin);
    scanf("%c", &usuario.persona.genero);
    while((usuario.persona.genero != 'm' && usuario.persona.genero != 'f'))
    {
        printf("Error. Ingrese m o f. \n");
        printf("Genero: \n");
        fflush(stdin);
        scanf("%c", &usuario.persona.genero);
    }
    printf("Calle: \n");
    fflush(stdin);
    gets(usuario.direccion.calle);
    printf("Altura: \n");
    fflush(stdin);
    gets(usuario.direccion.numero);
    while(!validarStringNum(usuario.direccion.numero))
    {
        printf("error \n");
        printf("Altura: \n");
        fflush(stdin);
        gets(usuario.direccion.numero);
    }
    printf("Piso: \n");
    fflush(stdin);
    gets(usuario.direccion.piso);

    printf("Departamento: \n");
    fflush(stdin);
    gets(usuario.direccion.departamento);

    printf("Ciudad: \n");
    fflush(stdin);
    gets(usuario.direccion.ciudad);
    while(!validarStringNombre(usuario.direccion.ciudad))
    {
        printf("error");
        printf("Ciudad: \n");
        fflush(stdin);
        gets(usuario.direccion.ciudad);
    }
    usuario = cargarContraseniaRegistro(usuario);
    return usuario;
}
//3. MOSTRAR USUARIO
void mostrarUsuario(stUsuario usuario)
{
    printf("------\n");
    printf("Nombre y Apellido: %s %s\n", usuario.persona.name.nombre, usuario.persona.name.apellido);
    printf("DNI: %s \n", usuario.persona.dni);
    printf("Telefono: %s \n", usuario.persona.telefono);
    if(usuario.persona.genero == 'f')
    {
        printf("Genero: Femenino \n");
    }
    else
    {
        printf("Genero: Masculino \n");
    }
    printf("Edad: %i \n", usuario.persona.edad);
    printf("------\n");
    printf("Direccion\n");
    printf("Calle: %s\n", usuario.direccion.calle);
    printf("Numero: %s\n", usuario.direccion.numero);
    printf("Piso: %s\n", usuario.direccion.piso);
    printf("Departamento: %s\n", usuario.direccion.departamento);
    printf("Ciudad: %s\n", usuario.direccion.ciudad);
}
//4. PASAR ARCHIVOS A ARREGLO DE STRUCT
int pasarArchivoAArregloUsuario(stUsuario A[], int dimension, int tipo)
{
    int validos=0;
    stUsuario aux;

    FILE *buffer=fopen(ARCHIVOUSUARIO, "rb");
    if(buffer)
    {
        while (((fread(&aux,sizeof(stUsuario), 1, buffer))>0) && (validos<dimension))
        {
            if(aux.tipo == tipo)
            {
                A[validos]=aux;
                validos++;
            }
        }
        fclose(buffer);
    }
    return validos;
}
//5. MOSTRAR ARREGLO DE STRUCT
void mostrarArregloUsuario(stUsuario aOrdenado[], int validos)
{
    int i = 0;
    while(i<validos)
    {
        if(aOrdenado[i].baja == 0)
        {
            mostrarUsuario(aOrdenado[i]);
        }
        i++;
    }
}
//6. INSERTAR DATO ORDENADAMENTE(STRING)
void insertarUsuarioParaOrdenamiento(stUsuario A[], int  i, stUsuario B)
{
    int u = i;
    while(u>= 0 &&  strcmpi(A[u].persona.name.apellido, B.persona.name.apellido)>0)
    {
        A[u+1] = A[u];
        u--;
    }
    A[u+1] = B;
}
//7. ORDENAMIENTO POR INSERCION ALFABETICO CON ARREGLO DE PALABRAS
void ordenarPorInsercionSegunApellidoUsuario(stUsuario a[], int validos)
{
    int i;

    for(i=0; i<validos-1; i++)
    {
        insertarUsuarioParaOrdenamiento(a, i, a[i+1]);
    }
}
//8. MOSTRAR ARREGLO DE PALABRAS
void mostrarListadoNombreCompletoUsuario(stUsuario aOrdenado[], int validos)
{
    int i = 0;
    while(i<validos)
    {
        printf("%s %s \n", aOrdenado[i].persona.name.apellido, aOrdenado[i].persona.name.nombre);
        i++;
    }
}


//------------------------------------
//2. FUNCIONES DE ARCHIVOS DE USUARIO:
//------------------------------------
//1. CARGAR ARCHIVO DE USUARIOS
void arCargarUsuario(stUsuario usuario)
{
    FILE* buffer = fopen(ARCHIVOUSUARIO, "ab");

    if(buffer)
    {
        fwrite(&usuario, sizeof(stUsuario), 1, buffer);
        fclose(buffer);
    }
}
//2. MOSTRAR USUARIOS CARGADOS EN ARCHIVOS
void arMostrarUsuariosCargados()
{
    stUsuario aux;
    FILE* buffer = fopen(ARCHIVOUSUARIO, "rb");
    if(buffer)
    {
        while(fread(&aux, sizeof(stUsuario), 1, buffer)>0)
        {
            if(aux.baja == 0)
            {
                mostrarUsuario(aux);
            }
        }
        fclose(buffer);
    }
}
//3. MOSTRAR USUARIOS CARGADOS SEGUN TIPO DE USUARIO
void arMostrarUsuariosCargadosSegunTipo(int tipo)
{
    stUsuario aux;
    FILE* buffer = fopen(ARCHIVOUSUARIO, "rb");
    if(buffer)
    {
        while(fread(&aux, sizeof(stUsuario), 1, buffer)>0)
        {
            if(aux.tipo == tipo && aux.baja == 0)
            {
                mostrarUsuario(aux);
            }
            fclose(buffer);
        }
    }
}
//4. MOSTRAR BAJAS SEGUN TIPO DE USUARIO
void arMostrarBajasSegunTipo(int tipo)
{
    stUsuario aux;
    FILE* buffer = fopen(ARCHIVOUSUARIO, "rb");
    if(buffer)
    {
        while(fread(&aux, sizeof(stUsuario), 1, buffer)>0)
        {
            if(aux.tipo == tipo && aux.baja == 1)
            {
                mostrarUsuario(aux);
            }
            fclose(buffer);
        }
    }
}
//5. DAR DE ALTA / DAR DE BAJA A UN USUARIO
stUsuario arBajaAltaLogica(char apellido[], int opcion)
{
    stUsuario aux;
    int flag = 0;


    FILE *buffer = fopen(ARCHIVOUSUARIO, "r+b");
    if(buffer)
    {
        while(flag == 0 && fread(&aux, sizeof(stUsuario), 1, buffer)>0)
        {
            if(strcmpi(aux.persona.name.apellido, apellido)==0)
            {
                if(opcion == 1)
                {
                    aux.baja = 1;
                }
                else
                {
                    aux.baja = 0;
                }
                flag = 1;
            }
            fseek(buffer, (-1)*sizeof(stUsuario), SEEK_CUR);
            fwrite(&aux, sizeof(stUsuario), 1, buffer);
        }
        fclose(buffer);
    }
    if(flag == 0)
    {
        aux.tipo = -1;
    }
    return aux;
}
//6. BUSCAR USUARIO LOGIN(DNI Y CONTRASENIA)
stUsuario arBuscarUsuarioLogin(char dni[], char contrasenia[])
{
    FILE* buffer = fopen(ARCHIVOUSUARIO, "rb");
    int flag = 0;
    stUsuario aux;
    if(buffer)
    {
        while(flag == 0 && fread(&aux, sizeof(stUsuario), 1, buffer)>0)
        {
            if(strcmpi(aux.persona.dni, dni)==0 && strcmp(aux.contrasenia, contrasenia)==0)
            {
                flag=1;
            }
        }
        fclose(buffer);
    }
    if(flag==0)
    {
        aux.tipo = -1;
    }
    return aux;
}
//7. BUSCAR USUARIO POR APELLIDO
stUsuario arBuscarUsuarioApellido(char apellido[])
{
    FILE* buffer = fopen(ARCHIVOUSUARIO, "rb");
    int flag = 0;
    stUsuario aux;

    if(buffer)
    {
        while(flag == 0 && fread(&aux, sizeof(stUsuario), 1, buffer)>0)
        {
            if(strcmpi(aux.persona.name.apellido, apellido)==0)
            {
                flag=1;
            }
        }
        fclose(buffer);
    }
    if(flag == 0)
    {
        aux.tipo = -1;
    }
    return aux;
}
//8. BUSCAR USUARIO POR DNI
stUsuario arBuscarUsuarioDni(char dni[])
{
    FILE* buffer = fopen(ARCHIVOUSUARIO, "rb");
    int flag = 0;
    stUsuario aux;

    if(buffer)
    {
        while(flag == 0 && fread(&aux, sizeof(stUsuario), 1, buffer)>0)
        {
            if(strcmpi(aux.persona.dni, dni)==0)
            {
                flag=1;
            }
        }
        fclose(buffer);
    }
    if(flag==0)
    {
        aux.tipo = -1;
    }
    return aux;
}
//9. BUSCAR USUARIO POR ID
stUsuario arBuscarUsuarioId(int id)
{
    FILE* buffer = fopen(ARCHIVOUSUARIO, "rb");
    int flag = 0;
    stUsuario aux;

    if(buffer)
    {
        while(flag == 0 && fread(&aux, sizeof(stUsuario), 1, buffer) > 0)
        {
            if(aux.id==id)
            {
                flag=1;
            }
        }
        fclose(buffer);
    }
    if(flag==0)
    {
        aux.tipo = -1;
    }
    return aux;
}
//10. MODIFICAR USUARIO EN ARCHIVO
void arModificarUsuario(char nombre[], char apellido[])
{
    int eleccion;
    stUsuario aux;
    int flag=0;
    FILE * buffer;
    buffer = fopen(ARCHIVOUSUARIO, "r+b" );
    if(buffer)
    {
        while (flag==0 && (fread(&aux, sizeof(stUsuario),1, buffer)) > 0)
        {
            if (strcmpi(aux.persona.name.nombre, nombre)==0 && strcmpi(aux.persona.name.apellido, apellido)==0)
            {
                flag=1;
            }
        }
        if(flag == 1)
        {
            mostrarUsuario(aux);
            printf("Que quiere modificar?\n");
            printf("1. Nombre \n");
            printf("2. Apellido \n");
            printf("3. DNI\n");
            printf("4. Telefono \n");
            printf("5. Genero\n");
            printf("6. Edad\n");
            printf("7. Direccion\n");
            scanf("%d", &eleccion);
            if(eleccion==1)
            {
                printf("Ingrese el nuevo nombre: \n");
                fflush(stdin);
                gets(aux.persona.name.nombre);
            }
            else if(eleccion==2)
            {
                printf("Ingrese el nuevo apellido: \n");
                fflush(stdin);
                gets(aux.persona.name.apellido);
            }
            else if (eleccion==3)
            {
                printf("Ingrese el nuevo DNI: \n");
                fflush(stdin);
                gets(aux.persona.dni);
            }
            else if (eleccion==4)
            {
                printf("Ingrese el nuevo telefono: \n");
                fflush(stdin);
                gets(aux.persona.telefono);
            }
            else if (eleccion==5)
            {
                printf("Ingrese el nuevo genero: \n");
                fflush(stdin);
                scanf("%c", &aux.persona.genero);
            }
            else if (eleccion==6)
            {
                printf("Ingrese la nueva edad: \n");
                scanf("%i", &aux.persona.edad);
            }
            else if (eleccion==7)
            {
                printf("Modificar: 1. Calle, 2.Numero, 3.Piso, 4. Departamento, 5.Ciudad\n");
                scanf("%i",&eleccion);
                if(eleccion == 1)
                {
                    printf("Ingrese la nueva calle: \n");
                    fflush(stdin);
                    gets(aux.direccion.calle);
                }
                else if(eleccion == 2)
                {
                    printf("Ingrese el nuevo numero: \n");
                    fflush(stdin);
                    gets(aux.direccion.numero);
                }
                else if(eleccion == 3)
                {
                    printf("Ingrese el nuevo piso: \n");
                    fflush(stdin);
                    gets(aux.direccion.piso);
                }
                else if(eleccion == 4)
                {
                    printf("Ingrese el nuevo departamento: \n");
                    fflush(stdin);
                    gets(aux.direccion.departamento);
                }
                else if(eleccion == 5)
                {
                    printf("Ingrese la nueva ciudad: \n");
                    fflush(stdin);
                    gets(aux.direccion.ciudad);
                }
                else
                {
                    printf("la opcion es incorrecta \n");
                }
            }
            else
            {
                printf("la opcion es incorrecta \n");
            }

            fseek(buffer,sizeof(stUsuario)*(-1), SEEK_CUR);
            fwrite(&aux,sizeof(stUsuario),1, buffer);
        }
        fclose(buffer);
    }
    if(flag == 0)
    {
        printf("Usuario no encontrado \n");
    }
}
//------------------------------------
//3.FUNCIONES CLIENTEXABOGADO
//------------------------------------
//1. CARGAR ESTRUCTURA
stClienteXAbogado cargarClienteXAbogado(int idAbogado, int idCliente)
{
    stClienteXAbogado aux;
    aux.idAbogado = idAbogado;
    aux.idCliente = idCliente;
    return aux;
}
//2. CARGAR ARCHIVO
void arCargarClienteXAbogado(int idAbogado, int idCliente)
{
    FILE *buffer = fopen(ARCHIVOCLIENTEXABOGADO, "ab");
    stClienteXAbogado aux;
    if(buffer)
    {
        aux = cargarClienteXAbogado(idAbogado, idCliente);
        fwrite(&aux, sizeof(stClienteXAbogado), 1, buffer);
        fclose(buffer);
    }
}
//3. MOSTRAR CLIENTES ASIGNADOS A ABOGADO
void mostrarClientesDeAbogado(int idAbogado)
{
    FILE *buffer = fopen(ARCHIVOCLIENTEXABOGADO, "rb");
    stClienteXAbogado aux;
    stUsuario cliente;

    if(buffer)
    {
        while(fread(&aux, sizeof(stClienteXAbogado),1,buffer)>0)
        {
            if(aux.idAbogado == idAbogado)
            {
                cliente = arBuscarUsuarioId(aux.idCliente);
                mostrarUsuario(cliente);
            }
        }
        fclose(buffer);
    }
}
//4. SABER SI UN CLIENTE PERTENECE A UN ABOGADO
stUsuario esClienteDeAbogado(int idAbogado, int idCliente)
{
    FILE *buffer = fopen(ARCHIVOCLIENTEXABOGADO, "rb");
    stClienteXAbogado aux;
    stUsuario cliente;
    int flag = 0;
    if(buffer)
    {
        while(fread(&aux, sizeof(stClienteXAbogado),1,buffer)>0)
        {
            if(aux.idAbogado == idAbogado && aux.idCliente == idCliente)
            {
                flag = 1;
                cliente = arBuscarUsuarioId(idCliente);
            }
            fclose(buffer);
        }
    }
    if(flag == 0)
    {
        cliente.tipo = -1;
    }
    return cliente;
}
