#include "../includes/view.h"

LD::GO::view::view(irr::IrrlichtDevice* device=0)
{
  if(device != 0)
 Device = device;
 camera = Device ->getSceneManager()->addCameraSceneNode(0, irr::core::vector3df(0, 10, 0), irr::core::vector3df(0, 0, 0));//vue plongente
 Font = Device ->getGUIEnvironment()->getFont();//font de base
 plateaux.push_back(new Plateau(10, 10));//un plateau de base
}

LD::GO::view::view(irr::scene::ICameraSceneNode* Camera, irr::IrrlichtDevice* device, int nbPlateau)
{
  Device = device;
  camera = Camera;
  for(int i = 0; i<nbPlateau; i++)//autant de plateau de demander
  plateaux.push_back(new Plateau(10, 10));
  Font = Device ->getGUIEnvironment()->getFont();//font de base
}