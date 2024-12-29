#include "Causas.h"
#include "tools.h"
//----------------------------------//
//1. FUNCIONES BASICAS CAUSA
//----------------------------------//
//1. CARGAR CAUSA
stCausa cargarCausa (char dni [])
{
    stCausa causa;
    causa.estado = 0;
    int tribunal = 0;
    strcpy(causa.dni, dni);

    printf("Ingrese el numero de causa: \n");
    while(!scanf("%i", &causa.numDeCausa))
    {
        printf("Error. Caracteres no permitidos \n");
        printf("Ingrese el numero de causa: \n");
        scanf("%i", &causa.numDeCausa);
    }

    printf("Ingrese el nombre del juez: \n");
    fflush(stdin);
    gets(causa.juez);
    while(!validarStringNombre(causa.juez))
    {
        printf("Error. Solo caracteres permitidos \n");
        printf("Ingrese el nombre del juez: \n");
        fflush(stdin);
        gets(causa.juez);
    }

    printf("Seleccione un tribunal\n");
    printf("1. Tribunal Familiar, 2. Tribunal criminal, 3. Juzgado Civil y comercial\n");
    scanf("%i", &tribunal);
    switch(tribunal)
    {
    case 1:
        strcpy(causa.tribunal, "TRIBUNAL FAMILIAR");
        break;
    case 2:
        strcpy(causa.tribunal, "TRIBUNAL CRIMINAL");
        break;
    case 3:
        strcpy(causa.tribunal, "JUZGADO CIVIL Y COMERCIAL");
        break;
    default:
        tribunal = 0;
        printf("Opcion incorrecta \n");
        break;
    }


    printf("Ingrese el tipo de caso: \n");
    fflush(stdin);
    gets(causa.caso);
    while(!validarStringNombre(causa.caso))
    {
        printf("Error. Solo caracteres permitidos \n");
        printf("Ingrese el caso: \n");
        fflush(stdin);
        gets(causa.caso);
    }

    printf("Ingrese el dia de apertura de la causa: \n");
    while(!scanf("%i", &causa.fecha.dia))
    {
        printf("Error. Caracteres no permitidos \n");
        printf("Ingrese dia: \n");
        scanf("%i", &causa.fecha.dia);
    }
    while(!validarDiaFecha(causa.fecha.dia))
    {
        printf("Error. Dia no valido \n");
        printf("Ingrese dia: \n");
        scanf("%i", &causa.fecha.dia);
    }
    printf("Ingrese el mes de apertura de la causa: \n");

    while(!scanf("%i", &causa.fecha.mes))
    {
        printf("Error. Caracteres no permitidos \n");
        printf("Ingrese dia: \n");
        scanf("%i", &causa.fecha.dia);
    }
    while(!validarMesFecha(causa.fecha.mes))
    {
        printf("Error. Mes no valido \n");
        printf("Ingrese mes: \n");
        scanf("%i", &causa.fecha.mes);
    }
    printf("Ingrese el anio de apertura de la causa: \n");
    while(!scanf("%i", &causa.fecha.anio))
    {
        printf("Error. Caracteres no permitidos \n");
        printf("Ingrese anio: \n");
        scanf("%i", &causa.fecha.anio);
    }
    return causa;
}
//2. MOSTRAR CAUSA
void mostrarCausa(stCausa causa)
{
    printf("------------------------------------------------\n");
    printf("N° de causa: %i\n", causa.numDeCausa);
    printf("DNI del titular de la causa: %s \n", causa.dni);
    printf("Nombre del juez: %s\n", causa.juez);
    printf("Tribunal: %s \n", causa.tribunal);
    printf("Tipo de caso: %s\n", causa.caso);
    printf("Fecha de apertura de la causa: %i / %i / %i \n", causa.fecha.dia, causa.fecha.mes, causa.fecha.anio);
    printf("Estado de la causa: %i\n", causa.estado);
    printf("------------------------------------------------\n");
}
//3. MOSTRAR EL ARREGLO DE CAUSAS ACTIVAS
void mostrarArregloCausasActivas(stCausa causas[], int validos)
{
    int i;

    for (i=0; i<validos; i++)
    {
        if(causas[i].estado == 0)
            mostrarCausa(causas[i]);
    }
}
//4. ENCONTRAR MENOR NUMERO DE CAUSA
int encontrarMenorNumeroDeCausa(stCausa causas[], int pos, int validos)
{
    int menor = causas[pos].numDeCausa;
    int posMenor = pos;
    int i = pos+1;

    while(i<validos)
    {
        if(menor>causas[i].numDeCausa)
        {
            menor = causas[i].numDeCausa;
            posMenor = i;
        }
        i++;
    }
    return posMenor;
}
//5. ORDENAMIENTO POR SELECCION POR NUMERO DE CAUSA
void ordenarPorSeleccionCausa(stCausa causas[], int validos)
{
    stCausa aux;
    int i=0;
    int posMenor;

    while (i< validos-1)
    {
        posMenor = encontrarMenorNumeroDeCausa(causas, validos, i);
        aux = causas[posMenor];
        causas[posMenor]=causas[i];
        causas[i]=aux;
        i++;
    }
}
//6. INSERTAR
void insertarDatoJuez(stCausa A[], int i, stCausa B)
{
    while (i>=0 && B.juez<A[i].juez)
    {
        A[i+1]=A[i];
        i--;
    }
    A[i+1]=B;
}
//7. ORDENAMIENTO POR INSERCION - ALFABETICAMENTE
void ordenamientoPorInsercionDelArregloPorJuez(stCausa A[], int validos)
{
    int i=0;

    while (i<validos-1)
    {
        insertarDatoJuez(A, i,A[i+1]);
        i++;
    }
}

