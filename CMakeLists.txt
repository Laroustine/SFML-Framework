##
## CMakeLists
##

cmake_minimum_required(VERSION 3.0.0)

# Set project NAME and VERSION
project("Little Game" VERSION 0.0.1)

# All Flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -std=c++17")

# Files for EXE
set(NAME_EXE "sfml")
set(SOURCES_EXE
    "src/main.cpp"
    "class/Game.cpp"
    "class/States/StatePlaying.cpp"
    "engine/Util/ToggleKey.cpp"
    "engine/Util/Maths.cpp"
    "engine/Util/FPSCounter.cpp"
    "engine/Util/FileUtil.cpp"
    "engine/Util/Animation.cpp"
    "engine/GUI/Widget.cpp"
    "engine/GUI/Textbox.cpp"
    "engine/GUI/StackMenu.cpp"
    "engine/GUI/Button.cpp"
    "engine/ResourceManager/ResourceHolder.cpp"
    )
    
# Inlude Directory
set(INCLUDE_EXE
    "engine"
    "class"
    "include")

include_directories(${INCLUDE_EXE})

# Custom Command
add_custom_target(
    "fclean"
    COMMAND make clean
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

# Create EXE
add_executable(${NAME_EXE} ${SOURCES_EXE})

# Link LIBS
target_link_libraries(${NAME_EXE} "sfml-system")
target_link_libraries(${NAME_EXE} "sfml-window")
target_link_libraries(${NAME_EXE} "sfml-graphics")
target_link_libraries(${NAME_EXE} "sfml-audio")
target_link_libraries(${NAME_EXE} "sfml-network")
