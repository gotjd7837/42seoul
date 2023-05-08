# ft_printf

이 프로젝트는 꽤 단순합니다. libc의 printf 함수를 직접 구현하면 됩니다.

| **프로그램 이름**            | libftprintf.a                                                             |
| ---------------------------- | ------------------------------------------------------------------------- |
| **제출할 파일**              | \*.c, \*/\*.c, \*.h, \*/\*.h, Makefile                                    |
| **Makefile 규칙**            | all, clean, fclean, re, bonus                                             |
| **사용가능한 <br>외부 함수** | malloc, free, write, va_start, va_arg, va_copy, va_end                    |
| **직접 만든 libft**          | 사용 가능                                                                 |
| **설명**                     | 실제 printf의 동작을 모방한 ft_printf를 포함하는 라이브러리를 작성하세요. |

- ft_printf의 프로토타입은 `int ft_printf(const char , ...);`
- 실제 printf 함수처럼 버퍼 관리를 수행해서는 안 됩니다.
- 다음과 같은 서식 지정자들을 구현할 것입니다: **cspdiuxX%**
- 라이브러리를 생성할 때에는 ar 명령어를 이용하세요. libtool 명령어는 허용되지 않습니다.

# 구현
이번 프로젝트에서는 소스파일 갯수의 제한이 없으므로 구현에 필요한 함수를 libft 프로젝트와 라피신에서 구현한 소스파일을 조금 수정해서 사용했다.

## ft_printf.c
`ft_printf` 함수와 입력 받은 서식 지정자 별로 출력 시켜주는 함수 `int convert(const char *format, va_list ap);` 구현

각 서식 지정자별로 출력하는 함수를 별도의 소스 파일로 작성
- `convert_d_i.c` `convert_p.c` `convert_per.c` `convert_s.c` `convert_u.c` `convert_x.c`

libft, 라피신에서 구현한 소스파일
- `ft_itoa.c` `ft_memory_base.c` `ft_putchar.c` `ft_putnbr_base.c` `ft_putstr.c` `ft_strlen.c` `ft_unsigned_itoa.c`
