PROJECT(LuminoStudio)
CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

#-------------------------------------------------------------------------------
set(LN_SOURCES_Core
	src/Core/Project.cpp
	src/Core/Project.h
)

set(LN_SOURCES_Editor
	src/NewProjectDialog.cpp
	src/NewProjectDialog.h
	src/main.cpp
	src/MainWindow.cpp
	src/MainWindow.h
	src/LuminoViewWidget.cpp
	src/LuminoViewWidget.h
	src/LuminoStudio.PCH.cpp
	src/LuminoStudio.PCH.h
)

source_group("Core"			FILES ${LN_SOURCES_Core})
source_group("Editor"		FILES ${LN_SOURCES_Editor})

set(LN_SOURCES
	${LN_SOURCES_Core}
	${LN_SOURCES_Editor}
)

add_subdirectory(external/Lumino)

include_directories(
	external/Lumino/include
	external/Lumino/external/Lumino.Core/include
)

#-------------------------------------------------------------------------------
# Qt のパスを最初に指定する必要がある
set (CMAKE_PREFIX_PATH "C:/Qt/5.7/msvc2015/")

# Qt 検索
find_package(Qt5Widgets REQUIRED)
find_package(Qt5OpenGL REQUIRED)

#この行はQtのバージョンを表示する。無いならなくてもいい
message(STATUS "Qt5 --> ${Qt5Widgets_VERSION_STRING}")

# http://doc.qt.io/qt-5/cmake-manual.html
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

qt5_add_resources(LN_QT_RESOURCES
	src/luminostudio.qrc
)

add_executable(LuminoStudio ${LN_SOURCES} ${LN_QT_RESOURCES})
target_link_libraries(LuminoStudio Qt5::Widgets)
target_link_libraries(LuminoStudio Lumino_Static)
ln_add_pch2(LuminoStudio "LuminoStudio.PCH.h" "src/LuminoStudio.PCH.cpp")
qt5_use_modules(LuminoStudio Widgets OpenGL)

# Qt の DLL をコピーする
add_custom_command(TARGET LuminoStudio POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_PREFIX_PATH}bin/Qt5Cored.dll" "Qt5Cored.dll"
	COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_PREFIX_PATH}bin/Qt5Widgetsd.dll" "Qt5Widgetsd.dll"
	COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_PREFIX_PATH}bin/Qt5Guid.dll" "Qt5Guid.dll"
	COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_PREFIX_PATH}bin/Qt5OpenGLd.dll" "Qt5OpenGLd.dll"
)

