#include <stdio.h>
#include <unistd.h> // for "F_OK" -> linux only header
#include <sys/stat.h> // for 'mkdir()'

#include "module/module.h"

int main()
{
    const char ver[12] = "0.0.5-alpha";
    clr_scr();

    struct usuario
    {
        char nome[15];
        short idade;
        char escola[15];
    };

    short linha = 1;

    if (access("usr", F_OK) != 0) // check if "usr" folder existence and if is not, create it
        mkdir("usr", S_IRWXU | S_IRGRP | S_IXGRP);

    if (access("usr", F_OK) == 0)
    {
        // main menu
        while (linha != 4)
        {
            printf("SISTEMA DETECTADO: %s\nVer: %s\n\n1- LISTAR DADOS DOS USUÁRIOS \n2- CADASTRAR NOVOS USUÁRIOS\n3- EXCLUIR USUÁRIO\n4- SAIR\n", ret_os(), ver);

            printf("\nOPÇÃO> ");
            scanf("%hd", &linha);

            if (linha == 1) // option 1 - list users
            {
                clr_scr();
                show_usr();

                printf("-------------------------\n4 - VOLTAR\n\nOPÇÃO> ");
                scanf("%hd", &linha);
                linha = 1;
            }

            else if (linha == 2) // option 2 - create user
            {
                if (show_usr() >= 5)
                {
                    clr_scr();
                    printf("< NÚMERO MÁXIMO DE USUÁRIOS CADASTRADOS! >\n-------------------------\n\n4 - VOLTAR > ");
                    scanf("%hd", &linha);

                    if (linha <= 0 || linha > 6) // protection for invalid options
                        linha = 3;

                    linha = 1;
                }
                else
                {
                    struct usuario pessoa;
                    clr_scr();
                    printf("\nDIGITE OS DADOS DO USUÁRIO:\n\n");

                    printf("NOME > ");
                    scanf("%s", pessoa.nome);

                    printf("IDADE > ");
                    scanf("%hd", &pessoa.idade);

                    printf("ESCOLA > ");
                    scanf("%s", pessoa.escola);

                    create_usr(pessoa.nome, pessoa.idade, pessoa.escola);
                }
            }

            else if (linha == 3) // option 3 - edit & delete users
            {
                while(linha != 6)
                {
                    if (show_usr() > 0)
                    {
                        clr_scr();
                        printf("SELECIONE O USUÁRIO:\n\n");
                        usrname();
                        printf("\n-------------------------\n6 - VOLTAR\n\nOPÇÃO> ");
                        scanf("%hd", &linha);

                        if (linha <= 0 || linha > 6) // protection for invalid options
                            linha = 7;
                    }

                    if ((linha > 0) && (linha < 6))
                    {
                        char usrpath[30];
                        snprintf(usrpath, sizeof(usrpath), "usr/usr%02hd", (linha -1));
                        FILE *arquivo = fopen(usrpath, "r");

                        if (arquivo != NULL)
                        {
                            clr_scr();
                            printf("< VOCÊ TEM CERTEZA QUE DESEJA EXCLUIR? >\n1 - SIM\n2 - NÃO\n\nOPÇÃO > ");

                            scanf("%hd", &linha);
                            if (linha == 1)
                            {
                                fclose(arquivo);
                                remove(usrpath);
                            }

                            else
                                fclose(arquivo);
                        }

                        else
                        {
                            if (show_usr() == 0)
                            {
                                clr_scr();
                                printf("< NÃO HÁ USUÁRIOS CADASTRADOS! >\n-------------------------\n\n4 - VOLTAR > ");
                                scanf("%hd", &linha);

                                if (linha <= 0 || linha > 6) // protection for invalid options
                                    linha = 3;
                                break;
                            }
                            else
                            {
                                clr_scr();
                                printf("< USUÁRIO SELECIONADO INVÁLIDO! >\n-------------------------\n\n4 - VOLTAR > ");
                                scanf("%hd", &linha);

                                if (linha <= 0 || linha > 6) // protection for invalid options
                                    linha = 3;
                            }
                        }
                    }
                }
                linha = 1;
            }
            clr_scr();
        }
    }
    return 0;
}
