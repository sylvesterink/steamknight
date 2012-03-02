include_directories(${STEAMKNIGHT_SOURCE_DIR}/src/gamebase)
include_directories(${STEAMKNIGHT_SOURCE_DIR}/test)

#add_library(TestBase TestBase.cpp)
#target_link_libraries(TestBase GBase GWindow GEvent)

add_executable(WindowTest Window.cpp TestBase.cpp)
target_link_libraries(WindowTest GBase GWindow GEvent ${SDL_LIBRARY} ${OPENGL_LIBRARY})
