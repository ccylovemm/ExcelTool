// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     CollectGhostDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _COLLECTGHOSTDATALOADER_H
#define _COLLECTGHOSTDATALOADER_H

#include <string>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct CollectGhostDataEntry
{
	CollectGhostDataEntry() : id(0), green(0), blue(0), purple(0), golden(0){}
	virtual ~CollectGhostDataEntry(){ }
	virtual UInt32 GetKey() const { return id; }
	/**
	id
	**/
	UInt32	id;

	/**
	妖魂名
	**/
	string	name;

	/**
	绿魂值
	**/
	UInt32	green;

	/**
	蓝魂值
	**/
	UInt32	blue;

	/**
	紫魂值
	**/
	UInt32	purple;

	/**
	金魂值
	**/
	UInt32	golden;
}; // CollectGhostDataEntry define end

//data visitor for the excel table
template <typename T>
class CollectGhostDataEntryVisitor
{
public:
	CollectGhostDataEntryVisitor(){ static_assert(std::is_base_of<CollectGhostDataEntry, T>::value != 0, "T must be inherited from CollectGhostDataEntry"); }
	virtual ~CollectGhostDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class CollectGhostDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	CollectGhostDataLoader(){ static_assert(std::is_base_of<CollectGhostDataEntry, T>::value != 0, "T must be inherited from CollectGhostDataEntry"); }
	~CollectGhostDataLoader(){ ClearData(); }

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
			doc.GetAttribute(pDataElem, "green", pData->green);
			doc.GetAttribute(pDataElem, "blue", pData->blue);
			doc.GetAttribute(pDataElem, "purple", pData->purple);
			doc.GetAttribute(pDataElem, "golden", pData->golden);
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

	void VisitData(CollectGhostDataEntryVisitor<T>& visitor)
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

