# Geometry++

**Полная библиотека 2D вычислительной геометрии на C++17**

[![C++](https://img.shields.io/badge/C++-17-blue.svg)](https://isocpp.org/)
[![License](https://img.shields.io/badge/license-MIT-green.svg)](LICENSE)
[![GitHub stars](https://img.shields.io/github/stars/FedorovIaromir/geometry-plus-plus.svg?style=social)](https://github.com/FedorovIaromir/geometry-plus-plus/stargazers)

---

## Описание

**Geometry++** — это полноценная библиотека для 2D вычислительной геометрии на C++17. Она предоставляет **112 функций** и **97 перегруженных операторов** для интуитивной работы с:

- **Точки** (`Point`)
- **Векторы** (`Vector`)
- **Прямые** (`Line`)
- **Отрезки** (`Segment`)
- **Ограничивающие прямоугольники** (`BBox`)
- **Окружности** (`Circle`)
- **Треугольники** (`Triangle`)
- **Барицентрические координаты** (`BaryCoords`)

Библиотека создаётся и продолжает улучшаться всего одним человеком. Если у вас есть идеи для улучшений, исправлений и нововведений — буду рад их увидеть!

---

## Быстрый старт

### Подключение

```cpp
#include "geometry++.h"
using namespace std;
```

### Базовый пример

```cpp
Triangle t = {{0, 0}, {4, 0}, {1, 3}};
cout << "Площадь: " << area(t) << endl;
cout << "Периметр: " << perimeter(t) << endl;

Circle c1 = {{0, 0}, 5};
Circle c2 = {{8, 0}, 5};
IntersectOut res = c1 & c2;

if (res.num == 2) {
    cout << "Точки пересечения: " << res.P1 << " и " << res.P2 << endl;
}
```

### Точки и прямые

```cpp
Point A = {1, 2};
Point B = {4, 6};
Vector v = B - A;        // (3, 4)
double dist = A > B;     // 5

Line l = P2L(A, B);
Point P = {3, 4};
Point proj = project(P, l);
```

### Проверка принадлежности

```cpp
Point P = {2, 2};
Segment s = {{0, 0}, {5, 5}};
bool onSegment = P | s;  // true
```

---

## Структуры данных

| Структура | Поля | Описание |
|-----------|------|----------|
| `Point` | `double x, y` | Точка на плоскости |
| `Vector` | `double x, y` | Вектор на плоскости |
| `Line` | `double A, B, C` | Прямая `Ax + By + C = 0` |
| `Segment` | `Point A, B` | Отрезок на плоскости |
| `BBox` | `Point mn, mx` | Ограничивающий прямоугольник |
| `Circle` | `Point O; double R` | Окружность (центр + радиус) |
| `Triangle` | `Point A, B, C` | Треугольник |
| `BaryCoords` | `double u, v, w` | Барицентрические координаты |
| `IntersectOut` | `Point P1, P2; int num` | Результат пересечения |

**Коды `num` в `IntersectOut`:**
- `-1` — бесконечное множество точек (совпадение)
- `0` — нет пересечения
- `1` — одна точка (`P1`)
- `2` — две точки (`P1`, `P2`)

---

## Операторы

| Категория | Операторы | Что делают |
|-----------|-----------|------------|
| **Сравнение** | `==`, `!=` | Сравнение всех типов |
| **Арифметика** | `+`, `-`, `*`, `/` | Сложение, вычитание, умножение/деление на скаляр |
| **Скалярное произведение** | `*` (Vector × Vector) | Возвращает `double` |
| **Псевдовекторное произведение** | `&&` | Возвращает `double` |
| **Углы** | `^` | Угол между векторами, прямыми, отрезками |
| **Расстояния** | `>`, `>>`, `<` | Геометрическое, алгебраическое, квадрат расстояния |
| **Принадлежность** | `\|` | Точка на прямой/отрезке/окружности/в BBox |
| **Пересечение (проверка)** | `\|\|` | Есть ли пересечение? (`bool`) |
| **Пересечение (точки)** | `&` | Возвращает `IntersectOut` |

---

## Основные функции

### Векторы
- `normalize(v)` — нормализация
- `RCC(v, a)`, `RC(v, a)` — поворот против/по часовой
- `ang(v)` — угол вектора
- `isCol()`, `isOrth()`, `isCodir()`, `isOpp()` — проверки

### Точки
- `midpoint(A, B)` — середина отрезка
- `RCC(A, O, a)`, `RC(A, O, a)` — поворот точки
- `reflect(A, line)` — отражение

### Прямые
- `project(A, line)` — проекция точки
- `direction(line)`, `normal(line)` — направляющий вектор и нормаль
- `isParallel()`, `isPerpendicular()` — проверки

### Треугольники (полный набор)
- **Площадь:** `area()`, `area2()`, `areaALG()`, `area2ALG()`
- **Углы:** `angleA()`, `angleB()`, `angleC()`
- **Проверки:** `isDeg()`, `isAcute()`, `isRight()`, `isObtuse()`, `isEquil()`, `isIsosc()`, `isScal()`, `isSim()`, `isCongr()`
- **Отрезки:** `heightA/B/C()`, `medianA/B/C()`, `bisectorA/B/C()`, `midsegmentAB/BC/CA()`
- **Точки:** `centroid()`, `incenter()`, `orthocenter()`, `circumcenter()`
- **Окружности:** `circumscribed()`, `inscribed()`, `inradius()`, `circumradius()`
- **Длины:** `lenHeiA/B/C()`, `lenMedA/B/C()`, `lenBisA/B/C()`, `lenAB/BC/AC()`, `perimeter()`

### Барицентрические координаты
- `PaT2Bar(P, t)` — точка → барицентрические координаты
- `TaBar2P(t, b)` — барицентрические координаты → точка

### Предупреждения

- Флаг `SHOW_WARNINGS` позволяет включать и выключать предупреждения в коде. По умолчанию он `включен`, чтоб выключить напишите
```cpp
int main() {
    SHOW_WARNINGS = false;
    // Дальнейший код
```

---

## Полная документация

Подробная документация доступна в файле [`Geometry++_Документация.docx`](Geometry++_Документация.docx) (на русском языке).

---

## Установка

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

## Контакты и поддержка

- **GitHub:** [FedorovIaromir/geometry-plus-plus](https://github.com/FedorovIaromir/geometry-plus-plus)
- **Telegram:** [@MathBred](https://t.me/MathBred)

По всем вопросам создавайте **Issues** на GitHub.

---

## Поддержка

Если библиотека вам пригодилась — поставьте **звезду** на GitHub! Это поможет другим разработчикам найти её.
