CONFIG(debug, debug|release): CONFIG -= release
else: CONFIG -= debug

QT += core gui qml quick
CONFIG += c++11
#CONFIG += qml_debug

TEMPLATE = lib
TARGET = qmlui
DEFINES += QMLUI_SHARED QT_DEPRECATED_WARNINGS


DESTDIR = $$PWD/../bin_win32
contains(QMAKE_TARGET.arch, x86_64):{
	DESTDIR = $$PWD/../bin_win64
}

macx {
	DESTDIR = $$PWD/../bin_macx
}
unix:!macx{
	DESTDIR = $$PWD/../bin_unix
}
linux-g++ {
    DESTDIR = $$PWD/../bin_linux
}


WPWD = $${PWD}
WPWD ~= s,/,\\,g
QMAKE_POST_LINK += $$quote(cmd /c copy /y $$WPWD\\qmlui.hpp $$WPWD\\..\\include)

SOURCES += \
    qmlui.cpp \
    qml-renderer.cpp \
    qml-cb.cpp \
    keyconv.cpp
HEADERS += qmlui.hpp \
    qml-renderer.hpp \
    platform.hpp \
    qml-cb.hpp \
    keyconv.hpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =
# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =
