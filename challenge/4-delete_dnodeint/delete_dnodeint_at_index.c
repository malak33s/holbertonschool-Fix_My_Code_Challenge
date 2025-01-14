#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Supprime un nœud à un index donné d'une liste doublement chaînée
 * @head: Double pointeur vers la tête de la liste
 * @index: Index du nœud à supprimer
 *
 * Return: 1 en cas de succès, -1 en cas d'échec
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current;
    unsigned int i;

    if (head == NULL || *head == NULL)
        return (-1);

    current = *head;

    /* Si on supprime le premier nœud */
    if (index == 0)
    {
        *head = current->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(current);
        return (1);
    }

    /* Parcours jusqu'à l'index */
    for (i = 0; current != NULL && i < index; i++)
        current = current->next;

    /* Si l'index est invalide */
    if (current == NULL)
        return (-1);

    /* Mise à jour des liens */
    if (current->next != NULL)
        current->next->prev = current->prev;

    if (current->prev != NULL)
        current->prev->next = current->next;

    free(current);
    return (1);
}
