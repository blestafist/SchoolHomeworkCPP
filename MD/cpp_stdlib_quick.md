# C/C++ Встроенные Библиотеки - Шпаргалка

## 📌 Основные C библиотеки

| Библиотека | Для чего | Основные функции |
|-----------|---------|-----------------|
| `<stdio.h>` | Ввод/вывод | `printf()`, `scanf()`, `fopen()`, `fread()` |
| `<stdlib.h>` | Память, числа | `malloc()`, `free()`, `atoi()`, `rand()` |
| `<string.h>` | Строки (C) | `strlen()`, `strcpy()`, `strcat()`, `strcmp()` |
| `<math.h>` | Математика | `sqrt()`, `pow()`, `sin()`, `cos()` |
| `<time.h>` | Время | `time()`, `clock()`, `ctime()` |
| `<ctype.h>` | Символы | `isalpha()`, `toupper()`, `tolower()` |
| `<limits.h>` | Границы типов | `INT_MAX`, `LONG_MIN` |

**⚠️ Компилировать с `-lm` если используешь `<math.h>`**

---

## 🚀 Важные C++ библиотеки

| Библиотека | Для чего | Когда использовать |
|-----------|---------|-------------------|
| `<iostream>` | Ввод/вывод | **Всегда** вместо `printf/scanf` |
| `<string>` | Строки (C++) | **Всегда** вместо `char*` |
| `<vector>` | Массивы | Когда размер заранее неизвестен |
| `<map>` | Словарь (отсортирован) | Нужен порядок, меньше памяти |
| `<unordered_map>` | Словарь (быстрый) | Нужна скорость O(1) поиска |
| `<set>` | Множество (отсортировано) | Уникальные элементы в порядке |
| `<unordered_set>` | Множество (быстрое) | Быстрая проверка наличия |
| `<algorithm>` | Алгоритмы | `sort()`, `find()`, `count()` |
| `<memory>` | Умные указатели | `unique_ptr`, `shared_ptr` вместо `new/delete` |
| `<queue>` | Очередь FIFO | `push()`, `pop()`, `front()` |
| `<stack>` | Стек LIFO | `push()`, `pop()`, `top()` |
| `<chrono>` | Время (C++) | Измерение времени выполнения |
| `<random>` | Случайные числа | Вместо `rand()` |
| `<exception>` | Исключения | `try/catch`, `throw` |
| `<numeric>` | Вычисления | `accumulate()`, `iota()` |
| `<regex>` | Регулярные выражения | Поиск/замена по шаблону |
| `<functional>` | Функции | `std::function`, `bind()` |

---

## 💡 Быстрые примеры

### Ввод/вывод
```cpp
#include <iostream>
std::cout << "Hello" << std::endl;
std::cin >> x;
```

### Строки
```cpp
#include <string>
std::string s = "Hello";
s.find("llo");        // Поиск
s.substr(0, 2);       // Подстрока
```

### Массивы
```cpp
#include <vector>
std::vector<int> v = {1, 2, 3};
v.push_back(4);       // Добавить
v.size();             // Размер
```

### Сортировка
```cpp
#include <algorithm>
std::sort(v.begin(), v.end());
std::sort(v.begin(), v.end(), std::greater<int>());  // Убывание
```

### Словари
```cpp
#include <map>
std::map<std::string, int> m;
m["key"] = 10;
m.find("key");        // Поиск
```

### Время
```cpp
#include <chrono>
auto start = std::chrono::high_resolution_clock::now();
// код
auto elapsed = std::chrono::high_resolution_clock::now() - start;
```

### Умные указатели
```cpp
#include <memory>
auto ptr = std::make_unique<int>(42);     // Исключительное владение
auto shared = std::make_shared<int>(10);  // Общее владение
```

### Случайные числа
```cpp
#include <random>
std::mt19937 gen(std::random_device{}());
std::uniform_int_distribution<> dis(1, 100);
int random_num = dis(gen);
```

---

## 🎯 Выбор контейнера

**Нужны быстрые вставка/удаление в начало/конец?** → `std::deque`
**Нужны быстрые вставка/удаление в середину?** → `std::list`
**Нужна скорость?** → `std::vector` (по умолчанию)
**Ключ-значение с порядком?** → `std::map`
**Ключ-значение без порядка (быстро)?** → `std::unordered_map`
**Уникальные значения?** → `std::set` / `std::unordered_set`

---

## 📝 Флаги компиляции

```bash
g++ file.cpp -o prog              # Базовая компиляция
g++ -std=c++17 file.cpp -o prog   # С C++17
g++ -O2 file.cpp -o prog          # Оптимизация
g++ -g file.cpp -o prog           # Отладка
g++ file.cpp -o prog -lm          # С математикой
g++ -Wall -Wextra file.cpp -o prog # Все warnings
```

---

**Правило:** В новом C++ коде забудь про C функции - используй STL контейнеры и алгоритмы! 🚀
