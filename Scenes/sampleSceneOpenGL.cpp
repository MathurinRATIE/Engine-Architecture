#include "sampleSceneOpenGL.h"
#include "meshActor.h"
#include "meshComponent.h"
#include "camera.h"
#include "texture.h"

void SampleSceneOpenGL::Start(IRenderer* pRenderer, Window* pWindow)
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

	MeshActor* cubeActor = new MeshActor(this, pWindow, pRenderer, {}, ActorState::Active, Transform3D(Vector3(10, 0, -2), Vector3(15, 15, 0.1f)), "Cube", "Wall", "Mesh");
	MeshActor* sphereActor = new MeshActor(this, pWindow, pRenderer, {}, ActorState::Active, Transform3D(Vector3(10, 0, 0)), "Sphere", "Wall", "Tesselation");
	sphereActor->GetTransform()->Rotate(Maths::ToRad(90), sphereActor->GetTransform()->Forward());

	Camera* camera = new Camera(this, pWindow, pRenderer, {}, ActorState::Active, Transform3D(Vector3(-5, 0, 0)));
}

void SampleSceneOpenGL::Update()
{
	for (Actor* actor : mActors)
	{
		actor->Update();
	}

	AddPendingActors();
	RemovePendingActors();
}

void SampleSceneOpenGL::Render()
{
	mRenderer->Draw();
}

void SampleSceneOpenGL::Close()
{
}
