# 1. Philosophers
이 프로젝트는 동기화 문제에서 데드락과 기아 문제를 보여줄 수 있는 식사하는 철학자들(Dining Philosophers)을 C언어로 구현한 것입니다.
프로세스에서 스레드를 생성하는 기본 개념을 배우고, 뮤텍스를 사용하여 상호배제를 구현하는 방법을 익히게 됩니다.
폴더에 (all, clean, fclean, re)규칙을 제공하는 `Makefile`이 있습니다. 이를 통해 소스 코드를 컴파일 하여 `philo`프로그램을 생성합니다.

* `philo` 컴파일
> make all

# 2. 실행 방법

`philo`는 각 철학자의 상태를 타임라인에 따라 메시지로 출력합니다.
프로그램에 몇 가지 인자가 필요합니다. 아래 인수는 모두 숫자 값으로 구성되어야 하며, 마지막 인수는 선택 사항입니다.
> ./philo \<number-of-philosophers> \<time-to-die> \<time-to-eat> \<time-to-sleep> [\<number-of-times-each-philosophers-eat]>
차례대로 철학자의 수, 철학자가 죽는 시간, 철학자가 먹는 시간, 철학자가 자는 시간, [철학자가 먹어야 하는 횟수]


# 3. 허용 함수

1. `memset` on \<string.h>
2. `printf` on \<stdio.h>
3. `malloc` on \<stdlib.h>
4. `free` on \<stdlib.h>
5. `write` on \<unistd.h>
6. `usleep` on \<unistd.h>
7. `gettimeofday` on \<sys/time.h>
8. `pthread_create` on \<pthread.h>
9. `pthread_detach` on \<pthread.h>
10. `pthread_join` on \<pthread.h>
11. `pthread_mutex_init` on \<pthread.h>
12. `pthread_mutex_destroy` on \<pthread.h>
13. `pthread_mutex_lock` on \<pthread.h>
14. `pthread_mutex_unlock` on \<pthread.h>

# 5. Features

1. 철학자들은 원형 테이블에 앉아 있으며, 테이블 중앙에는 스파게티가 있습니다.
2. 철학자들은 번갈아 가며 먹고, 생각하고, 잡니다.
3. 철학자가 먹거나, 생각하거나, 잘때는 다른 행동을 하지 않습니다.
4. 테이블 위에는 철학자 수만큼의 포크가 있습니다.
5. 철학자는 먹기 위해 오른쪽과 왼쪽에 있는 포크를 집어야 합니다.
6. 철학자가 식사를 마치면 포크를 내려놓고 잠을 잡니다. 깨어나면 다시 생각을 시작합니다.
7. 시뮬레이션은 철학자가 굶어 죽을 때 종료됩니다.
8. 모든 철학자는 반드시 먹어야 하며, 굶어 죽지 않아야 합니다.
9. 철학자들은 서로의 상태를 모릅니다.
10. 최대한 철학자가 죽지 않도록 해야합니다.

# 6. Demo

