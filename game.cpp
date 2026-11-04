#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
// Состояние игры (базовые переменные)
int hp = 100;
int resources = 50; // Евродоллары
int score = 0; // Очки репутации (Street cred)
int turn = 1;
void printHUD() {
 std::cout << "\n================ [ХОД: " << turn << " | STREET CRED: " << score
<< "] ================\n";
 std::cout << "♥︎ Биомонитор (hp): " << hp << "/100 | ◼ Чип валюты: " <<
resources << "\n";
 std::cout << "--------------------------------------------------------
\n";
}
// -------------------------------------------------------------
// [МЕСТО ДЛЯ ФУНКЦИЙ РАЗРАБОТЧИКОВ ИЗ PULL REQUEST'ОВ]
// -------------------------------------------------------------

// Разработчик 1: Функция риска (Issue #1) — Заказ от фиксера (Контракт)
void takeFixerJob() {
    std::cout << "\n Вакадо или Рехина присылают вам опасный заказ: налет на конвой «Арасаки»...\n";

    // Шанс ~50% (через rand() % 2)
    if (rand() % 2 == 0) {
        int lootEddies = 100 + rand() % 201; // +100-300 эдди
        int bonusCred = 200 + rand() % 301;  // +200-500 Street Cred
        resources += lootEddies;
        score += bonusCred;
        std::cout << "УСПЕХ! Вы взломали терминал конвоя. Получено +" << lootEddies << " €$ и +" << bonusCred << " к репутации!\n";
    } else {
        int damage = 30 + rand() % 21; // 30-50 урона
        hp -= damage;
        std::cout << "ЗАСАДА! Элитные штурмовики «Макс-Так» зажали вас в переулке. Получено " << damage << " ед. урона.\n";
    }
}

int main() {
 srand(time(NULL));
 int choice = 0;
 std::cout << ">>> ЗАПУСК СИМУЛЯЦИИ: ДОБРО ПОЖАЛОВАТЬ В НАЙТ-СИТИ (CYBERPUNK 2077) <<<\n";
 while (hp > 0) {
 printHUD();
 std::cout << "1. Заказ от фиксера (Контракт / Риск)\n";
 std::cout << "2. Клиника Рипера (Установка хрома и МаксДок)\n";
 std::cout << "3. Точка доступа Сети (Взлом и Нетраннинг)\n";
 std::cout << "0. Уехать из города и зафиксировать репутацию\n";
 std::cout << "Выберите действие > ";
 if (!(std::cin >> choice)) break;

 switch (choice) {
 case 1:
takeFixerJob();
break;
 case 2:
 // [РАЗРАБОТЧИК 2: ПОДКЛЮЧИТ МОДУЛЬ ОТХИЛА (ISSUE #2)]
 std::cout << "\n[!] Модуль лагеря еще в разработке (Issue
#2).\n";
 break;
 case 3:
 // [РАЗРАБОТЧИК 3: ПОДКЛЮЧИТ РУЛЕТКУ/БОССА (ISSUE #3)]
 std::cout << "\n[!] Модуль событий еще в разработке (Issue
#3).\n";
 break;
 case 0:
 hp = 0;
 break;
 default:
 std::cout << "\nНеизвестная команда на чипе!\n";
 break;
 }
 // Каждый успешный ход дает очки Street Cred
 if (hp > 0) {
 turn++;
 score += 10;
 }
 }
 std::cout << "\n💀 СИМУЛЯЦИЯ ОКОНЧЕНА. Вы стали легендой Найт-Сити с рекордом: " << score << "
Street Cred!\n";
 return 0;
}
