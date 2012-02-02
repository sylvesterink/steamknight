add_subdirectory(gamebase)

include_directories("${STEAMKNIGHT_SOURCE_DIR}/src/gamebase")
add_executable(Steamknight Game)
target_link_libraries(Steamknight GameBase GameWindow ${SDL_LIBRARY} ${OPENGL_LIBRARY})
