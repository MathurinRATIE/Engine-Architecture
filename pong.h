#pragma once
#include "scene.h"
#include "ball.h"
#include "paddle.h"

class Pong : public Scene
{
public :
	Pong();

	void Start(Renderer* pRenderer, Window* rWindow, std::vector<Actor*> pActors) override;
	void Update(float deltaTime) override;
	void Render() override;
	void OnInput(SDL_Event event) override;
	void Close() override;

private :
	int mScorePlayer1 = 0;
	int mScorePlayer2 = 0;
	bool mIsBallLaunched = false;
	bool mMovePaddleDown = false;
	bool mMovePaddleUp = false;
	Ball* mBall;
	Paddle* mPaddle1;
	Paddle* mPaddle2;
};

