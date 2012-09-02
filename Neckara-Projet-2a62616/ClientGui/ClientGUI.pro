SOURCES += main.cpp \
    jeux.cpp \
    map.cpp \
    eventrecever.cpp \
    reseau.cpp \
    preferances.cpp \
    soundmanager.cpp \
    map/diapo2D.cpp \
    sommaire.cpp \
    map/menu.cpp \
    map/Menu/fenetreconnexion.cpp \
    overevent.cpp \
    map/composantFenetre/boutonquitter.cpp \
    map/salongo.cpp \
    map/vulistesalon.cpp \
    go/pion.cpp \
    go/actions.cpp \
    go/joueur.cpp \
    go/equipe.cpp \
    go/socle.cpp \
    go/plateau.cpp \
    go/groupe.cpp \
    go/controleur.cpp \
    go/virtualeffet.cpp \
    go/ordrejoueur.cpp \
    go/fenetrecreationsalon.cpp
LIBS += -lIrrlicht \
    -lsfml-graphics \
    -lsfml-network \
    -lsfml-audio \
    -lsfml-system

HEADERS += \
    jeux.h \
    map.h \
    eventrecever.h \
    reseau.h \
    preferances.h \
    soundmanager.h \
    map/diapo2D.h \
    sommaire.h \
    map/menu.h \
    map/Menu/fenetreconnexion.h \
    overevent.h \
    map/composantFenetre/boutonquitter.h \
    map/salongo.h \
    map/vulistesalon.h \
    go/pion.h \
    go/actions.h \
    go/joueur.h \
    go/equipe.h \
    go/socle.h \
    go/plateau.h \
    go/groupe.h \
    go/controleur.h \
    go/virtualeffet.h \
    go/ordrejoueur.h \
    go/fenetrecreationsalon.h
win32:RC_FILE += icone.rc

