#include "GameWorld.h"
//compensate for computer performance
double currentTime = SDL_GetTicks();
//use deltaTime
GLfloat deltaTime = GLfloat(SDL_GetTicks() - currentTime)/1000;
const GLfloat speed = 0.01;
GLfloat x = 0.0;
GLfloat y = 0.0;
GLfloat z = -1.5;





GameWorld::GameWorld (ApplicationMode mode) {
  asset_manager = std::make_shared<GameAssetManager>(mode);
  asset_manager->AddAsset(std::make_shared<CubeAsset>());
}


void GameWorld::CAM_Forward(){
	z+=speed;
}

void GameWorld::CAM_Back(){
	z-=speed;
}

void GameWorld::CAM_Left(){
	x-=speed;
}

void GameWorld::CAM_Right(){
	x+=speed;
}

void GameWorld::CAM_Up(){
	y+=speed;
}

void GameWorld::CAM_Down(){
	y-=speed;
}

void GameWorld::Cam(GLuint program_token){
	//Handle for CAM uniform
	GLuint CAM_ID = glGetUniformLocation(program_token, "CAM");
//CAM matrix
	glm::mat4 CAM = glm::translate(glm::mat4(1.0f), glm::vec3(x,y, z));
	//send transformation to currently bound shader
	//in the "CAM" uniform
	glUniformMatrix4fv(CAM_ID, 1, GL_FALSE, &CAM[0][0]);

}


void GameWorld::Draw() {
  asset_manager->Draw();
}
