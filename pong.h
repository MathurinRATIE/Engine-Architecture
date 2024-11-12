#pragma once
#include "scene.h"
#include "ball.h"
#include "paddle.h"

class Pong : public Scene
{
public :
	Pong();

	void Start(Renderer* pRenderer) override;
	void Update() override;
	void Render() override;
	void OnInput(SDL_Event event) override;
	void Close() override;

private :
	float mLastFrameTime = 0.0f;
	float mDeltaTime = 0.0f;
	int mScorePlayer1 = 0;
	int mScorePlayer2 = 0;
	Ball* mBall = new Ball();
	Paddle* mPaddle1 = new Paddle(false);
	Paddle* mPaddle2 = new Paddle(true);
};

