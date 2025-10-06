#include <stdio.h>
#include <mtool.h>
#include <cxlib.h>

int BMR(int gender, int height, int weight, int years);
int Daily_Calories(int bmr);
int Balance (int calories);

int main(void)
{
    int gender;
    do
    {
        printf("Укажите ваш пол (1 - мужчина, 2 - женщина): ");
        scanf("%i", &gender);
        
        if (gender != 1 && gender != 2)
        { 
            cprintf(C_RED, "Ошибка! Введите 1 или 2\n"); 
        }
        while (getchar() != '\n');
    } 
    while (gender != 1 && gender != 2);

    int height = m_get_int("Укажите ваш рост в см: ");
    int weight = m_get_int("Укажите ваш вес в кг: ");
    int years = m_get_int("Укажите возраст в годах: ");

    int bmr = BMR(gender, height, weight, years);
    Daily_Calories(bmr);
    
    return 0;
}

int BMR(int gender, int height, int weight, int years)
{
    int bmr;
    if (gender == 1)
    {
        bmr = 10 * weight + 6.25 * height - 5 * years + 5;
    }
    else
    {
        bmr = 10 * weight + 6.25 * height - 5 * years - 161;
    }
    
    cprintf(C_YELLOW, "Ваш базовый метаболизм (BMR): %i ккал\n", bmr);
    return bmr;
}

int Daily_Calories(int bmr)
{
    int coef;
    do
    {
        printf("\nУкажите вашу физическую активность:\n");
        printf("1 - Сидячий образ жизни\n");
        printf("2 - Небольшая активность\n");
        printf("3 - Умеренная активность\n");
        printf("4 - Высокая активность\n");
        printf("5 - Очень высокая активность\n");
        printf("Ваш выбор: ");
        scanf("%i", &coef);
        
        if (coef < 1 && coef > 5)
        { 
            cprintf(C_RED, "Ошибка! Введите число от 1 до 5\n"); 
        }
        while (getchar() != '\n');
    } 
    while (coef < 1 && coef > 5);

    double coef2;
    switch (coef)
    {
        case 1: coef2 = 1.2; break;
        case 2: coef2 = 1.375; break;
        case 3: coef2 = 1.55; break;
        case 4: coef2 = 1.725; break;
        case 5: coef2 = 1.9; break;
        default: coef2 = 1.2; break;
    }

    int calories = bmr * coef2;

    cprintf(C_MAGENTA, "\n===== РЕЗУЛЬТАТ =====\n");
    cprintf(C_YELLOW, "Базовый метаболизм (BMR): %i ккал\n", bmr);
    cprintf(C_GREEN, "Суточная норма калорий: %i ккал\n\n", calories);

    Balance(calories);

    return calories;

}

int Balance (int calories)
{
    int or;
    do
    {
        printf("Отлично! Теперь давайте определим что вы хотите сделать (1 - похудеть, 2 - набрать): ");
        scanf("%i", &or);
        
        if (or != 1 && or != 2)
        { 
            cprintf(C_RED, "Ошибка! Введите 1 или 2\n"); 
        }
        while (getchar() != '\n');
    }
    while (or != 1 && or != 2);

    int balance;
    if ( or == 1)
    {
        balance = calories - 400;
    }
    else
    {
        balance = calories + 400;
    }
    cprintf (C_BLUE,"Для достижения вашей цели вам нужно питаться на %i ккал в день\n", balance);

    return balance;
}