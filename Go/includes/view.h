#ifndef VIEW_H
#define VIEW_H

#include <irrlicht/irrlicht.h>
#include <iostream>
#include "Plateau.h"
#include "pion.h"

namespace LD
{
 namespace GO
 {
  /** @brief classe 'view' traitent la vue */
  class view
   {
  public:
          /** @brief le constructeur basic
	   @param device : device */
 	 view(irr::IrrlichtDevice* device=0);
	 /** @brief le constructeur complet
	  @param Camera : la camera
	  @param device : device
	  @param nbPlateau : nombre de plateaux desirer */
	 view(irr::scene::ICameraSceneNode* Camera, irr::IrrlichtDevice* device, int nbPlateau);
 	 /** @brief defini le font
 	  @param textureD : emplacement de la texture à charger
 	  @param x : x
 	  @param y : y
 	  @param z : z coordonnées du rectangle */
 	 void setFont(const std::string& textureD, irr::u32 x,irr::u32 y, irr::u32 z);
 	 /** @brief defini une nouvelle camera
 	  @param camera : nouvelle camera */ 
 	 void setCamera(irr::scene::ICameraSceneNode* camera);
 	 /** @brief defini une device
 	  @param device : device */ 
 	 void setControlleur(irr::IrrlichtDevice* device);
 	 /** @brief defini la position du plateau
 	  @param numPlateau : id du plateau (numero)
 	  @param x : x
 	  @param y : y
 	  @param z : z */ 
 	 void setPositionPlateau(int numPlateau, int x, int y, int z);
 	  /** @brief place un pion
	   @param pion : pion
	   @param socle : socle attribué au pion */
	  void setPion(Pion* pion);
	  /** @brief permet l'ajout d'un plateau
	   @return : int :id dans le vector du plateau ajouter
	   
	  int setPlateau(Plateau* Plateau);
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
    irr::gui::IGUIFont* Font;
    irr::scene::ICameraSceneNode* camera;
    irr::IrrlichtDevice* Device;
    std::vector<Plateau*> plateaux;
    std::vector<pion*> pions;
  };
 }
}
#endif // VIEW_H
