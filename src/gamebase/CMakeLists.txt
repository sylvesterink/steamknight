add_library(GEvent GEvent.cpp)

add_library(GBase GBase.cpp)
target_link_libraries(GBase GEvent)

add_library(GWindow GWindow.cpp)
