#include "GameWorld.h"

GameWorld::GameWorld (ApplicationMode mode) {
  asset_manager = std::make_shared<GameAssetManager>(mode);
  asset_manager->AddAsset(std::make_shared<CubeAsset>());
}


void GameWorld::Cam(GLuint program_token){
	//Handle for CAM uniform
	GLuint CAM_ID = glGetUniformLocation(program_token, "CAM");
//CAM matrix
	glm::mat4 CAM = glm::translate(glm::mat4(1.0f), glm::vec3(0.0, 0.0, -1.0));
	//send transformation to currently bound shader
	//in the "CAM" uniform
	glUniformMatrix4fv(CAM_ID, 1, GL_FALSE, &CAM[0][0]);

}

void GameWorld::Draw() {
  asset_manager->Draw();
}
