# Set a minimum CMake vversion
cmake_minimum_required(VERSION 3.0)
# Define our project name
project(HunterTest)

# Look for the SFML components we're interested in
find_package(SFML 2.5 COMPONENTS audio graphics window system REQUIRED)

# Define a list of our source files
set(SOURCES
    main.c
    ./src/click.c
    ./src/clock.c
    ./src/create.c
    ./src/cursor.c
    ./src/destroy.c
    ./src/display.c
    ./src/fill.c
    ./src/game.c
)

# Define our target executable based on the source files above
add_executable(Hunter ${SOURCES})

# Link our executable to SFML and its dependencies
target_link_libraries(Hunter csfml-audio csfml-graphics csfml-window csfml-system)

# Set our source directory as the startup directory for debugging
set_target_properties(Hunter PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

