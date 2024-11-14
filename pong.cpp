#include "pong.h"

Pong::Pong() : Scene() 
{
};

void Pong::Start(Renderer* pRenderer, Window* pWindow, std::vector<Actor*> pActors)
{
	rRenderer = pRenderer;
	rWindow = pWindow;
	rActors = pActors;

	std::cout << "Player : " << mScorePlayer1 << " / AI : " << mScorePlayer2 << std::endl;

	mBall = new Ball(rWindow);
	mPaddle1 = new Paddle(true, rWindow);
	mPaddle2 = new Paddle(false, rWindow);
}

void Pong::Update(float pDeltaTime)
{
	// Move paddle
	if (mMovePaddleDown)
	{
		mPaddle1->MoveDown(pDeltaTime, 1.0f);
	}
	if (mMovePaddleUp)
	{
		mPaddle1->MoveUp(pDeltaTime, 1.0f);
	}

	// Move Ball
	int returnValue = mBall->Move(pDeltaTime, mIsBallLaunched);
	mPaddle2->FollowBall(mBall->GetRect().position.y, pDeltaTime);

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

	rRenderer->DrawRect(ballRect, ballColor);
	rRenderer->DrawRect(paddle1Rect, paddleColor);
	rRenderer->DrawRect(paddle2Rect, paddleColor);
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
