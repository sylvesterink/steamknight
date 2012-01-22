include_directories(${STEAMKNIGHT_SOURCE_DIR}/src/gamebase)

add_executable(WindowTest window)
target_link_libraries(WindowTest GameBase GameWindow ${SDL_LIBRARY} ${OPENGL_LIBRARY})
