#pragma once

class INetworkListener {
public:
	virtual void Start() = 0;
	virtual void Stop() = 0;

};