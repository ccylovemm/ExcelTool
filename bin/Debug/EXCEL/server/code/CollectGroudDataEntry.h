// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     CollectGroudDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _COLLECTGROUDDATALOADER_H
#define _COLLECTGROUDDATALOADER_H

#include <string>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct CollectGroudDataEntry
{
	CollectGroudDataEntry() : id(0), valume(0), needItem(0), needItemNum(0), greenShow(0), blueShow(0), purpleShow(0), goldenShow(0), greenPercent(0), bluePercent(0), purplePercent(0), goldenPercent(0){}
	virtual ~CollectGroudDataEntry(){ }
	virtual UInt32 GetKey() const { return id; }
	/**
	id
	**/
	UInt32	id;

	/**
	葫芦名
	**/
	string	name;

	/**
	葫芦容量
	**/
	UInt32	valume;

	/**
	进阶道具
	**/
	UInt32	needItem;

	/**
	需要道具数目
	**/
	UInt32	needItemNum;

	/**
	显示绿魂概率
	**/
	UInt32	greenShow;

	/**
	显示蓝魂概率
	**/
	UInt32	blueShow;

	/**
	显示掉紫魂概率
	**/
	UInt32	purpleShow;

	/**
	显示掉金魂概率
	**/
	UInt32	goldenShow;

	/**
	掉绿魂概率
	**/
	UInt32	greenPercent;

	/**
	掉蓝魂概率
	**/
	UInt32	bluePercent;

	/**
	掉紫魂概率
	**/
	UInt32	purplePercent;

	/**
	掉金魂概率
	**/
	UInt32	goldenPercent;

	/**
	葫芦故事（48字）
	**/
	string	story;
}; // CollectGroudDataEntry define end

//data visitor for the excel table
template <typename T>
class CollectGroudDataEntryVisitor
{
public:
	CollectGroudDataEntryVisitor(){ static_assert(std::is_base_of<CollectGroudDataEntry, T>::value != 0, "T must be inherited from CollectGroudDataEntry"); }
	virtual ~CollectGroudDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class CollectGroudDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	CollectGroudDataLoader(){ static_assert(std::is_base_of<CollectGroudDataEntry, T>::value != 0, "T must be inherited from CollectGroudDataEntry"); }
	~CollectGroudDataLoader(){ ClearData(); }

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
			doc.GetAttribute(pDataElem, "valume", pData->valume);
			doc.GetAttribute(pDataElem, "needItem", pData->needItem);
			doc.GetAttribute(pDataElem, "needItemNum", pData->needItemNum);
			doc.GetAttribute(pDataElem, "greenShow", pData->greenShow);
			doc.GetAttribute(pDataElem, "blueShow", pData->blueShow);
			doc.GetAttribute(pDataElem, "purpleShow", pData->purpleShow);
			doc.GetAttribute(pDataElem, "goldenShow", pData->goldenShow);
			doc.GetAttribute(pDataElem, "greenPercent", pData->greenPercent);
			doc.GetAttribute(pDataElem, "bluePercent", pData->bluePercent);
			doc.GetAttribute(pDataElem, "purplePercent", pData->purplePercent);
			doc.GetAttribute(pDataElem, "goldenPercent", pData->goldenPercent);
			doc.GetAttribute(pDataElem, "story", pData->story);
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

	void VisitData(CollectGroudDataEntryVisitor<T>& visitor)
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

