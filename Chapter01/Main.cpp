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
#include "StudyCpp_template_01.h"
#include "StudyCpp_std_pair_01.h"
#include "StudyCpp_RangeFor_01.h"
#include "StudyCpp_RawString_01.h"
#include "StudyCpp_ConstantExpression_01.h"
#include "StudyCpp_static_assert_01.h"
#include "StudyCpp_Lambda_01.h"





void f1() noexcept 
{
	std::cout << "noexcept func" << std::endl;
}

void f2() 
{
	std::cout << "normal func" << std::endl;
}

class StudyCpp_delete_01 {
public:
	StudyCpp_delete_01() = delete;
	StudyCpp_delete_01(const StudyCpp_delete_01&) = delete;
	~StudyCpp_delete_01() = delete;
//	StudyCpp_delete_01& oparator = (const StudyCpp_delete_01&) = delete;

};



int main(int argc, char** argv)
{
	Game game;


	// 学習メイン
	StudyCpp_Vector3D_01();				// Vector3Dクラス（演算子のオーバーロード）
	StudyCpp_decltype_01();				// decltype
	StudyCpp_template_01();				// テンプレート
	StudyCpp_std_pair_01();				// std::pair
	StudyCpp_RangeFor_01();				// 範囲for
	StudyCpp_RawString_01();			// 生文字リテラル
	StudyCpp_ConstantExpression_01();	// 定数式
	StudyCpp_static_assert_01();		// static_assert
	StudyCpp_Lambda_01();				// ラムダ式

	// 一時的なテスト
	f1();
	f2();



	bool success = game.Initialize();
	if (success)
	{
		game.RunLoop();
	}
	game.Shutdown();
	return 0;
}
