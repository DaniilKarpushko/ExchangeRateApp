cmake_minimum_required(VERSION 3.5)
project(ExchangeRateApp)

if(WIN32) # Install dlls in the same directory as the executable on Windows
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
endif()

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
        GIT_TAG 1.10.5) # Replace with your desired git commit from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)

include(FetchContent)
FetchContent_Declare(
        json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.10.4
)
FetchContent_MakeAvailable(json)


set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "C:/Qt/6.6.2/mingw_64")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Charts
        REQUIRED)
include_directories(include)
set(SOURCES src/main.cpp
        src/Controller/ApiController.cpp
        src/View/Presentation/ChooseExTypeWidget.cpp
        src/View/Presentation/InsertExAmounWidget.cpp
        src/View/Presentation/InputWidget.cpp
        src/View/Presentation/NumericExTextWidget.cpp
        src/View/Presentation/OutputExAmountWIdget.cpp
        src/View/Presentation/ExchangeMainWindow.cpp
        src/View/Presentation/GraphicBuilderWidget.cpp
        src/Controller/CurrentExchangeService.cpp
        src/Controller/RequestService.cpp
)
set(HEADERS
        include/Controller/ApiController.h
        include/ExchangeData/ExchangeData.h
        include/Presentation/Widget/ChooseExTypeWidget.h
        include/ExchangeDataParser/ExchangeDataTranslator.h
        include/Presentation/Widget/ListWidget.h
        include/Presentation/Widget/ExchangeMainWindow.h
        include/Presentation/Widget/InsertExAmountWidget.h
        include/Presentation/Widget/InputWidget.h
        include/Presentation/Widget/NumericExTextWidget.h
        include/Presentation/Widget/OutputExAmountWidget.h
        include/Presentation/Widget/GraphicBuilderWidget.h
        include/Controller/CurrentExchangeService.h
        include/Controller/RequestService.h
        include/ExchangeData/MonthlyExchangeData.h
)
set(app_icon_resource_windows "${CMAKE_CURRENT_SOURCE_DIR}/resources/app.rc")
add_executable(ExchangeRateApp ${SOURCES} ${HEADERS} ${app_icon_resource_windows})
target_link_libraries(ExchangeRateApp
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Charts
        cpr
        nlohmann_json::nlohmann_json
)

if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
