#pragma once
#include "scene.h"
#include "ballActor.h"
#include "paddleActor.h"
#include "engineTime.h"

class Pong : public Scene
{
public :
	Pong();

	void Start(Renderer* pRenderer, Window* rWindow) override;
	void Update() override;
	void Render() override;
	void Close() override;

private :
	int mScorePlayer1 = 0;
	int mScorePlayer2 = 0;
	bool mIsBallLaunched = false;
	bool mMovePaddleDown = false;
	bool mMovePaddleUp = false;
	BallActor* mBall;
	PaddleActor* mPaddle1;
	PaddleActor* mPaddle2;
};

