// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include "AnimSpriteComponent.h"
#include "Math.h"

AnimSpriteComponent::AnimSpriteComponent(Actor* owner, int drawOrder)
	:SpriteComponent(owner, drawOrder)
	, mCurrFrame(0.0f)
	, mAnimFPS(24.0f)
{
}

void AnimSpriteComponent::Update(float deltaTime)
{
	SpriteComponent::Update(deltaTime);

	if (mAnimTextures.size() > 0 && mCurrentTable != -1)
	{
		std::vector<int> table = mAnimPatternArray[mCurrentTable];

		// Update the current frame based on frame rate
		// and delta time
		mCurrFrame += mAnimFPS * deltaTime;

		// Wrap current frame if needed
		int patternNum = table.size();
		while (mCurrFrame >= patternNum)
		{
			mCurrFrame -= patternNum;
		}

		// Set the current texture
		int tableIndex = table[static_cast<int>(mCurrFrame)];
		SetTexture(mAnimTextures[tableIndex]);
	}
}

void AnimSpriteComponent::SetAnimTextures(const std::vector<SDL_Texture*>& textures)
{
	mAnimTextures = textures;
	if (mAnimTextures.size() > 0)
	{
		// Set the active texture to first frame
		mCurrFrame = 0.0f;
		SetTexture(mAnimTextures[0]);
	}
}

void AnimSpriteComponent::SetAnimTable(const std::vector<int>& array)
{
	mAnimPatternArray.push_back(array);
}

void AnimSpriteComponent::SetAnimIndex(int index)
{
	mCurrentTable = index;

	if (mAnimTextures.size() > 0 && mCurrentTable != -1)
	{
		// Set the active texture to first frame
		mCurrFrame = 0.0f;

		std::vector<int> table = mAnimPatternArray[mCurrentTable];
		int tableIndex = table[static_cast<int>(mCurrFrame)];
		SetTexture(mAnimTextures[tableIndex]);
	}
}

