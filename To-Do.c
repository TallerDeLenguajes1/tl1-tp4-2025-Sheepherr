#include <stdio.h>
#include <stdlib.h>

#define TAMA 100

struct 
{
    int TareaID; // Numerico autoincremental comenzando en 1000
    char *Descripcion;
    int Duracion; // entre 10 - 100
}typedef Tarea;

struct 
{
    Tarea T;
    nodoT * siguiente;
    
} typedef nodoT;

nodoT * CreaLilstaVacia();
nodoT * CrearNuevaTarea(char * descripcion, int duracion, int id);
void insertarNodo(nodoT **star, nodoT * nodoTnum);
int main () {

    int id = 1000, duracion, menu = 1;
    char * Tarea[TAMA];

    printf("Creacion de tareas pendientes:\nIngrese una descripcion de la tearea: ");
    
    gets(Tarea);

    printf("Igrese la duracion en horas de la tarea: ");
    scanf("%d", &duracion);

    nodoT * StarPendientes = CreaLilstaVacia();
    nodoT * nodoT1 = CrearNuevaTarea(Tarea,duracion,id);
    insertarNodo(&*StarPendientes, &nodoT1);



    nodoT * StartRealizadas = CreaLilstaVacia;
    nodoT * TareasRealizadas = CrearNuevaTarea;

    return 0;
}

nodoT * CreaLilstaVacia() {
    return NULL;
}
nodoT * CrearNuevaTarea(char * descripcion, int duracion, int id){
    nodoT * NuevaTarea = (nodoT *) malloc(sizeof(nodoT));
    NuevaTarea->T.TareaID = id;
    NuevaTarea->T.Duracion = duracion;
    NuevaTarea->T.Descripcion = descripcion; 
    NuevaTarea->siguiente = NULL;
    return NuevaTarea;
}
void insertarNodo(nodoT **start, nodoT * nodoTnum) {

    nodoTnum->siguiente = *start;
    *start = nodoTnum;
    
}
