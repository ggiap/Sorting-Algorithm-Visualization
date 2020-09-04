cmake_minimum_required(VERSION 3.17)
project(Sorting_Algorithm_Visualization)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH
        "${CMAKE_CURRENT_SOURCE_DIR}/cmake"
        ${CMAKE_MODULE_PATH})

# Download automatically, you can also just copy the conan.cmake file
if(NOT EXISTS "${CMAKE_MODULE_PATH}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/v0.15/conan.cmake"
            "${CMAKE_MODULE_PATH}/conan.cmake")
endif()

include(${CMAKE_MODULE_PATH}/conan.cmake)
conan_add_remote(NAME bincrafters URL
        https://api.bintray.com/conan/bincrafters/public-conan)

conan_cmake_run(REQUIRES
        sfml/2.5.1@bincrafters/stable
	flac/1.3.2@bincrafters/stable
        BASIC_SETUP
        BUILD missing)

add_library(SOURCE
            TimSort.cpp
            TimSort.h
            SelectionSort.cpp
            SelectionSort.h
            ShellSort.cpp
            ShellSort.h
            RadixSort.cpp
            RadixSort.h
            QuickSort.cpp
            QuickSort.h
            PancakeSort.cpp
            PancakeSort.h
            MergeSort.cpp
            MergeSort.h
            InsertionSort.cpp
            InsertionSort.h
            IntroSort.cpp
            IntroSort.h
            HeapSort.cpp
            HeapSort.h
            GnomeSort.cpp
            GnomeSort.h
            CocktailSort.cpp
            CocktailSort.h
            CombSort.cpp
            CombSort.h
            CountingSort.cpp
            CountingSort.h
            BubbleSort.cpp
            BubbleSort.h
            Button.h
            Button.cpp
            Algorithms.cpp
            Algorithms.h)

target_link_libraries(SOURCE ${SOURCE})

add_executable(Sorting_Algorithm_Visualization main.cpp)

target_link_libraries(Sorting_Algorithm_Visualization SOURCE ${CONAN_LIBS})

add_custom_command(
        TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/Font
        ${CMAKE_CURRENT_BINARY_DIR}/Font)

add_custom_command(
        TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/Images
        ${CMAKE_CURRENT_BINARY_DIR}/Images)