#include "AdvancedOpenglScene.h"
#include "assets.h"
#include "meshComponent.h"
#include "spriteComponent.h"
#include "engineTime.h"
#include "meshActor.h"
#include "platformActor.h"
#include "camera.h"

AdvancedOpenglScene::AdvancedOpenglScene()
{
}

void AdvancedOpenglScene::Start(IRenderer* pRenderer, Window* pWindow)
{
	mRenderer = pRenderer;
	mWindow = pWindow;

	Assets::LoadTexture(mRenderer, "pin.png", "Pin");
	Assets::LoadTexture(mRenderer, "Wall.png", "Wall");
	Assets::LoadShaderProgram("Mesh", "mesh.vs", "mesh.fs");
	Assets::LoadShaderProgram("Tesselation", "tesselation.vs", "tesselation.fs", "tesselation.tcs", "tesselation.tes");
	Assets::LoadMesh("pin.obj", "Pin");
	Assets::LoadMesh("Monkey.obj", "Monkey");
	Assets::LoadMesh("Sphere.obj", "Sphere");
	Assets::LoadMesh("cube.obj", "Cube");

	MeshActor* cubeActor = new MeshActor(this, pWindow, pRenderer, {}, ActorState::Active, Transform3D(Vector3(10, 0, -2), Vector3(15, 15, 0.1f)), "Cube", "Wall", "Tesselation");
     
    cubeActor->GetTransform()->SetRotation(Quaternion(Maths::ToRad(90), 0, 0, 1));

	//PlatformActor* platform = new PlatformActor(this, pWindow, pRenderer, {});

	Camera* camera = new Camera(this, pWindow, pRenderer, {}, ActorState::Active, Transform3D(Vector3(-5, 0, 0)));
}

void AdvancedOpenglScene::Render()
{
}

void AdvancedOpenglScene::Update()
{
	for (Actor* actor : mActors)
	{
		actor->Update();
	}

	AddPendingActors();
	RemovePendingActors();
}

void AdvancedOpenglScene::Close()
{
}
