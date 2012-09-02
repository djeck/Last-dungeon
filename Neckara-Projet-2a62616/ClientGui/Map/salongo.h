#ifndef SALONGO_H
#define SALONGO_H

#include "../map.h"

namespace LD
{
/** @brief repr�sente un salon de Go */
    class SalonGo : public Map
    {
    public:
        SalonGo(Jeux * jeux);
        ~SalonGo();
        bool onEvent(const irr::SEvent &event);

        void draw(void);
    private :
        /** @brief bouton permettant de commencer � jouer */
        irr::gui::IGUIButton * boutonJouer;
    };
}

#endif // SALONGO_H
