#include "eventList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
EventList *CreateEventList(void)
{
    EventList *eventList = malloc(sizeof(EventList));
    eventList->isEmpty = 1;
    eventList->head = NULL;
    eventList->last = NULL;

    return eventList;   
}   

void DestroyEventList(EventList *this)
{
    free(this);
}

Event *SearchEvent(EventList *this, char *name)
{

}

void AddEvent(EventList *this, Event *event)
{
    if(this->isEmpty == 1){    
        this->isEmpty = 0;
        this->head = event;
        this->last = event;
    }
    else{ 

        this->last->next = event;
        this->last = event;        
    }
    
}

void RemoveEvent(EventList *this, char *name)
{
    Event *contador =this->head;

    if(strcmp(this->head->eventName, name) == 0)//compara estructuras
    {
         
        this->head = this->head->next;  // le asigna al 2do al HEAD
        DestroyEvent(contador);   // destruye el primer evento
    }
    else if(strcmp(this->last->eventName, name) == 0)
    {
        while(contador->next != NULL)
        {
            if(contador->next->next == NULL)
            {
                this->last = contador->next;
                contador->next = NULL; 
                

                break;
            }
            contador = contador->next;
            
        }
        DestroyEvent(this->last);
    }
    
}

void ListEvents(EventList *this)
{
    if(this->isEmpty == 1)
    {
        printf("empty\n");
    }
    else
    {
        Event *contador = this->head;
        while(contador != NULL)
        { 
            printf("%s\n", contador->eventName);
            contador = contador->next;
        }   
    }
    
}
