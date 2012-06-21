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
            environnement.cpp
HEADERS += serveur.h \
            ../Communs/logger.h \
            ../Communs/Param.h \
            ../Communs/sha512.h \
            ../Communs/bdd.h \
            ../Communs/resultatrequete.h \
            ../Communs/requetebdd.h \
            administrateur.h \
            environnement.h
LIBS += -lmysqlclient \
    -lsfml-graphics \
    -lsfml-network
