
// #include <stdio.h>

// int main(int argc, char *argv[], char *envp[])
// {
// 	for (int i = 0; envp[i] != NULL; i++)
// 	{
// 		printf("%s\n", envp[i]);
// 	}
// 	(void)argc;
// 	(void)argv;
// 	return (0);
// }

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char *find_command_path(char *cmd, char *envp[]) {
    char *path = NULL;
    for (int i = 0; envp[i] != NULL; i++) {
        if (strncmp(envp[i], "PATH=", 5) == 0) {
            path = envp[i] + 5; // Skip "PATH="
            break;
        }
    }
    if (!path) return NULL; // PATH not found

    char *paths = strdup(path); // Copy PATH variable
	printf("%s\n", paths);
    char *token = strtok(paths, ":"); // Split by ":"

    char full_cmd[1024]; // Buffer for full path

    while (token) {
        snprintf(full_cmd, sizeof(full_cmd), "%s/%s", token, cmd); // Build path
        if (access(full_cmd, X_OK) == 0) { // Check if executable
            free(paths);
            return strdup(full_cmd); // Return valid path
        }
        token = strtok(NULL, ":");
    }
    free(paths);
    return NULL; // Command not found
}

int main(int argc, char *argv[], char *envp[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s command\n", argv[0]);
        return 1;
    }

    char *cmd_path = find_command_path(argv[1], envp);
    if (!cmd_path) {
        fprintf(stderr, "Command not found: %s\n", argv[1]);
        return 1;
    }
	printf("%s", cmd_path);
    // char *cmd_args[] = {cmd_path, NULL};
    // execve(cmd_path, cmd_args, envp); // Execute the command
    // perror("execve failed"); // If execve fails
    free(cmd_path);
    return 1;
}
