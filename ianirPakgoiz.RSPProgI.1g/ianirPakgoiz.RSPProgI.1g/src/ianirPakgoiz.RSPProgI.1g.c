#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char marca[20];
    int tipo;
    float peso;
} eVehiculo;

int veiculoSetMarca(eVehiculo* this,char* marca);
int vehiculo_setId(eVehiculo* this,int id);
int vehiculo_setPeso(eVehiculo* this,float peso);
int vehiculo_setTipo(eVehiculo* this,int tipo);
eVehiculo* vehiculo_new();
eVehiculo* vehiculo_nuevoParametros(int id,char* marca,int tipo, float peso);

int guardarTexto(char* path, eVehiculo* vehiculo);

int guardarBinario(char* path, eVehiculo* vehiculo);

int main()
{
	setbuf(stdout, NULL);

    eVehiculo* automovil = vehiculo_nuevoParametros(22, "Chevrolet", 51, 1732);
    printf("%d\n", automovil->id);
    printf("%s\n", automovil->marca);
    printf("%d\n", automovil->tipo);
    printf("%f\n", automovil->peso);

    guardarTexto("Auto", automovil);
    guardarBinario("AutoBin", automovil);
    //na ni me salió lo de binario

    return 0;
}

int guardarTexto(char* path, eVehiculo* vehiculo)
{
    int retorno=0;
    FILE* f = NULL;
    f = fopen(path, "w");
    if(f!= NULL && vehiculo != NULL)
    {
        int cant = fprintf(f, "%d,%s,%d,%f", vehiculo->id, vehiculo->marca,vehiculo->tipo,vehiculo->peso);
        if(cant <=0)
        {
            printf("Error\n");
        }
        retorno=1;
    }
    fclose(f);
    return retorno;
}



int veiculoSetMarca(eVehiculo* this,char* marca)
{
    int todoOk=1;
    if(this!=NULL && marca!=NULL && strlen(marca)<20)
    {
        strcpy(this->marca, marca);
        todoOk=0;
    }

    return todoOk;
}
int vehiculo_setId(eVehiculo* this,int id)
{
    int todoOk=1;
    if(this!=NULL && id >0)
    {
        this->id=id;
        todoOk=0;
    }

    return todoOk;
}

int vehiculo_setTipo(eVehiculo* this,int tipo)
{
    int todoOk=1;
    if(this!=NULL && tipo >0)
    {
        this->tipo=tipo;
        todoOk=0;
    }

    return todoOk;
}


int vehiculo_setPeso(eVehiculo* this,float peso)
{
    int todoOk=1;
    if(this!=NULL && peso >0)
    {
        this->peso=peso;
        todoOk=0;
    }

    return todoOk;
}


eVehiculo* vehiculo_new()
{
    eVehiculo* p =(eVehiculo*) malloc(sizeof(eVehiculo));
    if(p!= NULL)
    {
        p->id=0;
        p->peso=0;
        p->tipo=0;
        strcpy(p->marca, " ");
    }
    return p;
}

eVehiculo* vehiculo_nuevoParametros(int id,char* marca,int tipo, float peso)
{
    eVehiculo* p = vehiculo_new();
    if(p!= NULL)
    {
        if(!(vehiculo_setId(p, id)==0 && vehiculo_setTipo(p, tipo)==0 && veiculoSetMarca(p, marca)== 0&& vehiculo_setPeso(p, peso)==0))
        {
            p = NULL;
        }
    }
    return p;
}

int guardarBinario(char* path, eVehiculo* vehiculo)
{
    int retorno=0;
    FILE* f = NULL;
    f = fopen(path, "wb");
    if(f!= NULL && vehiculo != NULL)
    {
        if(fwrite(vehiculo, sizeof(eVehiculo), 1, f) != 1)
        {
            printf("Hubo un error\n");
        }
        retorno=1;
    }
    return retorno;
    fclose(f);
}
