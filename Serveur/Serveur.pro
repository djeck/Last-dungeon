DEFINES += ADMIN
SOURCES += main.cpp \
    serveur.cpp \
    ../Communs/logger.cpp \
    ../Communs/Param.cpp \
    ../Communs/sha512.cpp \
    ../Communs/bdd.cpp \
    ../Communs/resultatrequete.cpp \
    ../Communs/requetebdd.cpp \
    administrateur.cpp \
    environnement.cpp \
    InterfaceReseau/traitement.cpp \
    InterfaceReseau/listeinstruction.cpp \
    InterfaceReseau/listejoueurs.cpp \
    InterfaceReseau/joueur.cpp \
    InterfaceReseau/listener.cpp \
    InterfaceReseau/listefonctionserveur.cpp \
    InterfaceReseau/paramtraitement.cpp \
    InterfaceReseau/infojoueur.cpp
HEADERS += serveur.h \
    ../Communs/logger.h \
    ../Communs/Param.h \
    ../Communs/sha512.h \
    ../Communs/bdd.h \
    ../Communs/resultatrequete.h \
    ../Communs/requetebdd.h \
    ../Communs/enumTraitement.h \
    InfoJoueur.h \
    administrateur.h \
    environnement.h \
    InterfaceReseau/traitement.h \
    InterfaceReseau/listeinstruction.h \
    InterfaceReseau/listejoueurs.h \
    InterfaceReseau/joueur.h \
    InterfaceReseau/listener.h \
    InterfaceReseau/listefonctionserveur.h \
    InterfaceReseau/paramtraitement.h \
    InterfaceReseau/infojoueur.h
LIBS += -lmysqlclient \
    -lsfml-graphics \
    -lsfml-network
