// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     TribeBossDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _TRIBEBOSSDATALOADER_H
#define _TRIBEBOSSDATALOADER_H

#include <string>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct TribeBossDataEntry
{
	TribeBossDataEntry() : id(0), totemlevel(0), money(0), wood(0), soul(0), metal(0){}
	virtual ~TribeBossDataEntry(){ }
	virtual UInt32 GetKey() const { return id; }
	/**
	部落BOSS id
	**/
	UInt32	id;

	/**
	名字
	**/
	string	name;

	/**
	所需图腾等级
	**/
	UInt8	totemlevel;

	/**
	所需资金
	**/
	UInt32	money;

	/**
	所需木材
	**/
	UInt32	wood;

	/**
	所需兽魂
	**/
	UInt32	soul;

	/**
	所需金属
	**/
	UInt32	metal;
}; // TribeBossDataEntry define end

//data visitor for the excel table
template <typename T>
class TribeBossDataEntryVisitor
{
public:
	TribeBossDataEntryVisitor(){ static_assert(std::is_base_of<TribeBossDataEntry, T>::value != 0, "T must be inherited from TribeBossDataEntry"); }
	virtual ~TribeBossDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class TribeBossDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	TribeBossDataLoader(){ static_assert(std::is_base_of<TribeBossDataEntry, T>::value != 0, "T must be inherited from TribeBossDataEntry"); }
	~TribeBossDataLoader(){ ClearData(); }

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
			doc.GetAttribute(pDataElem, "totemlevel", pData->totemlevel);
			doc.GetAttribute(pDataElem, "money", pData->money);
			doc.GetAttribute(pDataElem, "wood", pData->wood);
			doc.GetAttribute(pDataElem, "soul", pData->soul);
			doc.GetAttribute(pDataElem, "metal", pData->metal);
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

	void VisitData(TribeBossDataEntryVisitor<T>& visitor)
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

