#include "pong.h"

Pong::Pong() : Scene() 
{
};

void Pong::Start(Renderer* pRenderer, Window* pWindow)
{
	mRenderer = pRenderer;
	mWindow = pWindow;

	std::cout << "Player : " << mScorePlayer1 << " / AI : " << mScorePlayer2 << std::endl;

	mBall = new BallActor(mWindow);
	mPaddle1 = new PaddleActor(true, mWindow);
	mPaddle2 = new PaddleActor(false, mWindow);
}

void Pong::Update()
{
	// Move paddle
	if (mMovePaddleDown)
	{
		mPaddle1->MoveDown(static_cast<float>(Time::deltaTime), 1.0f);
	}
	if (mMovePaddleUp)
	{
		mPaddle1->MoveUp(static_cast<float>(Time::deltaTime), 1.0f);
	}

	// Move Ball
	int returnValue = mBall->Move(static_cast<float>(Time::deltaTime), mIsBallLaunched);
	mPaddle2->FollowBall(mBall->GetRect().mPosition.y, static_cast<float>(Time::deltaTime));

	// Player loose
	if (returnValue != 0)
	{
		if (returnValue == 1)
		{
			mScorePlayer1++;
		}
		else if (returnValue == 2)
		{
			mScorePlayer2++;
		}

		mIsBallLaunched = false;
		std::cout << "Player : " << mScorePlayer1 << " / AI : " << mScorePlayer2 << std::endl;
		mPaddle1->Reset();
		mPaddle2->Reset();
		mBall->Reset();
	}

	// Check paddle collisions
	/*bool collideLeftPaddle = mBall->GetRect().CheckCollisions(mPaddle1->GetRect());
	bool collideRightPaddle = mBall->GetRect().CheckCollisions(mPaddle2->GetRect());

	if (collideLeftPaddle)
	{
		mBall->BounceX(false);
		mBall->SpeedUp();
	}
	else if (collideRightPaddle)
	{
		mBall->BounceX(true);
		mBall->SpeedUp();
	}*/
}

void Pong::Render()
{
	Rectangle ballRect = mBall->GetRect();
	Rectangle paddle1Rect = mPaddle1->GetRect();
	Rectangle paddle2Rect = mPaddle2->GetRect();

	Color ballColor = { 140, 253, 132, 255 };
	Color paddleColor = { 253, 168, 132, 255 };

	mRenderer->DrawRect(ballRect, ballColor);
	mRenderer->DrawRect(paddle1Rect, paddleColor);
	mRenderer->DrawRect(paddle2Rect, paddleColor);
}

void Pong::OnInput(SDL_Event pEvent)
{
	switch (pEvent.type) {
	case SDL_KEYDOWN:
		if (pEvent.key.keysym.sym == SDLK_s)
			mMovePaddleDown = true;
		if (pEvent.key.keysym.sym == SDLK_z)
			mMovePaddleUp = true;
		if (pEvent.key.keysym.sym == SDLK_DOWN)
			mMovePaddleDown = true;
		if (pEvent.key.keysym.sym == SDLK_UP)
			mMovePaddleUp = true;
		if (pEvent.key.keysym.sym == SDLK_SPACE)
			mIsBallLaunched = true;
		break;
	case SDL_KEYUP :
		if (pEvent.key.keysym.sym == SDLK_s)
			mMovePaddleDown = false;
		if (pEvent.key.keysym.sym == SDLK_z)
			mMovePaddleUp = false;
		if (pEvent.key.keysym.sym == SDLK_DOWN)
			mMovePaddleDown = false;
		if (pEvent.key.keysym.sym == SDLK_UP)
			mMovePaddleUp = false;
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
