// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     TribeTerritoryDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _TRIBETERRITORYDATALOADER_H
#define _TRIBETERRITORYDATALOADER_H

#include <string>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct TribeTerritoryDataEntry
{
	TribeTerritoryDataEntry() : id(0), level(0), uWoods(0), uRocks(0), uMetal(0), uSilver(0), uWarTime(0), uMapId(0){}
	virtual ~TribeTerritoryDataEntry(){ }
	virtual UInt32 GetKey() const { return id; }
	/**
	领土id
	**/
	UInt32	id;

	/**
	名称
	**/
	string	name;

	/**
	领土等级
	**/
	UInt8	level;

	/**
	每周出产的木头
	**/
	UInt32	uWoods;

	/**
	每周出产的石块
	**/
	UInt32	uRocks;

	/**
	每周出产的金属
	**/
	UInt32	uMetal;

	/**
	每周产出的金币
	**/
	UInt32	uSilver;

	/**
	战争时间段
	**/
	UInt8	uWarTime;

	/**
	领土对应的地图ID
	**/
	UInt32	uMapId;
}; // TribeTerritoryDataEntry define end

//data visitor for the excel table
template <typename T>
class TribeTerritoryDataEntryVisitor
{
public:
	TribeTerritoryDataEntryVisitor(){ static_assert(std::is_base_of<TribeTerritoryDataEntry, T>::value != 0, "T must be inherited from TribeTerritoryDataEntry"); }
	virtual ~TribeTerritoryDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class TribeTerritoryDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	TribeTerritoryDataLoader(){ static_assert(std::is_base_of<TribeTerritoryDataEntry, T>::value != 0, "T must be inherited from TribeTerritoryDataEntry"); }
	~TribeTerritoryDataLoader(){ ClearData(); }

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
			doc.GetAttribute(pDataElem, "uWoods", pData->uWoods);
			doc.GetAttribute(pDataElem, "uRocks", pData->uRocks);
			doc.GetAttribute(pDataElem, "uMetal", pData->uMetal);
			doc.GetAttribute(pDataElem, "uSilver", pData->uSilver);
			doc.GetAttribute(pDataElem, "uWarTime", pData->uWarTime);
			doc.GetAttribute(pDataElem, "uMapId", pData->uMapId);
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

	void VisitData(TribeTerritoryDataEntryVisitor<T>& visitor)
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

