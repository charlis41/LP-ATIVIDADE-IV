#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct Aluno {
    char nome[200];
    char dataNascimento[20];
    float nota1;
    float nota2;
    float media;
};


float calcularMedia(struct Aluno aluno) {
    return (aluno.nota1 + aluno.nota2) / 2;
}


void verificarAprovacao(struct Aluno aluno) {
    if (aluno.media >= 7.0) {
        printf("%s está aprovado!\n", aluno.nome);
    } else {
        printf("%s está reprovado.\n", aluno.nome);
    }
}

int main() {
	int i;
    
    struct Aluno alunos[5];

   
    for ( i = 0; i < 5; i++) {
        printf("\nNome do aluno %d: ", i + 1);
        scanf("%s", alunos[i].nome);
        printf("Data de nascimento do aluno : ", i + 1);
        scanf("%s", alunos[i].dataNascimento);
        printf("Primeira nota  do aluno : ", i + 1);
        scanf("%f", &alunos[i].nota1);
        printf("Segunda nota do aluno : ", i + 1);
        scanf("%f", &alunos[i].nota2);
        printf ("\n================================\n");

        
        alunos[i].media = calcularMedia(alunos[i]);
    }

  
    for ( i = 0; i < 5; i++) {
        printf("Média de %s: %.2f\n", alunos[i].nome, alunos[i].media);
        verificarAprovacao(alunos[i]);
    }

    return 0;
}
