# 1. get_next_line

이 프로젝트는 C언어로 fd로부터 한 번에 한 줄씩 읽어오는 라이브러리 함수를 개발합니다.

# 2. 사용 가능 외부 함수

1. \<unistd.h>의 `read`
2. \<stdlib.h>의 `malloc`
3. \<stdlib.h>의 `free`

# 3. prototype

| Name | Parameters | Return |
| - | - | - |
| get_next_line | int fd | char * |

# 4. Features

1. 반복 호출 (예: 루프를 사용하여)하여 get_next_line() 함수를 호출하면 파일 디스크립터가 가리키는 텍스트 파일을 한 번에 한 줄씩 읽어야 합니다.

2. 함수는 읽은 줄을 반환해야 합니다. 읽을 것이 더 이상 없거나 오류가 발생하면 NULL을 반환해야 합니다.

3. 버퍼링을 구현하기 위해 정적(static) 변수를 활용 합니다.

4. 전체 파일을 읽은 후 각 줄을 처리하는 방식으로 구현하지 않아야 합니다.

# 5. 호출 예시

```c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Failed to open file");
        return (1);
    }

    // 파일 끝까지 get_next_line() 함수를 반복 호출하여 줄을 읽습니다.
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Sentence: %s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```
