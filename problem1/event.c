#include "event.h"
#include <string.h>
#include <stdlib.h>

Event *CreateEvent(char *name)
{
    Event *event = malloc(sizeof(Event));
    name[15]=0; //no puede tener un evento con mas de 15 caracteres
    strncpy(event->eventName,name,strlen(name)+1); //nombre 
    event->next = NULL; //next

    return event;
}

void DestroyEvent(Event *this)
{
    free(this);
}
