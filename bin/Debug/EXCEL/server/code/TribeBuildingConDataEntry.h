// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     TribeBuildingConDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _TRIBEBUILDINGCONDATALOADER_H
#define _TRIBEBUILDINGCONDATALOADER_H

#include <string>
#include <vector>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct TribeBuildingConDataEntry
{
	TribeBuildingConDataEntry() : id(0), level(0), money(0), wood(0), stone(0), cost(0){}
	virtual ~TribeBuildingConDataEntry(){ }
	virtual UInt32 GetKey() const { return 0xFFFFFFFF; };
	/**
	部落建筑id
	**/
	UInt8	id;

	/**
	名字
	**/
	string	name;

	/**
	等级
	**/
	UInt8	level;

	/**
	建筑效果
	**/
	string	effect;

	/**
	升级消耗的资金
	**/
	UInt32	money;

	/**
	升级消耗紫薇木
	**/
	UInt32	wood;

	/**
	升级消耗天元石
	**/
	UInt32	stone;

	/**
	日常维护费用
	**/
	UInt32	cost;
}; // TribeBuildingConDataEntry define end

//data visitor for the excel table
template <typename T>
class TribeBuildingConDataEntryVisitor
{
public:
	TribeBuildingConDataEntryVisitor(){ static_assert(std::is_base_of<TribeBuildingConDataEntry, T>::value != 0, "T must be inherited from TribeBuildingConDataEntry"); }
	virtual ~TribeBuildingConDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class TribeBuildingConDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	TribeBuildingConDataLoader(){ static_assert(std::is_base_of<TribeBuildingConDataEntry, T>::value != 0, "T must be inherited from TribeBuildingConDataEntry"); }
	~TribeBuildingConDataLoader(){ ClearData(); }

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
			doc.GetAttribute(pDataElem, "level", pData->level);
			doc.GetAttribute(pDataElem, "effect", pData->effect);
			doc.GetAttribute(pDataElem, "money", pData->money);
			doc.GetAttribute(pDataElem, "wood", pData->wood);
			doc.GetAttribute(pDataElem, "stone", pData->stone);
			doc.GetAttribute(pDataElem, "cost", pData->cost);
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

	void VisitData(TribeBuildingConDataEntryVisitor<T>& visitor)
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

