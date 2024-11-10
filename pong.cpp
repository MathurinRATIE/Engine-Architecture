#include "pong.h"

Pong::Pong() : Scene() 
{

};

void Pong::Start(std::shared_ptr<Renderer> pRenderer)
{
	mRenderer = pRenderer;
}

void Pong::Update()
{
	mDeltaTime = SDL_GetTicks() - mLastFrameTime;
	mLastFrameTime = SDL_GetTicks();

	int returnValue = mBall.Move(mDeltaTime);

	if (returnValue == 1)
	{
		mScorePlayer1++;
	}
	else if (returnValue == 2)
	{
		mScorePlayer2++;
	}
}

void Pong::Render()
{
	Rectangle ballRect = mBall.GetRect();
	Rectangle paddle1Rect = mPaddle1.GetRect();
	Rectangle paddle2Rect = mPaddle2.GetRect();
	mRenderer->DrawRect(ballRect);
	mRenderer->DrawRect(paddle1Rect);
	mRenderer->DrawRect(paddle2Rect);
}

void Pong::OnInput(SDL_Event event)
{
	switch (event.type) {
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_s)
				mPaddle1.MoveDown(mDeltaTime);
			if (event.key.keysym.sym == SDLK_z)
				mPaddle1.MoveUp(mDeltaTime);
			if (event.key.keysym.sym == SDLK_DOWN)
				mPaddle2.MoveDown(mDeltaTime);
			if (event.key.keysym.sym == SDLK_UP)
				mPaddle2.MoveUp(mDeltaTime);
			break;
		default:
			break;
	}
}

void Pong::Close()
{
	delete(&mBall);
	delete(&mPaddle1);
	delete(&mPaddle2);
}
