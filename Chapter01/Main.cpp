// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include <iostream>
#include <string>

#include "Game.h"
#include "Vector3D.h"
#include "StudyCpp_decltype_01.h"


int main(int argc, char** argv)
{
	Game game;

	// äwèKÉÅÉCÉì
	StudyCpp_Vector3D_01();
	StudyCpp_decltype_01();



	bool success = game.Initialize();
	if (success)
	{
		game.RunLoop();
	}
	game.Shutdown();
	return 0;
}
