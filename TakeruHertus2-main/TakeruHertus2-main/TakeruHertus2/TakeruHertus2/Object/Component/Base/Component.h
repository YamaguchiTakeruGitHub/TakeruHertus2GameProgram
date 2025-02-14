#pragma once
#include <iostream>
#include <unordered_map>
#include <memory>
#include <string>
#include <vector>
#include <cassert>

#include <DxLib.h>
#include <EffekseerForDXLib.h>

/// <summary>
/// ��{�R���|�[�l���g
/// </summary>
class Component
{
public:
	virtual ~Component() = default;

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Final() = 0;

};