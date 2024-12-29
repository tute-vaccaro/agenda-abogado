#include "citas.h"
#include "usuario.h"
//------------------------------------//
//FUNCIONES BASICAS DE CITA
//------------------------------------//
//1. CARGAR CITA
stCita cargarCita(char dniAbogado[], char dniCliente[])
{
    stCita cita;
    int lugarCita = 0;
    int horaCita = 0;
    cita.estado = 0;
    strcpy(cita.dniAbogado, dniAbogado);
    strcpy(cita.dniCliente, dniCliente);

    printf("Que dia es la cita? Ingrese numeros\n");
    scanf("%i", &cita.fecha.dia);
    while(!validarDiaFecha(cita.fecha.dia))
    {
        printf("Error \n");
        printf("Que dia es la cita?\n");
        scanf("%i", &cita.fecha.dia);
    }

    while(horaCita == 0)
    {
        printf("A que hora es la cita?\n");
        printf("1. 8:00 hs\n");
        printf("2. 8:30 hs\n");
        printf("3. 9:00 hs\n");
        printf("4. 9:30 hs\n");
        printf("5. 10:00 hs\n");
        printf("6. 10:30 hs\n");
        printf("7. 11:00 hs\n");
        printf("8. 11:30 hs\n");
        printf("9. 12:00 hs\n");
        printf("10. 12:30 hs\n");
        printf("11. 13:00 hs\n");
        printf("12. 13:30 hs\n");
        printf("13. 14:00 hs\n");
        scanf("%i", &horaCita);
        switch(horaCita)
        {
        case 1:
            strcpy(cita.fecha.hora, "08:00");
            break;
        case 2:
            strcpy(cita.fecha.hora, "08:30");
            break;
        case 3:
            strcpy(cita.fecha.hora, "09:00");
            break;
        case 4:
            strcpy(cita.fecha.hora, "09:30");
            break;
        case 5:
            strcpy(cita.fecha.hora, "10:00");
            break;
        case 6:
            strcpy(cita.fecha.hora, "10:30");
            break;
        case 7:
            strcpy(cita.fecha.hora, "11:00");
            break;
        case 8:
            strcpy(cita.fecha.hora, "11:30");
            break;
        case 9:
            strcpy(cita.fecha.hora, "12:00");
            break;
        case 10:
            strcpy(cita.fecha.hora, "12:30");
            break;
        case 11:
            strcpy(cita.fecha.hora, "13:00");
            break;
        case 12:
            strcpy(cita.fecha.hora, "13:30");
            break;
        case 13:
            strcpy(cita.fecha.hora, "14:00");
            break;
        default:
            horaCita = 0;
            printf("Opcion incorrecta \n");
            break;
        }
    }
    printf("Ingrese mes de la cita con numeros\n");
    scanf("%i", &cita.fecha.mes);
    while(!validarMesFecha(cita.fecha.mes))
    {
        printf("Error. \n");
        printf("Ingrese mes de la cita: \n");
        scanf("%i", &cita.fecha.mes);
    }

    while(lugarCita == 0)
    {
        printf("En que lugar es la cita?\n");
        printf("1. Tribunal Familiar, 2. Tribunal criminal, 3. Juzgado Civil y comercial 4. Estudio Juridico\n");
        scanf("%i", &lugarCita);
        switch(lugarCita)
        {
        case 1:
            strcpy(cita.lugar, "TRIBUNAL FAMILIAR");
            lugarCita = 1;
            break;
        case 2:
            strcpy(cita.lugar, "TRIBUNAL CRIMINAL");
            lugarCita = 1;
            break;
        case 3:
            strcpy(cita.lugar, "JUZGADO CIVIL Y COMERCIAL");
            lugarCita = 1;
            break;
        case 4:
            strcpy(cita.lugar, "ESTUDIO JURIDICO");
            lugarCita = 1;
            break;
        default:
            lugarCita = 0;
            printf("Opcion incorrecta \n");
            break;
        }
    }

    return cita;
}
//2. MOSTRAR CITA
void verCita(stCita cita)
{
    stUsuario cliente;
    stUsuario abogado;
    abogado = arBuscarUsuarioDni(cita.dniAbogado);
    cliente = arBuscarUsuarioDni(cita.dniCliente);
    printf("Nombre del Cliente: %s %s\n", cliente.persona.name.nombre, cliente.persona.name.apellido);
    printf("Nombre del Abogado: %s %s\n", abogado.persona.name.nombre, abogado.persona.name.apellido);
    printf("Su cita es el %i / %i / 2023  a las %s \n", cita.fecha.dia, cita.fecha.mes, cita.fecha.hora);
    printf("Lugar de la cita: %s \n", cita.lugar);
}
//3. INSERTAR CITA SEGUN FECHA
void insertarCitaSegunFecha(stCita A[], int i, stCita B)
{

    while (i>=0)
    {
        if (B.fecha.mes<A[i].fecha.mes)
        {
            A[i+1]=A[i];
            i--;
        }
        else if (B.fecha.mes==A[i].fecha.mes)
        {
            if (B.fecha.dia<A[i].fecha.dia)
            {
                A[i+1]=A[i];
                i--;
            }
        }
    }
    A[i+1]=B;
}
//4. ORDENAMIENTO CITA SEGUN FECHA
void ordenamientoPorInsercionDelArregloPorFecha(stCita A[], int validos)
{
    int i=0;

    while (i<validos-1)
    {
        insertarCitaSegunFecha(A, i,A[i+1]);
        i++;
    }
}
//5. ENCONTRAR MENOR LUGAR
int encontrarMenorLugar(stCita cita[], int pos, int validos)
{
    char menor[MAXC];
    strcpy(menor, cita[pos].lugar);
    int posMenor = pos;
    int i = pos+1;

    while(i<validos)
    {
        if(strcmp(menor,cita[i].lugar)>0)
        {
            strcpy (menor,cita[i].lugar);
            posMenor = i;
        }
        i++;
    }
    return posMenor;
}
//7. ORDENAMIENTO POR SELECCION POR LUGAR
void ordenarPorSeleccionCita(stCita citas[], int validos)
{
    stCita aux;
    int i=0;
    int posMenor;

    while (i< validos-1)
    {
        posMenor = encontrarMenorLugar(citas, validos, i);
        aux = citas[posMenor];
        citas[posMenor]=citas[i];
        citas[i]=aux;
        i++;
    }
}
//8. MOSTRAR CITAS SEGUN LUGAR
void mostrarCitaSegunLugar(stCita citas[], int validos, char lugar[MAXC])
{
    int i = 0;
    while(i<validos)
    {
        if(strcpy(citas[i].lugar, lugar)==0)
        {
            verCita(citas[i]);
        }
        validos++;
    }
}
//------------------------------------//
//FUNCIONES DE ARCHIVO DE CITA
//------------------------------------//
//1. CARGAR ARCHIVO CON CITA
void cargarCitaArchivo(char dniAbogado[], char dniCliente[])
{
    stCita cita;
    FILE* archi;
    archi=fopen(ARCHIVOCITA, "ab");

    if(archi)
    {
        cita = cargarCita(dniAbogado, dniCliente);
        fwrite(&cita, sizeof(stCita), 1, archi);
        fclose(archi);
    }
}
//2. MOSTRAR ARCHIVO DE CITAS SEGUN ALTA O BAJA
void arVerCitas()
{
    stCita cita;
    FILE* archi = fopen(ARCHIVOCITA, "rb");
    if (archi)
    {
        while (fread(&cita, sizeof(stCita),1, archi)>0)
        {
            if(cita.estado==0)
            {
                verCita(cita);
            }
        }
        fclose(archi);
    }
}
//3. DAR DE BAJA UNA CITA
stCita arBajaLogicaCita(char dniCliente[])
{
    FILE* archi=fopen(ARCHIVOCITA, "r+b");
    stCita cita;
    int flag = 0;
    if (archi)
    {
        while(flag == 0 && fread(&cita, sizeof(cita),1, archi)>0)
        {
            if(strcmp(cita.dniCliente, dniCliente)==0)
            {
                cita.estado = 1;
                flag = 1;
                fseek(archi, sizeof(stCita) * (-1), SEEK_CUR);
                fwrite(&cita, sizeof(stCita),1,archi);
            }
        }
        fclose(archi);
    }
    if(flag == 0)
    {
        cita.estado = -1;
    }
    return cita;
}
//4. MODIFICAR CITA EXISTENTE
void arModificarCita(char DNIBuscado[])
{
    int lugarCita, horaCita;
    int eleccion;
    char seguir='s';
    stCita aux;
    int flag=0;
    FILE * archi;
    archi = fopen (ARCHIVOCITA, "r+b" );
    if (archi != NULL)
    {
        while (flag==0 && (fread(&aux, sizeof(stCita), 1, archi)) > 0)
        {
            if (strcmp(aux.dniCliente, DNIBuscado)==0)
            {
                flag=1;
            }
        }
        if(flag == 1)
        {
            verCita(aux);
            while (seguir=='s')
            {
                printf("Que dato quiere modificar?");
                printf("Dni del cliente: 1 \n Dia de la cita: 2 \n Hora de la cita: 3 \n Mes de la cita: 4 \n Lugar de la cita: 5 \n");
                scanf("%d", &eleccion);
                switch(eleccion)
                {
                case 1:
                    printf("Ingrese el nuevo dni \n");
                    fflush(stdin);
                    gets(aux.dniCliente);
                    break;
                case 2:
                    printf("Que dia es la cita?\n");
                    scanf("%i", &aux.fecha.dia);
                    while(!validarDiaFecha(aux.fecha.dia))
                    {
                        printf("Error \n");
                        printf("Que dia es la cita?\n");
                        scanf("%i", &aux.fecha.dia);
                    }
                    break;
                case 3:
                    while(horaCita == 0)
                    {
                        printf("A que hora es la cita?\n");
                        printf("1. 8:00 hs\n");
                        printf("2. 8:30 hs\n");
                        printf("3. 9:00 hs\n");
                        printf("4. 9:30 hs\n");
                        printf("5. 10:00 hs\n");
                        printf("6. 10:30 hs\n");
                        printf("7. 11:00 hs\n");
                        printf("8. 11:30 hs\n");
                        printf("9. 12:00 hs\n");
                        printf("10. 12:30 hs\n");
                        printf("11. 13:00 hs\n");
                        printf("12. 13:30 hs\n");
                        printf("13. 14:00 hs\n");
                        scanf("%i", &horaCita);
                        switch(horaCita)
                        {
                        case 1:
                            strcpy(aux.fecha.hora, "08:00");
                            break;
                        case 2:
                            strcpy(aux.fecha.hora, "08:30");
                            break;
                        case 3:
                            strcpy(aux.fecha.hora, "09:00");
                            break;
                        case 4:
                            strcpy(aux.fecha.hora, "09:30");
                            break;
                        case 5:
                            strcpy(aux.fecha.hora, "10:00");
                            break;
                        case 6:
                            strcpy(aux.fecha.hora, "10:30");
                            break;
                        case 7:
                            strcpy(aux.fecha.hora, "11:00");
                            break;
                        case 8:
                            strcpy(aux.fecha.hora, "11:30");
                            break;
                        case 9:
                            strcpy(aux.fecha.hora, "12:00");
                            break;
                        case 10:
                            strcpy(aux.fecha.hora, "12:30");
                            break;
                        case 11:
                            strcpy(aux.fecha.hora, "13:00");
                            break;
                        case 12:
                            strcpy(aux.fecha.hora, "13:30");
                            break;
                        case 13:
                            strcpy(aux.fecha.hora, "14:00");
                            break;
                        default:
                            horaCita = 0;
                            printf("Opcion incorrecta \n");
                            break;
                        }
                    }
                    break;
                case 4:
                    printf("Ingrese mes de la cita: \n");
                    scanf("%i", &aux.fecha.mes);
                    while(!validarMesFecha(aux.fecha.mes))
                    {
                        printf("Error. \n");
                        printf("Ingrese mes de la cita: \n");
                        scanf("%i", &aux.fecha.mes);
                    }
                    break;
                case 5:
                    while(lugarCita == 0)
                    {
                        printf("En que lugar es la cita?\n");
                        printf("1. Tribunal Familiar, 2. Tribunal criminal, 3. Juzgado Civil y comercial 4. Estudio Juridico\n");
                        scanf("%i", &lugarCita);
                        switch(lugarCita)
                        {
                        case 1:
                            strcpy(aux.lugar, "TRIBUNAL FAMILIAR");
                            lugarCita = 1;
                            break;
                        case 2:
                            strcpy(aux.lugar, "TRIBUNAL CRIMINAL");
                            lugarCita = 1;
                            break;
                        case 3:
                            strcpy(aux.lugar, "JUZGADO CIVIL Y COMERCIAL");
                            lugarCita = 1;
                            break;
                        case 4:
                            strcpy(aux.lugar, "ESTUDIO JURIDICO");
                            lugarCita = 1;
                            break;
                        default:
                            lugarCita = 0;
                            printf("Opcion incorrecta \n");
                            break;
                        }
                    }
                    break;
                default:
                    printf("esa opcion no existe \n");
                    break;

                    printf("desea modificar otro dato? s/n \n");
                    fflush(stdin);
                    scanf("%c",&seguir);
                }
            }
            fseek(archi,sizeof(stCita)*(-1), SEEK_CUR);
            fwrite(&aux,sizeof(stCita),1, archi);
        }
        fclose(archi);
    }
    if(flag == 0)
    {
        printf("Cliente no encontrado en el registro de citas \n");
    }
}
//5. PASAR ARCHIVO A ARREGLO
int pasarArchivoAArregloCita(stCita A[], int dimension)
{
    int validos=0;
    FILE*archi;
    stCita aux;

    archi=fopen(ARCHIVOCITA, "rb");
    if (archi != NULL)
    {
        while ((fread(&aux,sizeof(stCita), 1, archi)>0) && (validos<dimension))
        {
            A[validos]=aux;
            validos++;
        }
        fclose(archi);
    }
    return validos;
}
//6.VER CITAS DE UN USUARIO
void verCitasUsuario(char dniUsuario[], stCita citas[], int validos)
{
    int i = 0;
    while(i<validos)
    {
        if(strcmp(citas[i].dniAbogado, dniUsuario)==0 || strcmp(citas[i].dniCliente, dniUsuario)==0)
        {
            if(citas[i].estado == 0)
            {
                verCita(citas[i]);
            }
        }
        i++;
    }
}
//7. BUSCAR CITA POR DNI
stCita buscarCitaPorDni(char dniUsuario[])
{
    stCita cita;
    int flag = 0;
    FILE * buffer = fopen(ARCHIVOCITA, "rb");
    if(buffer)
    {
        while(flag == 0 && fread(&cita, sizeof(stCita), 1, buffer)>0)
        {
            if(strcmp(cita.dniAbogado,dniUsuario)==0 || strcmp(cita.dniCliente, dniUsuario)==0)
            {
                flag=1;
            }
        }
        fclose(buffer);
    }
    if(flag == 0)
    {
        cita.estado = -1;
    }
    return cita;
}
