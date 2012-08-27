#ifndef VIEW_H
#define VIEW_H

#include <irrlicht/irrlicht.h>
#include <iostream>

namespace LD
{
 namespace GO
 {
 /** @brief classe view traitent la vue */
 class view
 {
 public:
         /** @brief le constructeur */
	 view(void);
	 /** @brief defini le font
	  @param textureD : emplacement de la texture à charger
	  @param x : x
	  @param y : y
	  @param z : z coordonnées du rectangle */
	 void setFont(const std::string& textureD, irr::u32 x,irr::u32 y, irr::u32 z);
	 /** @brief defini une nouvelle camera
	  @param camera : nouvelle camera */ 
	 void setCamera(irr::scene::ICameraSceneNode* camera);
	 /** @brief defini un controlleur dans la vue
	  @param controlleur : constroleur */ 
	 void setControlleur(Controlleur* controlleur);
	 /** @brief defini la position du plateau
	  @param numPlateau : id du plateau (numero)
	  @param x : x
	  @param y : y
	  @param z : z */ 
	 void setPositionPlateau(int numPlateau, int x, int y, int z);
	 /** @brief place un pion
	  @param pion : pion
	  @param socle : socle attribué au pion */
	 void setPion(Pion* pion, Socle* socle);
	/** @brief redefini un socle
	  @param numPlateau : id du plateau
	  @param socleModel : socle servent de base pour placer le socle
	  @param socle : socle attribué au pion
	  @param x : position x relative au plateau
	  @param y : position y relative au plateau
	  @param z : position z relative au plateau
	  @param xb : orientation horisontale du socle
	  @param yb : orientation vertical du socle */
	void setSocle(int numPlateau = 0,Socle* socleModel = 0, Socle* socle, int x = 0, int y = 0, int z = 0, int xb = 0, int yb = 0, int zb = 0);/*on pourra mettre un socle soit:
	- paraport a un autre
	- ou paraport au plateau
	*/
 protected:
 };
 }
}
#endif // VIEW_H