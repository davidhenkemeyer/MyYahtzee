cmake_minimum_required(VERSION 3.20)
project(TripleYahtzee CXX)

# Statically link MFC and the CRT so the .exe runs on a clean Windows 10/11
# machine without needing the Visual C++ redistributable.
set(CMAKE_MFC_FLAG 1)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

set(SRC_DIR ${CMAKE_SOURCE_DIR}/MyYahtzee)
file(GLOB SOURCES ${SRC_DIR}/*.cpp)
list(FILTER SOURCES EXCLUDE REGEX "StdAfx\\.cpp$")
list(APPEND SOURCES ${SRC_DIR}/StdAfx.cpp)

add_executable(TripleYahtzee WIN32 ${SOURCES} ${SRC_DIR}/MyYahtzee.rc)
target_include_directories(TripleYahtzee PRIVATE ${SRC_DIR})
target_compile_definitions(TripleYahtzee PRIVATE _MBCS WIN32 _WINDOWS _CRT_SECURE_NO_WARNINGS _CRT_NONSTDC_NO_WARNINGS)
# VC6-era code: old for-loop scoping, relaxed conformance
target_compile_options(TripleYahtzee PRIVATE /W3 /EHsc /permissive- /Zc:forScope- /Zc:strictStrings-)
target_link_libraries(TripleYahtzee PRIVATE winmm)

# Sounds are loaded from the working directory at runtime
add_custom_command(TARGET TripleYahtzee POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different ${SRC_DIR}/Res/dice.wav $<TARGET_FILE_DIR:TripleYahtzee>
  COMMAND ${CMAKE_COMMAND} -E copy_if_different ${SRC_DIR}/Res/Click.wav $<TARGET_FILE_DIR:TripleYahtzee>)