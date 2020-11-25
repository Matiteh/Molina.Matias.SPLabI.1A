#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include <time.h>

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 1;
    srand (time(NULL));
    LinkedList* listaBicicletas = ll_newLinkedList();
    do{
        printf("\n-------Parcial LABO------\n1. Cargar los datos de los empleados desde el archivo bicicletas.csv\n2. Listar Bicicleta\n3. Asignar Tiempos\n4. Filtrar por tipo\n5. Mostrar posiciones\n6. Guardar Posiciones en archivo\n7. Salir\nOpcion:");
        scanf("%d",&option);
        system("cls");
        switch(option)
        {
            case 1:
                controller_loadFromText("bicicletas.csv",listaBicicletas);
                break;
            case 2:
                controller_ListeBicicleta(listaBicicletas);
                system("pause");
                break;
            case 3:
                controller_setTiempo(listaBicicletas);
                break;
            case 4:
                controller_filtroTipo(listaBicicletas);
                break;
            case 5:
                controller_sorteBicicleta(listaBicicletas);
                break;
            case 6:
                controller_saveAsText("bicicletasPosiciones.csv",listaBicicletas);
                break;
            default:

                break;
        }
        system("cls");
    }while(option != 7);
    return 0;
}
