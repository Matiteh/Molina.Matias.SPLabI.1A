#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "string.h"
#include "Employee.h"
#include <time.h>
eBicicleta* eBicicleta_new(){
    eBicicleta* auxeBicicleta;
    auxeBicicleta= (eBicicleta*) malloc(sizeof(eBicicleta));
    return auxeBicicleta;
}
eBicicleta* eBicicleta_newParametros(char* idStr,char* nombreStr,char* tipoStr,char* tiempoStr){
    eBicicleta* auxeBicicleta=eBicicleta_new();

    eBicicleta_setId(auxeBicicleta,atoi(idStr));
    eBicicleta_setNombre(auxeBicicleta,nombreStr);
    eBicicleta_setTiempo(auxeBicicleta,atoi(tiempoStr));
    eBicicleta_setTipo(auxeBicicleta,tipoStr);

    return auxeBicicleta;
}
int eBicicleta_setId(eBicicleta* this,int id_bike){
    int verificacion= -1;
    if(this!=NULL){
        this->id_bike=id_bike;
        verificacion=1;
    }
    return verificacion;
}
int eBicicleta_getId(eBicicleta* this,int* id_bike){
    int verificacion= -1;
    if(this!=NULL){
        *id_bike=this->id_bike;
        verificacion=1;
    }
    return verificacion;
}
int eBicicleta_setNombre(eBicicleta* this,char* nombre){
    int verificacion= -1;
    if(this!=NULL){
        strcpy(this->nombre,nombre);
        verificacion=1;
    }
    return verificacion;
}
int eBicicleta_getNombre(eBicicleta* this,char* nombre){
    int verificacion= -1;
    if(this!=NULL){
         strcpy(nombre,this->nombre);
        verificacion=1;
    }
    return verificacion;
}
int eBicicleta_setTiempo(eBicicleta* this,int tiempo){
    int verificacion= -1;
    if(this!=NULL){
        this->tiempo=tiempo;
        verificacion=1;
    }
    return verificacion;
}
int eBicicleta_getTiempo(eBicicleta* this,int* tiempo){
    int verificacion= -1;
    if(this!=NULL){
        *tiempo=this->tiempo;
        verificacion=1;
    }
    return verificacion;
}
int eBicicleta_setTipo(eBicicleta* this,char* tipo){
    int verificacion= -1;
    if(this!=NULL){
        strcpy(this->tipo,tipo);
        verificacion=1;
    }
    return verificacion;
}
int eBicicleta_getTipo(eBicicleta* this,char* tipo){
    int verificacion= -1;
    if(this!=NULL){
        strcpy(tipo,this->tipo);
        verificacion=1;
    }
    return verificacion;
}
int eBicicleta_checkStr(char* ingreso)
{
    int i;
    int flag=1;
    int len;
    len=strlen(ingreso);
    for(i=0;i<len;i++)
    {
        if(ingreso[i]=='\0')
        {

            break;

        }else{
            if(isdigit(ingreso[i])==0)
            {
                //printf("%d",flag);
                flag=isdigit(ingreso[i]);
                break;
            }
        }

    }
    return flag;
}
/*int eBicicleta_IngresarDatos(eBicicleta* this,int opcion,char* mensaje)
{
    char ingreso[128];

    puts(mensaje);
    fflush(stdin);
    switch(opcion)
    {
    case 1:
        scanf("%s",ingreso);

        ingreso[0]=toupper(ingreso[0]);

        eBicicleta_setNombre(this, ingreso);

        break;
    case 2:
        scanf("%s",ingreso);
        while(eBicicleta_checkStr(ingreso)==0)
        {
            printf("ERROR:");
            scanf("%s",ingreso);
        }
        eBicicleta_setHorasTrabajadas(this,atoi(ingreso));
        break;
    case 3:
        scanf("%s",ingreso);
        while(eBicicleta_checkStr(ingreso)==0)
        {
            printf("ERROR:");
            scanf("%s",ingreso);
        }
        eBicicleta_setSueldo(this,atoi(ingreso));
        break;
    default:
        printf("\n\nError modificacion\n");
        system("pause");

        break;
    }
    return 0;
}*/
int eBicicleta_list(eBicicleta* this)
{

    printf("%5d %20s %20s        %10d\n",this->id_bike,this->nombre,this->tipo,this->tiempo);

    return 1;
}
/*int eBicicleta_chooseMod(eBicicleta* this, char* mensaje)
{
    char mensajeMod[3][30]={"\nIngrese nombre:","\nIngrese Horas trabajadas:","\nIngrese salario:"};
    int opcion;

    puts(mensaje);
    scanf("%d",&opcion);

    system("cls");
    if(opcion>0&&opcion<=3)
    {
        eBicicleta_IngresarDatos(this,opcion,mensajeMod[opcion-1]);
    }else
    {
        eBicicleta_IngresarDatos(this,-1," ");
    }


    return 1;
}*/
void eBicicleta_delete(eBicicleta* this)
{
    free(this);

}
int eBicicleta_compareByType(void *e1, void *e2)
{
    eBicicleta* aux1=e1;
    eBicicleta* aux2=e2;
    int aux=stricmp(aux1->tipo,aux2->tipo);
    if(aux==0){
        if(aux1->tiempo>aux2->tiempo){
            aux=1;
        }else if(aux1->tiempo<aux2->tiempo){
            aux=-1;
        }
    }

    return aux;
}
int bicicleta_tiempoRandom(void* tiempoA ){
    eBicicleta* auxeBicicleta=tiempoA;
    int aux=0;
    int auxA=0;
    if(auxeBicicleta!=NULL){
        auxA=rand()%(71)+50;
        auxeBicicleta->tiempo=auxA;
        aux=1;
    }
    return aux;
}
int bicicleta_filtroBMX(void* filtroA ){
    eBicicleta* auxeBicicleta=filtroA;
    char auxF[10];
    int aux=0;

    if(auxeBicicleta!=NULL){
        eBicicleta_getTipo(auxeBicicleta,auxF);
        aux=stricmp(auxF,"BMX");
    }
    return aux;
}
int bicicleta_filtroMTB(void* filtroA ){
    eBicicleta* auxeBicicleta=filtroA;
    char auxF[10];
    int aux=0;

    if(auxeBicicleta!=NULL){
        eBicicleta_getTipo(auxeBicicleta,auxF);
        aux=stricmp(auxF,"MTB");
    }
    return aux;
}
int bicicleta_filtroPASEO(void* filtroA ){
    eBicicleta* auxeBicicleta=filtroA;
    char auxF[10];
    int aux=0;

    if(auxeBicicleta!=NULL){
        eBicicleta_getTipo(auxeBicicleta,auxF);
        aux=stricmp(auxF,"PASEO");
    }
    return aux;
}
int bicicleta_filtroPLAYERA(void* filtroA ){
    eBicicleta* auxeBicicleta=filtroA;
    char auxF[10];
    int aux=0;

    if(auxeBicicleta!=NULL){
        eBicicleta_getTipo(auxeBicicleta,auxF);
        aux=stricmp(auxF,"PLAYERA");
    }
    return aux;
}
