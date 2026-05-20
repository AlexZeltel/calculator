# Калькулятор v2.0

**Автор: AlexZeltel**

Я продолжаю изучать C++, и это мой первый проект — консольный калькулятор с поддержкой нескольких языков и кроссплатформенным кодом.

---

## версия 1.0 (19/05/2026)
- Первая Версия

## версия 2.0 (20/05/2026)
- Выбор языка интерфейса: **русский, английский, испанский** (легко добавить другие).
- Полный переход на Unicode (широкие строки `wstring`) — любые национальные символы отображаются корректно.
- Кроссплатформенность: один код работает на **Windows, Linux, macOS** без изменений.
- Безопасный ввод чисел — программа не ломается при вводе текста, очищает буфер и просит повторить попытку.
- Стандартные арифметические операции с проверкой деления на ноль.
- Очистка экрана после каждого действия для удобства.

## Особенности реализации
- **Многоязычность** реализована через хранение всех строк в переменных типа `std::wstring` (широкие символы). Благодаря этому программа не зависит от системной локали и кодовых страниц.
- **Переход на Unicode**:
  - в предыдущей версии программа использовала узкие строки и зависела от текущей кодовой страницы ОС (например, Windows-1251). Это не позволяло одновременно корректно отображать русские и испанские символы. Теперь весь вывод выполняется в Unicode, и любые национальные алфавиты работают вместе.
- **Кроссплатформенный вывод Unicode**:
  - На *Windows* используется прямой вызов `WriteConsoleW` и `_setmode` для перевода `stdout` в режим широких символов.
  - На *Linux/macOS* применяется стандартный `wcout` с настройкой глобальной локали UTF-8.
- **Безопасный ввод** — функция `readInt` проверяет состояние потока `cin`, сбрасывает флаги ошибок и игнорирует некорректные символы до конца строки.
- **Условная компиляция** (`#ifdef _WIN32`) разделяет платформозависимые участки, сохраняя общую логику без изменений.

---

# Calculator v2.0

**Author:** AlexZeltel  

I'm learning C++ and this is my first project — a console calculator with multi-language support and cross-platform code.

## version 1.0 (19/05/2026)
- First Version

## version 2.0  (20/05/2026)
- Interface language selection: **Russian, English, Spanish** (other languages can be added easily).
- Full Unicode support (wide strings `wstring`) — any national characters are displayed correctly.
- Cross-platform: the same code works on **Windows, Linux, macOS** without modifications.
- Safe numeric input — the program doesn't crash on text input; it clears the buffer and asks again.
- Basic arithmetic operations with division-by-zero check.
- Screen clearing after each action for better user experience.

## Technical Details
- **Multilingual support** is achieved by storing all strings in `std::wstring` variables. This makes the program independent of system locale and code pages.
- **Unicode migration**:
   - The previous version relied on narrow strings and the system code page (e.g., Windows-1251), which made it impossible to display Russian and Spanish characters simultaneously. Version 2.0 uses Unicode throughout, so any combination of languages works correctly.
- **Cross-platform Unicode output**:
  - On *Windows* it uses direct `WriteConsoleW` and `_setmode` to switch `stdout` to wide character mode.
  - On *Linux/macOS* it uses standard `wcout` with global UTF-8 locale configuration.
- **Safe input** — the `readInt` function checks the state of `cin`, clears error flags and ignores invalid characters until the end of the line.
- **Conditional compilation** (`#ifdef _WIN32`) isolates platform-dependent code while keeping the core logic identical.

---

*by AlexZeltel*
