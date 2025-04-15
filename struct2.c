#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h> 
#define LEN_STR 50
#define MAX_SELES_MAN 100
#define FILENAME "salesmen.dat"

typedef struct {
    char name[LEN_STR];
    char city[LEN_STR];
    int snum;
    float comm;
} SelesMan;

void input_seles_men(SelesMan *s, int num) {
    printf("Введите фамилию и инициалы: ");
    fgets(s->name, sizeof(s->name), stdin);
    s->name[strcspn(s->name, "\n")] = '\0';
    
    printf("Введите город: ");
    fgets(s->city, sizeof(s->city), stdin);
    s->city[strcspn(s->city, "\n")] = '\0';
    
    printf("Введите комиссионные: ");
    scanf("%f", &s->comm);
    while(getchar() != '\n');
    
    s->snum = num + 1;
}

void output_seles_men(SelesMan *s, int count) {
    if (count == 0) {
        printf("Нет данных о продавцах.\n");
        return;
    }
    
    printf("\n+-------+--------------------+--------------+-----------+\n");
    printf("|  id   |        name        |     city     | commision |\n");
    printf("+-------+--------------------+--------------+-----------+\n");
    
    for (int i = 0; i < count; i++) {
        printf("|%-7d|%-20s|%-14s|%-11.2f|\n", 
              s[i].snum, s[i].name, s[i].city, s[i].comm);
        printf("+-------+--------------------+--------------+-----------+\n");
    }
}

void save_to_file(SelesMan *s, int count) {
    FILE *file = fopen(FILENAME, "wb");
    if (!file) {
        printf("Ошибка открытия файла для записи!\n");
        return;
    }
    
    fwrite(&count, sizeof(int), 1, file);
    
    fwrite(s, sizeof(SelesMan), count, file);
    
    fclose(file);
    printf("Данные успешно сохранены в файл %s\n", FILENAME);
}

int load_from_file(SelesMan *s) {
    FILE *file = fopen(FILENAME, "rb");
    if (!file) {
        printf("Файл %s не найден или не может быть открыт\n", FILENAME);
        return 0;
    }
    
    int count;
    fread(&count, sizeof(int), 1, file);
    
    if (count > MAX_SELES_MAN) {
        printf("Ошибка: в файле слишком много записей\n");
        fclose(file);
        return 0;
    }
    
    fread(s, sizeof(SelesMan), count, file);
    
    fclose(file);
    printf("Загружено %d записей из файла %s\n", count, FILENAME);
    return count;
}

void print_menu() {
    printf("\nМеню:\n");
    printf("1. Добавить продавца\n");
    printf("2. Показать всех продавцов\n");
    printf("3. Сохранить данные в файл\n");
    printf("4. Загрузить данные из файла\n");
    printf("5. Выход\n");
    printf("Выберите действие: ");
}

int main() {
    SelesMan SELS[MAX_SELES_MAN];
    int NUM_SEL = 0;
    
    system("clear");    
    NUM_SEL = load_from_file(SELS);
    
    while(true) {
        print_menu();
        
        int command_index;
        if (scanf("%d", &command_index) != 1) {
            printf("Ошибка ввода!\n");
            while(getchar() != '\n');
            continue;
        }
        while(getchar() != '\n');
        
        switch(command_index) {
            case 1:
		system("clear");    
                if (NUM_SEL >= MAX_SELES_MAN) {
                    printf("Достигнуто максимальное количество продавцов (%d)\n", MAX_SELES_MAN);
                    break;
                }
                input_seles_men(&SELS[NUM_SEL], NUM_SEL);
                NUM_SEL++;
                break;
                
            case 2:
		system("clear");    
                output_seles_men(SELS, NUM_SEL);
                break;
                
            case 3:
		system("clear");    
                save_to_file(SELS, NUM_SEL);
                break;
                
            case 4:
		system("clear");    
                NUM_SEL = load_from_file(SELS);
                break;
                
            case 5:
		system("clear");    
                printf("Выход...\n");
                exit(0);
                
            default:
		system("clear");    
                printf("Неверный ввод! Введите число от 1 до 5.\n");
        }
    }
}
