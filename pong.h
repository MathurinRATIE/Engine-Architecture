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
	float mDeltaTime;
	int mScorePlayer1 = 0;
	int mScorePlayer2 = 0;
	Ball mBall = Ball();
	Paddle mPaddle1 = Paddle(false);
	Paddle mPaddle2 = Paddle(true);
};

