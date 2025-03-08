#ifndef MODULE_H_INCLUDED
#define MODULE_H_INCLUDED

short chk_os(); // OS DETECT | 1 = WINDOWS | 2 = LINUX | 3 = MACOS | 4 = OTHER
char* ret_os(); // OS DETECT -> RETURNS 'STRING'
void create_usr(char *nome, int idade, char *esc); // CREATE A NEW USER
short show_usr(); // SHOW ALL USERS
void usrname(); // SHOW USERS NAME
void clr_scr(); // CLEAR_SCREEN

#endif // MODULE_H_INCLUDED
