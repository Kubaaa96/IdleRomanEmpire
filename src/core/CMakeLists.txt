add_library_and_link(NAME IRELib
    SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Engine.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/gui/SystemWindow.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/state/StateMachine.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/state/State.cpp
)