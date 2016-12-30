// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     MallItemDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _MALLITEMDATALOADER_H
#define _MALLITEMDATALOADER_H

#include <string>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct MallItemDataEntry
{
	MallItemDataEntry() : id(0), itemid(0), num(0), price(0), discountprice(0), moneytype(0), subType(0), totalnum(0), limitnum(0), bBind(0), bLimit(0), hide(0){}
	virtual ~MallItemDataEntry(){ }
	virtual UInt32 GetKey() const { return id; }
	/**
	商品id
	**/
	UInt32	id;

	/**
	道具id
	**/
	UInt32	itemid;

	/**
	一组数量
	**/
	UInt16	num;

	/**
	原价
	**/
	UInt32	price;

	/**
	折扣价
	**/
	UInt32	discountprice;

	/**
	货币类型
	**/
	UInt8	moneytype;

	/**
	页签分类
	**/
	UInt8	subType;

	/**
	出售总量
	**/
	UInt32	totalnum;

	/**
	每人限量
	**/
	UInt32	limitnum;

	/**
	是否绑定
	**/
	UInt32	bBind;

	/**
	是否限量
	**/
	UInt32	bLimit;

	/**
	客户端是否隐藏
	**/
	UInt32	hide;

	/**
	节日类型
	**/
	string	festival;
}; // MallItemDataEntry define end

//data visitor for the excel table
template <typename T>
class MallItemDataEntryVisitor
{
public:
	MallItemDataEntryVisitor(){ static_assert(std::is_base_of<MallItemDataEntry, T>::value != 0, "T must be inherited from MallItemDataEntry"); }
	virtual ~MallItemDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class MallItemDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	MallItemDataLoader(){ static_assert(std::is_base_of<MallItemDataEntry, T>::value != 0, "T must be inherited from MallItemDataEntry"); }
	~MallItemDataLoader(){ ClearData(); }

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
			doc.GetAttribute(pDataElem, "itemid", pData->itemid);
			doc.GetAttribute(pDataElem, "num", pData->num);
			doc.GetAttribute(pDataElem, "price", pData->price);
			doc.GetAttribute(pDataElem, "discountprice", pData->discountprice);
			doc.GetAttribute(pDataElem, "moneytype", pData->moneytype);
			doc.GetAttribute(pDataElem, "subType", pData->subType);
			doc.GetAttribute(pDataElem, "totalnum", pData->totalnum);
			doc.GetAttribute(pDataElem, "limitnum", pData->limitnum);
			doc.GetAttribute(pDataElem, "bBind", pData->bBind);
			doc.GetAttribute(pDataElem, "bLimit", pData->bLimit);
			doc.GetAttribute(pDataElem, "hide", pData->hide);
			doc.GetAttribute(pDataElem, "festival", pData->festival);
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

	void VisitData(MallItemDataEntryVisitor<T>& visitor)
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

