add_library_and_link(NAME IRELib
    SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Engine.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/gui/SystemWindow.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/gui/widgets/Widget.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/gui/widgets/ClickableWidget.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/gui/widgets/Container.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/gui/widgets/Group.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/gui/widgets/Button.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/state/StateMachine.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/state/State.cpp
)