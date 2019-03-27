#pragma once
class PendingObjectEvent
{
public:
	virtual void cancel() = 0;
	virtual ~PendingObjectEvent() = default;
};

