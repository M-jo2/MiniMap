#include "TestBakkes.h"



BAKKESMOD_PLUGIN(TestBakkes, "Test Plugin", "0.1", 0)

using namespace std;

TestBakkes::TestBakkes(){
	posBall.X = 0;
	posBall.Y = 0;
}
void TestBakkes::onLoad() {

	shared_ptr<GameWrapper> gw = this->gameWrapper;
	gw->RegisterDrawable(bind(&TestBakkes::Render, this, placeholders::_1));
}

void TestBakkes::onUnload() {

}

void TestBakkes::Render(CanvasWrapper canvas) {

	ServerWrapper* svw;
	
	if (gameWrapper->IsInOnlineGame()) {
		svw = &gameWrapper->GetOnlineGame();
	}else if (gameWrapper->IsInReplay()) {
		svw = &gameWrapper->GetGameEventAsReplay();
	}
	else if (gameWrapper->IsInFreeplay() || gameWrapper->IsInGame()) {
		svw = &gameWrapper->GetGameEventAsServer();
	}
	else {
		return;
	}
	
	ArrayWrapper<CarWrapper> cars = svw->GetCars();
	Vector posCar3D;
	Vector2 posCar2D;
	Vector2 vec;
	Vector2 sizeCar2D;
	Vector2 posMap;


	sizeCar2D.Y = 10;
	sizeCar2D.X = 10;
	
	posMap.X = posMapX;
	posMap.Y = posMapY;

	canvas.SetPosition(posMap);
	canvas.SetColor(200, 200, 200, 125);

	
	vec.X = WIDTHMAP/FACTORHEIGHMAP;
	vec.Y = HEIGHMAP/FACTORHEIGHMAP;
	

	canvas.DrawBox(vec);
	canvas.SetColor(100, 100, 100, 50);
	canvas.FillBox(vec);

	for (int i = 0; i < cars.Count(); i++) {
		if(i==0) canvas.SetColor(0, 200, 0, 100);
		else {
			if (cars.Get(i).GetTeamNum2() == 0) {
				canvas.SetColor(0, 0, 200, 100);
			}
			else {
				canvas.SetColor(200, 0, 0, 100);
			}
		}
		posCar3D = cars.Get(i).GetLocation();

		posCar2D.X = (posMap.X + (-1*posCar3D.X) / FACTORHEIGHMAP)+ vec.X /2 -5;
		posCar2D.Y = (posMap.Y + (-1*posCar3D.Y) / FACTORHEIGHMAP)+ vec.Y /2 -5;
		canvas.SetPosition(posCar2D);
		canvas.DrawString(cars.Get(i).GetOwnerName());
		canvas.DrawBox(sizeCar2D);
		canvas.FillBox(sizeCar2D);

	}
	/*
	ArrayWrapper<BallWrapper> balls = svw->GetGameBalls();
	if (balls.Count() > 0) {
		Vector posBall3D = balls.Get(0).GetLocation();
		posBall.X = (posMap.X + (-1 * posBall3D.X) / FACTORHEIGHMAP) + vec.X / 2;
		posBall.Y = (posMap.Y + (-1 * posBall3D.Y) / FACTORHEIGHMAP) + vec.Y / 2;
	}

	canvas.SetColor(255, 250, 250, 250);
	canvas.SetPosition(posBall);
	canvas.DrawBox(sizeCar2D-2);
	canvas.FillBox(sizeCar2D-2);
	*/
}