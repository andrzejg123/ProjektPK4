#pragma once
class GameViewCloseCallback
{
public:
	virtual void closeGame() = 0;
	virtual ~GameViewCloseCallback() = default;
};

