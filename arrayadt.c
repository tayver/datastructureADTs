#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int loc = 0;
int max = 0;
int t = 0;

void insert(char * arr, char data);
void traverse_front(char * arr, int count);
void traverse_rear(char* arr, int count);
void delete (char* arr);
void get_data(char* arr);
void replace(char* arr, char new_data);
void empty(char* arr);
void move(char* arr, char new_position);
int data_count();
void print(char* arr);
int count(char* cm);
void is_Full(char* arr);                //나만의 기능1
void replace_at(char* arr, char* cm);   //나만의 기능2
void switch_data(char* arr, char at);   //나만의 기능3

int main(void) {
    char my_array[30];  //create(array)
    char cmd[3];
    int i = 0;

    while (1) {
        printf("명령을 입력해주세요:");
        scanf("%s", cmd);

        switch (cmd[0]) {
        case '+':
            insert(my_array, cmd[1]);
            t = t + 1;
            break;

        case '<':
            traverse_front(my_array, count(cmd));
            break;

        case '>':
            traverse_rear(my_array, count(cmd));
            break;

        case '-':
            delete(my_array);
            break;

        case '@':
            get_data(my_array);
            break;

        case '=':
            replace(my_array, cmd[1]);
            break;

        case 'E':
            empty(my_array);
            break;

        case 'M':
            move(my_array, cmd[1]);
            break;

        case 'L':
            print(my_array);
            break;

        case 'F':
            is_Full(my_array);
            break;

        case 'R':
            replace_at(my_array, cmd);
            break;

        case 'S':
            switch_data(my_array, cmd[1]);
            break;

        default:
            printf("\n종료되었습니다.");

        }
        
    }
    return 0;
}
void insert(char* arr, char data) {
    if (t == 0) {
        loc = 0;
        arr[loc] = data;
    }
    else {
        if (loc == max)
            arr[loc + 1] = data;
        else {
            for (int i = max; i > loc; i--) {
                arr[i + 1] = arr[i];
            }
            arr[loc + 1] = data;
        } 
        loc++;
        max++;
    } 
}
void traverse_front(char* arr, int count) {
    loc = 0;
    loc = loc + count;
    loc = loc % (max + 1);
}
void traverse_rear(char* arr, int count) {
    loc = max;
    loc = max + count;
    loc = loc % (max+1);
}
void delete (char* arr) {
    for (int i = loc; i < max; i++) {
        arr[i] = arr[i + 1];
    }
    arr[max] = '0';
    if (max == loc)
        loc = 0;
    max--;

}
void get_data(char* arr) { printf("해당 문자: %c\n", arr[loc]); }
void replace(char* arr, char new_data) {
    arr[loc] = new_data;
}
void empty(char* arr) {
    for (int i = max; i >= 0; i--)
        arr[i] = '0';
    loc = 0;
    max = 0;
    t = 0;
    printf("empty array\n");

}

void move(char* arr, char new_position) {
    char k;
    int new_p=0;

    if (new_position == 'n') {
        new_p = data_count();
        k = arr[new_p];
        arr[new_p] = arr[loc];
        arr[loc] = k;
        for (int i = 1; i < new_p; i++) {
            k = arr[new_p - i];
            arr[new_p - i] = arr[loc];
            arr[loc] = k;
        }
    }
    else if (new_position == 'P') {
        k = arr[loc - 1];
        arr[loc - 1] = arr[loc];
        arr[loc] = k;
        new_p = loc - 1;
    }
    else if (new_position == 'N') {
        k = arr[loc + 1];
        arr[loc + 1] = arr[loc];
        arr[loc] = k;
        new_p = loc + 1;
    }
    else {
        new_p = new_position - '0';
        k = arr[new_p];
        arr[new_p] = arr[loc];
        arr[loc] = k;

        if (new_p > loc) {
            for (int i = 1; i < new_p; i++) {
                k = arr[new_p - i];
                arr[new_p - i] = arr[loc];
                arr[loc] = k;
            }
        }
        else {
            for (int i = 1; i < loc - new_p; i++) {
                k = arr[new_p + i];
                arr[new_p + i] = arr[loc];
                arr[loc] = k;
            }
        }
    }

    loc = new_p;
}
int data_count() {
    return max;
}

void print(char* arr) {
    for (int i = 0; i <= max; i++) {
        printf("%c\t", arr[i]);
    }
    printf("\n");
    for (int i = 0; i <= max; i++) {
        if (i == loc)
            printf("-\t");
        else
            printf(" \t");
    }
    printf("\n");
}
void is_Full(char* arr) {
    if (max == 30)
        printf("배열이 가득 찼습니다.\n");
    else
        printf("아직 공간이 남았습니다.\n");
}
int count(char* cm) {
    int add = 0;

    for (int i = 1; i < 3; i++) {
        if (cm[i] == 'N')
            add = add + 1;
        else if (cm[i] == 'P')
            add = add - 1;
    }

    return add;
}
void replace_at(char* arr, char* cm) {
    int k = cm[1] - '0';
    arr[k] = cm[2];
}
void switch_data(char* arr, char at) {
    char in;
    int k = at - '0';

    in = arr[k];
    arr[k] = arr[loc];
    arr[loc] = in;
}
