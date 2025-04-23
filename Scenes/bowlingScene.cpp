#include "bowlingScene.h"
#include "camera.h"
#include "meshActor.h"
#include "texture.h"

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

	MeshActor* blowlingFloor = new MeshActor(this, pWindow, pRenderer, {}, ActorState::Active, Transform3D(Vector3(10, 0, 0), Vector3(10, 2, 0.1f)), "Cube", "Floor");
	MeshActor* floor = new MeshActor(this, pWindow, pRenderer, {}, ActorState::Active, Transform3D(Vector3(5, 0, -0.1f), Vector3(15, 15, 0.1f)), "Cube", "Black");
	MeshActor* roof = new MeshActor(this, pWindow, pRenderer, {}, ActorState::Active, Transform3D(Vector3(5, 0, 6), Vector3(15, 15, 0.1f)), "Cube", "Black");
	MeshActor* wallEast = new MeshActor(this, pWindow, pRenderer, {}, ActorState::Active, Transform3D(Vector3(7.5, 5, 0), Vector3(15, 0.1f, 15)), "Cube", "Wall");
	MeshActor* wallWest = new MeshActor(this, pWindow, pRenderer, {}, ActorState::Active, Transform3D(Vector3(7.5, -5, 0), Vector3(15, 0.1f, 15)), "Cube", "Wall");
	MeshActor* wallNorth = new MeshActor(this, pWindow, pRenderer, {}, ActorState::Active, Transform3D(Vector3(20, 0, 3), Vector3(0.1f, 8, 8)), "Cube", "Wall");
	MeshActor* wallSouth = new MeshActor(this, pWindow, pRenderer, {}, ActorState::Active, Transform3D(Vector3(-5, 0, 3), Vector3(0.1f, 8, 8)), "Cube", "Wall");
	MeshActor* BowlingBall = new MeshActor(this, pWindow, pRenderer, {}, ActorState::Active, Transform3D(Vector3(2, 0, .5f), Vector3(.5f, .5f, .5f)), "Sphere", "Ball");
	MeshActor* pin1 = new MeshActor(this, pWindow, pRenderer, {}, ActorState::Active, Transform3D(Vector3(18, -0.9f, 0.2f), Vector3(.1f, .1f, .1f), Quaternion(Maths::ToRad(40), 0, 0, 1)), "Pin", "Pin");
	MeshActor* pin2 = new MeshActor(this, pWindow, pRenderer, {}, ActorState::Active, Transform3D(Vector3(18, -0.3f, 0.2f), Vector3(.1f, .1f, .1f), Quaternion(Maths::ToRad(40), 0, 0, 1)), "Pin", "Pin");
	MeshActor* pin3 = new MeshActor(this, pWindow, pRenderer, {}, ActorState::Active, Transform3D(Vector3(18, 0.3f, 0.2f), Vector3(.1f, .1f, .1f), Quaternion(Maths::ToRad(40), 0, 0, 1)), "Pin", "Pin");
	MeshActor* pin4 = new MeshActor(this, pWindow, pRenderer, {}, ActorState::Active, Transform3D(Vector3(18, 0.9f, 0.2f), Vector3(.1f, .1f, .1f), Quaternion(Maths::ToRad(40), 0, 0, 1)), "Pin", "Pin");
	MeshActor* pin5 = new MeshActor(this, pWindow, pRenderer, {}, ActorState::Active, Transform3D(Vector3(17.5f, -0.6f, 0.2f), Vector3(.1f, .1f, .1f), Quaternion(Maths::ToRad(40), 0, 0, 1)), "Pin", "Pin");
	MeshActor* pin6 = new MeshActor(this, pWindow, pRenderer, {}, ActorState::Active, Transform3D(Vector3(17.5f, 0, 0.2f), Vector3(.1f, .1f, .1f), Quaternion(Maths::ToRad(40), 0, 0, 1)), "Pin", "Pin");
	MeshActor* pin7 = new MeshActor(this, pWindow, pRenderer, {}, ActorState::Active, Transform3D(Vector3(17.5f, 0.6f, 0.2f), Vector3(.1f, .1f, .1f), Quaternion(Maths::ToRad(40), 0, 0, 1)), "Pin", "Pin");
	MeshActor* pin8 = new MeshActor(this, pWindow, pRenderer, {}, ActorState::Active, Transform3D(Vector3(17.0f, -0.3f, 0.2f), Vector3(.1f, .1f, .1f), Quaternion(Maths::ToRad(40), 0, 0, 1)), "Pin", "Pin");
	MeshActor* pin9 = new MeshActor(this, pWindow, pRenderer, {}, ActorState::Active, Transform3D(Vector3(17.0f, 0.3f, 0.2f), Vector3(.1f, .1f, .1f), Quaternion(Maths::ToRad(40), 0, 0, 1)), "Pin", "Pin");
	MeshActor* pin10 = new MeshActor(this, pWindow, pRenderer, {}, ActorState::Active, Transform3D(Vector3(16.5f, 0, 0.2f), Vector3(.1f, .1f, .1f), Quaternion(Maths::ToRad(40), 0, 0, 1)), "Pin", "Pin");

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
