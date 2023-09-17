add_app(${CMAKE_PROJECT_NAME}
        SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Application.cpp

        ${CMAKE_CURRENT_SOURCE_DIR}/state/MenuState.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/state/GameState.cpp

        DEPENDS
        IRELib
)
