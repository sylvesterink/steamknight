add_subdirectory(gamebase)

include_directories("${STEAMKNIGHT_SOURCE_DIR}/src/gamebase")
add_executable(Steamknight Game.cpp)

target_link_libraries(Steamknight GBase GWindow ${SDL_LIBRARY} ${OPENGL_LIBRARY})
