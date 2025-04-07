// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
//
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include "Character.h"
#include "AnimSpriteComponent.h"
#include "Game.h"

Character::Character(Game* game)
	:Actor(game)
	,mRightSpeed(0.0f)
	,mDownSpeed(0.0f)
{
	// Create an animated sprite component
	AnimSpriteComponent* asc = new AnimSpriteComponent(this);
	mASC = asc;
	std::vector<SDL_Texture*> anims = {
		game->GetTexture("Assets/Character01.png"),	// 0
		game->GetTexture("Assets/Character02.png"),	// 1
		game->GetTexture("Assets/Character03.png"),	// 2
		game->GetTexture("Assets/Character04.png"),	// 3
		game->GetTexture("Assets/Character05.png"),	// 4
		game->GetTexture("Assets/Character06.png"),	// 5
		game->GetTexture("Assets/Character07.png"),	// 6
		game->GetTexture("Assets/Character08.png"),	// 7
		game->GetTexture("Assets/Character09.png"),	// 8
		game->GetTexture("Assets/Character10.png"),	// 9
		game->GetTexture("Assets/Character11.png"),	// 10
		game->GetTexture("Assets/Character12.png"),	// 11
		game->GetTexture("Assets/Character13.png"),	// 12
		game->GetTexture("Assets/Character14.png"),	// 13
		game->GetTexture("Assets/Character15.png"),	// 14
		game->GetTexture("Assets/Character16.png"),	// 15
		game->GetTexture("Assets/Character17.png"),	// 16
		game->GetTexture("Assets/Character18.png"),	// 17
	};
	asc->SetAnimTextures(anims);

	asc->SetAnimTable(std::vector<int>{2,2,2,5,5,5}); // Idle
	asc->SetAnimTable(std::vector<int>{0,0,1,2,3,4,5}); // Walk
	asc->SetAnimTable(std::vector<int>{6,7,8,9,10,11,12,13,14}); // Jump
	asc->SetAnimTable(std::vector<int>{15,16,17,17,17,16,15}); // Punch

	asc->SetAnimIndex(EAnimIdle);
}

void Character::UpdateActor(float deltaTime)
{
	Actor::UpdateActor(deltaTime);
	// Update position based on speeds and delta time
	Vector2 pos = GetPosition();
	pos.x += mRightSpeed * deltaTime;
	pos.y += mDownSpeed * deltaTime;
	// Restrict position to left half of screen
	if (pos.x < 25.0f)
	{
		pos.x = 25.0f;
	}
	else if (pos.x > 500.0f)
	{
		pos.x = 500.0f;
	}
	if (pos.y < 25.0f)
	{
		pos.y = 25.0f;
	}
	else if (pos.y > 743.0f)
	{
		pos.y = 743.0f;
	}
	SetPosition(pos);
}

void Character::ProcessKeyboard(const uint8_t* state)
{
	AnimSpriteComponent* asc = mASC;

	mRightSpeed = 0.0f;
	mDownSpeed = 0.0f;
	// right/left
	if (state[SDL_SCANCODE_D])
	{
		mRightSpeed += 250.0f;
		asc->SetAnimIndex(EAnimWalk);
	}
	if (state[SDL_SCANCODE_A])
	{
		mRightSpeed -= 250.0f;
		asc->SetAnimIndex(EAnimWalk);
	}
	// up/down
	if (state[SDL_SCANCODE_S])
	{
		mDownSpeed += 300.0f;
		asc->SetAnimIndex(EAnimWalk);
	}
	if (state[SDL_SCANCODE_W])
	{
		mDownSpeed -= 300.0f;
		asc->SetAnimIndex(EAnimWalk);
	}
	if (state[SDL_SCANCODE_SPACE])
	{
		asc->SetAnimIndex(EAnimJump);
	}
	if (state[SDL_SCANCODE_RETURN])
	{
		asc->SetAnimIndex(EAnimPunch);
	}
}
