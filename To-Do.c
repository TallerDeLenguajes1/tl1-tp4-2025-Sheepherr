#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMA 100

typedef struct Tarea 
{
    int TareaID; // Numerico autoincremental comenzando en 1000
    char * Descripcion;
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

nodoT * QuitarNodo(nodoT **Start, int dato);

void mostrarListas (nodoT * startP, nodoT * startR);


int main () {

    int duracion, id = 1000, *pid, menu = 1;
    pid= &id;
    char descripcion[TAMA];
    printf("Creando tareas pendientes\n");
    printf("Ingrese una descripcion de la tarea peniente: ");
    fgets(descripcion, sizeof(descripcion), stdin);
    printf("Ingrese la duracion de la tarea en horas (entre 10 y  100): ");
    scanf("%d", &duracion);
    
    nodoT * Pendientestart = CreaLilstaVacia();
    nodoT * Realizadastart = CreaLilstaVacia();
    while (menu != 0)
    {   
        nodoT * nodoP = CrearNuevaTarea(descripcion, duracion, pid);
        insertarNodo(&Pendientestart, nodoP);

        printf("Desea agregar una nueva tarea? Ingrese 0 si desea salir o ingrese 1 si desea crear una nueva tarea: ");
        scanf("%d", &menu);
        if (menu == 1)
        {
            printf("Creando tareas pendientes\n");
            printf("Ingrese una descripcion de la tarea peniente: ");
            fflush(stdin);
            gets(descripcion);
            printf("Ingrese la duracion de la tarea en horas (entre 10 y  100): ");
            scanf("%d", &duracion);
            getchar();
        }
        
    }
    mostrarTareas(Pendientestart);

    int idReal;
    printf("Ingrese el id de la tarea que se realizo: ");
    scanf("%d", &idReal);
    
    nodoT * nodoR = QuitarNodo(&Pendientestart, idReal);

    insertarNodo(&Realizadastart, nodoR);

    mostrarListas(Pendientestart,Realizadastart);
    
    return 0;
    
}

nodoT * CreaLilstaVacia() {
    return NULL;
}
nodoT * CrearNuevaTarea(char * descripcion, int duracion, int * Pid){
    nodoT * NuevaTarea = (nodoT *) malloc(sizeof(nodoT));
    NuevaTarea->tarea.TareaID = * Pid;
    NuevaTarea->tarea.Duracion = duracion;
    int cont = strlen(descripcion);
    NuevaTarea->tarea.Descripcion = (char *) malloc(sizeof(char) * (cont + 1));
    strcpy(NuevaTarea->tarea.Descripcion, descripcion);
    NuevaTarea->siguiente = NULL;
    (*Pid)++;
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
        printf("Id: %d\n", aux->tarea.TareaID);
        
        aux = aux->siguiente;
    }
}
nodoT * QuitarNodo(nodoT **Start, int dato)
{
    nodoT *nodoAux = (*Start);
    nodoT *nodoAnt = NULL;
    
    while (nodoAux != NULL && nodoAux->tarea.TareaID != dato)
    {
        nodoAnt = nodoAux;
        nodoAux = nodoAux->siguiente;
    }
    if (nodoAux != NULL)
    {
        if (nodoAux == (*Start))
        {
            (*Start) = nodoAux->siguiente;
        }
        else
        {
            nodoAnt->siguiente = nodoAux->siguiente;
        }
    nodoAux->siguiente = NULL;
    }
    return (nodoAux);
}
void mostrarListas (nodoT * startP, nodoT * startR)
{
    
    printf("Lista de tareas PENDIENTES\n========================\n");
    mostrarTareas(startP);
    printf("Lista de tareas REALIZADAS\n========================\n");
    mostrarTareas(startR);

}