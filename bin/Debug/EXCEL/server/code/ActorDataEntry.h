// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     ActorDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _ACTORDATALOADER_H
#define _ACTORDATALOADER_H

#include <string>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct ActorDataEntry
{
	ActorDataEntry() : id(0), pathID(0), gatherTime(0), level(0), type(0), quality(0), size(0), moveSpeed(0), attackMode(0), moveInterval(0), viewRadius(0), moveRadius(0), approachRadius(0), reviveTime(0), exp(0), dropGroup(0), atk(0), def(0), maxhp(0), hit(0), evd(0), cri(0), crires(0), pri(0), hitrate(0), dodgerate(0), crirate(0), crireducerate(0), piercerate(0), critimes(0), resistrate(0){}
	virtual ~ActorDataEntry(){ }
	virtual UInt32 GetKey() const { return id; }
	/**
	序号
	**/
	UInt32	id;

	/**
	名称
	**/
	string	name;

	/**
	子名称
	**/
	string	subname;

	/**
	头像
	**/
	string	icon;

	/**
	路径ID
	**/
	UInt32	pathID;

	/**
	采集类读条时间
	**/
	UInt32	gatherTime;

	/**
	采集类读条提示
	**/
	string	gatherMsg;

	/**
	等级
	**/
	UInt16	level;

	/**
	类型
	**/
	UInt8	type;

	/**
	品质
	**/
	UInt8	quality;

	/**
	体型
	**/
	UInt8	size;

	/**
	移动速度
	**/
	UInt32	moveSpeed;

	/**
	攻击模式
	**/
	UInt32	attackMode;

	/**
	移动间隔
	**/
	UInt16	moveInterval;

	/**
	视野范围
	**/
	UInt16	viewRadius;

	/**
	巡逻范围
	**/
	UInt16	moveRadius;

	/**
	追击范围
	**/
	UInt16	approachRadius;

	/**
	复活时间
	**/
	UInt32	reviveTime;

	/**
	携带技能
	**/
	string	skills;

	/**
	经验
	**/
	UInt32	exp;

	/**
	掉落组
	**/
	UInt32	dropGroup;

	/**
	攻击
	**/
	UInt32	atk;

	/**
	防御
	**/
	UInt32	def;

	/**
	生命上限
	**/
	UInt32	maxhp;

	/**
	命中
	**/
	UInt16	hit;

	/**
	闪避
	**/
	UInt16	evd;

	/**
	暴击
	**/
	UInt16	cri;

	/**
	抗暴
	**/
	UInt16	crires;

	/**
	破防
	**/
	UInt16	pri;

	/**
	命中率
	**/
	UInt32	hitrate;

	/**
	闪避率
	**/
	UInt32	dodgerate;

	/**
	暴击率
	**/
	UInt32	crirate;

	/**
	抗暴率
	**/
	UInt32	crireducerate;

	/**
	破防率
	**/
	UInt32	piercerate;

	/**
	暴击伤害倍率
	**/
	UInt32	critimes;

	/**
	控制抵抗率
	**/
	UInt32	resistrate;
}; // ActorDataEntry define end

//data visitor for the excel table
template <typename T>
class ActorDataEntryVisitor
{
public:
	ActorDataEntryVisitor(){ static_assert(std::is_base_of<ActorDataEntry, T>::value != 0, "T must be inherited from ActorDataEntry"); }
	virtual ~ActorDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class ActorDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	ActorDataLoader(){ static_assert(std::is_base_of<ActorDataEntry, T>::value != 0, "T must be inherited from ActorDataEntry"); }
	~ActorDataLoader(){ ClearData(); }

	virtual bool ParseData(T* pT)
	{
		return true;
	}

	virtual bool AfterLoad()
	{
		return true;
	}

