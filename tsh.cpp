#include "tsh.h"
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

void simple_shell::parse_command(char *cmd, char **cmdTokens) {
	// check to see if the user just pressed enter
	if(!strcmp(cmd, "\n")){	
		cmdTokens[0] = "\n";
	} else{
		// init first token and counter
		char* token;
		int i = 0;
		token = strtok(cmd, " \n");

		// iterate through all the strings and put them
		// into cmdTokens. strtok returns NULL if there are no
		// more tokens
		while(token != NULL){
			cmdTokens[i] = token;

			i++;
			token = strtok(NULL," \n");
		}

		// the last element in the arguments must be a NULL 
		// pointer for execvp to work
		cmdTokens[i] = NULL;

	}
}

void simple_shell::exec_command(char **argv) {
	//	 parent process should wait for the child process to complete and reap

	// if the user just pressed enter then do nothing
	if(strcmp(argv[0], "\n")){
		// sleep(3);
		int pid = fork();

		// child
		if(pid == 0){
			if(execvp(argv[0], argv) == -1)
				printf("ERROR: Invalid command\n");

			exit(1);
		}
		// handle if the child failed to be created
		else if(pid < 0){
			printf("creation of child failed\n");
		}
		// parent: wait for child process to finish
		else{
			waitpid(pid, NULL, 0);
		}
	}
}

bool simple_shell::isQuit(char *cmd) {
	// strcmp returns 0 if the strings are the same
	// so just negate the return value
	return !strcmp(cmd, "quit");
}
