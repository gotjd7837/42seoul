# 1. pipex

pipex는 파이프 명령을 실행하고 파일로 입출력을 리디렉션하는 쉘의 일부를 구현하는 프로젝트입니다. 
루트에 (all, clean, fclean, re)규칙을 제공하는 `Makefile`이 있습니다. 이를 통해 소스 코드를 컴파일 하여 `pipex`프로그램을 생성합니다.
단일 파이프만 처리할 수 있으며, 실행 인자 형식은 `infile cmd1 cmd2 outfile`이어야 합니다.

* `pipex` 생성
> make all

# 2. 실행 방법
프로그램 이름은 pipex이며, 이는 infile과 outfile을 사용하여 STDIN(<)과 STDOUT(>)을 리디렉션합니다.
> ./pipex \<infile> \<cmd1> \<cmd2> \<outfile>
다음과 같이 프로그램 인자를 입력합니다. 이는 쉘에서 `< infile cmd1 | cmd2 > outfile`와 동일하게 처리됩니다.

# 3. 허용 함수

1. `access` on \<unistd.h>
2. `unlink` on \<unistd.h>
3. `close` on \<unistd.h>
4. `read` on \<unistd.h>
5. `write` on \<unistd.h>
6. `pipe` on \<unistd.h>
7. `dup` on \<unistd.h>
8. `dup2` on \<unistd.h>
9. `execve` on \<unistd.h>
10 `fork` on \<unistd.h>
11. `malloc` on \<stdlib.h>
12. `free` on \<stdlib.h>
13. `exit` on \<stdlib.h>
14. `waitpid` on \<sys/wait.h>
15. `wait` on \<sys/wait.h>
16. `perror` on \<stdio.h>
17. `strerror` on \<string.h>
18. `open` on \<fcntl.h>

# 4. Demo