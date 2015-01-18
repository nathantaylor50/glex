#include "GameWorld.h"

GameWorld::GameWorld (ApplicationMode mode) {
  asset_manager = std::make_shared<GameAssetManager>(mode);
  asset_manager->AddAsset(std::make_shared<CubeAsset>());
}


void GameWorld::Cam(GLuint program_token){
//cam matrix
	glm::mat4 Projection = glm::Perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
	glm::mat4 View = glm::lookAt(
									glm::vec3(4,3,3),
									glm::vec3(0,0,0),
									glm::vec3(0,1,0));
	glm::mat4 Model = glm::mat4(1.0f);
	glm::mat4 MVP = Projection * View * Model;
}

void GameWorld::Draw() {
  asset_manager->Draw();
}
