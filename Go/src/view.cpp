#include "../includes/view.h"

LD::GO::view::view(irr::IrrlichtDevice* device=0)
{
  if(device != 0)
 Device = device;
 camera = Device ->getSceneManager()->addCameraSceneNode(0, irr::core::vector3df(0, 10, 0), irr::core::vector3df(0, 0, 0));//vue plongente
 Font = Device ->getGUIEnvironment()->getFont();//font de base
}

LD::GO::view::view(irr::scene::ICameraSceneNode* Camera, irr::IrrlichtDevice* device, Plateau* Plateaux)
{
  Device = device;
  camera = Camera;
  Font = Device ->getGUIEnvironment()->getFont();//font de base
  plateaux.push_back(Plateaux);
}

LD::GO::view::setFont(const std::string& textureD, irr::u32 x,irr::u32 y, irr::u32 z)
{
  irr::gui::IGUIEnvironment* environement = Device->getGUIEnvironment();
 Font = environement->getFont(textureD);
 environement->getSkin()->setFont(Font);
 environement->getSkin()->setFont(environement->getBuiltInFont(), irr::gui::EGDF_TOOLTIP);
}