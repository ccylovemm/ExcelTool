// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     TribeDonateDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _TRIBEDONATEDATALOADER_H
#define _TRIBEDONATEDATALOADER_H

#include <string>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct TribeDonateDataEntry
{
	TribeDonateDataEntry() : id(0), item1(0), type1(0), number1(0), con1(0), fund1(0), item2(0), type2(0), number2(0), con2(0), fund2(0){}
	virtual ~TribeDonateDataEntry(){ }
	virtual UInt32 GetKey() const { return id; }
	/**
	捐献ID
	**/
	UInt32	id;

	/**
	物品1
	**/
	UInt8	item1;

	/**
	帮会所获资源
	**/
	UInt8	type1;

	/**
	每次捐献数量1
	**/
	UInt8	number1;

	/**
	单个获得帮贡
	**/
	UInt8	con1;

	/**
	帮会获得资金
	**/
	UInt32	fund1;

	/**
	物品2
	**/
	UInt8	item2;

	/**
	帮会所获资源
	**/
	UInt8	type2;

	/**
	每次捐献数量2
	**/
	UInt8	number2;

	/**
	单个获得帮贡
	**/
	UInt8	con2;

	/**
	帮会获得资金
	**/
	UInt32	fund2;
}; // TribeDonateDataEntry define end

//data visitor for the excel table
template <typename T>
class TribeDonateDataEntryVisitor
{
public:
	TribeDonateDataEntryVisitor(){ static_assert(std::is_base_of<TribeDonateDataEntry, T>::value != 0, "T must be inherited from TribeDonateDataEntry"); }
	virtual ~TribeDonateDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class TribeDonateDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	TribeDonateDataLoader(){ static_assert(std::is_base_of<TribeDonateDataEntry, T>::value != 0, "T must be inherited from TribeDonateDataEntry"); }
	~TribeDonateDataLoader(){ ClearData(); }

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
			doc.GetAttribute(pDataElem, "item1", pData->item1);
			doc.GetAttribute(pDataElem, "type1", pData->type1);
			doc.GetAttribute(pDataElem, "number1", pData->number1);
			doc.GetAttribute(pDataElem, "con1", pData->con1);
			doc.GetAttribute(pDataElem, "fund1", pData->fund1);
			doc.GetAttribute(pDataElem, "item2", pData->item2);
			doc.GetAttribute(pDataElem, "type2", pData->type2);
			doc.GetAttribute(pDataElem, "number2", pData->number2);
			doc.GetAttribute(pDataElem, "con2", pData->con2);
			doc.GetAttribute(pDataElem, "fund2", pData->fund2);
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

	void VisitData(TribeDonateDataEntryVisitor<T>& visitor)
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

