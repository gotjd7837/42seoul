#include <stdio.h>
#include <stdlib.h>

int* convert_to_int_array(char* numbers[], int size) {
    int* int_array = malloc(size * sizeof(int));
    
    if (int_array == NULL) {
        printf("메모리 할당 오류\n");
        return NULL;
    }
    
    for (int i = 0; i < size; i++) {
        int_array[i] = atoi(numbers[i]);
    }
    
    return int_array;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("사용법: 프로그램명 숫자1 숫자2 숫자3 ...\n");
        return 1;
    }
    
    int size = argc - 1;
    int* int_array = convert_to_int_array(&argv[1], size);
    
    if (int_array != NULL) {
        printf("변환된 배열: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", int_array[i]);
        }
        printf("\n");
    }
    
    // 동적 할당된 메모리 해제
    free(int_array);
    
    return 0;
}