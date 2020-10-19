#pragma once
#pragma comment(lib,"bakkesmod.lib")
#include "bakkesmod/plugin/bakkesmodplugin.h"
#include "bakkesmod/plugin/pluginwindow.h"

class TestBakkes : public BakkesMod::Plugin::BakkesModPlugin
{
private :
	
	int HEIGHMAP = 10280;
	int WIDTHMAP = 8240;
	int posMapX = 50;
	int posMapY = 550;
	int FACTORHEIGHMAP = 50;
	Vector2 posBall;
public :
	TestBakkes();
	virtual void onLoad();
	virtual void onUnload();
	void Render(CanvasWrapper canvas);
};