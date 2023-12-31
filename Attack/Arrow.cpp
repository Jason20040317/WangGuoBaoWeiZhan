#include "Arrow.h"

bool Arrow::init()
{
	if (!Sprite::init())
	{
		return false;
	}
	sprite = Sprite::createWithSpriteFrameName("arrow.png");
	addChild(sprite);		
	return true;
}

void Arrow::shoot()
{
	SoundManager::playArrowRelease();
	runAction(Sequence::create(bulletAction,
              CallFuncN::create(CC_CALLBACK_0(Arrow::removeBullet, this)),
               NULL));
}

void Arrow::removeBullet()
{
	bool isMissed = true;//默认未击中
    auto instance = GameManager::getInstance();
   //下面表示弓箭所在区域，原理是将子弹相对于防御塔的位置与防御塔所在位置相加，再加上宽高共同判断
	auto bulletRect = Rect(this->getPositionX() +this->getParent()->getPositionX() - this->getContentSize().width /2,
                                this->getPositionY() +this->getParent()->getPositionY() - this->getContentSize().height/2,
								this->sprite->getContentSize().width,
                                this->sprite->getContentSize().height );
	
	auto monsterVector = instance->monsterVector;//开始遍历怪物
	for (int j = 0; j < monsterVector.size(); j++)
	{
		auto monster = monsterVector.at(j);
		auto monsterRect = monster->baseSprite->getBoundingBox();
		if (monsterRect.intersectsRect(bulletRect) && monster->getAttackBySoldier())//判断是否重叠并且是否可以被击中
		{
			auto currHp = monster->getCurrHp();
			currHp =  currHp - this->getMaxForce() + monster->getArmor();//执行扣血操作，现有生命值+护甲-被攻击值
			if(currHp <= 0){//没血了
				currHp = 0;
			}
			monster->setCurrHp( currHp );
			monster->getHpBar()->setPercentage((currHp/monster->getMaxHp())*100);//更新血条
			monster->getHurt();
            isMissed = false;//设为击中
			if(currHp == 0){
				monster->death();
			}
			break;
		}
	}
	if(isMissed){//如果没有击中
		sprite->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("decal_arrow.png"));
		sprite->runAction(Sequence::create(FadeOut::create(1.0f)//箭会插在地上并停留1秒
										,CallFuncN::create(CC_CALLBACK_0(Bullet::removeFromParent, this))
                                       , NULL));
	}else{
		this->removeFromParent();
	}
}