include($$PWD/../../plugins.pri)
include($$PWD/common/common.pri)

QT += opengl
TARGET = $$PLUGINS_PREFIX/Visual/mountain

HEADERS += mountainplugin.h \
           mountainwidget.h \
           visualmountainfactory.h

SOURCES += mountainplugin.cpp \
           mountainwidget.cpp \
           visualmountainfactory.cpp

win32:{
    LIBS += -lglu32 -lopengl32
}

unix{
    target.path = $$PLUGIN_DIR/Visual
    INSTALLS += target
}
