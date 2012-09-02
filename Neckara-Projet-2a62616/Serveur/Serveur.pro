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
    InterfaceReseau/listeinstruction.cpp \
    InterfaceReseau/listejoueurs.cpp \
    InterfaceReseau/joueur.cpp \
    InterfaceReseau/listefonctionserveur.cpp \
    InterfaceReseau/paramtraitement.cpp \
    InterfaceReseau/infojoueur.cpp \
    InterfaceReseau/Listener/virtuallistener.cpp \
    InterfaceReseau/Traitement/virtualtraitement.cpp
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
    InterfaceReseau/listeinstruction.h \
    InterfaceReseau/listejoueurs.h \
    InterfaceReseau/joueur.h \
    InterfaceReseau/listefonctionserveur.h \
    InterfaceReseau/paramtraitement.h \
    InterfaceReseau/infojoueur.h \
    InterfaceReseau/Listener/virtuallistener.h \
    InterfaceReseau/Listener/listener.h \
    InterfaceReseau/Listener/listener.tpp \
    InterfaceReseau/Listener/listeneradmin.h \
    InterfaceReseau/Listener/listenerclient.h \
    InterfaceReseau/Listener/listenerclient.inline \
    InterfaceReseau/Traitement/virtualtraitement.h \
    InterfaceReseau/Traitement/Traitement.h \
    InterfaceReseau/Traitement/Traitement.tpp \
    InterfaceReseau/Traitement/traitementclient.inline \
    InterfaceReseau/Traitement/traitementclient.h \
    InterfaceReseau/Listener/listeneradmin.inline \
    InterfaceReseau/Traitement/traitementadmin.h \
    InterfaceReseau/Traitement/traitementadmin.inline
LIBS += -lmysqlclient \
    -lsfml-graphics \
    -lsfml-network
