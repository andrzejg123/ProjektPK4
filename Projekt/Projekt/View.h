#pragma once
class View
{
public:
	//Displays new view (this may stop current execution for a while)
	virtual void show() = 0;
	virtual ~View() = default;
};

