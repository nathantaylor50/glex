#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include <memory>
//for the getTicks()
#include <SDL2/SDL.h>

#include <GL/gl.h>

#include "common.h"
#include "GameAssetManager.h"
class CubeAsset;
#include "CubeAsset.h"

/**
 * GameWorld allows us to separate the management of the game world from the
 * nuts and bolts of game loop initialisation.  The GameWorld currently has
 * a very simplified scene graph consisiting of a single GameAssetManager.
 */
class GameWorld {
 public:
  /**
   * We thread the ApplicationMode through the GameWorld ss we want to read it
   * in from the user.  Threading the state through the various function calls
   * is preferable (in this case) to having some kind of global state.
   */
  GameWorld(ApplicationMode);


  /*
   * move CAM forward
   */
  void CAM_Forward();

  /*
   * move CAM back
   */
  void CAM_Back();

  /*
   * move CAM left
   *
   */
  void CAM_Left();

  /*
   * move CAM right
   */
  void CAM_Right();

  /*
   * move CAM up
   */
  void CAM_Up();

  /*
   * move CAM Down
   */
  void CAM_Down();


  /**
   * generate camera matrix
   */
  void Cam(GLuint program_token);

  /**
   * Calling Draw() will draw the entire world.
   */
  void Draw();
 private:
  std::shared_ptr<GameAssetManager> asset_manager;
  glm::mat4 cam;
};
#endif // GAMEWORLD_H
