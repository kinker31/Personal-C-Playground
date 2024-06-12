#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define DNA_SIZE 32

struct Hooman{
    short unsigned int age;
    char dna[DNA_SIZE];
    float weight;
};

char DNAPick(){
    char final;
    unsigned int i = (rand() % 4);
    switch(i){
        case 0: final = 'A';
        break;
        case 1: final = 'C';
        break;
        case 2: final = 'G';
        break;
        case 3: final = 'T';
        break;
        default:final = 'x';
        break;
    }
    return final;
}

void DNASequence(char * d){
    for(unsigned short int i = 0;i < DNA_SIZE;i++){
        d[i] = DNAPick();
    }
}

void initHooman(struct Hooman *s){
    s->age = (rand() % 99) + 1;
    char tempS[DNA_SIZE];
    DNASequence(tempS);
    strcpy(s->dna, tempS);
    float tempFloat = (((float)s->age * 5) / 7.0f);
    s->weight = tempFloat;
}

int main(){
    srand(time(NULL));
    printf("Test String \n");
    struct Hooman h1, *hp = &h1;
    initHooman(hp);
    printf("Hooman Properties: %u years old, weighs %f, DNA Sequence is %s\n", h1.age, h1.weight, h1.dna);
    return 0;
}
