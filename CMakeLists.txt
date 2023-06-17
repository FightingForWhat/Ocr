# CMakeList.txt: Ocr 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required(VERSION 3.12)

project ("Ocr")

# 将源代码添加到此项目的可执行文件。
# add_executable (Ocr "Ocr.cpp" "Ocr.h")

set(CMAKE_CXX_STANDARD 11)
add_definitions(-DUNICODE -D_UNICODE)

set(OcrLib_DIR "${CMAKE_CURRENT_LIST_DIR}/OcrLib")

set(OcrLib_INCLUDE_DIRS "${OcrLib_DIR}/include")

include_directories(${OcrLib_INCLUDE_DIRS})

link_directories(${OcrLib_DIR}/lib)

set(OcrLib_LIBS RapidOcrOnnx)

add_executable(Ocr "Ocr.cpp")

# Test CLib Program
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(Ocr ${OcrLib_LIBS})