//8. CARGAR PILA CON NUMERO DE CAUSAS
void cargarNumDeCausaEnPila(Pila * A, stCausa B)
{
    apilar(A, B.numDeCausa);
}

//9. HISTORIAL NUMEROS DE CAUSAS CARGADAS
void historialNumDeCausas(Pila * A)
{
    printf("Causas cargadas: \n");
    mostrar(A);
    printf("Nota: En la base se encuentra la causa mas antigua, el tope la mas reciente\n");
}
//----------------------------------//
//2. FUNCIONES DE ARCHIVOS DE CAUSA
//----------------------------------//
//1. CARGAR CAUSA
void arCargarCausa(char dni[], Pila * A)
{
    stCausa aux;

    FILE * archi;
    archi = fopen (ARCHIVOCAUSAS, "ab" );

    if (archi != NULL)
    {
        aux=cargarCausa(dni);
        cargarNumDeCausaEnPila(A, aux);
        fwrite(&aux, sizeof(stCausa), 1, archi);
    }
    fclose(archi);
}
//2. MOSTRAR ARCHIVO DE CAUSAS
void arMostrarArchivoCausas(int estado)
{
    stCausa aux;
    FILE * archi;
    archi = fopen (ARCHIVOCAUSAS, "rb" );

    if (archi != NULL)
    {
        while(fread(&aux, sizeof(stCausa), 1, archi)>0)
        {
            if(aux.estado == estado)
            {
                mostrarCausa(aux);
            }
        }
        fclose(archi);
    }
}
//3. BUSCAR CAUSA POR DNI
stCausa arBuscarCausaSegunDni(char dniBuscado[])
{
    int flag=0;

    stCausa aux;
    FILE * archi;
    archi = fopen (ARCHIVOCAUSAS, "rb" );

    if (archi != NULL)
    {
        while(flag == 0 && fread(&aux, sizeof(stCausa), 1, archi)>0)
        {
            if (strcmp(aux.dni, dniBuscado)==0)
            {
                flag=1;
            }
        }
        fclose(archi);
    }
    if(flag == 0)
    {
        aux.estado = -1;
    }
    return aux;
}
//4. BUSCAR CAUSA POR NUMERO DE CAUSA
stCausa arBuscarCausaSegunNumDeCausa(int causaBuscada)
{
    int flag=0;

    stCausa aux;
    FILE * archi;
    archi = fopen (ARCHIVOCAUSAS, "rb" );

    if (archi != NULL)
    {
        while ((flag==0) && (fread(&aux, sizeof(stCausa), 1, archi)>0))
        {
            if (aux.numDeCausa == causaBuscada)
            {
                flag=1;
            }
        }
        fclose(archi);
    }
    if(flag == 0)
    {
        aux.estado = -1;
    }
    return aux;
}
//5. BUSCAR CAUSA POR JUEZ
stCausa arBuscarCausaSegunJuez(char juezBuscado[])
{
    int flag=0;

    stCausa aux;
    FILE * archi;
    archi = fopen (ARCHIVOCAUSAS, "rb" );

    if (archi != NULL)
    {
        while(flag == 0 && fread(&aux, sizeof(stCausa), 1, archi)>0)
        {
            if (strcmp(aux.juez, juezBuscado)==0)
            {
                flag=1;
            }
        }
        fclose(archi);
    }
    if(flag == 0)
    {
        aux.estado = -1;
    }
    return aux;
}
//6. MODIFICAR UN DATO DE LA CAUSA EN EL ARCHIVO
void arModficarDatoCausa(int causaBuscada)
{
    stCausa aux;
    int eleccion=0;
    int flag=0;
    FILE * archi;
    archi = fopen (ARCHIVOCAUSAS, "r+b" );

    if (archi != NULL)
    {
        while (flag==0 && (fread(&aux,sizeof(stCausa),1, archi)) > 0)
        {
            if (aux.numDeCausa == causaBuscada)
            {
                flag=1;
            }
        }
        if(flag == 1)
        {
            mostrarCausa(aux);

            printf("Que desea modificar? Ingrese el numero correspondiente: \n l-JUEZ\n 2-TRIBUNAL\n  ");
            scanf("%d", &eleccion);
            switch (eleccion)
            {
            case 1:
                printf("Ingrese el nuevo juez\n");
                fflush(stdin);
                gets(aux.juez);
                break;
            case 2:
                printf("Ingrese el nuevo tribunal\n");
                fflush(stdin);
                gets(aux.tribunal);
                break;
            default:
                printf("Opcion invalida \n");
            }

            fseek(archi,sizeof(stCausa)*(-1), SEEK_CUR);
            fwrite(&aux,sizeof(stCausa),1, archi);

            fclose(archi);
        }
    }
    if(flag == 0)
    {
        printf("Causa no encontrada \n");
    }
}
//7. DAR DE BAJA /  DAR DE ALTA UNA CAUSA
void arBajaAltaLogicaCausa(int numCausa, int opcion)
{
    stCausa aux;
    int flag = 0;


    FILE *buffer = fopen(ARCHIVOCAUSAS, "r+b");
    if(buffer)
    {
        while(flag == 0 && fread(&aux, sizeof(stCausa), 1, buffer)>0)
        {
            if(aux.numDeCausa == numCausa)
            {
                fseek(buffer, (-1)*sizeof(stCausa), SEEK_CUR);
                if(opcion == 1)
                {
                    aux.estado = 1;
                }
                else
                {
                    aux.estado = 0;
                }
                fwrite(&aux, sizeof(stCausa), 1, buffer);
                flag = 1;
            }
        }
        fclose(buffer);
    }
}
//8. PASAR EL ARCHIVO A UN ARRAY
int pasarArchivoAArregloCausas(stCausa A[], int dimension)
{
    int validos=0;
    FILE*archi;
    stCausa aux;

    archi=fopen(ARCHIVOCAUSAS, "rb");
    if (archi != NULL)
    {
        while (((fread(&aux,sizeof(stCausa), 1, archi))>0) && (validos<dimension))
        {
            A[validos]=aux;
            validos++;
        }
        fclose(archi);
    }
    return validos;
}

