#ifndef BOUTON_H
#define BOUTON_H

#include "BuilderBouton.h"

namespace LD
{
    /** @brief Bouton une fois construit. Il est important de conserver le BoutonData si vous voulez modifier le bouton pendant son utilisation */
    template<typename Event, typename Image>
    class Bouton
    {
        /** @brief constuit le bouton
            @param BuilderBouton::BoutonData<Event, Image> & ptr : référence sur les données du bouton */
        Bouton(BuilderBouton::BoutonData<Event, Image> & ptr);

        typedef BuilderBouton::BoutonData<Event, Image>::ListeCondition ListeCondition;
        typedef BuilderBouton::BoutonData<Event, Image>::ListeEvent ListeEvent;

        /** @brief permet d'envoyer un event au bouton
            @param Event * event : évènement à envoyer
            @return int : retourne le focus du bouton */
        int sendEvent(Event * event)
        {
            ListeCondition::const_iterator * const fin = ptr.listeCondition.end();
            ListeCondition::iterator * p = ptr.listeCondition.begin();
            int focus;

            for(; p != fin; ++p)
            {
                focus = p->lauch(ptr, event);
                if(focus == BuilderBouton::FINI || focus == BuilderBouton::ISNOTCIBLE)
                    return focus;
            }
            if(focus == BuilderBouton::INCONNU)
                return BuilderBouton::ISNOTCIBLE;
            return focus;
        }

        /** @brief permet d'obtenir le dernier évent dont le bouton a été la cible.
            @return const Event & : dernier évènement dont le bouton a été la cible */
        const Event & getLastEvent()
        {
            return ptr.lastEvent;
        }

        /** @brief permet d'obtenir la position du bouton
          @return const Position & : position du bouton */
        const Position & getPosition()
        {
            return ptr.position;
        }

        /** @brief permet d'attribuer une nouvelle position au bouton
          @param Position & p : nouvelle position du bouton
          @return Position & : position nouvelle du bouton */
        Position & setPosition(const Position & p)
        {
            ptr.position = p;
        }

        /** @brief permet d'obtenir l'image actuelle du bouton
            @return  const Image * : image actuelle du bouton */
        const Image * getImage()
        {
            return ptr.image;
        }

        /** @brief permet d'obtenir l'image liée à l'état passé en argument.
            @param int etat : état dont on veut l'image
            @return const Image * : image lié à l'état passé en paramètre. */
        const Image * getImage(int etat)
        {
            return ptr.listeEtat[etat].getImage();
        }

        /** @brief change l'état du bouton manuellement et appelle la fonction lié au changement d'état
          @param int etat : état à donner au bouton
          @return int : nouvel état du bouton (peut être différent de l'état passé en paramètre).
        int changeEtat(int etat)
        {
                return ptr.etat = ptr.listeEtat[etat].run(ptr);
        }

        /** @brief change l'état du bouton manuellement sans appeler la fonction lié au changement d'état
            @param int etat : nouvel état du bouton */
        void changeEtatDiscret(int etat)
        {
            ptr.etat = etat;
        }

    private :
            /** @brief données du bouton */
            BuilderBouton::BoutonData<Event, Image> & ptr;
    };

    template<typename Event, typename Image>
    Bouton::Bouton(BuilderBouton::BoutonData<Event, Image> &ptr) : ptr(ptr){}
    
     
}

#endif // BOUTON_H
