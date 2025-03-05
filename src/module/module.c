#include <stdio.h>  // basic header for c
#include <stdlib.h> // for 'malloc()' and 'free()'
#include <string.h> // for 'fgets()' and 'strcpy()'

int chk_os()
{
    // OS DETECT | 1 = WINDOWS | 2 = LINUX | 3 = MACOS | 4 = OTHER
    int sys_os = 2;
    #ifdef _WIN32
    { sys_os = 1; }
    #elifdef __linux__
    { sys_os = 2; }
    #elifdef __APPLE__
    { sys_os = 3; }
    #else
    { sys_os = 4; }
    #endif
    return sys_os;
}

char* rtn_os()
{
    switch (chk_os())
    {
        case 1:
            return "Windows";
            break;
        case 2:
            return "Linux";
            break;
        case 3:
            return "MacOS";
            break;
        default:
            return "Desconhecido";
            break;
    }
}

char* return_line(int linha)
{
    char *dados = malloc(1024);
    FILE *arquivo = fopen("usr/usr00", "r");

    int linha_atual = 0;
    while (fgets(dados, sizeof(dados), arquivo) != NULL)
    {
        linha_atual++;
        if (linha_atual == linha)
        {
            break;
        }
    }
    return dados;
    fclose(arquivo);
    free(dados);
}

void edit_line(int linha, char *texto)
{
    char* txt_tmp[100][1024]; // Texto temporário

    int i = 0; // Contador
    FILE *arquivo = fopen("usr/usr00", "r"); // Abre arquivo no modo de LEITURA
    while (fgets(txt_tmp[i], 1024, arquivo) != NULL)
    {
        i++;
    }
    fclose(arquivo);

    strcpy(txt_tmp[linha -1], texto);
    arquivo = fopen("usr/usr00", "w");

    for (i = 0; i < 100; i++)
    {
        fprintf(arquivo, "%s", txt_tmp[i]);
    }

    fclose(arquivo);
}

void create_usr(char *nome, int idade, char *esc)
{
    char usr[30] = "usr/usr00";
    int i = 0;

    while (i <= 5)
    {
        FILE *arquivo = fopen(usr, "r");

        if (arquivo == NULL)
        {
            arquivo = fopen(usr, "w");
            fprintf(arquivo, "%s\n%d\n%s\n", nome, idade, esc);
            i = 6;
        }

        else
        {
            i++;
            snprintf(usr, sizeof (usr), "usr/usr%02d", i);
        }

        fclose (arquivo);
    }
}

void show_usr()
{
    char linha[30], usr_file[30] = "usr/usr00";
    int cont = 0;

    for (int i = 1; i < 6; i ++)
    {
        FILE *arquivo = fopen(usr_file, "r");

        if (arquivo == NULL)
            snprintf(usr_file, sizeof(usr_file), "usr/usr%02d", i);

        else
        {
            cont ++;
            printf("USUÁRIO %d: ----------------\n\n", cont);
            for (int x = 0; x <= 2; x ++)
            {
                fscanf(arquivo, "%20[^\n]", linha);
                printf("VALOR: %s\n", linha);
                fgetc(arquivo);
            }
            fclose(arquivo);
            snprintf(usr_file, sizeof(usr_file), "usr/usr%02d", i);
            printf("\n");
        }
    }
    if (cont == 0)
        printf("< SEM USUÁRIOS CADASTRADOS! >\n");
}

void clr_scr()
{
    printf("\033[2J\033[H"); // \033[2J clear screen and \033[H move cursor for starting position
}
