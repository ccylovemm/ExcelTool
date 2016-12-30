// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     TribeBuildingFuncDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _TRIBEBUILDINGFUNCDATALOADER_H
#define _TRIBEBUILDINGFUNCDATALOADER_H

#include <string>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct TribeBuildingFuncDataEntry
{
	TribeBuildingFuncDataEntry() : id(0), FUN1(0), FUN2(0), FUN3(0), FUN4(0), FUN5(0), FUN6(0), FUN7(0), FUN8(0), FUN9(0), FUN10(0){}
	virtual ~TribeBuildingFuncDataEntry(){ }
	virtual UInt32 GetKey() const { return id; }
	/**
	部落建筑功能ID
	**/
	UInt16	id;

	/**
	名字
	**/
	string	name;

	/**
	1级效果
	**/
	UInt32	FUN1;

	/**
	2级效果
	**/
	UInt32	FUN2;

	/**
	3级效果
	**/
	UInt32	FUN3;

	/**
	4级效果
	**/
	UInt32	FUN4;

	/**
	5级效果
	**/
	UInt32	FUN5;

	/**
	6级效果
	**/
	UInt32	FUN6;

	/**
	7级效果
	**/
	UInt32	FUN7;

	/**
	8级效果
	**/
	UInt32	FUN8;

	/**
	9级效果
	**/
	UInt32	FUN9;

	/**
	10级效果
	**/
	UInt32	FUN10;
}; // TribeBuildingFuncDataEntry define end

//data visitor for the excel table
template <typename T>
class TribeBuildingFuncDataEntryVisitor
{
public:
	TribeBuildingFuncDataEntryVisitor(){ static_assert(std::is_base_of<TribeBuildingFuncDataEntry, T>::value != 0, "T must be inherited from TribeBuildingFuncDataEntry"); }
	virtual ~TribeBuildingFuncDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class TribeBuildingFuncDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	TribeBuildingFuncDataLoader(){ static_assert(std::is_base_of<TribeBuildingFuncDataEntry, T>::value != 0, "T must be inherited from TribeBuildingFuncDataEntry"); }
	~TribeBuildingFuncDataLoader(){ ClearData(); }

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
			doc.GetAttribute(pDataElem, "FUN1", pData->FUN1);
			doc.GetAttribute(pDataElem, "FUN2", pData->FUN2);
			doc.GetAttribute(pDataElem, "FUN3", pData->FUN3);
			doc.GetAttribute(pDataElem, "FUN4", pData->FUN4);
			doc.GetAttribute(pDataElem, "FUN5", pData->FUN5);
			doc.GetAttribute(pDataElem, "FUN6", pData->FUN6);
			doc.GetAttribute(pDataElem, "FUN7", pData->FUN7);
			doc.GetAttribute(pDataElem, "FUN8", pData->FUN8);
			doc.GetAttribute(pDataElem, "FUN9", pData->FUN9);
			doc.GetAttribute(pDataElem, "FUN10", pData->FUN10);
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

	void VisitData(TribeBuildingFuncDataEntryVisitor<T>& visitor)
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

