#include "../includes/view.h"

LD::GO::view::view(irr::IrrlichtDevice* device=0)
{
  if(device != 0)
 Device = device;
 camera = Device ->getSceneManager()->addCameraSceneNode(0, irr::core::vector3df(0, 10, 0), irr::core::vector3df(0, 0, 0));//vue plongente
 Font = Device ->getGUIEnvironment()->getFont();//font de base
}

LD::GO::view::view(irr::scene::ICameraSceneNode* Camera, irr::IrrlichtDevice* device, int nbPlateau)
{
  Device = device;
  camera = Camera;
  Font = Device ->getGUIEnvironment()->getFont();//font de base
}