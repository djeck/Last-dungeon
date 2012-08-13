#ifndef BUILDERBOUTON_H
#define BUILDERBOUTON_H

#include <iostream>
#include <vector>

namespace LD
{
    /** @brief position dans un espace à 2 dimension avec x la position sur l'axe des absisce et y la position sur l'axe des ordonnées */
    struct Position
    {
        int x;
        int y;
    };

    /** @brief Namespace contenant tous les outils pour construire un bouton */
    namespace BuilderBouton
    {
        /** @brief "Focus" indique si l'objet prend, traite ou rejette l'évent.
            @enum ISNOTCIBLE : le bouton n'est pas la cible de l'évent
            @enum CONTINU : le bouton est la cible de l'évent, mais on peut transmettre l'évent à une autre cible
            @enum FINI : le bouton est la cible de l'évent, on s'arrête maintenant
            @enum INCONNU : on ne sait pas si le bouton est la cible ou non de l'évent */
        enum {ISNOTCIBLE, CONTINU, FINI, INCONNU} Focus;

        /** @brief N'est pas une classe. Sert dans les templates quand on veut utiliser une fonction et non une méthode. */
        class NoClass{};

        template<typename Event, typename Image>
        class BoutonData;

        /** @brief classe vide dont hérite BoutonData, permet de transmettre un BoutonData quand on ne peut pas utiliser les templates */
        class VirtualBoutonData
        {

        };

        /** @brief Classe virtuelle pure, permet de définir un état pour un (ou plusieurs) bouton(s) . */
        template<typename Image, typename Event>
        class VirtualEtat
        {
        public :
            /** @brief lance la fonction/méthode à lancer lorsque cet état est atteint
              @param VirtualBoutonData * : pointeur sur les données du bouton
              @return nouvel état */
            virtual int lauch(VirtualBoutonData *) = 0;

            /** @brief retourne l'image associé à cet état
                @return  const Image * image associé à l'état */
        virtual const Image * getImage(void) = 0;

            virtual ~VirtualEtat(){}
        };

        /** @brief Défini un état pour un (ou plusieurs) bouton(s).
            Il suffit de créer un état puis de l'ajouter à la liste listeEtat du bouton. */
        template<typename Event, typename Image,  typename Classe = NoClass>
        class Etat : VirtualEtat<Event, Image>
        {
        public :

                typedef int (Classe::*Methode)(VirtualBoutonData *);

                /** @brief construit un état
                    @param Image * img : pointeur sur l'image associé à l'état (Vous pouvez l'utiliser pour stocker un tableau d'images servant à la construction de l'état final. Par défaut vaut NULL.
                    @param  Classe * classe = NULL : pointeur sur la classe à utiliser pour lancer la méthode de traitement, par défaut vaut NULL.
                    @param  Methode * meth = NULL : méthode à lancer lorsque cet état est atteinds.
                    prototype : int Classe::(VirtualBoutonData *) */
                Etat(Image * img = NULL, Classe * classe = NULL, Methode * meth = NULL) : image(img), classe(classe), methode(meth){};
            /** @brief pointeur sur la classe à appeler */
            Classe * classe;
            /** @brief pointeur sur la méthode à appeler */
            Methode * methode;
            /** @brief pointeur sur l'image de l'état
                /!\ L'image doit être conservée dans un gestionnaire d'images pendant le cycle de vie de cet état. */
            Image * image;
            /** @brief lance la fonction/méthode à lancer lorsque cet état est atteint
              @param VirtualBoutonData * : pointeur sur les données du bouton
              @return nouvel état ou -1 si aucune méthode ou fonction n'est associé à cet état. */
            int lauch(VirtualBoutonData * data)
            {
                if(methode)
                    return run(data);
                else
                    return -1;
            }

            /** @brief lance la fonction/méthode à lancer lorsque cet état est atteint
              @param BoutonData * : pointeur sur les données du bouton
              @return nouvel état */
            int run(BoutonData<Image, Event> * data)
            {
                return classe->methode(data);
            }
            /** @brief retourne l'image associé à cet état */
            const Image * getImage(void)
            {
                return image;
            }
        };

        template<typename Event, typename Image>
        class Etat<Image, Event, NoClass>
        {
        public :
               typedef int (* Fonction)(VirtualBoutonData *);

