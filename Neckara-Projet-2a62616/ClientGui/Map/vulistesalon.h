#ifndef VULISTESALON_H
#define VULISTESALON_H

#include "../map.h"

namespace LD
{
    class FenetreCreationSalon;
    class VuListeSalon : public Map
    {
    public:
        VuListeSalon(Jeux * jeux);
        ~VuListeSalon();

        bool onEvent(const irr::SEvent &event);

        void draw(void);
    private :
        /** @brief bouton permettant de créer un nouveau salon */
        irr::gui::IGUIButton * boutonCreer;
        /** @brief fenetre permettant de créer un nouveau salon */
        FenetreCreationSalon * fenCreatSalon;
    };
}

#endif // VULISTESALON_H
