include_directories(${STEAMKNIGHT_SOURCE_DIR}/src/gamebase)
include_directories(${STEAMKNIGHT_SOURCE_DIR}/test)

add_library(TestBase TestBase ${STEAMKNIGHT_SOURCE_DIR}/src/gamebase/GameBase)

add_executable(WindowTest Window)
target_link_libraries(WindowTest GameBase GameWindow TestBase ${SDL_LIBRARY} ${OPENGL_LIBRARY})
