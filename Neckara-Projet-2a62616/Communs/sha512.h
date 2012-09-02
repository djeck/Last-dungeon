#ifndef SHA512_H
#define SHA512_H

#include <string>
#include <vector>
#include <iostream>

/** @brief Simplifie l'écriture */
typedef unsigned int uint;
/** @brief Simplifie l'écriture */
typedef unsigned long long ullint;

namespace LD
{
    /** @brief Classe permettant de calculer le hash (sha512) d'un string passé en paramètre.
        Classe écrite par jagatsastry.nitk@gmail.com  le 9th April 09
        Réécrite, optimisée et documentée par Neckara Neckara.LastDungeon@gmail.com */
    class Sha512
    {
    public:
        /** @brief Construit le hash (sha512) du mot passé en paramètre
            @param const std::string & mot : mot dont on doit calculer le hash */
        Sha512(const std::string & mot);

        /** @brief Construit un hash (sha512) déj�  connu
            @param const ullint hash [8] : hash connu */
        Sha512(const ullint hash [8]);

        /** @brief Perme de récupérer le hash (sha512) calculé.
            @return const ullint[] & : référence constante vers le tableau de hash ainsi calculé */
        const unsigned long long * getHash();

        /** @brief met le hash en une chaine affichant le hash en hexadécimal dans le string passé en paramètre
            @param  std::string & resultat : chaine dans laquelle il faut mettre le hash écris en hexadécimal
            @rerturn  const std::string & : référence constante sur le hash */
        const std::string & getHexadecimal(std::string & resultat) const;

        friend std::ostream & operator<< (std::ostream & , Sha512 &);

        bool operator<(const Sha512 &) const;

        bool operator==(const Sha512 &)const;

        bool operator!=(const Sha512 &)const;

    private :
            /** @brief Hash (sha512) du mot passé en paramètre */
            ullint hash[8];

            /** @brief fonction utilisée pour le sha512, converti un nombre passé en paramètre en un string (sans modification des bits)
                @param ullint x : unsigned long long, nombre �  transformer en string
                @return string : string ainsi obtenu. */
            std::string mynum(ullint x);

            /** @brief structure représentant un bloc */
            struct Block
            {
                /** @brief bloc? */
                   std::vector<ullint> msg;
                /** @brief constructeur par défaut, constuit un bloc contenant 16 0. */
                    Block();
                /** @brief constuit un bloc �  partir d'un string.
                    @param  const std::string & p_msg : string qui construit un bloc */
                    Block(const std::string & p_msg);

                /** @brief remplit le bloc �  partir d'un string
                    @param const std::string & p_msg : source */
                    void makeblock(const std::string &  p_msg);

            };

            /** @brief remplit un vecteur de Block �  partir d'un string. (Un block correspondant �  128 caractère du string)
              @param vector<Block>& blks : vecteur �  remplir
              @param string& msg : string source */
            void split(std::vector<Block>& blks, std::string& msg);


            /** @brief ???? */
            ullint ch(ullint x, ullint y, ullint z);

            /** @brief ???? */
            ullint maj(ullint x, ullint y, ullint z);

            /** @brief ???? */
            ullint fn0(ullint x);

            /** @brief ???? */
            ullint fn1(ullint x);

            /** @brief ???? */
            ullint sigma0(ullint x);

            /**  @brief ???? */
            ullint sigma1(ullint x);

            /** @brief tableau d'unsigned long long nécessaire �  la fonction de hash sha512*/
            static ullint K[80];
			
			inline ullint shr( ullint x, uint n){ return (x & 0xFFFFFFFFFFFFFFFFULL) >> n; }
			inline ullint rotr(ullint x, uint n){ return shr(x,n) | (x << (64 - n)); }
    };

    inline std::ostream & operator<< (std::ostream & sortie, Sha512 & sha)
    {
        std::string tmp;

        sortie << sha.getHexadecimal(tmp) << std::endl;
        return sortie;
    }

}
#endif // SHA512_H
