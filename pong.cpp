#include "pong.h"

Pong::Pong() : Scene() 
{
};

void Pong::Start(Renderer* pRenderer, Window* pWindow)
{
	rRenderer = pRenderer;
	rWindow = pWindow;

	std::cout << "Player : " << mScorePlayer1 << " / AI : " << mScorePlayer2 << std::endl;

	mBall = new Ball(rWindow);
	mPaddle1 = new Paddle(true, rWindow);
	mPaddle2 = new Paddle(false, rWindow);
}

void Pong::Update(float deltaTime)
{
	// Move paddle
	if (mMovePaddleDown)
	{
		mPaddle1->MoveDown(deltaTime);
	}
	if (mMovePaddleUp)
	{
		mPaddle1->MoveUp(deltaTime);
	}

	// Move Ball
	int returnValue = mBall->Move(deltaTime, mIsBallLaunched);
	mPaddle2->FollowBall(mBall->GetRect().position.y);

	// Player loose
	if (returnValue == 1)
	{
		mScorePlayer1++;
		mIsBallLaunched = false;
		std::cout << "Player : " << mScorePlayer1 << " / AI : " << mScorePlayer2 << std::endl;
	}
	else if (returnValue == 2)
	{
		mScorePlayer2++;
		mIsBallLaunched = false;
		std::cout << "Player : " << mScorePlayer1 << " / AI : " << mScorePlayer2 << std::endl;
	}

	// Check paddle collisions
	bool collideLeftPaddle = mBall->GetRect().CheckCollisions(mPaddle1->GetRect());
	bool collideRightPaddle = mBall->GetRect().CheckCollisions(mPaddle2->GetRect());

	if (collideLeftPaddle)
	{
		mBall->BounceX(false);
	}
	else if (collideRightPaddle)
	{
		mBall->BounceX(true);
	}
}

void Pong::Render()
{
	Rectangle ballRect = mBall->GetRect();
	Rectangle paddle1Rect = mPaddle1->GetRect();
	Rectangle paddle2Rect = mPaddle2->GetRect();
	rRenderer->DrawRect(ballRect);
	rRenderer->DrawRect(paddle1Rect);
	rRenderer->DrawRect(paddle2Rect);
}

void Pong::OnInput(SDL_Event event)
{
	switch (event.type) {
	case SDL_KEYDOWN:
		if (event.key.keysym.sym == SDLK_s)
			mMovePaddleDown = true;
		if (event.key.keysym.sym == SDLK_z)
			mMovePaddleUp = true;
		if (event.key.keysym.sym == SDLK_DOWN)
			mMovePaddleDown = true;
		if (event.key.keysym.sym == SDLK_UP)
			mMovePaddleUp = true;
		if (event.key.keysym.sym == SDLK_SPACE)
			mIsBallLaunched = true;
		break;
	case SDL_KEYUP :
		if (event.key.keysym.sym == SDLK_s)
			mMovePaddleDown = false;
		if (event.key.keysym.sym == SDLK_z)
			mMovePaddleUp = false;
		if (event.key.keysym.sym == SDLK_DOWN)
			mMovePaddleDown = false;
		if (event.key.keysym.sym == SDLK_UP)
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
