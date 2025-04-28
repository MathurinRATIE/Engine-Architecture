#include "bowlingScene.h"
#include "camera.h"
#include "meshActor.h"
#include "texture.h"
#include "collider3DComponent.h"
#include "bowlingBall.h"
#include "pin.h"

void BowlingScene::Start(IRenderer* pRenderer, Window* pWindow)
{
	mRenderer = pRenderer;
	mWindow = pWindow;

	Assets::LoadTexture(mRenderer, "Pin.png", "Pin");
	Assets::LoadTexture(mRenderer, "Wall.png", "Wall");
	Assets::LoadTexture(mRenderer, "BowlingBall.png", "Ball");
	Assets::LoadTexture(mRenderer, "BowlingFloor.jpg", "Floor");
	Assets::LoadTexture(mRenderer, "Black.png", "Black");
	Assets::LoadShaderProgram("Mesh", "mesh.vs", "mesh.fs");
	Assets::LoadMesh("Pin.obj", "Pin");
	Assets::LoadMesh("Sphere.obj", "Sphere");
	Assets::LoadMesh("Cube.obj", "Cube");

	MeshActor* blowlingFloor = new MeshActor(this, pWindow, pRenderer, {}, ActorState::Active, Transform3D(Vector3(10, 0, 0), Vector3(20, 4, 0.1f)), "Cube", "Floor");
	MeshActor* floor = new MeshActor(this, pWindow, pRenderer, {}, ActorState::Active, Transform3D(Vector3(5, 0, -0.1f), Vector3(30, 15, 0.1f)), "Cube", "Black");
	MeshActor* roof = new MeshActor(this, pWindow, pRenderer, {}, ActorState::Active, Transform3D(Vector3(5, 0, 6), Vector3(30, 15, 0.1f)), "Cube", "Black");
	MeshActor* wallEast = new MeshActor(this, pWindow, pRenderer, {}, ActorState::Active, Transform3D(Vector3(7.5, 5, 0), Vector3(30, 0.1f, 30)), "Cube", "Wall");
	MeshActor* wallWest = new MeshActor(this, pWindow, pRenderer, {}, ActorState::Active, Transform3D(Vector3(7.5, -5, 0), Vector3(30, 0.1f, 30)), "Cube", "Wall");
	MeshActor* wallNorth = new MeshActor(this, pWindow, pRenderer, {}, ActorState::Active, Transform3D(Vector3(20, 0, 3), Vector3(0.1f, 16, 16)), "Cube", "Wall");
	MeshActor* wallSouth = new MeshActor(this, pWindow, pRenderer, {}, ActorState::Active, Transform3D(Vector3(-5, 0, 3), Vector3(0.1f, 16, 16)), "Cube", "Wall");
	Pin* pin1 = new Pin(this, pWindow, pRenderer, {}, ActorState::Active, Transform3D(Vector3(18, -1.5f, 0.2f), Vector3(.3f, .3f, .3f), Quaternion(Maths::ToRad(40), 0, 0, 1)));
	Pin* pin2 = new Pin(this, pWindow, pRenderer, {}, ActorState::Active, Transform3D(Vector3(18, -0.5f, 0.2f), Vector3(.3f, .3f, .3f), Quaternion(Maths::ToRad(40), 0, 0, 1)));
	Pin* pin3 = new Pin(this, pWindow, pRenderer, {}, ActorState::Active, Transform3D(Vector3(18, 0.5f, 0.2f), Vector3(.3f, .3f, .3f), Quaternion(Maths::ToRad(40), 0, 0, 1)));
	Pin* pin4 = new Pin(this, pWindow, pRenderer, {}, ActorState::Active, Transform3D(Vector3(18, 1.5f, 0.2f), Vector3(.3f, .3f, .3f), Quaternion(Maths::ToRad(40), 0, 0, 1)));
	Pin* pin5 = new Pin(this, pWindow, pRenderer, {}, ActorState::Active, Transform3D(Vector3(17, -1, 0.2f), Vector3(.3f, .3f, .3f), Quaternion(Maths::ToRad(40), 0, 0, 1)));
	Pin* pin6 = new Pin(this, pWindow, pRenderer, {}, ActorState::Active, Transform3D(Vector3(16, 0, 0.2f), Vector3(.3f, .3f, .3f), Quaternion(Maths::ToRad(40), 0, 0, 1)));
	Pin* pin7 = new Pin(this, pWindow, pRenderer, {}, ActorState::Active, Transform3D(Vector3(16, 1, 0.2f), Vector3(.3f, .3f, .3f), Quaternion(Maths::ToRad(40), 0, 0, 1)));
	Pin* pin8 = new Pin(this, pWindow, pRenderer, {}, ActorState::Active, Transform3D(Vector3(15, -0.5f, 0.2f), Vector3(.3f, .3f, .3f), Quaternion(Maths::ToRad(40), 0, 0, 1)));
	Pin* pin9 = new Pin(this, pWindow, pRenderer, {}, ActorState::Active, Transform3D(Vector3(15, 0.5f, 0.2f), Vector3(.3f, .3f, .3f), Quaternion(Maths::ToRad(40), 0, 0, 1)));
	Pin* pin10 = new Pin(this, pWindow, pRenderer, {}, ActorState::Active, Transform3D(Vector3(14, 0, 0.2f), Vector3(.3f, .3f, .3f), Quaternion(Maths::ToRad(40), 0, 0, 1)));

	BowlingBall* bowlingBall = new BowlingBall(this, pWindow, pRenderer, {}, ActorState::Active, Transform3D(Vector3(2, 0, .2f), Vector3(.8f, .8f, .8f)));
	bowlingBall->GetTransform()->Rotate(Maths::ToRad(180), bowlingBall->GetTransform()->Up());

	//sphereActor->GetTransform()->Rotate(Maths::ToRad(90), sphereActor->GetTransform()->Forward());

	Camera* camera = new Camera(this, pWindow, pRenderer, {}, ActorState::Active, Transform3D(Vector3(-4, 0, 2)));
}

void BowlingScene::Update()
{
	for (Actor* actor : mActors)
	{
		actor->Update();
	}

	AddPendingActors();
	RemovePendingActors();
}

void BowlingScene::Render()
{
	mRenderer->Draw();
}

void BowlingScene::Close()
{
}
