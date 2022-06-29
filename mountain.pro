include($$PWD/common/common.pri)

QT += opengl

HEADERS += mountainplugin.h \
           mountainwidget.h \
           visualmountainfactory.h

SOURCES += mountainplugin.cpp \
           mountainwidget.cpp \
           visualmountainfactory.cpp

#CONFIG += BUILD_PLUGIN_INSIDE
contains(CONFIG, BUILD_PLUGIN_INSIDE){
    include($$PWD/../../plugins.pri)
    TARGET = $$PLUGINS_PREFIX/Visual/mountain

    win32{
        LIBS += -lglu32 -lopengl32
    }

    unix{
        target.path = $$PLUGIN_DIR/Visual
        INSTALLS += target
    }
}else{
    CONFIG += warn_off plugin lib thread link_pkgconfig c++11
    TEMPLATE = lib

    unix{
        PKGCONFIG += qmmp-1

        PLUGIN_DIR = $$system(pkg-config qmmp-1 --variable=plugindir)/Visual
        INCLUDEPATH += $$system(pkg-config qmmp-1 --variable=prefix)/include

        plugin.path = $${PLUGIN_DIR}
        plugin.files = lib$${TARGET}.so
        INSTALLS += plugin
    }
}
