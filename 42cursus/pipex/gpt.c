#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  if (argc != 5) {
    printf("Usage: ./pipex file1 cmd1 cmd2 file2\n");
    return 1;
  }

  char *file1 = argv[1];
  char *cmd1 = argv[2];
  char *cmd2 = argv[3];
  char *file2 = argv[4];

  // Create a pipe
  int pipefd[2];
  if (pipe(pipefd) == -1) {
    perror("pipe");
    return 1;
  }

  // Fork the process
  pid_t pid = fork();
  if (pid == -1) {
    perror("fork");
    return 1;
  }

  if (pid == 0) {
    // Child process

    // Close the read end of the pipe
    close(pipefd[0]);

    // Redirect stdout to the write end of the pipe
    if (dup2(pipefd[1], STDOUT_FILENO) == -1) {
      perror("dup2");
      return 1;
    }

    // Close the pipe
    close(pipefd[1]);

    // Execute the first command
    if (execlp("sh", "sh", "-c", cmd1, NULL) == -1) {
      perror("execlp");
      return 1;
    }
  } else {
    // Parent process

    // Close the write end of the pipe
    close(pipefd[1]);

    // Open file2 for writing
    int file2fd = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (file2fd == -1) {
      perror("open");
      return 1;
    }

    // Redirect stdin to the read end of the pipe
    if (dup2(pipefd[0], STDIN_FILENO) == -1) {
      perror("dup2");
      return 1;
    }

    // Close the pipe
    close(pipefd[0]);

    // Redirect stdout to file2
    if (dup2(file2fd, STDOUT_FILENO) == -1) {
      perror("dup2");
      return 1;
    }

    // Close the file
    close(file2fd);

    // Execute the second command
    if (execlp("sh", "sh", "-c", cmd2, NULL) == -1) {
      perror("execlp");
      return 1;
    }
  }

  // Wait for the child process to complete
  if (wait(NULL) == -1) {
    perror("wait");
    return 1;
  }

  return 0;
}
