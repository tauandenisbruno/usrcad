#ifndef MODULE_H_INCLUDED
#define MODULE_H_INCLUDED

int chk_os(); // OS DETECT | 1 = WINDOWS | 2 = LINUX | 3 = MACOS | 4 = OTHER
char* rtn_os(); // OS DETECT -> RETURNS 'STRING'
char* return_line(int linha); // RETURN 'usr00' FILE DATA
void edit_line(int linha, char *texto); // EDIT 'usr00' FILE
void create_usr(char *nome, int idade, char *esc); // CREATE A NEW USER
void show_usr(); // SHOW ALL USERS
void clr_scr(); // CLEAR_SCREEN

#endif // MODULE_H_INCLUDED
