# 1. Libft란?

이 프로젝트는 `Libc`의 구현입니다. 일부 42 프로젝트는 라이브러리 사용이 제한되지만, Libft는 사용 가능합니다.
루트에 (all, clean, fclean, re)규칙을 제공하는 `Makefile`이 있습니다. 이를 통해 `libft.a` 정적 라이브러리 파일을 만들 수 있습니다. 

* 필수 항목
  > make all

* 보너스 항목
  > make bonus

# 2. 허용되는 외부 함수

1. \<unistd.h>의 `write`
2. \<stdlib.h>의 `malloc`
3. \<stdlib.h>의 `free`

# 3. Libft 라이브러리 함수

## 1) 필수 항목

| 이름           | 매개변수                                      | 반환값   |
|----------------|-----------------------------------------------|----------|
| `ft_atoi`      | const char *s                                 | int      |
| `ft_itoa`      | int n                                         | char *   |
| `ft_bzero`     | void *s, size_t n                             | void     |
| `ft_calloc`    | size_t cnt, size_t n                          | void *   |
| `ft_isalnum`   | int c                                         | int      |
| `ft_isalpha`   | int c                                         | int      |
| `ft_isascii`   | int c                                         | int      |
| `ft_isdigit`   | int c                                         | int      |
| `ft_isprint`   | int c                                         | int      |
| `ft_memccpy`   | void *dst, const void *src, int c, size_t n   | void *   |
| `ft_memcpy`    | void *dst, const void *src, size_t n          | void *   |
| `ft_memmove`   | void *dst, const void *src, size_t n          | void *   |
| `ft_memset`    | void *s, int c, size_t n                      | void *   |
| `ft_memchr`    | const void *s, int c, size_t n                | void *   |
| `ft_memcmp`    | const void *s1, const void *s2, size_t n      | int      |
| `ft_putchar_fd`| char c, int fd                                | void     |
| `ft_put_endl`  | char *s, int fd                               | void     |
| `ft_putnbr_fd` | int n, int fd                                 | void     |
| `ft_putstr_fd` | char *s, int fd                               | void     |
| `ft_split`     | char const *s, char c                         | char **  |
| `ft_strchr`    | const char *s, int c                          | char *   |
| `ft_strrchr`   | const char *s, int c                          | char *   |
| `ft_strdup`    | const char *s                                 | char *   |
| `ft_strjoin`   | char const *s1, char const *s2                | char *   |
| `ft_strlcat`   | char *dst, const char *src, size_t dstsize    | size_t   |
| `ft_strlcpy`   | char *dst, const char *src, size_t dstsize    | size_t   |
| `ft_strlen`    | const char *s                                 | size_t   |
| `ft_strmapi`   | char const *s, char (*f)(unsigned int, char)  | char *   |
| `ft_strncmp`   | const char *s1, const char *s2, size_t n      | int      |
| `ft_strnstr`   | const char *s1, const char *set, size_t n     | char *   |
| `ft_strtrim`   | char const *s1, char const *set               | char *   |
| `ft_substr`    | char const *s, unsigned int start, size_t len | char *   |
| `ft_tolower`   | int c                                         | int      |
| `ft_toupper`   | int c                                         | int      |

## 2) 보너스

| 이름            | 매개변수                              | 반환값  |
|-----------------|---------------------------------------|---------|
| `ft_lstadd_back`| t_list **lst, t_list *new             | void    |
| `ft_lstadd_front`| t_list **lst, t_list *new            | void    |
| `ft_lstclear`   | t_list **lst, void (*del)(void *)     | void    |
| `ft_lstdelone`  | t_list *lst, void (*del)(void *)      | void    |
| `ft_lstiter`    | t_list *lst, void  (*f)(void *)       | void    |
| `ft_lstmap`     | t_list *lst, void *(*f)(void *), void (*del)(void *) | t_list * |
| `ft_lstlast`    | t_list *lst                           | t_list *|
| `ft_lstnew`     | void *content                         | t_list *|
| `ft_lstsize`    | t_list *lst                           | int     |
