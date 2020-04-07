include($$PWD/../../plugins.pri)

HEADERS += decoderopusfactory.h \
           decoder_opus.h \
           opusmetadatamodel.h
    
SOURCES += decoderopusfactory.cpp \
           decoder_opus.cpp \
           opusmetadatamodel.cpp

DESTDIR = $$PLUGINS_PREFIX/Input
TARGET = $${TARGET}

INCLUDEPATH += $$EXTRA_PREFIX/libopusfile/include \
               $$EXTRA_PREFIX/libogg/include \
               $$EXTRA_PREFIX/libtaglib/include

unix {
    QMAKE_CLEAN = $$DESTDIR/lib$${TARGET}.so
    LIBS += -L$$EXTRA_PREFIX/libopusfile/lib -lopusfile$$STATIC_LIBRARY_SUFFIX -lopus$$STATIC_LIBRARY_SUFFIX \
            -L$$EXTRA_PREFIX/libtaglib/lib -ltag$$STATIC_LIBRARY_SUFFIX \
            -L$$EXTRA_PREFIX/libogg/lib -logg$$STATIC_LIBRARY_SUFFIX
}

win32 {
    LIBS += -L$$EXTRA_PREFIX/libopusfile/lib -lopusfile -lopus \
            -L$$EXTRA_PREFIX/libtaglib/lib -ltag -lm \
            -L$$EXTRA_PREFIX/libogg/lib -logg
}
