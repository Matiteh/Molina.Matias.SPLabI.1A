#ifndef eBicicleta_H_INCLUDED
#define eBicicleta_H_INCLUDED
typedef struct
{
    int id_bike;
    char nombre[50];
    char tipo[50];
    int tiempo;
}eBicicleta;

eBicicleta* eBicicleta_new();
eBicicleta* eBicicleta_newParametros(char* idStr,char* nombreStr,char* tiempoStr,char* tipoStr);
void eBicicleta_delete();

int eBicicleta_setId(eBicicleta* this,int id_bike);
int eBicicleta_getId(eBicicleta* this,int* id_bike);

int eBicicleta_setNombre(eBicicleta* this,char* nombre);
int eBicicleta_getNombre(eBicicleta* this,char* nombre);

int eBicicleta_setTiempo(eBicicleta* this,int tiempo);
int eBicicleta_getTiempo(eBicicleta* this,int* tiempo);

int eBicicleta_setTipo(eBicicleta* this,char* tipo);
int eBicicleta_getTipo(eBicicleta* this,char* tipo);

int eBicicleta_checkStr(char* ingreso);
int eBicicleta_IngresarDatos(eBicicleta* this,int opcion,char* mensaje);
int eBicicleta_list(eBicicleta* this);
int eBicicleta_chooseMod(eBicicleta* this, char* mensaje);
void eBicicleta_delete(eBicicleta* this);
int eBicicleta_compareByType(void *e1, void *e2);
int bicicleta_tiempoRandom(void* tiempoA );

int bicicleta_filtroBMX(void* filtroA );
int bicicleta_filtroMTB(void* filtroA );
int bicicleta_filtroPASEO(void* filtroA );
int bicicleta_filtroPLAYERA(void* filtroA );

#endif // eBicicleta_H_INCLUDED
