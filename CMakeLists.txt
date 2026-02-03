cmake_minimum_required(VERSION 3.16)

project(GameLife VERSION 0.1 LANGUAGES CXX)

if(MSVC)
    add_compile_options(/Zc:__cplusplus)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    add_compile_options(/EHsc /W4 /WX)
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS NOMINMAX WIN32_LEAN_AND_MEAN)
endif()

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appGameLife
       main.cpp

       Model/Rules/IRuleStrategy.h
       Model/Rules/StandartRule.h
       Model/Rules/StandartRule.cpp

       Model/Render/IRenderer.h
       Model/GameGrid/GameGrid.h
       Model/GameGrid/GameGrid.cpp
       Model/Render/ConsoleRender.h
       Model/Render/ConsoleRender.cpp
       Model/MainClass/GameLife.h
       Model/MainClass/GameLife.cpp

       Model/FileWriter/IWriter.h
       Model/FileWriter/DefaultWriter.h
       Model/FileWriter/DefaultWriter.cpp

       Model/Reader/IReader.h
       Model/Reader/DefaultReader.h
       Model/Reader/DefaultReader.cpp

       Model/Parser/IParser.h
       Model/Parser/StrJONParser.h
       Model/Parser/StrJONParser.cpp
       Model/ConfigStruct.h
       Model/Parser/JSONConfigStructParser.h
       Model/Parser/JSONConfigStructParser.cpp
       Model/Parser/VectVectBoolResultParser.h
       Model/Parser/VectVectBoolResultParser.cpp

       ViewModel/GameLifeViewModel.h
       ViewModel/GameLifeViewModel.cpp

       Model/Events/IGameEvent.h
)

qt_add_qml_module(appGameLife
    URI GameLife
    QML_FILES View/Main.qml
    SOURCES Model/Events/AirstrikeEvent.h Model/Events/AirstrikeEvent.cpp
    SOURCES
    SOURCES Model/AirStrikeConfigStruct.h
    SOURCES Model/Parser/AirStrikeJSONConfigStructParser.h Model/Parser/AirStrikeJSONConfigStructParser.cpp
)

set_target_properties(appGameLife PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appGameLife
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appGameLife
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
