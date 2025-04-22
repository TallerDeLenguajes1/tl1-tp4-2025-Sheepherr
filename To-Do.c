#include <stdio.h>
#include <stdlib.h>

#define TAMA 100

typedef struct Tarea 
{
    int TareaID; // Numerico autoincremental comenzando en 1000
    char *Descripcion;
    int Duracion; // entre 10 - 100
} Tarea;

typedef struct nodoT 
{
    Tarea tarea;
    struct nodoT * siguiente;
    
}nodoT;

nodoT * CreaLilstaVacia();
nodoT * CrearNuevaTarea(char * descripcion, int duracion, int * Pid);
void insertarNodo(nodoT **start, nodoT * nodoTnum);
void mostrarTareas(nodoT * start);
int main () {

    int duracion, id = 1000, *pid;
    pid= &id;
    char descripcion[TAMA];
    printf("Creando tareas pendientes\n");
    printf("Ingrese una descripcion de la tarea peniente: ");
    fgets(descripcion, sizeof(descripcion), stdin);
    printf("Ingrese la duracion de la tarea en horas (entre 10 y  100): ");
    scanf("%d", &duracion);

    nodoT * Pendientestart = CreaLilstaVacia();
    
    nodoT * nodoT1 = CrearNuevaTarea(descripcion, duracion, pid);
    insertarNodo(&Pendientestart, nodoT1);
    mostrarTareas(Pendientestart);

    
    
}
nodoT * CreaLilstaVacia() {
    return NULL;
}
nodoT * CrearNuevaTarea(char * descripcion, int duracion, int * Pid){
    nodoT * NuevaTarea = (nodoT *) malloc(sizeof(nodoT));
    NuevaTarea->tarea.TareaID = * Pid;
    NuevaTarea->tarea.Duracion = duracion;
    NuevaTarea->tarea.Descripcion = descripcion; 
    NuevaTarea->siguiente = NULL;
    *Pid++;
    return NuevaTarea;
}
void insertarNodo(nodoT **start, nodoT * nodoTnum) {

    nodoTnum->siguiente = *start;
    *start = nodoTnum;
}
void mostrarTareas (nodoT *start) {
    nodoT * aux = start;

    while (aux)
    {
        printf("Duracion: %d", aux->tarea.Duracion);
        printf("\nDescripcion: %s", aux->tarea.Descripcion);
        printf("\nId: %d", aux->tarea.TareaID);
        
        aux = aux->siguiente;
    }
}