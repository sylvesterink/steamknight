include_directories(${STEAMKNIGHT_SOURCE_DIR}/src/gamebase)
include_directories(${STEAMKNIGHT_SOURCE_DIR}/test)

#TODO: clean up this line to be smaller and more readable
add_library(TestBase TestBase.cpp ${STEAMKNIGHT_SOURCE_DIR}/src/gamebase/GBase.cpp ${STEAMKNIGHT_SOURCE_DIR}/src/gamebase/GWindow.cpp)

add_executable(WindowTest Window.cpp)
target_link_libraries(WindowTest GBase GWindow TestBase ${SDL_LIBRARY} ${OPENGL_LIBRARY})
