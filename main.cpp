#include "tsh.h"

using namespace std;

int main(){
	char cmd[81]; // array of chars (a string)
	char *cmdTokens[20]; // array of strings
	simple_shell *shell = new simple_shell(); // creates a simple_shell object
	
	while (true){
		cout << "tsh> ";
		fgets(cmd, sizeof(cmd), stdin);
		shell->parse_command(cmd, cmdTokens);
		if (shell->isQuit(*cmdTokens)){
			exit(0);
		}
		else{
			shell->exec_command(cmdTokens);
		}

	}
	exit(1);
}