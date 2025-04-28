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

nodoT * BuscarTareaClave (nodoT * startP, nodoT * startR, char * clave);

nodoT * BuscarTareaId (nodoT * startP, nodoT * startR, int id);

void liberarMemoria(nodoT * start);

void mostrarTarea(nodoT * tarea);

int main () {

    int duracion, id = 1000, *pid, menu = 1;
    pid = &id;
    char descripcion[TAMA];
    printf("Creando tareas pendientes\n");
    printf("Ingrese una descripcion de la tarea peniente: ");
    gets(descripcion);
    printf("Ingrese la duracion de la tarea en horas (entre 10 y  100): ");
    scanf("%d", &duracion);

    while (duracion < 10 || duracion > 100)
    {
        printf("Porfavor ingrese la duracion de la tarea en horas (entre 10 y  100): ");
        scanf("%d", &duracion); 
    }
    
    
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

    while (idReal < 1000)
    {
        printf("Porfavor ingrese el id de la tarea que se realizo: ");
        scanf("%d", &idReal);
    }
    
    
    nodoT * nodoR = QuitarNodo(&Pendientestart, idReal);

    insertarNodo(&Realizadastart, nodoR);

    mostrarListas(Pendientestart,Realizadastart);
    
    

    printf("Consulte las tareas.\nIngrese 1 si quiere buscar la tarea por palabra clave. Ingrese 2 si quiere buscar tarea por numero de id: ");
    scanf("%d", &menu);
    while (menu > 2)
    {
        printf("Ingrese 1 si quiere buscar la tarea por palabra clave. Ingrese 2 si quiere buscar tarea por numero de id: ");
        scanf("%d", &menu);
    }
    
    getchar();

    nodoT * nodoBuscado;
    char buscarPalabra[TAMA];

    while (menu != 0)
    {
        if (menu == 1)
        {
            printf("Ingrese la palabra clave para buscar: ");
            gets(buscarPalabra);
            nodoBuscado = BuscarTareaClave(Pendientestart, Realizadastart, buscarPalabra);
        }
        else if (menu == 2)
        {
            printf("Ingrese el id que desea buscar: ");
            scanf("%d", &idReal);
            nodoBuscado = BuscarTareaId(Pendientestart, Realizadastart, idReal);
        }
        
        if (nodoBuscado != NULL)
        {
            mostrarTarea(nodoBuscado);
        }
        
        printf("Ingrese 1 si quiere buscar otra tarea por palabra clave, ingrese 2 si desea buscar otra tarea por id. Si desea terminar ingrese 0: ");
        scanf("%d", &menu);
        getchar();
        
    }
    

    liberarMemoria(Pendientestart);
    liberarMemoria(Realizadastart);

    return 0;
    
}

nodoT * CreaLilstaVacia() 
{
    return NULL;
}

nodoT * CrearNuevaTarea(char * descripcion, int duracion, int * Pid)
{
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

void insertarNodo(nodoT **start, nodoT * nodoTnum) 
{

    nodoTnum->siguiente = *start;
    *start = nodoTnum;
}

void mostrarTareas (nodoT *start) 
{
    nodoT * aux = start;
    printf("==============\n");
    while (aux)
    {
        printf("Duracion: %d", aux->tarea.Duracion);
        printf("\nDescripcion: %s\n", aux->tarea.Descripcion);
        printf("Id: %d\n", aux->tarea.TareaID);
        printf("==============\n");
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
    
    printf("Lista de tareas PENDIENTES\n");
    
    mostrarTareas(startP);
    
    printf("Lista de tareas REALIZADAS\n");
    
    mostrarTareas(startR);

}

nodoT * BuscarTareaClave (nodoT * startP, nodoT * startR, char * clave)
{
    nodoT * aux = startP;
    char * comparacion;

    while (aux)
    {
        if (strstr(aux->tarea.Descripcion, clave) != NULL)
        {
            printf("La tarea fue encontrada en la lista de PENDIENTES.\n");        
            return aux;
        }
        
        aux = aux->siguiente;
    }
    
    aux = startR;

    while (aux)
    {
        if (strstr(aux->tarea.Descripcion, clave) != NULL)
        {
            printf("La Tarea fue encontrada en la lista de REALIZADAS.\n");
            return aux;
        }
        
        aux = aux->siguiente;
    }
        
    printf("No se encontro la tarea buscada.\n");
    return NULL;
    
}

nodoT * BuscarTareaId (nodoT * startP, nodoT * startR, int id)
{
    nodoT * aux = startP;
    
    while (aux && (id != aux->tarea.TareaID))
    {
        aux = aux->siguiente;
    }
    
    if (aux == NULL)
    {
        aux = startR;
        
        while (aux && (id != aux->tarea.TareaID))
        {
            aux = aux->siguiente;
        }
        
        if (aux == NULL)
        {
            printf("No se encontro tarea con el id %d\n", id);
        }
        else
        {
            printf("La Tarea fue encontrada esta en la lista REALIZADAS.\n");
        }
    
    }
    else
    {
        printf("La Tarea fue encontrada en la lista de PENDIENTES.\n");
    }

    return aux;

}
void liberarMemoria(nodoT * start)
{
    nodoT *aux;
    while (start)
    {
        aux = start;
        start = start->siguiente;
        free(aux->tarea.Descripcion);
        free(aux);
    }
}
void mostrarTarea(nodoT * tarea) 
{
    printf("==========\n");
    printf("Descripcion: %s\nTiempo en horas: %d\nId: %d\n", tarea->tarea.Descripcion, tarea->tarea.Duracion, tarea->tarea.TareaID);
    printf("==========\n");

}
