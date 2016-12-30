// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     LotteryItemDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _LOTTERYITEMDATALOADER_H
#define _LOTTERYITEMDATALOADER_H

#include <string>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct LotteryItemDataEntry
{
	LotteryItemDataEntry() : id(0), set(0), itemid(0), bind(0), number(0), type(0), rate(0){}
	virtual ~LotteryItemDataEntry(){ }
	virtual UInt32 GetKey() const { return id; }
	/**
	id
	**/
	UInt32	id;

	/**
	祈福编号id
	**/
	UInt8	set;

	/**
	道具id
	**/
	UInt32	itemid;

	/**
	是否绑定
	**/
	UInt8	bind;

	/**
	掉落数量
	**/
	UInt32	number;

	/**
	品质类别
	**/
	UInt8	type;

	/**
	概率
	**/
	UInt16	rate;
}; // LotteryItemDataEntry define end

//data visitor for the excel table
template <typename T>
class LotteryItemDataEntryVisitor
{
public:
	LotteryItemDataEntryVisitor(){ static_assert(std::is_base_of<LotteryItemDataEntry, T>::value != 0, "T must be inherited from LotteryItemDataEntry"); }
	virtual ~LotteryItemDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class LotteryItemDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	LotteryItemDataLoader(){ static_assert(std::is_base_of<LotteryItemDataEntry, T>::value != 0, "T must be inherited from LotteryItemDataEntry"); }
	~LotteryItemDataLoader(){ ClearData(); }

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
			doc.GetAttribute(pDataElem, "set", pData->set);
			doc.GetAttribute(pDataElem, "itemid", pData->itemid);
			doc.GetAttribute(pDataElem, "bind", pData->bind);
			doc.GetAttribute(pDataElem, "number", pData->number);
			doc.GetAttribute(pDataElem, "type", pData->type);
			doc.GetAttribute(pDataElem, "rate", pData->rate);
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

	void VisitData(LotteryItemDataEntryVisitor<T>& visitor)
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

