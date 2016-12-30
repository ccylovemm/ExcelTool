// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     TribeShopDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _TRIBESHOPDATALOADER_H
#define _TRIBESHOPDATALOADER_H

#include <string>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct TribeShopDataEntry
{
	TribeShopDataEntry() : id(0), tslevel(0), bLimit(0), sum(0), buynum(0), price(0){}
	virtual ~TribeShopDataEntry(){ }
	virtual UInt32 GetKey() const { return id; }
	/**
	部落商店物品id
	**/
	UInt32	id;

	/**
	所需宝库等级
	**/
	UInt8	tslevel;

	/**
	是否限量
	**/
	UInt8	bLimit;

	/**
	出售总量
	**/
	UInt16	sum;

	/**
	每人限购数量
	**/
	UInt16	buynum;

	/**
	所需贡献
	**/
	UInt32	price;
}; // TribeShopDataEntry define end

//data visitor for the excel table
template <typename T>
class TribeShopDataEntryVisitor
{
public:
	TribeShopDataEntryVisitor(){ static_assert(std::is_base_of<TribeShopDataEntry, T>::value != 0, "T must be inherited from TribeShopDataEntry"); }
	virtual ~TribeShopDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class TribeShopDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	TribeShopDataLoader(){ static_assert(std::is_base_of<TribeShopDataEntry, T>::value != 0, "T must be inherited from TribeShopDataEntry"); }
	~TribeShopDataLoader(){ ClearData(); }

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
			doc.GetAttribute(pDataElem, "tslevel", pData->tslevel);
			doc.GetAttribute(pDataElem, "bLimit", pData->bLimit);
			doc.GetAttribute(pDataElem, "sum", pData->sum);
			doc.GetAttribute(pDataElem, "buynum", pData->buynum);
			doc.GetAttribute(pDataElem, "price", pData->price);
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

	void VisitData(TribeShopDataEntryVisitor<T>& visitor)
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

