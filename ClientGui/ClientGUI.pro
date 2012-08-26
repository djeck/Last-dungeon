SOURCES += main.cpp \
    jeux.cpp \
    map.cpp \
    fond2d.cpp \
    eventrecever.cpp \
    reseau.cpp \
    preferances.cpp \
    soundmanager.cpp \
    map/diapo2D.cpp \
    sommaire.cpp \
    map/menu.cpp \
    map/Menu/fenetreconnexion.cpp \
    overevent.cpp
LIBS += -lIrrlicht \
    -lsfml-graphics \
    -lsfml-network \
    -lsfml-audio \
    -lsfml-system

HEADERS += \
    jeux.h \
    map.h \
    fond2d.h \
    eventrecever.h \
    reseau.h \
    preferances.h \
    soundmanager.h \
    map/diapo2D.h \
    sommaire.h \
    map/menu.h \
    map/Menu/fenetreconnexion.h \
    overevent.h \
    overevent.h
win32:RC_FILE += icone.rc

