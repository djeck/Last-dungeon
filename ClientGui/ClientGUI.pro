SOURCES += main.cpp \
    jeux.cpp \
    map.cpp \
    fond2d.cpp \
    eventrecever.cpp \
    reseau.cpp \
    preferances.cpp \
    soundmanager.cpp
LIBS += -lIrrlicht \
    -lsfml-graphics \
    -lsfml-network \
    -lsfml-audio

HEADERS += \
    jeux.h \
    map.h \
    fond2d.h \
    eventrecever.h \
    reseau.h \
    preferances.h \
    soundmanager.h
win32:RC_FILE += icone.rc
