#ifndef _BASE_TOWER_
#define _BASE_TOWER_

#include "cocos2d.h"
#include "Circle.h"
#include "Terrain.h"
#include "BaseMonster.h"
#include "SoundManager.h"

USING_NS_CC;

typedef enum{
    ARCHER_1 = 0, //������
    ARCHER_2, //2������
    ARCHER_3, //3������
	COSSBOW, //����
	TOTEMTOWER, //Ұ��
	ARTILLERY_1,//1������
	ARTILLERY_2,//2������
	ARTILLERY_3,//3������
	EARTHQUAKE, //����
	MECHS, //����
	BARAACKS_1,//1����Ӫ
	BARAACKS_2,//2����Ӫ
	BARAACKS_3,//3����Ӫ
	ASSASSIN,//����
	TEMPLAR,//սʿ
	MAGE_1,//1����ʦ��
	MAGE_2,//2����ʦ��
	MAGE_3,//3����ʦ��
	ARCHMAGE,//������
	NEC,//���鷨
}TowerType;

class BaseTower: public Sprite
{
public:
   BaseTower();
   ~BaseTower();
   virtual void updateTower(){};
   virtual void sellTower();
   virtual void removeTower();
   virtual bool init();
   CC_SYNTHESIZE(TowerType, towerType, TowerType); 
   CC_SYNTHESIZE(xh::Terrain*, myTerrain, MyTerrain);
public:
   CC_SYNTHESIZE(std::string, towerName, TowerName); 
   CC_SYNTHESIZE(int, level, Level);
   CC_SYNTHESIZE(float, scope, Scope);
   CC_SYNTHESIZE(float, nextScope, NextScope);
   CC_SYNTHESIZE(float, rate, Rate);
   CC_SYNTHESIZE(int, force, Force);
   CC_SYNTHESIZE(int, updateMoney, UpdateMoney);
   CC_SYNTHESIZE(int, buildMoney, BuildMoney);
   virtual void showTowerInfo();
   bool isUpdateMenuShown;
   virtual void update1(){};
   virtual void update2(){};
   virtual void setRallyPoint(Point point){};
protected:   
   virtual void checkNearestMonster();
   BaseMonster* nearestMonster;  
   bool onTouchBegan(Touch *touch, Event *event);
   void onTouchEnded(Touch* touch, Event* event);
   virtual void showUpdateMenu(){};
   virtual void hideUpdateMenu();
   Sprite* terrain;
   void setListener();

};

#endif