//----------------------------------//
//3. FUNCIONES CAUSAXCLIENTEYABOGADO
//----------------------------------//
//1. CARGAR ESTRUCTURA CAUSA
stCausaXClienteYAbogado cargarCausaXClyAb(int numCausa, int idCliente, int idAbogado)
{
    stCausaXClienteYAbogado aux;
    aux.numCausa = numCausa;
    aux.idCliente = idCliente;
    aux.idAbogado = idAbogado;
    return aux;
}
//2. CARGAR ARCHIVO ESTRUCTURA
void arCargarCausaXClyAb(int numCausa, int idCliente,int idAbogado)
{
    FILE *buffer = fopen(ARCHIVOCAUSAXCLIENTEYABOGADO, "ab");
    stCausaXClienteYAbogado aux;

    if(buffer)
    {
        aux = cargarCausaXClyAb(numCausa, idCliente, idAbogado);
        fwrite(&aux, sizeof(stCausaXClienteYAbogado), 1, buffer);
        fclose(buffer);
    }
}
//3. MOSTRAR CAUSAS DE CLIENTE
void mostrarCausasDeUsuario(int idUsuario)
{
    FILE *buffer = fopen(ARCHIVOCAUSAXCLIENTEYABOGADO, "rb");
    stCausaXClienteYAbogado aux;
    stCausa causa;

    if(buffer)
    {
        while(fread(&aux, sizeof(stCausaXClienteYAbogado),1,buffer)>0)
        {
            if(aux.idCliente == idUsuario || aux.idAbogado == idUsuario)
            {
                causa = arBuscarCausaSegunNumDeCausa(aux.numCausa);
                mostrarCausa(causa);
            }
        }
        fclose(buffer);
    }
}
//4. SABER SI UNA CAUSA PERTENECE A UN USUARIO
stCausa esCausaDeUsuario(int numCausa, int idUsuario)
{
    FILE *buffer = fopen(ARCHIVOCAUSAXCLIENTEYABOGADO, "rb");
    stCausaXClienteYAbogado aux;
    stCausa causa;
    int flag = 0;
    if(buffer)
    {
        while(fread(&aux, sizeof(stCausaXClienteYAbogado),1,buffer)>0)
        {
            if(aux.idCliente == idUsuario || aux.idAbogado == idUsuario)
            {
                flag = 1;
                causa = arBuscarCausaSegunNumDeCausa(numCausa);
            }
            fclose(buffer);
        }
        if(flag == 0)
        {
            causa.estado = -1;
        }
    }
    return causa;
}
