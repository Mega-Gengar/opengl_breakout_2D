#include "game.h"
#include"resource_manager.h"
#include"sprite_renderer.h"

SpriteRenderer* Renderer;
game::game(unsigned int  width, unsigned int  height) :State(GAME_ACTIVE), Keys(), Width(width), Height(height) {

}

game::~game() {
	delete Renderer;
}


void game::Init() {
	//load shaders
	ResourceManager::LoadShader("./resource/shader/sprite.vs", "./resource/shader/sprite.frag", nullptr, "sprite");
	//configure shaders
	glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(this->Width),
		static_cast<float>(this->Height), 0.0f, -1.0f, 1.0f);
	ResourceManager::GetShader("sprite").use().SetInteger("image", 0);
	ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);
	//设置专用于渲染的控制
	Renderer = new SpriteRenderer(ResourceManager::GetShader("sprite"));
	// load textures
	ResourceManager::LoadTexture("./resource/image/awesomeface.png", true, "face");
}

void game::Update(float dt) {

}

void game::ProcessInput(float dt) {

}

void game::Render() {
	Renderer->DrawSprite(ResourceManager::GetTexture("face"),
		glm::vec2(200.0f, 200.0f), glm::vec2(300.0f, 400.0f), 45.0f, glm::vec3(0.0f, 1.0f, 0.0f));
}