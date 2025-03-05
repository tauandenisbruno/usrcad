#include <stdio.h>
#include <unistd.h> // for "F_OK" -> linux only header
#include <sys/stat.h> // for 'mkdir()'

#include "module/module.h"

int main()
{
    clr_scr();
    struct usuario
    {
        char nome[15];
        int idade;
        char escola[15];
    };

    int linha = 1, b = 0;

    if (access("usr", F_OK) != 0) // verifica se a pasta 'usr' existe
        mkdir("usr", S_IRWXU | S_IRGRP | S_IXGRP); // cria a pasta caso não exista

    if (access("usr", F_OK) == 0) // verifica a existência da pasta
    {
        while (linha != 4)
        {
            printf("SISTEMA: %s\n\n1- LISTAR USUÁRIOS \n2- CADASTRAR USUÁRIOS\n3- RESETAR\n4- SAIR\n", rtn_os());

            printf("\nOPÇÃO> ");
            scanf("%d", &linha);

            if (linha == 1) // list users
            {
                clr_scr();
                show_usr();

                printf("-------------------------\n4 - VOLTAR > ");
                scanf("%d", &b);
            }


            else if (linha == 2) // create user
            {
                struct usuario pessoa;
                clr_scr();
                printf("\nDIGITE O DADOS DO USUÁRIO:\n\n");

                printf("NOME > ");
                scanf("%s", pessoa.nome);

                printf("IDADE > ");
                scanf("%d", &pessoa.idade);

                printf("ESCOLA > ");
                scanf("%s", pessoa.escola);

                create_usr(pessoa.nome, pessoa.idade, pessoa.escola);
            }

            // criar código aqui


            clr_scr(); // limpa a tela
        }
    }
    return 0;
}
