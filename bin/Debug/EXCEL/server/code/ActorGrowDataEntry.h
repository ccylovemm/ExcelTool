// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     ActorGrowDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _ACTORGROWDATALOADER_H
#define _ACTORGROWDATALOADER_H

#include <string>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct ActorGrowDataEntry
{
	ActorGrowDataEntry() : occu(0), basePoint(0), Stren(0), Intel(0), Agil(0), Vital(0), phyattack(0), magattack(0), phydefense(0), magdefense(0), maxhp(0), fruitStren(0), fruitIntel(0), fruitAgil(0), fruitVital(0){}
	virtual ~ActorGrowDataEntry(){ }
	virtual UInt32 GetKey() const { return occu; }
	/**
	职业
	**/
	UInt16	occu;

	/**
	点数
	**/
	UInt16	basePoint;

	/**
	力量
	**/
	UInt16	Stren;

	/**
	智力
	**/
	UInt16	Intel;

	/**
	敏捷
	**/
	UInt16	Agil;

	/**
	体力
	**/
	UInt16	Vital;

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
	蟠桃力量
	**/
	UInt16	fruitStren;

	/**
	蟠桃智力
	**/
	UInt16	fruitIntel;

	/**
	蟠桃敏捷
	**/
	UInt16	fruitAgil;

	/**
	蟠桃体力
	**/
	UInt16	fruitVital;
}; // ActorGrowDataEntry define end

//data visitor for the excel table
template <typename T>
class ActorGrowDataEntryVisitor
{
public:
	ActorGrowDataEntryVisitor(){ static_assert(std::is_base_of<ActorGrowDataEntry, T>::value != 0, "T must be inherited from ActorGrowDataEntry"); }
	virtual ~ActorGrowDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class ActorGrowDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	ActorGrowDataLoader(){ static_assert(std::is_base_of<ActorGrowDataEntry, T>::value != 0, "T must be inherited from ActorGrowDataEntry"); }
	~ActorGrowDataLoader(){ ClearData(); }

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
			doc.GetAttribute(pDataElem, "occu", pData->occu);
			doc.GetAttribute(pDataElem, "basePoint", pData->basePoint);
			doc.GetAttribute(pDataElem, "Stren", pData->Stren);
			doc.GetAttribute(pDataElem, "Intel", pData->Intel);
			doc.GetAttribute(pDataElem, "Agil", pData->Agil);
			doc.GetAttribute(pDataElem, "Vital", pData->Vital);
			doc.GetAttribute(pDataElem, "phyattack", pData->phyattack);
			doc.GetAttribute(pDataElem, "magattack", pData->magattack);
			doc.GetAttribute(pDataElem, "phydefense", pData->phydefense);
			doc.GetAttribute(pDataElem, "magdefense", pData->magdefense);
			doc.GetAttribute(pDataElem, "maxhp", pData->maxhp);
			doc.GetAttribute(pDataElem, "fruitStren", pData->fruitStren);
			doc.GetAttribute(pDataElem, "fruitIntel", pData->fruitIntel);
			doc.GetAttribute(pDataElem, "fruitAgil", pData->fruitAgil);
			doc.GetAttribute(pDataElem, "fruitVital", pData->fruitVital);
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

	void VisitData(ActorGrowDataEntryVisitor<T>& visitor)
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