	bool LoadData(const std::string& strPath)
	{
		ClearData();
		Avalon::XmlDocument doc(strPath);
		if(!doc.LoadFile()) return false;
		Avalon::XmlElement* pElemRoot = doc.RootElement();
		if(pElemRoot == NULL)
		{
			return false;
		}
		TiXmlElement* pDataElem = doc.FirstChildElement(pElemRoot, "Row");
		UInt32 autoIncKey = 0;
		while(pDataElem != NULL)
		{
			T* pData = new T;
			doc.GetAttribute(pDataElem, "id", pData->id);
			doc.GetAttribute(pDataElem, "name", pData->name);
			doc.GetAttribute(pDataElem, "subname", pData->subname);
			doc.GetAttribute(pDataElem, "icon", pData->icon);
			doc.GetAttribute(pDataElem, "pathID", pData->pathID);
			doc.GetAttribute(pDataElem, "gatherTime", pData->gatherTime);
			doc.GetAttribute(pDataElem, "gatherMsg", pData->gatherMsg);
			doc.GetAttribute(pDataElem, "level", pData->level);
			doc.GetAttribute(pDataElem, "type", pData->type);
			doc.GetAttribute(pDataElem, "quality", pData->quality);
			doc.GetAttribute(pDataElem, "size", pData->size);
			doc.GetAttribute(pDataElem, "moveSpeed", pData->moveSpeed);
			doc.GetAttribute(pDataElem, "attackMode", pData->attackMode);
			doc.GetAttribute(pDataElem, "moveInterval", pData->moveInterval);
			doc.GetAttribute(pDataElem, "viewRadius", pData->viewRadius);
			doc.GetAttribute(pDataElem, "moveRadius", pData->moveRadius);
			doc.GetAttribute(pDataElem, "approachRadius", pData->approachRadius);
			doc.GetAttribute(pDataElem, "reviveTime", pData->reviveTime);
			doc.GetAttribute(pDataElem, "skills", pData->skills);
			doc.GetAttribute(pDataElem, "exp", pData->exp);
			doc.GetAttribute(pDataElem, "dropGroup", pData->dropGroup);
			doc.GetAttribute(pDataElem, "atk", pData->atk);
			doc.GetAttribute(pDataElem, "def", pData->def);
			doc.GetAttribute(pDataElem, "maxhp", pData->maxhp);
			doc.GetAttribute(pDataElem, "hit", pData->hit);
			doc.GetAttribute(pDataElem, "evd", pData->evd);
			doc.GetAttribute(pDataElem, "cri", pData->cri);
			doc.GetAttribute(pDataElem, "crires", pData->crires);
			doc.GetAttribute(pDataElem, "pri", pData->pri);
			doc.GetAttribute(pDataElem, "hitrate", pData->hitrate);
			doc.GetAttribute(pDataElem, "dodgerate", pData->dodgerate);
			doc.GetAttribute(pDataElem, "crirate", pData->crirate);
			doc.GetAttribute(pDataElem, "crireducerate", pData->crireducerate);
			doc.GetAttribute(pDataElem, "piercerate", pData->piercerate);
			doc.GetAttribute(pDataElem, "critimes", pData->critimes);
			doc.GetAttribute(pDataElem, "resistrate", pData->resistrate);
			if(!ParseData(pData)) return false;
			if(pData->GetKey() != 0xFFFFFFFF)
			{
				if(!_mapData.insert(std::make_pair(pData->GetKey(), pData)).second)
				{
					delete pData;
					ClearData();
					return false;
				}
			}
			else
			{
				if(!_mapData.insert(std::make_pair(++autoIncKey, pData)).second)
					delete pData;
			}
			pDataElem = doc.NextElement(pDataElem);
		}
		return AfterLoad();
	}

	void VisitData(ActorDataEntryVisitor<T>& visitor)
	{
		for(auto itr = _mapData.begin(); itr != _mapData.end(); ++itr)
		{
			if(!visitor(itr->second))
				return;
		}
	}

	T* FindEntry(UInt32 key)
	{
		auto itr = _mapData.find(key);
		if(itr != _mapData.end())
			return itr->second;
		return NULL;
	}

	void ClearData()
	{
		for(auto itr = _mapData.begin(); itr != _mapData.end();++itr)
		{
			const T *p = itr->second;
			delete p;
		}
		_mapData.clear();
	}
};

#endif

