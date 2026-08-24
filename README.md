# Geometry++

**Ultimate (почти) 2D Geometry Library for C++**

[![C++](https://img.shields.io/badge/C++-17-blue.svg)](https://isocpp.org/)
[![License](https://img.shields.io/badge/license-MIT-green.svg)](LICENSE)
[![GitHub stars](https://img.shields.io/github/stars/FedorovIaromir/geometry-plus-plus.svg?style=social)](https://github.com/FedorovIaromir/geometry-plus-plus/stargazers)

---

##  Описание

**Geometry++** — это полноценная библиотека для 2D вычислительной геометрии на C++17. Она предоставляет более **100 функций** и **60 перегруженных операторов** для интуитивной работы с:

-  **Точки** (`Point`)
-  **Векторы** (`Vector`)
-  **Прямые** (`Line`)
-  **Отрезки** (`Segment`)
-  **Ограничивающие прямоугольники** (`BBox`)
-  **Окружности** (`Circle`)
-  **Треугольники** (`Triangle`)

Всё, что нужно для решения геометрических задач — от простых расстояний до сложных пересечений и центров треугольников.

---

##  Документация

**Полная документация** доступна в файле:  
 [`Geometry++_Документация.docx`](Geometry++_Документация.docx) (на русском языке)

Или вызовите справку прямо в коде:

```cpp
HELP();  // Выведет полный справочник в консоль
```

---

##  Быстрый старт

### Подключение

```cpp
#include "geometry++.h"
using namespace std;

int main() {
    // Ваш код здесь
    return 0;
}
```

### Пример 1: пересечение окружностей

```cpp
Circle c1 = {{0, 0}, 5};
Circle c2 = {{8, 0}, 5};
IntersectOut res = c1 & c2;

if (res.num == 2) {
    cout << "Точки пересечения: " << res.P1 << " и " << res.P2 << endl;
}
```

### Пример 2: работа с треугольником

```cpp
Triangle t = {{0, 0}, {4, 0}, {1, 3}};

cout << "Площадь: " << area(t) << endl;
cout << "Периметр: " << perimeter(t) << endl;
cout << "Центроид: " << centroid(t) << endl;
cout << "Угол A: " << r2d(angleA(t)) << "°" << endl;

cout << boolalpha;
cout << "Остроугольный: " << isAcute(t) << endl;
cout << "Прямоугольный: " << isRight(t) << endl;
cout << "Тупоугольный: " << isObtuse(t) << endl;
```

### Пример 3: расстояние и принадлежность

```cpp
Point A = {1, 2};
Point B = {4, 6};
double dist = A > B;        // 5

Line l = P2L(A, B);
Point P = {3, 4};
bool onLine = P | l;        // true

Segment s = {{0, 0}, {5, 5}};
Point Q = {2, 2};
bool onSegment = Q | s;     // true
```

---

##  Основные возможности

### Структуры данных

| Структура | Поля | Описание |
|-----------|------|----------|
| `Point` | `double x, y` | Точка на плоскости |
| `Vector` | `double x, y` | Вектор |
| `Line` | `double A, B, C` | Прямая `Ax + By + C = 0` |
| `Segment` | `Point A, B` | Отрезок |
| `BBox` | `Point mn, mx` | Осевой ограничивающий прямоугольник |
| `Circle` | `Point O; double R` | Окружность |
| `Triangle` | `Point A, B, C` | Треугольник |
| `IntersectOut` | `Point P1, P2; int num` | Результат пересечения |

**Коды `num` в `IntersectOut`:**
- `-1` — бесконечное множество точек (совпадают)
- `0` — нет пересечения
- `1` — одна точка (`P1`)
- `2` — две точки (`P1`, `P2`)

---

### Операторы

| Категория | Операторы | Что делают |
|-----------|-----------|------------|
| **Арифметика** | `+`, `-`, `*`, `/` | Сложение, вычитание, умножение/деление на скаляр |
| **Сравнение** | `==`, `!=` | Сравнение всех типов |
| **Углы** | `^` | Угол между векторами, прямыми, отрезками |
| **Расстояния** | `>`, `>>`, `<` | Геометрическое, алгебраическое, квадрат расстояния |
| **Принадлежность** | `\|` | Точка на прямой/отрезке/окружности/в BBox |
| **Пересечение (проверка)** | `\|\|` | Есть ли пересечение? (bool) |
| **Пересечение (точки)** | `&` | Возвращает `IntersectOut` с точками и их количеством |

---

### Треугольники (полный набор)

| Категория | Функции |
|-----------|---------|
| **Площадь** | `area()`, `area2()`, `areaALG()`, `area2ALG()` |
| **Углы** | `angleA()`, `angleB()`, `angleC()`, `angleAOB()` |
| **Стороны** | `lenAB()`, `lenBC()`, `lenAC()`, `perimeter()` |
| **Проверки** | `isDeg()`, `isAcute()`, `isRight()`, `isObtuse()` |
| **Отрезки** | `heightA/B/C()`, `medianA/B/C()`, `bisectorA/B/C()`, `midsegmentAB/BC/CA()` |
| **Точки** | `centroid()`, `incenter()`, `orthocenter()`, `circumcenter()` |
| **Окружности** | `circumscribed()`, `inscribed()` |
| **Длины** | `lenHeiA/B/C()`, `lenMedA/B/C()`, `lenBisA/B/C()` |

---

##  Установка

### 1. Скачайте файл

```bash
git clone https://github.com/FedorovIaromir/geometry-plus-plus.git
```

Или просто скачайте `geometry++.h` вручную.

### 2. Подключите в проекте

```cpp
#include "geometry++.h"
```

### 3. Скомпилируйте с C++17

```bash
g++ -std=c++17 main.cpp -o program
```

---

## Структура репозитория

```
geometry-plus-plus/
├── geometry++.h                      # Основная библиотека
├── Geometry++_Документация.docx      # Полная документация
└── README.md                         # Этот файл
```

---

## Лицензия

**MIT License** — свободно для коммерческого и некоммерческого использования.

Подробнее: [LICENSE](LICENSE)

---

## Вклад

Буду рад любым улучшениям, исправлениям и предложениям!

1. Форкните репозиторий
2. Создайте ветку (`git checkout -b feature/AmazingFeature`)
3. Закоммитьте изменения (`git commit -m 'Add some AmazingFeature'`)
4. Запушьте (`git push origin feature/AmazingFeature`)
5. Откройте Pull Request

---

## Контакты

- **GitHub**: [FedorovIaromir](https://github.com/FedorovIaromir)

---

## Поддержка

Если библиотека вам пригодилась — поставьте **звезду** на GitHub! Это поможет другим разработчикам найти её.

---
