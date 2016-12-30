// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     GiftBoxDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _GIFTBOXDATALOADER_H
#define _GIFTBOXDATALOADER_H

#include <string>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct GiftBoxDataEntry
{
	GiftBoxDataEntry() : id(0), icon(0), P1(0), P2(0), P3(0){}
	virtual ~GiftBoxDataEntry(){ }
	virtual UInt32 GetKey() const { return id; }
	/**
	礼包ID
	**/
	UInt16	id;

	/**
	礼包名称
	**/
	string	name;

	/**
	内容
	**/
	string	content;

	/**
	礼包ICON
	**/
	UInt16	icon;

	/**
	参数1
	**/
	UInt32	P1;

	/**
	参数2
	**/
	UInt32	P2;

	/**
	参数3
	**/
	UInt32	P3;

	/**
	说明
	**/
	string	exp;

	/**
	描述
	**/
	string	description;
}; // GiftBoxDataEntry define end

//data visitor for the excel table
template <typename T>
class GiftBoxDataEntryVisitor
{
public:
	GiftBoxDataEntryVisitor(){ static_assert(std::is_base_of<GiftBoxDataEntry, T>::value != 0, "T must be inherited from GiftBoxDataEntry"); }
	virtual ~GiftBoxDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class GiftBoxDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	GiftBoxDataLoader(){ static_assert(std::is_base_of<GiftBoxDataEntry, T>::value != 0, "T must be inherited from GiftBoxDataEntry"); }
	~GiftBoxDataLoader(){ ClearData(); }

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
			doc.GetAttribute(pDataElem, "content", pData->content);
			doc.GetAttribute(pDataElem, "icon", pData->icon);
			doc.GetAttribute(pDataElem, "P1", pData->P1);
			doc.GetAttribute(pDataElem, "P2", pData->P2);
			doc.GetAttribute(pDataElem, "P3", pData->P3);
			doc.GetAttribute(pDataElem, "exp", pData->exp);
			doc.GetAttribute(pDataElem, "description", pData->description);
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

	void VisitData(GiftBoxDataEntryVisitor<T>& visitor)
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

