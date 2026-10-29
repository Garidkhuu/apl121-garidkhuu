#include <stdio.h>
#include <string.h>
 
// Зогсоолын төлбөр тооцоолох функц (else-if шатлал)
int calcFee(int minutes) {
    int fee = 0;
    if (minutes <= 30) {
        fee = 0;
    } else if (minutes <= 60) {
        fee = 1500;
    } else if (minutes <= 120) {
        fee = 3500;
    } else {
        // 120 минутаас хэтэрсэн эхэлсэн цаг бүрт 1000 тугрик нэмнэ
        fee = 3500 + ((minutes - 120 + 59) / 60) * 1000;
    }
    return fee;
}
 
int main() {
    int i;
    char plate[20];
    char maxPlate[20] = "";
    int entryHour, entryMinute, exitHour, exitMinute;
    int entryTotal, exitTotal, parkedMinutes, fee;
    int totalIncome = 0;
    int maxMinutes = 0;
 
    // Хүснэгтийн толгой
    printf("%-3s | %6s | %8s | %s\n", "No", "Minut", "Tulbur", "Dugaar");
 
    // 5 машины мэдээллийг авах давталт
    for (i = 1; i <= 5; i++) {
        printf("Mashinii dugaar: ");
        scanf("%19s", plate);
 
        // Оролтын шалгалт: буруу бол орсон, гарсан цагийг дахин асууна
        do {
            printf("Orson tsag (0-23): ");
            scanf("%d", &entryHour);
            printf("Orson minut (0-59): ");
            scanf("%d", &entryMinute);
            printf("Garsan tsag (0-23): ");
            scanf("%d", &exitHour);
            printf("Garsan minut (0-59): ");
            scanf("%d", &exitMinute);
 
            entryTotal = entryHour * 60 + entryMinute;
            exitTotal = exitHour * 60 + exitMinute;
        } while (entryHour < 0 || entryHour > 23 ||
                 entryMinute < 0 || entryMinute > 59 ||
                 exitHour < 0 || exitHour > 23 ||
                 exitMinute < 0 || exitMinute > 59 ||
                 exitTotal <= entryTotal);
 
        parkedMinutes = exitTotal - entryTotal;
 
        // Функц дуудаж төлбөр бодох
        fee = calcFee(parkedMinutes);
        totalIncome = totalIncome + fee;
 
        // Хамгийн удаан зогссон машиныг хайх
        if (parkedMinutes > maxMinutes) {
            maxMinutes = parkedMinutes;
            strcpy(maxPlate, plate);
        }
 
        // Хүснэгтийн нэг мөр
        printf("%-3d | %6d | %8d | %s\n", i, parkedMinutes, fee, plate);
    }
 
    printf("Niit orlogo: %d\n", totalIncome);
    printf("Hamgiin udaan: %s (%d min)\n", maxPlate, maxMinutes);
    return 0;
}
 