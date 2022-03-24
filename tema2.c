#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "util/task_helper.h"
#define DELIM " .,;!?:"

  // Cerinta 1
void uppercase(char *text) {
    int i; // Pentru a parcurge litere
    for (i = 0; i < strlen(text); i++) {
        if ((text[i] >= 'A') && (text[i] <= 'Z')) {  // litere mari
            text[i] = text[i] + 32;  // transformarea in litera mica
        }
        if ((text[i] >= 'a') && (text[i] <= 'z')  // litere mici
            && (text[i - 1] == '\n') && (i > 0)) {
            text[i] = text[i] - 32;  // transformarea in litera mare
        }
    }  // Pentru prima litera din poezie
    if ((text[0] >= 'a') && (text[0] <= 'z')) {
        text[0] = text[0] - 32;
    }
}

  // Cerinta 2
void trimming(char *text) {
    char aux_text[2500];
    strcpy(aux_text, text);  // copiez poemul intr-un text auxiliar
    char new_poem[2500];
    char *word = strtok(aux_text, DELIM);  // tokenizez textul auxiliar
    strcpy(new_poem, word);
    word = strtok(NULL, DELIM);
    while (word != NULL) {  // iterez prin tokene, adica prin worduri
        if ( *word == '\n') {
            strcat(new_poem, word);  // adaug new-line-urile poemelor
        } else {
            strcat(new_poem, " ");  // adaug spatiu
            strcat(new_poem, word);  // adaug cuvintul in noul poem
        }
        word = strtok(NULL, DELIM);  
    }
    strcpy(text, new_poem);  // noul poem il copiez in text
}

  // Cerinta 3
void make_it_silly(char *text) {
    int i;
    float prob;
    scanf("%f", &prob);  // Citesc probabilitatea
    for (i = 0; i < strlen(text); i++) {  // verific daca caracterul e litera
        if (((text[i] >= 'a') && (text[i] <= 'z'))
            || ((text[i] >= 'A') && (text[i] <= 'Z'))) {
            float sample = rand() % 100 / 99.0;  // generez sample
            if (sample < prob) {
                if ((text[i] >= 'a') && (text[i] <= 'z')) {
                    text[i] = text[i] - 32;
                } else {
                    text[i] = text[i] + 32;
                  }
            }
        }
    }
}

  // Cerinta 4
void make_it_friendlier(char *text) {
    char new_poem[2500];
    char *new_word;
    char *p;  // un pointer auxiliar
    char aux[2500];
    strcpy(new_poem, text);  // copiez text intr-un text auxiliar
    char *word;
    p = text;
    word = strtok(new_poem, " .,;!?:\n");  // tokenizez prin textul auxiliar
    while (word != NULL) {
        get_friendly_word(word, &new_word);  // caut existena diminutivelor
        if (new_word != NULL) {
            p = strstr(p, word);  // atribui lui p vectorul ce incepe cu word
            strcpy(aux, new_word);  // copiez in aux diminutivul gasit
              // concatenez in aux continutul de dupa word
            strcat(aux, p + strlen(word));
            strcpy(p, aux);  // copizez vectorul aux in p
              // initializez p cu pozitia de dupa diminutiv
            p = p + strlen(new_word);
        }
        word = strtok(NULL, " .,;!?:\n");
    }
}

void print(char *text) {
    printf("%s\n\n", text);
}

int main(void) {
    srand(42);
    char poem[2500];
    char comand[30];
    int executare = 1;
    char stop[5] = "quit";
    while (executare) {  // cat timp cat se citeste
        scanf("%s", comand);
        if (strcmp(comand, "load") == 0) {
            char path[30];
            scanf("%s", path);
            load_file(path, poem);
        } else if (strcmp(comand, "uppercase") == 0) {
            uppercase(poem);
        } else if (strcmp(comand, "print") == 0) {
            print(poem);
        } else if (strcmp(comand, "trimming") == 0) {
            trimming(poem);
        } else if (strcmp(comand, "make_it_silly") == 0) {
            make_it_silly(poem);
        } else if (strcmp(comand, "make_it_friendlier") == 0) {
            make_it_friendlier(poem);
        }
        if (strcmp(comand, "quit") == 0) {
            return 0;
        }
    }
    return 0;
}