#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "stdio.h"
#include "errno.h"
#include "stdlib.h"
#include "unistd.h"
#include <string.h>
#include <signal.h>

void handler (int sig) {
    fflush(stdout);
    printf("\n");
}

int main () {
    int i;
    char* argv[10];
    char command[1024];
    char* token;

    if (signal(SIGINT, handler) == SIG_ERR) {
        printf("\ncan't catch SIGSTOP\n");
    }

    while(1) {
        printf("%s", "AvihayFinish_AmitRovshitz:~ ");
        fgets(command, 1024, stdin);
        command[strlen(command) - 1] = '\0'; // replace \n with \0

	    /* parse command line */
	    i = 0;
	    token = strtok(command," ");
	    while (token != NULL) {
            argv[i] = token;
            token = strtok (NULL, " ");
            i++;
	    }
	    argv[i] = NULL;

        /* Is command empty */
		if (argv[0] == NULL) {
			continue;
        }

        if (strcmp(argv[0], "exit") == 0) {
            printf("%s", "close the shell..");
            exit(1);
        }

        int id = fork();
        if (id == -1) {
            perror("error in fork function");
            exit(1);
        }

        if (id == 0) {
            signal(SIGINT, SIG_DFL);
            int t = 0;
            int bool1 = 0;
            char* args[10];
            while (argv[t] != NULL) {
                if (strcmp(argv[t], ">") == 0) {
                    int fd = open(argv[t + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
                    if (fd == -1) {
                        perror("error in open the output file");
                        exit(1);
                    }
                    if (dup2(fd, STDOUT_FILENO) == -1) {
                        perror("error in change the stdout file descriptor");
                        exit(1);
                    }
                    close(fd);
                    for (int i = 0; i < t; i++) {
                        args[i] = argv[i];
                    }
                    args[t] = NULL;
                    bool1 = 1;
                    break;
                }

                else if (strcmp(argv[t], ">>") == 0) {
                    int fd = open(argv[t + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
                    if (fd == -1) {
                        perror("error in open the output file");
                        exit(1);
                    }
                    if (dup2(fd, STDOUT_FILENO) == -1) {
                        perror("error in change the stdout file descriptor");
                        exit(1);
                    }
                    close(fd);
                    for (int i = 0; i < t; i++) {
                        args[i] = argv[i];
                    }
                    args[t] = NULL;
                    bool1 = 1;
                    break;
                }
                else if (strcmp(argv[t], "|") == 0) {
                    int fd[2]; // fd[0] for read, fd[1] for write
                    int suc = pipe(fd);
                    if (suc == -1) {
                        perror("error in pipe function");
                        exit(1);
                    }

                    int id1 = fork();
                    if (id1 == 0) {
                       close(fd[0]);
                       char* argt[10];
                       for (int i = 0; i < t; i++) {
                            argt[i] = argv[i];
                       }
                       argt[t] = NULL;

                       if (dup2(fd[1], STDOUT_FILENO) == -1) {
                            perror("error in change the stdout file descriptor");
                            exit(1);
                       }
                       close(fd[1]);

                       execvp(argt[0], argt); 
                    } else {
                        wait(NULL);
                        close(fd[1]);

                        int j = t + 1;
                        int i = 0;
                        while (argv[j] != NULL) {
                            argv[i++] = argv[j++];
                        }
                        argv[i] = NULL;
                        t = -1;
                        if (dup2(fd[0], 0) == -1) {
                            perror("error in change the stdin file descriptor");
                            exit(1);
                        }
                        close(fd[0]);
                    }
                }
                t++;               
            }
            if (bool1 == 1) {
                if (execvp(args[0], args) == -1) {
                    perror("failed to run your command, please check that the format command is okay");
                }
            } else {
                if (execvp(argv[0], argv) == -1) {
                    perror("failed to run your command, please check that the format command is okay");
                }
            }
        } else {
            wait(NULL);
        }
    }
}