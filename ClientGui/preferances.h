#ifndef PREFERANCES_H
#define PREFERANCES_H

namespace LD
{
    /** @brief pr�f�rances utilisateurs */
    class Preferances
    {
    public:
        /** @brief Charge les pr�f�rances */
        Preferances();

        /** @brief Sauvegarde les pr�f�rances */
        void save(void);
    };
}

#endif // PREFERANCES_H
