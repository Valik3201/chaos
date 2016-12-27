#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <locale.h>


typedef struct abit_info
{
	char first_name[20];
	char last_name[20];
	int age;
    char subjects[20];
}abit_info;


char* input_name()
{
    int input_check = 0;
	char name[20];
	while (input_check == 0)
	{
		fflush(stdin);
		printf("Введите имя: ");
		scanf("%s", &name);
		if (strchr(name, '0') || strchr(name, '1') || strchr(name, '2') || strchr(name, '3') || strchr(name, '4') ||
			strchr(name, '5') || strchr(name, '6') || strchr(name, '7') || strchr(name, '8') || strchr(name, '9') ||
            strchr(name, '/') || strchr(name, '*') || strchr(name, '+') || strchr(name, '-') || strchr(name, '=') || strchr(name, '[') || strchr(name, ']') || strchr(name, ';'))
		{
			system("color F4");printf("Ошибка!\n");system("pause");system("color F1");
			getchar();
			system("cls");
		}
		else input_check = 1;
	}

	return name;
}


char* input_surname()
{
    int input_check = 0;
	char surname[20];
	while (input_check == 0)
	{
		fflush(stdin);
		printf("Введите фамилию: ");
		scanf("%s",&surname);
		if (strchr(surname, '0') || strchr(surname, '1') || strchr(surname, '2') || strchr(surname, '3') || strchr(surname, '4') ||
			strchr(surname, '5') || strchr(surname, '6') || strchr(surname, '7') || strchr(surname, '8') || strchr(surname, '9') ||
            strchr(surname, '/') || strchr(surname, '*') || strchr(surname, '+') || strchr(surname, '-') || strchr(surname, '=') || strchr(surname, '[') || strchr(surname, ']') || strchr(surname, ';'))
		{
			system("color F4");printf("Ошибка!\n");system("pause");system("color F1");
			getchar();
			system("cls");
		}
		else input_check = 1;
	}
	system("cls");
	return surname;
}

int input_age()
{
	int error;
	float age;

	do {
		fflush(stdin);
        do {

			printf("Введите возвраст: ");
			error = scanf("%f", &age);

			if (error != 1) {
				printf("Введенное не число. Введите заново: "); fflush(stdin);
			}

			char c;
			while ((c = getchar()) != '\n' && c != EOF) {}

			if (int(age)-age!=0)
                {
                system("color F4");printf("Ошибка!\n");system("color F1");
                getchar();
                error = 0;
                }
        else {
			error = 1;
		}

        if (age <= 0){
            system("color F4");printf("Ошибка! Отрицательное число!\n");system("color F1");
            getchar();
			error = 0;}
		else {
			error = 1;
		}
	} while ((error != 1));

	        if (age > 100){
            system("color F4");printf("Ошибка! Нажмите ENTER и введите заново!");system("color F1"); fflush(stdin);
            getchar();
			error = 0;}
		else {
			error = 1;
		}
	} while ((error == 0));

	return age;
}


int main(int argc, char *argv[])
{
    system("color F1");
    setlocale(LC_ALL, "Rus");

    abit_info *abit1 = NULL;
    abit1 = (abit_info *) malloc(sizeof(abit_info));

	int i, n;
	int error;

	strcpy(abit1->first_name, input_name());
	fflush(stdin);

    system("cls");

	strcpy(abit1->last_name, input_surname());
	fflush(stdin);

	system("cls");

	abit1->age = input_age();

	system("cls");

	printf("\n\nКонец!");
	free(abit1);

	_getch();
	return 0;
}
