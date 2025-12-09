cmake_minimum_required(VERSION 3.10)
project(algorithmAndStructure)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置输出目录
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/out)

# 查找 code 目录下的所有 .cpp 文件
file(GLOB_RECURSE CPP_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/code/**/*.cpp"
)

# 遍历每个 .cpp 文件，创建可执行文件
foreach(file ${CPP_FILES})
    get_filename_component(filename ${file} NAME_WE)  # 获取文件名（不含扩展名）
    get_filename_component(dir ${file} DIRECTORY)     # 获取所在目录

    # 创建可执行文件
    add_executable(${filename} ${file})

    # 设置输出路径
    set_target_properties(${filename} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${EXECUTABLE_OUTPUT_PATH})
endforeach()