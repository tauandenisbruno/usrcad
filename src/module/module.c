#include <stdio.h>  // basic header for c
#include <stdlib.h> // for 'malloc()' and 'free()'
#include <string.h> // for 'fgets()' and 'strcpy()'

short chk_os()
{
    // OS DETECT | 1 = WINDOWS | 2 = LINUX | 3 = MACOS | 4 = OTHER
    short sys_os = 2;
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

char* ret_os()
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

void create_usr(char *nome, short idade, char *esc)
{
    char usr[30] = "usr/usr00";
    short i = 0;

    while (i <= 5)
    {
        FILE *arquivo = fopen(usr, "r");

        if (arquivo == NULL)
        {
            arquivo = fopen(usr, "w");
            fprintf(arquivo, "%s\n%hd\n%s\n", nome, idade, esc);
            fclose(arquivo);
            break;
        }

        else
        {
            i++;
            snprintf(usr, sizeof (usr), "usr/usr%02hd", i);
        }
    }
}

void usrname()
{
    char file_usr[30] = "usr/usr00", name[30];

    for (short i = 1; i < 6; i ++)
        {
            FILE *arquivo = fopen(file_usr, "r");
            if (arquivo == NULL)
            {
                snprintf(file_usr, sizeof(file_usr), "usr/usr%02hd", i);
            }
            else
            {
                fscanf(arquivo, "%20[^\n]", name);
                printf("USUÁRIO %d: %s\n", i, name);
                fclose(arquivo);
                snprintf(file_usr, sizeof(file_usr), "usr/usr%02hd", i);
            }
        }
}


short show_usr()
{
    char linha[30], usr_file[30] = "usr/usr00";
    short cont = 0;

    for (short i = 1; i < 6; i ++)
    {
        FILE *arquivo = fopen(usr_file, "r");

        if (arquivo == NULL)
            snprintf(usr_file, sizeof(usr_file), "usr/usr%02hd", i);

        else
        {
            cont ++;
            printf("USUÁRIO %hd: ================\n", cont);
            for (short x = 0; x <= 2; x ++)
            {
                fscanf(arquivo, "%20[^\n]", linha);
                printf("|| > %s\n", linha);
                fgetc(arquivo);
            }
            fclose(arquivo);
            snprintf(usr_file, sizeof(usr_file), "usr/usr%02hd", i);
            printf("\n");
        }
    }
    if (cont == 0)
        printf("< SEM USUÁRIOS CADASTRADOS! >\n");
    return cont;
}

void clr_scr()
{
    printf("\033[2J\033[H"); // \033[2J clear screen and \033[H move cursor for starting position
}
