#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListeBicicleta LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListeBicicleta)
{
    FILE* pArchivo;

    pArchivo=fopen(path, "r");
    if(pArchivo!=NULL){
        parser_eBicicletaFromText(pArchivo, pArrayListeBicicleta);
    }else{
        printf("El archivo no existe\n");
        system("pause");
    }
    fclose(pArchivo);
    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListeBicicleta LinkedList*
 * \return int
 *
 *
int controller_loadFromBinary(char* path , LinkedList* pArrayListeBicicleta,int* idMax, char* pId)
{
    FILE* aux;
    FILE* pArchivo;

    pArchivo=fopen(path, "rb");
    aux=fopen(pId, "rb");
    if(pArchivo!=NULL && aux!=NULL){
        parser_eBicicletaFromBinary(pArchivo, pArrayListeBicicleta);
        fscanf(aux,"%d",idMax);
    }else{
        printf("El archivo no existe\n");
        system("pause");
    }
    fclose(pArchivo);
    fclose(aux);
    return 1;
}

** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListeBicicleta LinkedList*
 * \return int
 *
 *
int controller_addeBicicleta(LinkedList* pArrayListeBicicleta, int* idMax)
{
    eBicicleta* auxeBicicleta=eBicicleta_new();

    *idMax=*idMax+1;
    if(pArrayListeBicicleta!=NULL){
        eBicicleta_setId(auxeBicicleta,*idMax);
        eBicicleta_IngresarDatos(auxeBicicleta,1,"Ingrese Nombre:");
        eBicicleta_IngresarDatos(auxeBicicleta,2,"Ingrese Horas Trabajadas:");
        eBicicleta_IngresarDatos(auxeBicicleta,3,"Ingrese Salario:");
        ll_add(pArrayListeBicicleta,auxeBicicleta);
    }
    return 1;
}

** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListeBicicleta LinkedList*
 * \return int
 *
 *
int controller_editeBicicleta(LinkedList* pArrayListeBicicleta)
{
    int auxId;
    int flag=-1;
    eBicicleta* auxeBicicleta;
    if(pArrayListeBicicleta!=NULL){
        controller_ListeBicicleta(pArrayListeBicicleta);
        printf("Ingrese ID del empleado a modificar: ");
        scanf("%d",&auxId);
        for(int i=0;i<ll_len(pArrayListeBicicleta);i++){
            auxeBicicleta=ll_get(pArrayListeBicicleta,i);
            if(auxId==auxeBicicleta->id){
                flag=1;
                break;
            }
        }
        system("cls");
        if(flag==1){
            eBicicleta_chooseMod(auxeBicicleta,"1. Cambiar Nombre\n2. Cambiar Horas Trabajadas\n3. Cambiar Salario");
        }else{
            printf("El Id ingresado no existe");
        }
    }
    return 1;
}

** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListeBicicleta LinkedList*
 * \return int
 *
 *
int controller_removeeBicicleta(LinkedList* pArrayListeBicicleta)
{
    int auxI;
    int auxId;
    int flag=-1;
    eBicicleta* auxeBicicleta;
    if(pArrayListeBicicleta!=NULL){
        controller_ListeBicicleta(pArrayListeBicicleta);
        printf("Ingrese ID del empleado a Eliminar: ");
        scanf("%d",&auxId);
        for(int i=0;i<ll_len(pArrayListeBicicleta);i++){
            auxeBicicleta=ll_get(pArrayListeBicicleta,i);
            auxI=ll_indexOf(pArrayListeBicicleta,auxeBicicleta);
            if(auxId==auxeBicicleta->id){
                flag=1;
                break;
            }
        }
        system("cls");
        if(flag==1){
            ll_remove(pArrayListeBicicleta,auxI);
            eBicicleta_delete(auxeBicicleta);

        }else{
            printf("El Id ingresado no existe");
        }
    }

    return 1;
}

** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListeBicicleta LinkedList*
 * \return int
 *
 */
int controller_ListeBicicleta(LinkedList* pArrayListeBicicleta)
{
    eBicicleta* auxeBicicleta;
    if(pArrayListeBicicleta!=NULL){
        printf("   |Id|           |Nombre|     |Tipo|         |Tiempo|\n");
        for(int i=0;i<ll_len(pArrayListeBicicleta);i++){
            auxeBicicleta=ll_get(pArrayListeBicicleta, i);
            eBicicleta_list(auxeBicicleta);
        }
    }
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListeBicicleta LinkedList*
 * \return int
 *
 */
int controller_sorteBicicleta(LinkedList* pArrayListeBicicleta)
{
    ll_sort(pArrayListeBicicleta,eBicicleta_compareByType,1);
    controller_ListeBicicleta(pArrayListeBicicleta);
    system("pause");
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListeBicicleta LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListeBicicleta)
{
    int auxS;
    int auxI;
    char auxH[50];
    char auxN[50];
    eBicicleta* auxeBicicleta;
    FILE* pArchivo;

    pArchivo=fopen(path,"w");

    if(pArchivo!=NULL){
        for(int i=0;i<ll_len(pArrayListeBicicleta);i++){
            auxeBicicleta=(eBicicleta*)ll_get(pArrayListeBicicleta, i);

            eBicicleta_getId(auxeBicicleta, &auxI);
            eBicicleta_getTiempo(auxeBicicleta, &auxS);
            eBicicleta_getTipo(auxeBicicleta, auxH);
            eBicicleta_getNombre(auxeBicicleta, auxN);

            fprintf(pArchivo,"%d,%s,%s,%d\n",auxI,auxN,auxH,auxS);
        }
        fclose(pArchivo);
    }else{
        printf("\n\nERROR MEMORIA\n");

        system("pause");
    }


    return 1;
}
/*
** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListeBicicleta LinkedList*
 * \return int
 *
 *
int controller_saveAsBinary(char* path , LinkedList* pArrayListeBicicleta,int* idMax, char* pId)
{
    int auxS;
    int auxI;
    int auxH;
    char auxN[50];
    eBicicleta* auxeBicicleta;
    FILE* pArchivo;
    FILE* aux;

    pArchivo=fopen(path,"wb");
    aux=fopen(pId,"wb");

    if(aux!=NULL&&pArchivo!=NULL){
        fprintf(aux,"%d",*idMax);
        //fprintf(pArchivo,"%[^,],%[^,],%[^,],%[^\n]",auxI,auxN,auxH,auxS);
        for(int i=0;i<ll_len(pArrayListeBicicleta);i++){
            auxeBicicleta=(eBicicleta*)ll_get(pArrayListeBicicleta, i);

            eBicicleta_getId(auxeBicicleta, &auxI);
            eBicicleta_getSueldo(auxeBicicleta, &auxS);
            eBicicleta_getHorasTrabajadas(auxeBicicleta, &auxH);
            eBicicleta_getNombre(auxeBicicleta, auxN);

            fprintf(pArchivo,"%d,%s,%d,%d\n",auxI,auxN,auxH,auxS);
        }
        fclose(pArchivo);
        fclose(aux);
    }else{
        printf("\n\nERROR MEMORIA\n");
        system("pause");
    }
    return 1;
}
*/
void controller_setTiempo(LinkedList* pArrayListeBicicleta){
    ll_map(pArrayListeBicicleta,bicicleta_tiempoRandom);
}
void controller_filtroTipo (LinkedList* pArrayListeBicicleta){
    int opcion;
    printf("Seleccione tipo de moto a filtrar\n1. BMX\n2. MTB\n3. PLAYERA\n4. PASEO\nOpcion: ");
    scanf("%d", &opcion);
    switch(opcion)
        {
            case 1:
                controller_saveAsText("BMX.csv",ll_filter(pArrayListeBicicleta,bicicleta_filtroBMX));
                break;
            case 2:
                controller_saveAsText("MTB.csv",ll_filter(pArrayListeBicicleta,bicicleta_filtroMTB));
                break;
            case 3:
                controller_saveAsText("PLAYERA.csv",ll_filter(pArrayListeBicicleta,bicicleta_filtroPLAYERA));
                break;
            case 4:
                controller_saveAsText("PASEO.csv",ll_filter(pArrayListeBicicleta,bicicleta_filtroPASEO));
                break;
            default:
                break;
        }
}