                /** @brief construit un état
                    @param Image * img : pointeur sur l'image associé à l'état (Vous pouvez l'utiliser pour stocker un tableau d'images servant à la construction de l'état final. Par défaut vaut NULL.
                    @param  Fonction * fct = NULL : fonction à lancer lorsque cet état est atteinds : prototype : int (VirtualBoutonData *) */
                Etat(Image * img = NULL, Fonction * fct = NULL) : image(img), fonction(fct){};

            /** @brief pointeur sur la fonction à appeler */
            Fonction * fonction;
            Image * image;t */
            int run(BoutonData<Event, Image> * data)
            {
                if( fonction )
                    return fonction(data);
                else
                    return -1;
            }

            int lauch(VirtualBoutonData * data)
            {
                return run(data);
            }


            const Image * getImage(void)
            {
                return image;
            }
        };

        //----------------- Conditions --------------------------------------------------------------
        /** @brief Classe virtuelle pure, permet de définir une condition pour un ou plusieurs boutons */
        template<typename Event, typename Image>
        class VirtualCondition
        {
            public :
                    /** @brief lance la condition
                        @param VirtualBoutonData * : bouton cible
                        @param  Event * : évènement reçu
                        @return int : Focus */
                virtual int lauch(VirtualBoutonData *, Event *) = 0;
        };

        /** @brief Permet de définir une condition pour un ou plusieurs boutons, il suffit de créer la condition et de l'ajouter à la liste listeCondition du bouton.
            Les conditions seront traité dans l'ordre d'ajout.
            Il est donc très conseillé de placer en premier lieu des conditions qui vérifieront si le bouton est la cible de l'event ou non. */
        template<typename Event, typename Image, typename Classe = NoClass>
        class Condition : VirtualCondition<Event, Image>
        {
        public :
                typedef int(Classe::*Methode)(VirtualBoutonData * data, Event * event);
        /** @brief construit une condition
            @param Methode * meth = NULL : méthode à lancer.
            Prototype : int Classe::(VirtualBoutonData *, Event *)
            @param Classe * classe = NULL : classe à partir de laquelle lancer la méthode. */
            Condition(Methode * meth = NULL, Classe * classe = NULL) : methode(meth), classe(classe) {}

            /** @brief méthode à lancer */
            Methode * methode;

            /** @brief classe à partir de laquelle lancer la méthode */
            Classe * classe;

            /** @brief lance la condition
                @param VirtualBoutonData * data : bouton depuis lequel est lancé la condition
                @param Event * event : évènement reçu
                @return int : Focus, si aucune méthode/fonction est rattachée à la condition retourne -1 */
            int lauch(VirtualBoutonData * data, Event * event)
            {
                if(methode)
                    return run(data, event);
                else
                    return -1;
            }

            /** @brief lance la condition */
            int run(BoutonData<Event, Image> * data, Event * event)
            {
                return classe->methode(data, event);
            }
        };

        template<typename Event, typename Image>
        class Condition<Event, Image, NoClass>
        {
        public :
                typedef int (*Fonction)(VirtualBoutonData *, Event *);
        /** @brief construit une condition
          @param Fonction * fct : fonction à lancer */
            Condition(Fonction * fct = NULL) : fonction(fct) {}

            /** @brief fonction à lancer */
        Fonction * fonction;

            int lauch(VirtualBoutonData * data, Event * event)
            {
                return run(data, event);
            }

            int run(BoutonData<Event, Image> * data, Event * event)
            {
                return fonction(data, event);
            }
        };

        //-----------------BoutonData -------------------------------------------------------------
        /** @brief contient toutes les données du bouton */
        template<typename Event, typename Image>
        class BoutonData : VirtualBoutonData
        {
        public :
                BoutonData() : image(NULL){}
                typedef std::vector<VirtualEtat<Event, Image> > ListeEtat;
                typedef std::vector<VirtualCondition<Event, Image> > ListeCondition;

                /** @brief liste des état du bouton */
                ListeEtat listeEtat;
                /** @brief liste des condition du bouton, ils sont traité dans l'ordre où ils ont été ajoutés */
                ListeCondition listeCondition;
                /** @brief dernier évènement dont le bouton a été la cible */
                Event lastEvent;
                /** @brief Image actuelle du bouton */
                Image * image;
                /** @brief position du bouton */
                Position position;
        };
    }
}
#endif // BUILDERBOUTON_H
