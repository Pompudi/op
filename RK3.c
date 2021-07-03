#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 256

void null_pointer(void *pointer);

typedef struct node{
	int index, value;
	struct node *next;

} node_t;

void node_sort(node_t *head){

  node_t *current = head;
  int temp;

  while(current->next != NULL){

    if(current->value > current->next->value)
	{
      temp = current->value;
      current->value = current->next->value;
      current->next->value = temp;
      current = head;

    }
    else

      current = current->next;

  }

}

void node_del(node_t  **head, int from, int to){

  node_t *current = *head, *temp;

  while((*head)->value >= from && (*head)->value <= to){

    if((*head)->next == NULL){

      free(*head);
      (*head) = NULL;
      break;

    }
    else{

      current = (*head)->next;
      free(*head);
      *head = current;

    }

  }

  while(current->next != NULL){

    if(current->next->value >= from && current->next->value <= to){

      temp = current->next->next;
      free(current->next);
      current->next = temp;

    }
    else
      current = current->next;

  }

}

void node_print(node_t *head){

  node_t *current = head;

  while(current != NULL){

    printf("%d\n", current->value);
    current = current->next;

  }

}

int node_add(node_t *head, FILE *file){

  node_t *current = head;
  int  index   = head->index;

  while(current->next != NULL){

    ++index;
    current = current->next;

  }

  current->next = malloc(sizeof(node_t));
  null_pointer(current->next);
  current->next->index = ++index;

  if(fscanf(file, "%d\n", &current->next->value) == EOF){

    free(current->next);
    current->next = NULL;
    return EOF;

  }

  return 1;

}

int node_init(node_t **head, FILE *file){

  node_t *current = malloc(sizeof(node_t));

  null_pointer(current);
  current->index = 0;

  int out = fscanf(file, "%d\n", &current->value);

  *head = current;

  return out;

}

void null_pointer(void *pointer){

  if(pointer == NULL){

    printf("ERROR\n");
    exit(1);

  }

}

int main(int argc, char *argv[]){

  if(argc != 2){

    printf("Error\n");
    return 1;

  }

  node_t *head;
  FILE   *file = fopen(argv[1], "r");
  null_pointer(file);

  if(node_init(&head, file))

    while(node_add(head, file) != EOF){}

  node_sort(head);

  int from, to;
  scanf("%d %d", &from, &to);
  node_del(&head, from, to);

  node_print(head);

  fclose(file);
  return 0;

}


