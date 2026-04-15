cmake_minimum_required(VERSION 3.16)
project(sfml-t)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ищем SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Исполняемый файл
add_executable(sfml-t
    src/main.cpp
    src/config.h
)

# Подключаем заголовки
target_include_directories(sfml-t PRIVATE src)

# Линкуем SFML
target_link_libraries(sfml-t
    sfml-graphics
    sfml-window
    sfml-system
)
