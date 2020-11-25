#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListeBicicleta LinkedList*
 * \return int
 *
 */
int parser_eBicicletaFromText(FILE* pFile , LinkedList* pArrayListeBicicleta)
{
    int r;
    char auxI[20];
    char auxN[50];
    char auxH[20];
    char auxS[20];

    eBicicleta* aux;

    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",auxI, auxN, auxH, auxS);
    do{
        r=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",auxI, auxN, auxH, auxS);
        if(r==4){
            aux=eBicicleta_newParametros(auxI,auxN,auxH,auxS);
            ll_add(pArrayListeBicicleta,aux);
        }
    }while(!feof(pFile));
    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListeBicicleta LinkedList*
 * \return int
 *
 */
/*int parser_eBicicletaFromBinary(FILE* pFile , LinkedList* pArrayListeBicicleta)
{
    int r;
    char auxI[20];
    char auxN[50];
    char auxH[20];
    char auxS[20];

    eBicicleta* aux;

    //fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",auxI, auxN, auxH, auxS);
    do{
        r=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",auxI, auxN, auxH, auxS);
        if(r==4){
            aux=eBicicleta_newParametros(auxI,auxN,auxH,auxS);
            ll_add(pArrayListeBicicleta,aux);
        }
    }while(!feof(pFile));
    return 1;
}
*/
