#ifndef PREFERANCES_H
#define PREFERANCES_H

namespace LD
{
    /** @brief préférances utilisateurs */
    class Preferances
    {
    public:
        /** @brief Charge les préférances */
        Preferances();

        /** @brief Sauvegarde les préférances */
        void save(void);
    };
}

#endif // PREFERANCES_H
