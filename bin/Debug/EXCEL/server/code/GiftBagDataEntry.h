// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     GiftBagDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _GIFTBAGDATALOADER_H
#define _GIFTBAGDATALOADER_H

#include <string>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct GiftBagDataEntry
{
	GiftBagDataEntry() : id(0), param1(0), param2(0), param3(0){}
	virtual ~GiftBagDataEntry(){ }
	virtual UInt32 GetKey() const { return id; }
	/**
	礼包id
	**/
	UInt32	id;

	/**
	礼包名称
	**/
	string	name;

	/**
	参数1
	**/
	UInt32	param1;

	/**
	参数2
	**/
	UInt32	param2;

	/**
	参数3
	**/
	UInt32	param3;

	/**
	奖励
	**/
	string	reward;

	/**
	说明
	**/
	string	exp;

	/**
	描述
	**/
	string	description;
}; // GiftBagDataEntry define end

//data visitor for the excel table
template <typename T>
class GiftBagDataEntryVisitor
{
public:
	GiftBagDataEntryVisitor(){ static_assert(std::is_base_of<GiftBagDataEntry, T>::value != 0, "T must be inherited from GiftBagDataEntry"); }
	virtual ~GiftBagDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class GiftBagDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	GiftBagDataLoader(){ static_assert(std::is_base_of<GiftBagDataEntry, T>::value != 0, "T must be inherited from GiftBagDataEntry"); }
	~GiftBagDataLoader(){ ClearData(); }

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
			doc.GetAttribute(pDataElem, "param1", pData->param1);
			doc.GetAttribute(pDataElem, "param2", pData->param2);
			doc.GetAttribute(pDataElem, "param3", pData->param3);
			doc.GetAttribute(pDataElem, "reward", pData->reward);
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

	void VisitData(GiftBagDataEntryVisitor<T>& visitor)
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

