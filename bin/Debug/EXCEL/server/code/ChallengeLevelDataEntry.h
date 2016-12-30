// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     ChallengeLevelDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _CHALLENGELEVELDATALOADER_H
#define _CHALLENGELEVELDATALOADER_H

#include <string>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct ChallengeLevelDataEntry
{
	ChallengeLevelDataEntry() : id(0), needCredit(0), phyattack(0), magattack(0), phydefense(0), magdefense(0), maxhp(0), hit(0), damageBonus(0), crit(0){}
	virtual ~ChallengeLevelDataEntry(){ }
	virtual UInt32 GetKey() const { return id; }
	/**
	id
	**/
	UInt32	id;

	/**
	仙阶名称
	**/
	string	level;

	/**
	需要声望
	**/
	UInt32	needCredit;

	/**
	物理攻击
	**/
	UInt32	phyattack;

	/**
	法术攻击
	**/
	UInt32	magattack;

	/**
	物理防御
	**/
	UInt32	phydefense;

	/**
	法术防御
	**/
	UInt32	magdefense;

	/**
	生命上限
	**/
	UInt32	maxhp;

	/**
	命中
	**/
	UInt32	hit;

	/**
	伤害加成
	**/
	UInt32	damageBonus;

	/**
	暴击
	**/
	UInt32	crit;
}; // ChallengeLevelDataEntry define end

//data visitor for the excel table
template <typename T>
class ChallengeLevelDataEntryVisitor
{
public:
	ChallengeLevelDataEntryVisitor(){ static_assert(std::is_base_of<ChallengeLevelDataEntry, T>::value != 0, "T must be inherited from ChallengeLevelDataEntry"); }
	virtual ~ChallengeLevelDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class ChallengeLevelDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	ChallengeLevelDataLoader(){ static_assert(std::is_base_of<ChallengeLevelDataEntry, T>::value != 0, "T must be inherited from ChallengeLevelDataEntry"); }
	~ChallengeLevelDataLoader(){ ClearData(); }

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
			doc.GetAttribute(pDataElem, "level", pData->level);
			doc.GetAttribute(pDataElem, "needCredit", pData->needCredit);
			doc.GetAttribute(pDataElem, "phyattack", pData->phyattack);
			doc.GetAttribute(pDataElem, "magattack", pData->magattack);
			doc.GetAttribute(pDataElem, "phydefense", pData->phydefense);
			doc.GetAttribute(pDataElem, "magdefense", pData->magdefense);
			doc.GetAttribute(pDataElem, "maxhp", pData->maxhp);
			doc.GetAttribute(pDataElem, "hit", pData->hit);
			doc.GetAttribute(pDataElem, "damageBonus", pData->damageBonus);
			doc.GetAttribute(pDataElem, "crit", pData->crit);
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

	void VisitData(ChallengeLevelDataEntryVisitor<T>& visitor)
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

