#ifndef _BULLET_H_
#define _BULLET_H_

#include "SoundManager.h"
#include "cocos2d.h"
#include "GameManager.h"

USING_NS_CC;

class Bullet : public Sprite
{
public:
	 Bullet();
    ~Bullet();
    virtual bool init();
    CREATE_FUNC(Bullet);

protected:
	CC_SYNTHESIZE(int, maxForce, MaxForce);//塔的攻击力
	CC_SYNTHESIZE(int, bulletScope, BulletScope);//塔的子弹攻击范围
	CC_SYNTHESIZE(int, bulletType, BulletType);//子弹类型
	CC_SYNTHESIZE(Spawn*, bulletAction, BulletAction);//子弹飞行动画
	Sprite* sprite;//子弹精灵
	virtual void shoot(){};//攻击
	virtual void removeBullet(){};//攻击后移除
};

#endif