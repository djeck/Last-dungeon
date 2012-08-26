#ifndef ListeImage_H
#define ListeImahe_H

#include "Image.h"
#include "Jeux.h"

namespace LD
{
	/** @brief Classe permettant de stocker des images */
	class ListeImage
	{
		public :
			/** @brief constructeur
				Rq : code exécutable dans le .cpp
				@param Jeux * jeux : pointeur vers le jeux */
			ListeImage(Jeux * jeux) : jeux(jeux){};
			/** @brief destructeur */
			~ListeImage();
			/** @brief méthode permettant d'ajouter une image par copie
				@param Image & image : image a ajouter
				@param const std::string & nom : nom de l'image (par défaut "")
				@return Image * : pointeur sur l'image nouvellement créée */
			Image * setImage(Image & image, const std::string & nom = "");
			/** @brief permet de créer une nouvelle image vide
				@param const std::string & nom : nom de l'image
				@return Image * : pointeur sur l'image nouvellement créée  */
			Image * newImage(const std::string & nom);
			/** @brief permet de récupérer une image
				@param const std::string & nom : nom de l'image à récupérer
				@return Image * : image récupérée */
			Image * getImage(const std::string & nom);
			/** @brief permet de supprimer une image
				@param const std::string & nom : nom de l'image à supprimer
				@return bool : Booléen indiquant si la suppression c'est bien passée */
			bool deleteImage(const std::string &nom);
			/** @brief permet de vérifier l'existance d'une image
				@param const std::string & nom : nom de l'image à rechercher
				@return bool : Booléen indiquant si l'image existe (true) ou non (false) */
			bool existImage(const std::string &nom);
			/** @brief permet d'activer/désactiver la fenetre principale (à activer avant toute création d'image et à désactivée ensuite sinon bug sous Unix ) 
				@param bool active : Booléen indiquant si on veut désactiver la fenêtre (false) ou l'activer (true) */
			void activer(bool active);
		private :
			/** @brief Pointeur vers le jeux */
			Jeux *jeux;
			/** @brief liste des images */
			std::map<const std::string, Image *> Liste;
	};
}
#endif //ListeImage_H
